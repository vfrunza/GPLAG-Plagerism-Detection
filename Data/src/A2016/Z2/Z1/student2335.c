#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n,a,c,x=0,i=0,y;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if (n<0)
	n=abs(n);
	else if(n>-10 && n<10){
		printf("0");
		return 0;
	}
	do{
	a=n%10;
	n/=10;
	c=abs(a-(n%10));
	y=pow(10,i);
	x+=c*y;
	i++;
	}while (n>9);
	printf("%d",x);
	return 0;
}
