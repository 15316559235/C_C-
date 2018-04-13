#include <iostream>
using namespace std;

void move(int n,char from,char to){
    cout<<"将"<<n<<"号盘从"<<from<<"移动到"<<to<<endl;
}

void hanoi(int n,char from,char depend,char to){
    if(n==1)
        move(1,from,to);
    else{
        hanoi(n-1,from,to,depend);
        move(n,from,to);
        hanoi(n-1,depend,from,to);
    }
};

int main() {
    int n;
    char x='A',y='B',z='C';
    cin>>n;
    hanoi(n,x,y,z);
    return 0;
}