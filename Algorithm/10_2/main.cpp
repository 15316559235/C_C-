#include <iostream>
using namespace std;

void MatrixChain(int *p,int n,int m[][100],int s[][100]) {
    for (int i = 0; i < n; i++)
        m[i][i] = 0;

    for (int r = 1; r < n; r++) {
        for (int i = 0; i < n - r; i++) {
            int j = i + r;
            m[i][j] = m[i][i] + m[i + 1][j] + p[i] * p[i + 1] * p[j + 1];
            s[i][j] = i;
            for (int k = i + 1; k < j; k++) {
                int t = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (t < m[i][j]) {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    }
}

void Traceback(int i,int j,int s[][100])
{
    if(i==j)return;
    Traceback(i,s[i][j],s);
    Traceback(s[i][j]+1,j,s);
    cout<<"A"<<i+1<<"和A"<<(s[i][j]+2)<<"相乘"<<endl;
}

int main() {
    int r[100],m[100][100],s[100][100],n,i,j;
    char a[100],temp;
    FILE *fp;
    fp=fopen("/Users/sc/CloudStation/Sync/C_C++/Algorithm/10_2/矩阵.txt","r");
    if(fp==NULL)
        cout<<"error";
    fscanf(fp,"%d",&n);
    fscanf(fp,"%c",&temp);
    for(i=0,j=0;i<n;i++){
        fscanf(fp,"%c",&a[i]);
        fscanf(fp,"%c",&temp);
        fscanf(fp,"%d",&r[j++]);
        fscanf(fp,"%c",&temp);
        fscanf(fp,"%d",&r[j++]);
        fscanf(fp,"%c",&temp);
    }

    MatrixChain(r,n,m,s);
    Traceback(0,n-1,s);

    fclose(fp);
    return 0;
}