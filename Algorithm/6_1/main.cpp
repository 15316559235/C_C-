#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    char s[100];
    cin>>s;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='('){
            if(((s[i+2]=='+'||s[i+2]=='-')&&(s[i-1]=='+'||s[i-1]=='-'))||(i==0)||((s[i+2]=='*')||(s[i+2]=='/'))){
                int j=i;
                while(1){
                    if(s[j+1]==')'){
                        while(1){
                            s[j]=s[j+2];
                            if(s[j]=='\0')
                                break;
                            j++;
                        }
                        break;
                    }
                    s[j]=s[j+1];
                    if(s[j]=='\0')
                        break;
                    j++;
                }
            }
        }
    }
    printf("%s",s);
    return 0;
}