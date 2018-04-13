#include <stdio.h>
#include <stdlib.h>

struct LinkList{
	int data;
	LinkList *front;
	LinkList *next;
};

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
	int n,t,i;
	LinkList *L;
	while(1){
		printf("1 初始化单链表\n");
		printf("2 插入单链表\n");
		printf("3 删除单链表\n");
		printf("4 退出\n");
		scanf("%d",&i);
		switch(i){
				case 1:	LinkListInit(L);break;
				case 2: {
					    printf("请输入要插入的数值和位置\n");
						scanf("%d%d",&n,&t);
						LinkListInsert(L,n,t);
						LinkListPrint(L);
						printf("\n");
						break;
				}
				case 3: {
					    printf("请输入要删除的位置\n");
						scanf("%d",&t);
						LinkListDelete(L,t);
						LinkListPrint(L);
						printf("\n");
						break;
				}
				case 4:exit(0);
			}

		}
	return 0;
}