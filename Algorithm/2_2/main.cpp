#include <iostream>
using namespace std;

int main() {
    int num,a[10],i,count=0;
    cin>>num;
    while(num>=10){
        i=0;
        while(num>0){
            a[i]=num%10;
            num=num/10;
            i++;
        }
        num=1;
        for(int j=0;j<i;j++)
            num=num*a[j];
        count++;
    }
    cout<<count<<endl;
    return 0;
}