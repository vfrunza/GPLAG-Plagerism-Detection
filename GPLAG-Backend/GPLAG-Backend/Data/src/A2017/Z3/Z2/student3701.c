#include <stdio.h>
#include <math.h>
void zaokruzi1 (float *niz,int vel)
{
	int i;
	for(i=0; i<vel; i++) {
		*(niz+i)=*(niz+i)*10;
		*(niz+i)=round(*(niz+i));
		*(niz+i)=*(niz+i)/10;
	}
}
void preslozi(float*niz,int vel,int k)
{

	zaokruzi1(niz,vel);

	int i,suma=0,temp,cifra,brojac=0;
	float noviniz[100];
	/*rastavljanje broja na cifre*/
	/*petljom se traze clanovi cija je suma cifara veca ili jednaka od k*/
	for(i=0; i<vel; i++) {
		suma=0;
		temp=fabs(niz[i]*10);
		do {

			cifra=temp%10;
			temp=(int)temp/10;
			suma=suma+cifra;

		} while(cifra!=0);

		if(suma>=k) {

			noviniz[brojac]=niz[i];
			brojac++;

		}

	}
	/*rastavljanje broja na cifre*/
	/*trazenje clanova cija je suma cifara manja od k*/
	for(i=0; i<vel; i++) {
		suma=0;
		temp=fabs(niz[i]*10);
		do {
			cifra=temp%10;
			temp=(int)temp/10;
			suma=suma+cifra;

		} while(cifra!=0);
		if(suma<k) {
			noviniz[brojac]=niz[i];
			brojac++;
		}
	}
	/*vracanje vrijednosti u novi niz*/
	for(i=0; i<vel; i++) {
		niz[i]=noviniz[i];
	}


}

int main()
{

	float niz[100];
	int i,vel,k;
	printf("Unesite velicinu niza: ");
	scanf("%d",&vel);
	printf("Unesite clanove niza: ");
	for(i=0; i<vel; i++) {
		scanf("%f",&niz[i]);

	}
	printf("Unesite k: ");
	scanf("%d",&k);
	zaokruzi1(niz,vel);
	preslozi(niz,vel,k);

	return 0;
}
