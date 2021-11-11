#include <stdio.h>
#include <math.h>
void zaokruzi1(float *niz , int n)
{

	int i;

	for(i=0 ; i<n ; i++) {
		*(niz+i)=((int)round(*(niz+i)*10))/10.;
	}

}

int sum(float broj)
{
	int suma=0;
	int br=(int)round(fabs(broj)*10);
	
	do {

		suma+=br%10;
		br=br/10;
	} while (br!=0);


	return suma;
}


void preslozi(float *niz , int n ,int k)
{
	int i,j,suma,brojac=0;
	float x;
	zaokruzi1(niz,n);
	for(i=0; i<n; i++) {
		suma=sum(*(niz+i));

		if(suma>=k) {
			x=*(niz+i);

			for(j=i; j>brojac; j--) {
				*(niz+j)=*(niz+j-1);
			}
			*(niz+brojac)=x;
			brojac++;
		}

	}

}


int main()
{

	int k=14,i;
	float niz[]= {13.1,15.749999,15,75,9.22,78.1};
	preslozi(niz,5,k);
	printf("Niz glasi: ");
	for(i=0; i<5; i++)
		printf("%g ",niz[i]);




	return 0;
}
