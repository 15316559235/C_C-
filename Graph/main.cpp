#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef struct ArcNode
{
    int adjvex;
    int data;
    int flag=0;
    int temp=0;
    struct ArcNode *next;
}ArcNode,AdjList[MAXSIZE];

typedef struct ALGraph{
    AdjList h;
    int vexnum,arcnum;
};

struct Stack{
    ArcNode *data;
    Stack *next;
};

struct Queue{
    ArcNode *data;
    Queue *front;
    Queue *next;
};
int f=0;

void InitQueue(Queue *&Q){
    Q=(Queue *)malloc(sizeof(Queue));
    Q->front=NULL;
    Q->next=NULL;
}

void EnQueue(Queue *&Q,ArcNode *&e){
    Queue *p;
    if(f==0){
        Q->data=e;
        f=1;
    }
    else{
        p=(Queue *)malloc(sizeof(Queue));
        p->data=e;
        p->next=Q;
        Q->front=p;
        p->front=NULL;
        Q=p;
    }
}

void DeQueue(Queue *&Q,ArcNode *&e){
    Queue *p;
    p=Q;
    while(p->next!=NULL){
        p=p->next;
    }
    e=p->data;
    if(p->front==NULL){
        p->next=NULL;
        f=0;
    }
    else{
        p->front->next=NULL;
    }
}

void InitStack(Stack *&S){
    S=(Stack *)malloc(sizeof(Stack));
    S->next=NULL;
}

void Pop(Stack *&S,ArcNode *&e){
    e=S->data;
    S=S->next;
}

void Push(Stack *&S,ArcNode *&e){
    Stack *p;
    p=(Stack *)malloc(sizeof(Stack));
    p->data=e;
    p->next=S;
    S=p;
}

int AdjMatrix[MAXSIZE][MAXSIZE]={0};

void CreateList(ALGraph *g){
    int i,j,k;
    ArcNode *p;
    printf("输入顶点数和边数：\n");
    scanf("%d%d",&g->vexnum,&g->arcnum);
    for(i=1;i<=g->vexnum;i++){
        printf("请输入顶点信息：\n");
        scanf("%d",&g->h[i].data);
    }
    for(k=0;k<2*g->arcnum;k++){
        printf("请输入边（i,j）的顶点序号：\n");
        scanf("%d%d",&i,&j);
        p=(ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex=i;
        p->next=g->h[j].next;
        g->h[j].next=p;
    }
}

void exchange(ALGraph *g){
    int i,k;
    ArcNode *p;
    for(k=1;k<=g->vexnum;k++){
        p=g->h[k].next;
        while(p!=NULL){
            i=p->adjvex;
            AdjMatrix[k][i]=1;
            p=p->next;
        }
    }
}

bool isempty(Stack *&s){
    if(s==NULL)
        return true;
    else
        return false;
}

void depth(ALGraph *g){
    printf("深度遍历：");
    Stack *S;
    ArcNode *p,*q;
    InitStack(S);
    q=&g->h[1];
    Push(S,q);
    q->flag=1;
    while(!isempty(S)){
        printf("%d",q->data);
        p=q;
        p=p->next;
        if(p==NULL)
            Pop(S,p);
        q=&g->h[p->adjvex];
        while(q->flag!=0){
            p=p->next;
            if(p==NULL)
                Pop(S,p);
            if(isempty(S)){
                printf("\n");
                return;
            }
            if(p->flag==1)
                p=p->next;
            q=&g->h[p->adjvex];
        }
        Push(S,q);
        q->flag=1;
    }
}

bool isempty(Queue *&Q){
    if(Q->next==NULL&&Q->front==NULL&&f==0)
        return true;
    else
        return false;
}

void print(ALGraph *g){
    int i,j;
    printf("邻接矩阵：\n");
    for(i=1;i<=g->vexnum;i++){
        for(j=1;j<=g->vexnum;j++){
            printf("%d  ",AdjMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void broadth(ALGraph *g){
    printf("广度遍历：");
    Queue *Q;
    InitQueue(Q);
    ArcNode *p,*q;
    p=&g->h[1];
    q=p;
    do{
        if(q->temp==0){
            printf("%d",q->data);
            EnQueue(Q,q);
            q->temp=1;
            p=p->next;
            if(p==NULL){
                DeQueue(Q,p);
            }
            else
                q=&g->h[p->adjvex];
        }
        else{
            p=p->next;
            if(p==NULL){
                if(isempty(Q)) {
                    printf("\n");
                    return;
                }
                DeQueue(Q,p);
            }
            else
                q=&g->h[p->adjvex];
        }
    }while(!(isempty(Q)&&p==NULL));
}

int main(){
    ALGraph G;
    CreateList(&G);
    exchange(&G);
    depth(&G);
    broadth(&G);
    print(&G);
    return 0;
}
