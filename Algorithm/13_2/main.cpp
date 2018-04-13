#include <iostream>
using namespace std;

int maze[8][8]={
        {0,0,0,0,0,0,0,0},
        {0,1,1,1,1,0,1,0},
        {0,0,0,0,1,0,1,0},
        {0,1,0,0,0,0,1,0},
        {0,1,0,1,1,0,1,0},
        {0,1,0,0,0,0,1,1},
        {0,1,0,0,1,0,0,0},
        {0,1,1,1,1,1,1,0}};
int fx[4]={1,-1,0,0};
int fy[4]={0,0,-1,1};

struct {
    int x;
    int y;
    int pre;
}sq[100];

int qh,qe,i,j,k;

int check(int i,int j){
    int flag=1;
    if(i<=-1 || i>=8 || j<=-1 || j>=8)
        flag=0;
    if(maze[i][j]==1 || maze[i][j]==-1)
        flag=0;
    return flag;
}

void out(){
    cout<<'('<<sq[qe].x<<','<<sq[qe].y<<')';
    while (sq[qe].pre!=0){
        qe=sq[qe].pre;
        cout<<"- -"<<'('<<sq[qe].x<<','<<sq[qe].y<<')';
    }
    cout<<"- - "<<'('<<0<<','<<0<<')';
}

void search(){
    qh=-1;
    qe=0;
    maze[0][0]=-1;
    sq[0].pre=-1;
    sq[0].x=0;
    sq[0].y=0;
    while (qh!=qe){
        qh++;
        for(k=0;k<4;k++){
            i=sq[qh].x+fx[k];
            j=sq[qh].y+fy[k];
            if(check(i,j)==1){
                qe++;
                sq[qe].x=i;
                sq[qe].y=j;
                sq[qe].pre=qh;
                maze[i][j]=-1;
                if(sq[qe].x==7 && sq[qe].y==7){
                    out();
                    return;
                }
            }
        }
    }
    cout<<"没有出路";
}

int main(){
    search();
    return 0;
}