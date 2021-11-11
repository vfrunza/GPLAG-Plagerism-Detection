#include <stdio.h>
#include <math.h>
void zaokruzi1(float *niz,int velicina) //zaokruzujemo clanove niza na jednu decimalu
{
	int i;
	for(i=0; i<5; i++) {
		niz[i]=round(niz[i]*10)/10;
	}
}

int sum(float broj) //unutar ove funkcije se obavlja operacija rastavljanja datih brojeva na cifre
{
	int suma=0;
	float temp=broj*10;
	int cifra=temp;
	while(cifra!=0) {

		suma+=fabs(cifra%10);
		(cifra/=10);
	}
	return suma;
}
void preslozi(float *niz,int velicina,int k) //unutar ove funkcije vrsimo preslaganje novog niza
{
	zaokruzi1(niz,velicina);

	float veci[5];
	int brojV=0;
	float manji[5];
	int brojM=0;
	int i;
	for(i=0; i<5; i++) {
		if(sum(niz[i])>=k) //Ako je suma cifara  jednog elementa niza veca ili jednaka od unesenog broja k,tada sastavljamo novi niz koji
			// ce se na kraju ispisati
		{
			veci[brojV]=niz[i]; //Taj broj cija je suma cifara veca ili jednaka od k,tada taj broj stavljamo u novi niz-niz
			// vecih brojeva i pridruzujemo index,koji povecavamo za svaki sljedeci broj koji ispunjava uslov
			brojV++;
		} else {
			manji[brojM]=niz[i]; //Broj cija je suma cifara manja od k,tada taj broj stavljamo u novi niz-niz
			// manjih brojeva i pridruzujemo mu "poziciju",tj.ovaj index,koji se povecava sa svakim sljedecim clanom koji ispunjava dati uslov
			brojM++;
		}

	}
	int pozicija=0;
	for(i=0; i<brojV; i++) {
		niz[pozicija]=veci[i];//Sastavljamo krajnji niz koji se sastoji od prethodna dva napravljena niza
		pozicija++;
	}
	for(i=0; i<brojM; i++) {
		niz[pozicija]=manji[i];
		pozicija++;
	}
}

int main()
{
	return 0;
}
