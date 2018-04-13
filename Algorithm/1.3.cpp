#include <iostream>
#include <cmath>
#define PI 3.141592653

using namespace std;
int main(int argc, char *argv[]) {
	double p[100][2];
	int i;
	int num;
	double m,n;
	double x=0,t=0,a,b;
	cout<<"输入已知点个数"<<endl;
	cin>>num;
	for(i=0;i<num;i++){
		cin>>m>>n;
		p[i][0]=m;
		p[i][1]=n;
	}
	p[num+1][0]=p[0][0];
	p[num+1][1]=p[0][1];
	cout<<"请输入已知点"<<endl;
	cin>>m>>n;
	for(i=0;i<num;i++){
		a=(p[i][1]-n)/(p[i][0]-m);
		b=(p[i+1][1]-n)/(p[i+1][0]-m);
		if(a<0){
			a=PI-atan(a);
		}
		if(b<0){
			b=PI-atan(b);
		}
		x=PI-fabs(b-a);
		t=t+x;
	}
	if(t<=2*PI+0.5&&t>=2*PI-0.5){
		cout<<"点在多边形内";
	}
	else{
		cout<<"点不在多边形内";
	}
	return 0;
}