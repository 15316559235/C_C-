#include <iostream>
using namespace std;
int num=0;

void merge(int a[], int left, int mid, int right) {
    int i = left,j = mid + 1,k = 0;
    int b[100];
    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            i++;
            k++;
        } else {
            b[k] = a[j];
            j++;
            k++;
            num=num+mid-i+1;
        }
    }
    while (i <= mid) {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= right) {
        b[k] = a[j];
        j++;
        k++;
    }

    for (k = 0, i = left; i <= right; i++, k++) {
        a[i] = b[k];
    }
}

void sort(int a[],int left,int right){
    int mid;
    if(right<=left)
        return;
    else{
        mid=(left+right)/2;
        sort(a,left,mid);
        sort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}

int main() {
    int a[100],n;
    cout << "输入数组个数：";
    cin>>n;
    cout<<"输入数组：";
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,0,n-1);
    cout<<num;
    return 0;
}


