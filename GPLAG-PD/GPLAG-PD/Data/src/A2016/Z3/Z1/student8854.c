#include <stdio.h>


int daj_prost()
{
	static int n;
	static int a=0;/*Broj pozivanja funkcije*/
	a++;
	
	
	if(a==1)
	/*Prvo pozivanje funkcije*/
	{n=3;return 2;
		}
		else
	{
			
	int i;
	do
	{
		/*Odredjivanje da li je broj prost*/
		for(i=2;i<=n-1;i++)
		{
			if(n%i==0)
			{n++;i=1;
			continue;
			}
			
		}
		if(i==n)
		{n++;
		return n-1;
		}
	}
	while(i!=n-1);
	
}}





int main() {
	

int A,B;
/* Unos brojeva A i B*/
do 
{
	printf("Unesite brojeve A i B: ");
	scanf("%d %d",&A,&B);
	if (A<=0)
	{
		printf("A nije prirodan broj.\n");
	}
	else
	{
		if(A>=B)
		printf("A nije manje od B.\n");
		else
		{if(B<=0)
			printf("B nije prirodan broj.\n");}
	}
	
}
while(A>=B || A<=0 || B<=0);
	int k;
	int suma=0;

/*Odredjivanje sume prostih brojeva*/
do
{k=daj_prost();
if(k<=A)
continue;
else
{if(k<B)
suma=suma+k;
	else
	break;}
}
while(1>0);
printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);


	
	return 0;
}
