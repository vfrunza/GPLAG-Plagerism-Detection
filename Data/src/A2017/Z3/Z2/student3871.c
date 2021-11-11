#include <stdio.h>
#include <math.h>
/*Zaokruzivanje na jednu decimalu*/
void zaokruzi1(float niz[],int x)
{
 int i;
 for(i=0;i<x;i++)
  niz[i]=round(niz[i]*10)/10;
}
void preslozi(float niz[], int x, int k)
{
 int i,cifra,s=0,br,brojac1=0,brojac2=0;
 float pom1[10000]={0},pom2[10000]={0};
 zaokruzi1(niz,x);
 for(i=0;i<x;i++)
 {
  s=0;
  /*Pridruzivanje broju vrijednost iz niza pomnozeno sa 10*/
  br=fabs(niz[i]*10);
  /*Racunanje sume cifara niza*/
  while(br!=0)
  {
   cifra=br%10;
   s+=cifra;
   br/=10;
  }
  /*Ispitivanje za sumu vecu i manju od k i pridruzivanje pomocnim*/
  if(s>=k)
  {
   pom1[brojac1]=niz[i];
   brojac1++;
  }
  else
  {
   pom2[brojac2]=niz[i];
   brojac2++;
  }
 }
 /*Pridruzivanje pomocnih nizova starom nizu*/
 for(i=0;i<brojac1;i++)
 {
  niz[i]=pom1[i];
 }
 for(i=brojac1;i<brojac1+brojac2;i++)
 {
  niz[i]=pom2[i-brojac1];
 }
}
int main() {
	return 0;
}


/*
#include <stdio.h>
#include <math.h>
void zaokruzi1(float niz[], int n)
{
	int i;
	double broj;
	for(i=0;i<n;i++) 
	{
		broj=round(niz[i]*10)/10;
		niz[i]=broj;
	}
}

void preslozi(float niz[], int n, int k)
{
	
	int i,j,brojac1=0,broj,suma;
	double temp;
	zaokruzi1(niz,n);
	for(i=0;i<n;i++)
	{
		suma=0;
		for(broj=niz[i]*10;broj!=0;broj/=10) suma+=fabs(broj%10);
	    if(suma>=k) 
		{
			if(i!=brojac1) //Ako se broj cija je suma cifara veca od datog k ne nalazi na mjestu gdje se treba nalaziti, pomjerimo ga na to mjesto i sve ostale elemente za jedno mjesto u desno 
			{
				temp=niz[brojac1];
				niz[brojac1]=niz[i];
				for(j=i;j>brojac1;j--) 
				{
					niz[j]=niz[j-1];
				}
				brojac1++;
				niz[brojac1]=temp;
			}
			else brojac1++;
		}
	}
}

int main() 
{
	int i;
	float niz[] = { 3.1, 2.2, 1.1, 7.2, 4.5, 5.6 };
	preslozi(niz, 6, 5);
	printf("Niz glasi: ");
	for (i=0; i<6; i++)
    	printf("%g ", niz[i]);
 	return 0;
}
*/