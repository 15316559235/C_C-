#include <stdio.h>
#include <stdlib.h>
#define maxsize 5

struct LinkList{
    int key;
    int data;
    LinkList *front;
    LinkList *next;
};

void LinkListInit(LinkList *&L){
    L=(LinkList *)malloc(sizeof(LinkList));
    L->next=NULL;
    L->front=NULL;
}

void LinkListInsert(LinkList *&L,int n,int k,int t){
    int i;
    LinkList *q,*p;
    p=L;
    q=(LinkList *)malloc(sizeof(LinkList));
    if(t==1&&p->next==NULL){
        p->data=n;
        p->key=k;
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
            q->key=k;
            q->front=p;
            q->next=NULL;
            p->next=q;
        }
        else{
            if(p->front==NULL){
                q->data=n;
                q->key=k;
                q->next=p;
                q->front=NULL;
                p->front=q;
                L=q;
            }
            else{
                q->data=n;
                q->key=n;
                q->next=p;
                q->front=p->front;
                p->front->next=q;
                p->front=q;
            }
        }
    }
}

void Isort(LinkList *&num,int n){
    int i,key,data;
    LinkList *p;
    p=num->next;
    for(i=0;i<n-1;i++,p=num->next){
        key=p->key;
        data=p->data;
        while(key<p->front->key){
            p->key=p->front->key;
            p->data=p->front->data;
            p=p->front;
            if(p->front==NULL)
                break;
        }
        p->data=data;
        p->key=key;
        num=num->next;
    }
}

int main(){
    LinkList *num,*head;
    int data,key;
    int i;
    LinkListInit(num);
    head=num;
    printf("请输入键值和数据：\n");
    for(i=0;i<maxsize;i++){
        scanf("%d%d",&key,&data);
        LinkListInsert(num,data,key,i+1);
    }
    Isort(num,maxsize);
    for(i=0;i<maxsize;i++,head=head->next)
        printf("%d->%d\n",head->key,head->data);
    return 0;
}