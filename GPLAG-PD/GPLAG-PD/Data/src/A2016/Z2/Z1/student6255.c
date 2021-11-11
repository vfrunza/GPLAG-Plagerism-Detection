#include <stdio.h>
#include <math.h>

int main() {
	int n,x,y,broj,rezultat=0,k=1;
	printf("Unesite broj: ");
	scanf("%d",&n);
	while(n>=10 || n<=-10){
	x=n%10;
	y=n%100;
	y=y/10;
	broj=fabs(x-y);
	rezultat=rezultat+broj*k; k=k*10;
	n=n/10;
	}
	printf("%d",rezultat);
	return 0;
}
