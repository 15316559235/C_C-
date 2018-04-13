#include <iostream>
using namespace std;

bool fn(char s[],int n1,int n2){
    if(n1>=n2)
        return true;
    else{
        if(s[n1]==s[n2]) {
            if(true==fn(s, n1 + 1, n2 - 1))
                return true;
        }
        else
            return false;
    }
}

int main() {
    char s[100];
    int n;
    cin>>s>>n;
    if(true==fn(s,0,n-1))
        cout<<"true";
    else
        cout<<"false";
    return 0;
}