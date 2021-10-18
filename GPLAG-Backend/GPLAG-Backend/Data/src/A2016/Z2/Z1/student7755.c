#include <stdio.h>
#include <stdlib.h>

int main() {
	int n,x,y,c=0,promjena=0,broj=0,r=0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n<=9 && n>0)
	{
		printf("0");
	}
	else {
	while(n!=0)
	{
	x=n%10;
	n=n/10;
	if(n==0)  {
		break;
	}
	y=n%10;
	c=abs(x-y);
	broj+=c;
	broj*=10;
	if(broj==0) r=1;
}
	broj/=10;
	while(broj!=0)
	{
		promjena=promjena*10;
		promjena=promjena+broj%10;
		broj=broj/10;
	}
	if(r==1) 
		promjena*=10;
	

	printf("%d", promjena);
}
	return 0;
}
