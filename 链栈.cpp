#include <stdio.h>
#include <stdlib.h>

struct Stack{
	int data;
	Stack *next;
};

void InitStack(Stack *&S){
	S=(Stack *)malloc(sizeof(Stack));
	S->next=NULL;
}

void Pop(Stack *&S,int &e){
	e=S->data;
	S=S->next;
}

void Push(Stack *&S){
	Stack *p;
	int e;
	printf("请输入要压入的元素\n");
	scanf("%d",&e);
	p=(Stack *)malloc(sizeof(Stack));
	p->data=e;
	p->next=S;
	S=p;
}

int main(){
	int i,e;
	Stack *S;
	while(1){
		printf("1.初始化链栈\n");
		printf("2.压入一个元素\n");
		printf("3.弹出一个元素\n");
		printf("4.退出\n");
		scanf("%d",&i);
		switch(i){
			case 1:InitStack(S);break;
			case 2:Push(S);break;
			case 3:{
				Pop(S,e);
				printf("弹出元素为：%d\n",e);
				break;
			}
			case 4:exit(0);
		}
	}
	return 0;
}