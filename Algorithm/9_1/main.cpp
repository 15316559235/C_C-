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
            while(low < high && a[low] < key){
                low++;
            }
            int temp=a[low];
            a[low] = a[high];
            a[high] = temp;
        }
        quicksort(a,left,low-1);
        quicksort(a,low+1,right);
    }
}

int main() {
    int a[100],n;
    cout<<"输入数组个数：";
    cin>>n;
    cout<<"输入数组：";
    for(int i=0;i<n;i++)
        cin>>a[i];
    quicksort(a,0,n-1);
    cout<<"第二大的数为："<<a[n-2]<<endl;
    for(int i=0;i<n;i++)
    cout<<a[i]<<"   ";
    return 0;
}