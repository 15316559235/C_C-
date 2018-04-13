#include <stdio.h>
#include <stdlib.h>

struct Stack{
	int s;
	Stack *next;
};

void InitStack(Stack *&S){
	S=(Stack *)malloc(sizeof(Stack));
	S->next=NULL;
}

void Pop(Stack *&S,int &s){
	s=S->s;
	S=S->next;
}

void Push(Stack *&S,int &s){
	Stack *p;
	p=(Stack *)malloc(sizeof(Stack));
	p->s=s;
	p->next=S;
	S=p;
}

int main(){
	int s,c[100];
	Stack *S;
	int i=0;
	InitStack(S);
	printf("请输入一串字符,并以‘0’结束:\n");
	scanf("%d",&s);
	while(s!= 0){
		fflush(stdin);
		Push(S,s);
		c[i]=s;
		i++;
		scanf("%d",&s);
	};
	i=0;
	Pop(S,s);
	while(S!=NULL){
		if(s==c[i]){
			i++;
			Pop(S,s);
		}
		else{
			printf("输入的字符串不是回文");
			return 0;
		}	
	}
	printf("输入的字符串是回文");
	return 0;
}