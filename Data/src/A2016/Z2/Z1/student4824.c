#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	int broj,j,l,k=0,m=0,z=0;
	printf("Unesite broj: ");
	scanf("%d",&broj);
	if ((broj>0) && (broj<10))
	{
		z=0;
		printf("%d",z);
		return 0;
	
	}
	if (broj<0)
	{ broj=abs(broj);
	}
	for(;broj>=10;k++)
	{
		j=broj%10;
		broj=broj/10;
		l=broj%10;
		m=abs((j-l))*pow(10,k);
		z=z+m;
		
	}
	printf("%d",z);
	return 0;
	
}

