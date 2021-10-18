#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int a,b,c,d,e;
	int suma=0;
	int brojac=0;
	printf("Unesite broj: ");
	scanf("%d",&a);
	if(a>0 && a<10)
	printf("0");
	else
	{
	e=abs(a);
	b=e%10;
	a=e/10;
	do
	{c=a%10;
	d=abs(b-c);

	suma=suma+d*pow(10,brojac);
	brojac++;
	b=c;
	a=a/10;
		
	}
	while(a>0);
	printf("%d",suma);
	
	}
	return 0;
}
