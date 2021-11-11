#include <stdio.h>
#include <math.h>

int main() {
	int n;
	printf("Unesite broj: ");
	scanf("%d",&n);
	int temp=n,pom=0,pom1=0,razl=0,suma=0,i=0,m=0;
	
	while(temp!=0)
	{
		pom=temp%10;
		temp=temp/10;
		pom1=temp%10;
		razl=pom-pom1;
		if(razl<0)
		{
			razl=razl*-1;
		}
		if(pom1!=0)
		{
		  	m=razl;
		  	suma=suma+m*pow(10,i);
		  	i++;
		}
	}
	printf("%d",suma);
	return 0;
}
