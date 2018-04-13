#include <stdio.h>
#include <stdlib.h>

struct Queue{
	int data;
	Queue *front;
	Queue *next;
};
int f=0;

void InitQueue(Queue *&Q){
	Q=(Queue *)malloc(sizeof(Queue));
	Q->front=NULL;
	Q->next=NULL;
}

void EnQueue(Queue *&Q){
	int e;
	Queue *p;
	printf("请输入要插入元素：\n");
	scanf("%d",&e);
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

void DeQueue(Queue *&Q,int &e){
	Queue *p;
	p=Q;
	while(p->next!=NULL){
		p=p->next;
	}
	e=p->data;
	if(p->front==NULL){
		p->next=NULL;
	}
	else{
		p->front->next=NULL;
	}
}

int main(){
	int i,e;
	Queue *Q;	
	while(1){
		printf("1.初始化链队\n");
		printf("2.插入一个元素\n");
		printf("3.删除一个元素\n");
		printf("4.退出\n");
		scanf("%d",&i);
		switch(i){
			case 1:InitQueue(Q);break;
			case 2:EnQueue(Q);break;
			case 3:{
				DeQueue(Q,e);
				printf("删除元素为：%d\n",e);
				break;
			}
			case 4:exit(0);
		}
	}
	return 0;
}