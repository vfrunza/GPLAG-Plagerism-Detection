#include <stdio.h>
#include <math.h>
void zaokruzi1(float niz[], int vel)
{
int i;
float pom;
for(i=0;i<vel;i++)
{
	pom=round(niz[i]*10)/10;
	niz[i]=pom;
}
}

void preslozi(float niz[], int vel,int k)
{
	int i;
	int suma=0;
	int brojac=0;
	int q,p;
	float broj1;
	int broj;
	int pomocniniz[10000];
	float niz1[10000];
	zaokruzi1(niz,vel);
	for(i=0;i<vel;i++)
	{
		suma=0;
		broj1=fabs(niz[i])*10+0.5;
		broj=broj1;
		while(broj!=0)
		{
		q=broj%10;
		if(q<0) q*=-1;
		suma+=q;
		broj/=10;
		}
		if(suma>=k)
		{
			brojac++;
			pomocniniz[i]=1;
		}
		else
		pomocniniz[i]=0;
	}
	
	p=0;
	for(i=0;i<vel;i++)
	niz1[i]=niz[i];
	for(i=0;i<vel;i++)
	{
		if(pomocniniz[i]==1) { niz[p]=niz1[i]; p++;}
		if(pomocniniz[i]==0) { niz[brojac]=niz1[i]; brojac++;}
	}
}

int main() 
{
	int i;
float niz[] = { -1.0, -0.1, -0.19999, -4.449999, -4.45001 };
preslozi(niz, 5, 6);
    printf("Niz glasi: ");
    for (i=0; i<5; i++)
    printf("%g ", niz[i]);
	return 0;
}
