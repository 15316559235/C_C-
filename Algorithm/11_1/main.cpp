#include <iostream>
using namespace std;

int main() {
    int f[100][100],l[100][100],a[100][100],t[100][100],e[3],x[3],n;
    int i,j;
    int end,time;
    FILE *fp;
    fp=fopen("/Users/sc/CloudStation/Sync/C_C++/Algorithm/11_1/n.txt","r");
    if(fp==NULL)
        cout<<"error";
    fscanf(fp,"%d",&n);
    fclose(fp);
    fp=fopen("/Users/sc/CloudStation/Sync/C_C++/Algorithm/11_1/a.txt","r");
    if(fp==NULL)
        cout<<"error";
    for(i=0;i<=3;i++){
        for(j=0;j<=n;j++){
            fscanf(fp,"%d",&a[i][j]);
        }
    }
    fclose(fp);
    fp=fopen("/Users/sc/CloudStation/Sync/C_C++/Algorithm/11_1/t.txt","r");
    if(fp==NULL)
        cout<<"error";
    for(i=0;i<=6;i++){
        for(j=0;j<=n;j++){
            fscanf(fp,"%d",&t[i][j]);
        }
    }
    fclose(fp);
    fp=fopen("/Users/sc/CloudStation/Sync/C_C++/Algorithm/11_1/e.txt","r");
    if(fp==NULL)
        cout<<"error";
    for(i=0;i<=3;i++){
        fscanf(fp,"%d",&e[i]);
    }
    fclose(fp);
    fp=fopen("/Users/sc/CloudStation/Sync/C_C++/Algorithm/11_1/x.txt","r");
    if(fp==NULL)
        cout<<"error";
    for(i=0;i<=3;i++){
        fscanf(fp,"%d",&x[i]);
    }
    fclose(fp);

    f[1][1]=e[1]+a[1][1];
    f[2][1]=e[2]+a[2][1];
    f[3][1]=e[2]+a[3][1];
    
    for(j=2;j<=6;j++) {
        if(f[1][j-1]+a[1][j]<=f[2][j-1]+t[3][j-1]+a[1][j]&&f[1][j-1]+a[1][j]<=f[3][j-1]+t[5][j-1]+a[3][j]) {
            f[1][j]=f[1][j-1]+a[1][j];
            l[1][j]=1;
        }
        else {
            if(f[2][j-1]+t[3][j-1]+a[1][j]<=f[1][j-1]+a[1][j]&&f[2][j-1]+t[3][j-1]+a[1][j]<=f[3][j-1]+t[5][j-1]+a[3][j]) {
                f[1][j]=f[2][j-1]+t[3][j-1]+a[1][j];
                l[1][j]=2;
            }
            else{
                f[1][j]=f[3][j-1]+t[5][j-1]+a[3][j];
                l[1][j]=3;
            }
        }

        if(f[2][j-1]+a[2][j]<=f[1][j-1]+t[1][j-1]+a[2][j]&&f[2][j-1]+a[2][j]<=f[3][j-1]+t[6][j-1]+a[3][j]) {
            f[2][j]=f[2][j-1]+a[2][j];
            l[2][j]=2;
        }
        else {
            if(f[1][j-1]+t[1][j-1]+a[2][j]<=f[2][j-1]+a[2][j]&&f[1][j-1]+t[1][j-1]+a[2][j]<=f[3][j-1]+t[6][j-1]+a[3][j]) {
                f[2][j]=f[1][j-1]+t[1][j-1]+a[2][j];
                l[2][j]=1;
            }
            else{
                f[2][j]=f[3][j-1]+t[6][j-1]+a[3][j];
                l[2][j]=3;
            }
        }

        if(f[3][j-1]+a[3][j]<=f[1][j-1]+t[2][j-1]+a[3][j]&&f[3][j-1]+a[3][j]<=f[2][j-1]+t[4][j-1]+a[3][j]) {
            f[3][j]=f[3][j-1]+a[3][j];
            l[3][j]=3;
        }
        else {
            if(f[1][j-1]+t[2][j-1]+a[3][j]<=f[3][j-1]+a[3][j]&&f[1][j-1]+t[2][j-1]+a[3][j]<=f[2][j-1]+t[4][j-1]+a[3][j]) {
                f[2][j]=f[1][j-1]+t[2][j-1]+a[3][j];
                l[3][j]=1;
            }
            else{
                f[2][j]=f[2][j-1]+t[4][j-1]+a[3][j];
                l[3][j]=3;
            }
        }
    }
    
    if(f[1][6]+x[1]<=f[2][6]+x[2]&&f[1][6]+x[1]<=f[3][6]+x[3]) {
        time=f[1][6]+x[1];
        end=1;
    }
    else {
        if(f[2][6]+x[2]<=f[1][6]+x[1]&&f[2][6]+x[2]<=f[3][6]+x[3]) {
            time=f[2][6]+x[2];
            end=2;
        }
        else{
            time=f[3][6]+x[3];
            end=3;
        }
    }

    i=end;
    cout<<"line "<<i<<",station "<<n<<endl;
    for(j=n;j>=2;j--) {
        i=l[i][j];
        cout<<"line "<<i<<",station "<<j-1<<endl;
    }
    cout<<"最短时间为"<<time<<endl;

    return 0;
}