#include<iostream>

using namespace std;

int main()
{
	int n,m=1,i,j;
	int a[100][100];
	cin>>n;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			a[i][j] = 0;
	    }
	}
	for(i=0;i<n/2;i++){
		for(j=i;j<n;j++){	                
			if(a[j][i]==0){
				a[j][i] = m;
				m++;
			}
		}
		for(j=i+1;j<n;j++){
			if(a[n-i-1][j]==0){
				a[n-i-1][j]= m++;
			}
		}
	    for(j=n-i-2;j>i;j--){
		    if(a[j][n-i-1]==0){
			    a[j][n-i-1]=m++;
		    }
	    }
	    for(j=n-i-1;j>i;j--){
		    if(a[i][j]==0){
			    a[i][j]=m++;
		    }
		}
	}
	if(n%2==1)
		a[n/2][n/2] = m;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<a[i][j]<<' '<<'\t';
		}
		cout<<endl;
	}
	return 0;
} 
