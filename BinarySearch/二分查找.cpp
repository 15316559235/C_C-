#include <stdio.h>
#define maxsize 10

void binarysearch(int n,int num[]){
    int mid,lower=0,high=maxsize;
    while(lower<=high){
        mid=(lower+high)/2;
        if(n==num[mid]) {
            printf("%d位置为%d", n, mid+1);
            return;
        }
        else{
            if(num[mid]>n)
                high=mid-1;
            else
                lower=mid+1;
        }
    }
    printf("不存在%d",n);
}

int main() {
    int num[maxsize],i,n;
    for(i=0;i<maxsize;i++)
        scanf("%d",&num[i]);
    printf("请输入要查找的数：");
    scanf("%d",&n);
    binarysearch(n,num);
    return 0;
}