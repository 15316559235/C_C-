#include <iostream>
using namespace std;

int main() {
    int n,k,a[50],i,j,b;
    cin>>n>>k;
    if(n<2||n>50){
        cout<<"error";
        return 0;
    }
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<k;i++){
        b=a[0];
        for(j=0;j<n;j++){
            if(j==n-1)
                a[j]=a[j]+b;
            else
                a[j]=a[j]+a[j+1];
            if(a[j]>=100)
                a[j]=a[j]%100;
        }
    }
    for(i=0;i<n;i++)
        cout<<a[i]<<"  ";
    return 0;
}