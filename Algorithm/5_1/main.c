#include <stdio.h>
#include <stdlib.h>

struct Linklist{
    int n;
    struct Linklist *front,*next;
};

int main() {
    int n,m;
    struct Linklist *head,*p,*q;
    scanf("%d%d",&n,&m);
    head=(struct Linklist *)malloc(sizeof(struct Linklist));
    head->n=0;
    for(int i;i<n;i++){
        p=(struct Linklist *)malloc(sizeof(struct Linklist));
        p->n=i+1;
        p->next=NULL;
        if(p->n==1) {
            p->front = head;
            head->next=p;
        }
        else{
            q=head->next;
            for(int j=0;j<i;j++){
                if(q->n==p->n-1){
                    p->front=q;
                    q->next=p;
                }
                else
                    q=q->next;
            }
        }
        if(i==n-1) {
            p->next = head->next;
            head->front = p;
        }
    }
    p=head->next;
    p->front=head->front;
    head=p;
    int k;
    scanf("%d",&k);
    for(int i=1;i<k;i++)
        p=p->next;
    int num=1;
    while (p->next!=p){
        if(num==m) {
            q=p->next;
            p->front->next = p->next;
            p->next->front = p->front;
            printf("第%d个排出\n",p->n);
            free(p);
            p=q;
            num=1;
        }
        else{
            num++;
            p=p->next;
        }
    }
    printf("剩下第%d个",p->n);
    return 0;
}