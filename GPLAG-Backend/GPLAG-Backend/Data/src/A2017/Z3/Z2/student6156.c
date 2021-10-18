#include <stdio.h>
#include <math.h>


int ispitaj(float broj, int k);
void preslozi(float niz[],int velicina, int k);
void zaokruzi1(float niz[], int velicina);

int main()
{

	float niz[]= {13.1,15.749999,15.75,9.222,78.1};
	int k=14;
	int i;

	zaokruzi1(niz,5);
	preslozi(niz,5,k);

	for(i=0; i<5; i++)
		printf("%g,%d  ",niz[i],ispitaj(niz[i],k));


	return 0;
}
/*-----------------------------------------------------------*/
void zaokruzi1(float niz[], int velicina)
{
	int i;
	for(i=0; i<velicina; i++)
	{
		niz[i]=(round(niz[i]*10)/10.);
	}
}
/*----------------------no comment
					
------------------------------------*/
void preslozi(float niz[],int velicina, int k)
{
	int i,j;
	int mjesto=0;
	float temp;

	zaokruzi1(niz,velicina);
	for(i=0; i<velicina; i++)
	{

		if(ispitaj(niz[i],k))
		{
			for(j=i; j>mjesto; j--)
			{
				temp=niz[j];
				niz[j]=niz[j-1];
				niz[j-1]=temp;

			}
			mjesto++;
		}
	}
}
/*-----------------------------------------------------------*/
int ispitaj(float broj, int k)
{
	int znak=broj<0?-1:1;
	
	int a=(int)(round(znak*broj*10));
	
	int suma=0;

	while(a!=0)
	{
		suma+=a%10;
		a/=10;
	}
	if(suma>=k)return 1;
	else return 0;
}