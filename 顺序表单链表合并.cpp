#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

struct LinkList{
	int data;
	LinkList *front;
	LinkList *next;
};

typedef struct{
	int data[100];
	int length;
}SqList;

void InitSqList(SqList &L){
	L.length=0;
}

int SqListInsert(int n,SqList &L,int t){
	int i,j;
	if(t<0||t>L.length)
		return false;
	for(i=0;i<=L.length;i++){
		if(i==t){
			for(j=L.length-1;j!=t-1;j--){
				L.data[j+1]=L.data[j];
			}
			break;
		}
	}
	L.data[t]=n;
	L.length++;
	return true;
}

int SqListDelete(int t,SqList &L){
	int i;
	if(t<0||t>=L.length)
		return false;
	for(i=t;i<L.length-1;i++){
		L.data[i]=L.data[i+1];
	}
	L.length--;
	return true;
}

void SqListPrint(SqList &L){
	int i;
	for(i=0;i<L.length;i++)
		printf("%d     ",L.data[i]);
}

void LinkListInit(LinkList *&L){
	L=(LinkList *)malloc(sizeof(LinkList));
	L->next=NULL;
	L->front=NULL;
}

void LinkListPrint(LinkList *&L){
	LinkList *p;
	p=L;
	while(p!=NULL){
		printf("%d     ",p->data);
		p=p->next;
	}
}

void LinkListInsert(LinkList *&L,int n,int t){
	int i;
	LinkList *q,*p;
	p=L;
	q=(LinkList *)malloc(sizeof(LinkList));
	if(t==1&&p->next==NULL){
		p->data=n;
	}
	else{
		for(i=1;i<t;i++){
				p=p->next;
			}
			if(p==NULL){
				p=L;
				for(i=1;i<t-1;i++)
					p=p->next;
				q->data=n;
				q->front=p;
				q->next=NULL;
				p->next=q;
			}
			else{
				if(p->front==NULL){
					q->data=n;
					q->next=p;
					q->front=NULL;
					p->front=q;
					L=q;
				}
				else{
					q->data=n;
					q->next=p;
					q->front=p->front;
					p->front->next=q;
					p->front=q;
				}
			}
	}
}

void LinkListDelete(LinkList *&L,int t){
	int i;
	LinkList *p;
	p=L;
	for(i=1;i<t;i++){
		p=p->next;
	}
	if(p->next==NULL)
		p->front->next=NULL;
	else{
		if(p->front==NULL){
			p->next->front=NULL;
			L=p->next;
		}
		else{
			p->front->next=p->next;
			p->next->front=p->front;
		}
	}
}

int main(){
	SqList L;
	LinkList *l;
	int f,n,t,i;
	while(1){
		printf("1 初始化顺序表\n");
		printf("2 插入顺序表\n");
		printf("3 删除顺序表\n");
		printf("4 初始化单链表\n");
		printf("5 插入单链表\n");
		printf("6 删除单链表\n");
		printf("7 退出\n");
		scanf("%d",&i);
		switch(i){
				case 1:	InitSqList(L);break;
				case 2: {
					    printf("请输入要插入的数值和位置\n");
						scanf("%d%d",&n,&t);
						f=SqListInsert(n,L,t-1);
						SqListPrint(L);
						printf("\n");
						break;
				}
				case 3: {
					    printf("请输入要删除的位置\n");
						scanf("%d",&t);
						f=SqListDelete(t-1,L);
						SqListPrint(L);
						printf("\n");
						break;
				}
				case 4:	LinkListInit(l);break;
				case 5: {
					    printf("请输入要插入的数值和位置\n");
						scanf("%d%d",&n,&t);
						LinkListInsert(l,n,t);
						LinkListPrint(l);
						printf("\n");
						break;
				}
				case 6: {
					    printf("请输入要删除的位置\n");
						scanf("%d",&t);
						LinkListDelete(l,t);
						LinkListPrint(l);
						printf("\n");
						break;
				}
				case 7:exit(0);
			}

		}
	return 0;
}