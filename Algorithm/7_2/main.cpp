#include <iostream>
using namespace std;

bool d1[100],d2[100],l[100];
int a[100];
int total;

int print()
{
    int b[8][8]={0};
    int i,j;
    total++;
    cout<<"sum="<<total<<endl;
    for(i=0;i<8;i++){
        b[i][a[i+1]-1]=1;
    }
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            cout<<b[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int search(int x)
{
    for(int i=1;i<=8;i++)
        if((!l[i])&&(!d1[i+x])&&(!d2[x-i+7]))
        {
            a[x]=i;
            l[i]=1;
            d1[i+x]=1;
            d2[x-i+7]=1;
            if(x==8)
                print();
            else
                search(x+1);
            l[i]=0;
            d1[x+i]=0;
            d2[x-i+7]=0;
        }
}

int main()
{
    search(1);
    return 0;
}