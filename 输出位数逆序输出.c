#include <stdio.h>

int main(int argc, char *argv[]) {
	int n,t,i=1,j,k=1,s=0;
	scanf("%d",&n);
	t=n;
	while(t/10!=0){
		i++;
		t=t/10;
	}
	printf("输入的数是%d位数\n",i);
	t=n;
	for(j=0;j<i-1;j++)
	k=k*10;
	for(j=0;j<i;j++){
		s=s+(t%10)*k;
		k=k/10;
		t=t/10;
	}
	printf("逆序输出：%d",s);
	return 0;
}