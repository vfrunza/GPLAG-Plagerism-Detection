#include <stdio.h>
#include <math.h>
int main() {
	int n,a,b,k,rez;
	
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n<0)n*=-1;
	rez=0;
	k=1;
	a=n%10;
	n=n/10;
	while(n!=0)
	{
	b=n%10;
	rez=rez+fabs(a-b)*k;
	a=b;
	k=k*10;
	n=n/10;	
	}
	printf("%d",rez);
	return 0;
}
