#include <iostream>

using namespace std;

int amount=0,Board[100][100];

void Cover(int tr,int tc,int dr,int dc,int size)
{
    int s;
    if(size<2)
        return ;
    amount++;
    s=size/2;
    if(dr<tr+s&&dc<tc+s)
    {
        Board[tr+s-1][tc+s]=amount;
        Board[tr+s][tc+s-1]=amount;
        Board[tr+s][tc+s]=amount;

        Cover(tr,tc,dr,dc,s);
        Cover(tr,tc+s,tr+s-1,tc+s,s);
        Cover(tr+s,tc,tr+s,tc+s-1,s);
        Cover(tr+s,tc+s,tr+s,tc+s,s);
    }
    else if(dr<tr+s&&dc>=tc+s)
    {
        Board[tr+s-1][tc+s-1]=amount;
        Board[tr+s][tc+s-1]=amount;
        Board[tr+s][tc+s]=amount;

        Cover(tr,tc,tr+s-1,tc+s-1,s);
        Cover(tr,tc+s,dr,dc,s);
        Cover(tr+s,tc,tr+s,tc+s-1,s);
        Cover(tr+s,tc+s,tr+s,tc+s,s);
    }
    else if(dr>=tr+s&&dc<tc+s)
    {
        Board[tr+s-1][tc+s-1]=amount;
        Board[tr+s-1][tc+s]=amount;
        Board[tr+s][tc+s]=amount;

        Cover(tr,tc,tr+s-1,tc+s-1,s);
        Cover(tr,tc+s,tr+s-1,tc+s,s);
        Cover(tr+s,tc,dr,dc,s);
        Cover(tr+s,tc+s,tr+s,tc+s,s);
    }
    else
    {
        Board[tr+s-1][tc+s-1]=amount;
        Board[tr+s-1][tc+s]=amount;
        Board[tr+s][tc+s-1]=amount;

        Cover(tr,tc,tr+s-1,tc+s-1,s);
        Cover(tr,tc+s,tr+s-1,tc+s,s);
        Cover(tr+s,tc,tr+s,tc+s-1,s);
        Cover(tr+s,tc+s,dr,dc,s);
    }
}

void Print(int s)
{
    for(int i=1;i<=s;i++)
    {
        for(int j=1;j<=s;j++)
            printf("%5d",Board[i][j]);
        cout<<endl;
    }
}

int main()
{
    int s=1,k,x,y;
    cout<<"输入2残缺棋盘的规模:2^k,k=";
    cin>>k;
    for(int i=1;i<=k;i++)
        s=s*2;
    cout<<"输入棋盘残缺位置(x,y):";
    cin>>x>>y;
    Board[x][y]=0;
    Cover(1,1,x,y,s);
    Print(s);
    return 0;
}
