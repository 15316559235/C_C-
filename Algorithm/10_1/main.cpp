#include <iostream>
#define maxsize 100
using namespace std;

int main() {
    int data[maxsize][maxsize],temp[maxsize][maxsize],l[maxsize],n;
    int i,j;
    cout<<"输入数塔的高度：";
    cin>>n;
    cout<<"输入数塔：";
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            cin>>data[i][j];
            temp[i][j]=data[i][j];
        }
    }
    for(i=n-2;i>=0;i--){
        for(j=0;j<=i;j++){
            if(temp[i+1][j]>temp[i+1][j+1]){
                temp[i][j]=temp[i][j]+temp[i+1][j];
                l[i]=0;  //左
            }
            else{
                temp[i][j]=temp[i][j]+temp[i+1][j+1];
                l[i]=1;   //右
            }
        }
    }
    cout<<"最大和为："<<temp[0][0]<<endl;
    cout<<"路径为："<<data[0][0]<<"  ";
    for(i=0,j=0;i<n-1;i++){
        if(l[i]==0)
            cout<<data[i+1][j]<<"  ";
        else
            cout<<data[i+1][++j]<<"  ";
    }
    return 0;
}