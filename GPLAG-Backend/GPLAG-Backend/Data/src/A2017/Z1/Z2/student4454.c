#include <stdio.h>
#include <math.h>
int main()
{
	int iznos,ostatak,k,a,b,c,d,e,i,osta1,osta2,osta3,osta4;
	printf("Unesite iznos: ");
	scanf("%d",&iznos);
	for(i=iznos;i>=50;i-=50)
	{
		ostatak=i;
		k++;
	}
	
	for(i=ostatak;i>=20;i-=20)
	{
		osta1=i;
		a++;
	}
	
	for(i=osta1;i>=10;i-=10)
	{
		osta2=i;
		b++;
	}
	
	for(i=osta2;i>=5;i-=5)
	{
		osta3=i;
		c++;
	}
	
		for(i=osta3;i>=2;i-=2)
	{
		osta4=i;
		d++;
	}
	
	for(i=osta4;i>=1;i-=1)
	{
		osta4=i;
		e++;
	}
	
	
	printf("\n%d novcanica od 50 KM",k);
	printf("\n%d novcanica od 20 KM",a);
	printf("\n%d novcanica od 10 KM",b);
	printf("\n%d novcanica od 5 KM",c);
	printf("\n%d novcanica od 2 KM",d);
	printf("\n%d novcanica od 1 KM",e);
	
	
	
	return 0;
}
