#include <iostream>
using namespace std;

void quicksort(int a[], int left, int right){
    if(left < right){
        int key = a[left];
        int low = left;
        int high = right;
        while(low < high){
            while(low < high && a[high] > key){
                high--;
            }
            a[low] = a[high];
            while(low < high && a[low] < key){
                low++;
            }
            a[high] = a[low];
        }
        a[low] = key;
        quicksort(a,left,low-1);
        quicksort(a,low+1,right);
    }
}

int main() {
    int a[100],n,k,t;
    cout<<"请输入数字的个数：";
    cin>>n;
    cout<<"请输入"<<n<<"个数：";
    for(int i=0;i<n;i++)
        cin>>a[i];
    quicksort(a,0,n-1);
    t=a[1]-a[0];
    for(int i=0;i<n-1;i++){
        k=a[i+1]-a[i];
        if(k<t)
            t=k;
    }
    cout<<"两个数之间的最近距离为："<<t;
    return 0;
}