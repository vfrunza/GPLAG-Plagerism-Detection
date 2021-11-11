#include <stdio.h>
#include<stdlib.h>
#include<math.h>
int main() 
{
	int n,rezultat,brojac=0, broj=1;
	printf("Unesite broj: ");
	scanf("%d",&n);
	int p;
	p=n/10;
	while(p!=0)
	{
		int pom1,a,pom2,b;
		pom1=n%10;
		a=pom1;
		n=n/10;
		pom2=n%10;
		b=pom2;
		rezultat=abs(a-b);
		if(rezultat==0) broj*=10;
		brojac=brojac*10+rezultat;
		p/=10;
	}
	p=brojac;
	brojac=0;
	while(p!=0)
	{
		brojac=brojac*10+p%10;
		p/=10;
		
	}
	if(broj==10) brojac*=10;
	printf("%d", brojac);
	return 0;
}