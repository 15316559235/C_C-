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
    int a[100],n,num,flag=0;
    cout<<"请输入数组长度及数组"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"请输入定值"<<endl;
    cin>>num;
    quicksort(a,0,n-1);
    int left=0,right=n-1;
    for(int i;i<n;i++){
        if(a[left]+a[right]<num)
            left++;
        else{
            if(a[left]+a[right]>num)
                right--;
            else {
                cout << "{" << a[left] << "," << a[right] << "}" << endl;
                left++;
            }
        }
    }
    return 0;
}