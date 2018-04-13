#include <iostream>
using namespace std;

struct Stack{
    char data;
    Stack *next;
};

void InitStack(Stack *&S){
    S=(Stack *)malloc(sizeof(Stack));
    S->next=NULL;
}

void Pop(Stack *&S, char &e){
    e=S->data;
    S=S->next;
}

void Push(Stack *&S, char &e){
    Stack *p;
    p=(Stack *)malloc(sizeof(Stack));
    p->data=e;
    p->next=S;
    S=p;
}

int main() {
    string str;
    Stack *s;
    char e;
    int flag=0;
    InitStack(s);
    cin>>str;
    for(int i=0;str[i]!='\0';i++){
        Push(s,str[i]);
    }
    while(s!=NULL){
        Pop(s,e);
        if(e=='('&&flag<=0){
            cout<<"匹配错误"<<endl;
            exit(0);
        }
        if(e==')')
            flag++;
        if(e=='(')
            flag--;
    }
    if(flag==0)
        cout<<"匹配正确";
    else
        cout<<"匹配错误";
    return 0;
}