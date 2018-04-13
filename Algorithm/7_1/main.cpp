#include <iostream>
using namespace std;

int main() {
    int s=0,m,n,t;
    m=3;
    t=0;
    cout<<"1:取"<<m<<"张"<<endl;
    s=s+m;
    while(s!=54){
        cout<<"现在剩余"<<54-s<<"张"<<endl;
        cin>>n;
        t=1;
        cout << "2:取" << n << "张" << endl;
        s=s+n;
        if(s==54)
            break;
        else {
            cout<<"现在剩余"<<54-s<<"张"<<endl;
            t=0;
            if (n == 1)
                m = 4;
            if (n == 2)
                m = 3;
            if (n == 3)
                m = 2;
            if (n == 4)
                m = 1;
            s=s+m;
            cout << "1:取" << m << "张" << endl;
            if(s==54)
                break;
        }
    }
    if(t==1)
        cout<<"1号获胜"<<endl;
    else
        cout<<"2号获胜"<<endl;
    return 0;
}