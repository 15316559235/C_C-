#include <iostream>
using namespace std;

int job[6][2]={{3,8}, {12,10}, {5,9}, {2,6}, {9,3}, {11,1}};
int x[6],bestx[6],f1=0,bestf,f2[7]={0};

void fn(int i){
    int j,temp;
    if(i==6) {
        for(j=0;j<6;j++)
            bestx[j]=x[j];
        bestf=f2[i];
    }
    else {
        for(j=i;j<6;j++) {
            f1=f1+job[x[j]][0];
            if(f2[i]>f1)
                f2[i+1]=f2[i]+job[x[j]][1];
            else
                f2[i+1]=f1+job[x[j]][1];
            if(f2[i+1]<bestf) {
                temp=x[i];
                x[i]=x[j];
                x[j]=temp;

                fn(i+1);

                temp=x[i];
                x[i]=x[j];
                x[j]=temp;
            }
            f1=f1-job[x[j]][0];
        }
    }
}


int main()
{
    int i,j;
    bestf=10000;
    for(i=0;i<6;i++)
        x[i]=i;
    fn(0);
    for(i=0;i<6;i++)
        cout<<bestx[i]+1<<"  ";
    cout<<endl<<"最短时间为"<<bestf<<endl;
    return 0;
}
