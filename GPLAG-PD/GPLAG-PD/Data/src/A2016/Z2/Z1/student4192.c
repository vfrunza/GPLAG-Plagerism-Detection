#include <stdio.h>
#include <math.h>

int main() {
	printf("Unesite broj: ");
	int n,a,suma=0,cifra1,cifra2,c,b=1;
	scanf("%d",&n);

	if(n<0) n=fabs(n);
	if(n>=0 && n<10) {n=0; printf("%d",n); return 0;}
	a=n/10;
	while(n!=0 && a!=0)
	{
		cifra1=n%10;
		cifra2=a%10;
	
		c=fabs(cifra1-cifra2);
		suma=suma*10+c;
		if(suma==0) b*=10;
		n/=10;
		a/=10;
	}
	n=suma;
	suma=0;
	while(n!=0)
	{
		suma=suma*10+n%10;
		n/=10;
	}
	if(b>1) suma*=b;
	printf("%d",suma);
	return 0;
}
