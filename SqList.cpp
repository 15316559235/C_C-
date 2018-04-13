#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef struct{
	int data[100];
	int length;
}SqList;

struct LinkList{
	int data;
	LinkList *front;
	LinkList *next;
};

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

int main(){
	SqList L;
	int f,n,t,i;
	while(1){
		printf("1 初始化顺序表\n");
		printf("2 插入顺序表\n");
		printf("3 删除顺序表\n");
		printf("4 退出\n");
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
				case 4:exit(0);
			}

		}
	return 0;
}