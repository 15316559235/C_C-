#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int array[100],i,n;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>array[i];
	for(i=0;i<n-1;i++){
		if(array[i]==array[i+1]){
			for(int j=i+1;j<n-1;j++)
				array[j]=array[j+1];
			n--;
		}
	}
	for(i=0;i<n;i++){
		cout<<array[i];
	}
	cout<<endl<<n;
	return 0;
}