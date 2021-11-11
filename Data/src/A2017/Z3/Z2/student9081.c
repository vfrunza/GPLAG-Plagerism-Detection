#include <stdio.h>
#include <math.h>
void zaokruzi1 (float niz[],int vel)
{
	int i;
	for (i=0; i<vel; i++) {
		niz[i]=niz[i]*10;
		niz[i]=round(niz[i]);
		niz[i]=niz[i]/10;
	}
}
void preslozi (float niz[],int vel,int k)
{
	int i,j,brojac=0;
	int suma=0,cifra;
	int  temp;
	float pomocna1,pomocna2;
	zaokruzi1(niz,vel);
	/*Dodijelimo svaki clan niza pomocnoj varijabli tipa float,koju onda zaokruzimo da bismo obuhvatili i cifru iza zareza*/
	for (i=0; i<vel; i++) {
		pomocna1=niz[i];
		pomocna1=round(pomocna1*10);
		if (pomocna1<0)
		pomocna1=-pomocna1;
		temp=pomocna1;
		/*Uz pomoc while petlje racunamo sumu cifara svakog clana niza*/
		while (temp>0) {
			cifra=temp%10;
			temp/=10;
			suma+=cifra;
		}
		/*Prvi clan niza cije je suma veca od parametra k saljemo na pocetak niza,a svaki sljedeci clan koji ispunjava ovaj uslov na mjesto pored,sto je osigurano uz pomoc brojaca*/
		if (suma>=k) {
			for (j=i; j>brojac; j--) {
				pomocna2=niz[j];
				niz[j]=niz[j-1];
				niz[j-1]=pomocna2;
			}
			brojac++;
		}

		suma=0;
	}

}

int main()
{
	int n,i,k;
	float niz[100];
	printf ("Unesite dimenziju:");
	scanf ("%d",&n);
	printf ("Unesite clanove niza: ");
	for (i=0; i<n; i++)
		scanf ("%f",&niz[i]);

	zaokruzi1(niz,n);
	printf ("Novi niz glasi: ");

	for (i=0; i<n; i++)
		printf ("%g ",niz[i]);
	printf ("Unesite k:");
	scanf ("%d",&k);
	preslozi(niz,n,k);
	printf ("Novi niz glasi: \n");
	for (i=0; i<n; i++)
		printf ("%g ",niz[i]);


	return 0;
}
