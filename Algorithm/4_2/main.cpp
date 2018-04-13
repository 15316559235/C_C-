#include<iostream>
using namespace std;

int fn(int n, int m)
{
    int sum = 0;
    if (m < 0 || m > 10 * n){
        return 0;
    }
    if(n==1)
        return 1;
    n--;
    for(int i = 0; i <= 10;i++)
    {
        if (m-i >=0)
            sum += fn(n,m-i);
    }
    return sum;
}

int main() {
    int n,m;
    cin>>n>>m;
    int sum=fn(n,m);
    cout<<"共有"<<sum<<"种可能"<<endl;
    return 0;
}
