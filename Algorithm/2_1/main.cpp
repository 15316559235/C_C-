#include <iostream>
using namespace std;

int main() {
    int fishSize[50],n,minSize,maxSize,i,count=0;
    cin>>minSize>>maxSize;
    if(minSize<1||maxSize>1000) {
        cout << "error";
        return 0;
    }
    cin>>n;
    if(n<1||n>50){
        cout << "error";
        return 0;
    }
    for(i=0;i<n;i++){
        cin>>fishSize[i];
    }
    for(int l=minSize;l<=maxSize;l++){
        for(i=0;i<n;i++){
            if(l>=fishSize[i]*2&&l<=fishSize[i]*10)
                break;
            if(fishSize[i]>=l*2&&fishSize[i]<=l*10)
                break;
        }
        if(i==n)
           count++;
        i=0;
    }
    cout<<"可放入"<<count<<"种大小的鱼"<<endl;
    return 0;
}