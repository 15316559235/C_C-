#include <stdio.h>
#include <stdlib.h>
#define  SIZE 100

struct BTree{
    int data;
    BTree *lchild,*rchild;
};

struct stack{
    BTree *data[SIZE];
    int top;
    int flag[SIZE]={-1};
};

struct Queue{
	BTree *data;
	Queue *front;
	Queue *next;
};

int f=0;
int k=0;
int sum=0;

BTree * CreateBTree(){
    BTree *bt;
    int ch;
    printf("请输入数据：  \n");
    scanf("%d",&ch);
    if(ch!=0){
        bt=(BTree *)malloc(sizeof(BTree));
        bt->data=ch;
        bt->lchild=CreateBTree();
        bt->rchild=CreateBTree();
    }
    return bt;
}

void push(stack *s,BTree *bt){
    s->top++;
    s->data[s->top]=bt;
}

BTree *pop(stack *s){
    if(s->top==-1)
        return NULL;
    else{
        s->top--;
        return s->data[s->top+1];
    }
}

void preorder(BTree *bt){
    stack s;
    s.top=-1;
    if(bt!=NULL){
        printf("前序遍历：");
        while(bt!=NULL||s.top!=-1){
            while (bt!=NULL){
                printf("%d",bt->data);
                push(&s,bt);
                bt=bt->lchild;
            }
            bt=pop(&s);
            bt=bt->rchild;
        }
    }
    else{
        printf("二叉树为空\n");
    }
    printf("\n");
}

void midorder(BTree *bt){
    stack s;
    s.top=-1;
    if(bt!=NULL){
        printf("中序遍历：");
        while(bt!=NULL||s.top!=-1){
            while(bt!=NULL){
                push(&s,bt);
                bt=bt->lchild;
            }
            bt=pop(&s);
            printf("%d",bt->data);
            bt=bt->rchild;
        }
    }
    else{
        printf("二叉树为空\n");
    }
    printf("\n");
}

void aforder(BTree *bt){
    stack s;
    s.top=-1;
    if(bt!=NULL){
        printf("后序遍历：");
        while (bt!=NULL||s.top!=-1){
            while (bt!=NULL){
                push(&s,bt);
                s.flag[s.top]=0;
                bt=bt->lchild;
            }
            if(s.flag[s.top]==0){
                bt=s.data[s.top];
                s.flag[s.top]=1;
                bt=bt->rchild;
            }
            else{
                bt=pop(&s);
                printf("%d",bt->data);
                bt=NULL;
            }
        }
    }
    else{
        printf("二叉树为空\n");
    }
    printf("\n");
}

void InitQueue(Queue *&Q){
	Q=(Queue *)malloc(sizeof(Queue));
	Q->front=NULL;
	Q->next=NULL;
}

void EnQueue(Queue *&Q,BTree *&e){
	Queue *p;
    k++;
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

void DeQueue(Queue *&Q,BTree *&e){
	Queue *p;
    p=Q;
    k--;
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

void letree(BTree *bt){
    Queue *q;
    InitQueue(q);
    BTree *t;
    if(bt!=NULL){
        EnQueue(q,bt);
        printf("层次遍历：");
        while(k!=0){
            DeQueue(q,t);
            printf("%d",t->data);
            if(t->lchild!=NULL){
                EnQueue(q,t->lchild);
            }
            if(t->rchild!=NULL){
                EnQueue(q,t->rchild);
            }
            if(t->lchild==NULL&&t->rchild==NULL)
                sum++;
        }
    }
    else{
        printf("二叉树为空\n");
    }
    printf("\n");
}

int Travel(BTree *&bt,int lv,int n){
    int l;
    if(bt!=NULL){
        if(bt->data==n)
            return lv;
        l=Travel(bt->lchild,lv+1,n);
        if(l!=0)
            return l;
        else
            return Travel(bt->rchild,lv+1,n);
    }
    return 0;
}

BTree *ExTravel(BTree *&bt,int lv,int n){
    BTree *l;
    if(bt!=NULL){
        if(bt->data==n)
            return bt;
        l=ExTravel(bt->lchild,lv+1,n);
        if(l!=NULL)
            return l;
        else
            return ExTravel(bt->rchild,lv+1,n);
    }
    return NULL;
}


void exchange(BTree *&bt,int l){
    BTree *p,*q;
    p=ExTravel(bt,1,l);
    q=p->lchild;
    p->lchild=p->rchild;
    p->rchild=q;
}


int main(){
    BTree *bt;
    int n,lv,l;
    bt=CreateBTree();
    preorder(bt);
    midorder(bt);
    aforder(bt);
    letree(bt);
    printf("叶子个数：%d\n",sum);
    printf("请输入数据：\n");
    scanf("%d",&n);
    lv=Travel(bt,1,n);
    printf("%d所在层数为：%d\n",n,lv);
    printf("请输入子树交换的数据：\n");
    scanf("%d",&l);
    exchange(bt,l);
    preorder(bt);
    midorder(bt);
    aforder(bt);
    letree(bt);
    return  0;
}