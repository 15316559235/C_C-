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

void select(LinkList *&num,int n){
    int i,j,k,data,key;
    LinkList *p,*q;
    p=num;
    for(i=0;i<n;i++){
        q=p->next;
        k=i;
        for(j=i+1;j<n;j++){
            if(q->key<p->key) {
                k=j;
            }
            q=q->next;
        }
        if(i!=k){
            q=p;
            for(int t=i;t<k;t++)
                q=q->next;
            data=q->data;
            key=q->key;
            q->data=p->data;
            q->key=p->key;
            p->data=data;
            p->key=key;
        }
        p=p->next;
    }
}

int main(){
    LinkList *num,*head;
    int i;
    int key,data;
    printf("请输入键值和数据：\n");
    LinkListInit(num);
    head=num;
    for(i=0;i<maxsize;i++){
        scanf("%d%d",&key,&data);
        LinkListInsert(num,data,key,i+1);
    }
    select(num,maxsize);
    for(i=0;i<maxsize;i++) {
        printf("%d->%d\n", head->key, head->data);
        head=head->next;
    }
    return 0;
}