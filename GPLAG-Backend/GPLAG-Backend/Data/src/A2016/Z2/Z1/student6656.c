#include <stdio.h>
#include <math.h>

int main() {
	int n,p=0,dr=0,x=0,a=0;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n<10 && n>=0)
	{
	printf("0");
	return 0;
	}
	a=1;
	n=fabs(n);
	while(n>=10)
	{
	 p=n%10;
	 dr=(n/10)%10;
	 x=x+fabs(p-dr)*a;
	 a=a*10;
	 n=n/10;
	}
	printf("%d",x);
	return 0;
}
