#include <stdio.h>
#include <stdlib.h>
#define maxsize 10

struct BTree{
    int data;
    struct BTree *lchild,*rchild;
};

BTree *q;

BTree *BSTInsert(BTree *&p, int e)
{
    BTree *q;
    if(p == NULL)
    {
        p = (BTree *)malloc(sizeof(BTree));
        p->data = e;
        p->lchild=NULL;
        p->rchild=NULL;
        return p;
    }
    if(p->data==e)
        return NULL;
    if(e<p->data){
        q=BSTInsert(p->lchild,e);
        return q;
    }
    else{
        q=BSTInsert(p->rchild,e);
        return q;
    }
}

BTree *Search(BTree *&p,int e){
    if(p==NULL||p->data==e)
        return p;
    else {
        if (p->data < e)
            return Search(p->rchild, e);
        else
            return Search(p->lchild, e);
    }
}

BTree *Desearch(BTree *&p,int e){
    if(p==NULL||p->rchild->data==e||p->lchild->data==e)
        return p;
    else {
        if (p->data < e)
            return Desearch(p->rchild, e);
        else
            return Desearch(p->lchild,e);
    }
}

void createBST(BTree *&T, int a[], int n){
    T = NULL;
    int i;
    BTree *bt;
    for(i = 0; i < n; i++)
    {
        bt=BSTInsert(T, a[i]);
        if(i==0)
            q=bt;
    }
}

void Delete(BTree *&T,int e){
    BTree *p,*q,*s,*m;
    p=Search(T,e);
    m=Desearch(T,e);
    if(p->lchild==NULL&&p->rchild==NULL) {
        free(p);
        if(m->lchild->data==e)
            m->lchild=NULL;
        else
            m->rchild=NULL;
        return;
    }
    if(p->lchild!=NULL&&p->rchild==NULL){
        q=p;
        p=p->lchild;
        free(q);
    }
    if(p->rchild!=NULL&&p->lchild==NULL){
        q=p;
        p=p->rchild;
        free(q);
    }
    else{
        q=p;
        s=p->lchild;
        while(s->rchild!=NULL){
            q=s;
            s=s->rchild;
        }
        p->data=s->data;
        if(q!=p)
            q->rchild=s->lchild;
        else
            q->lchild=s->lchild;
    }
    free(s);
}

int main()
{
    int a[maxsize],n=maxsize,e,i;
    BTree *T,*p;
    printf("请输入要创建的数据：");
    for(i=0;i<maxsize-1;i++)
        scanf("%d",&a[i]);
    createBST(T, a, n-1);
    printf("请输入要插入的值：");
    scanf("%d",&e);
    BSTInsert(T,e);
    printf("请输入要查找的值：");
    scanf("%d",&e);
    p=Search(q,e);
    if(p==NULL)
        printf("不存在%d\n",e);
    else
        printf("已找到%d\n",e);
    printf("请输入要删除的数据：\n");
    scanf("%d",&e);
    Delete(q,e);
    printf("请输入要查找的值：\n");
    scanf("%d",&e);
    p=Search(q,e);
    if(p==NULL)
        printf("不存在%d\n",e);
    else
        printf("已找到%d\n",e);
    printf("请输入要查找的值：\n");
    scanf("%d",&e);
    p=Search(q,e);
    if(p==NULL)
        printf("不存在%d\n",e);
    else
        printf("已找到%d\n",e);
    return 0;
}