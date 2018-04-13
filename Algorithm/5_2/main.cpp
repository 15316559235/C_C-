#include <iostream>
using namespace std;

int main() {
    int a[100],n,num,flag=0;
    cout<<"请输入数组长度及数组"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"请输入定值"<<endl;
    cin>>num;
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++) {
            if (a[i] + a[j] == num){
                if(i>j)
                    break;
                cout<<"{"<<a[i]<<","<<a[j]<<"}"<<endl;
            }
        }
    }
    return 0;
}