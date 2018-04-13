#include <iostream>
using namespace std;

int main() {
    int a[100][100],n;
    cin>>n;
    int i,j,k,f=n;
    for(k=1;k!=n/2+1;k++) {
        for (i = k - 1, j = k - 1; i < f-1; i++) {
            a[i][j] = k;
        }
        for (j = k - 1; j <= f-1; j++) {
            a[i][j] = k;
        }
        for (i = k - 1, j = k - 1; j < f-1; j++) {
            a[i][j] = k;
        }
        for (i = k - 1; i <= f-1; i++) {
            a[i][j] = k;
        }
        f--;
    }
    if(n%2!=0)
        a[n/2][n/2]=k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            cout << a[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}