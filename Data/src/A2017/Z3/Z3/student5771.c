#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Ispituje da li se element ponavlja u nizu */
int provjera(int x,int niz[],int n,int y)
{
	int i;
	for(i=0; i<n; i++) {
		if(x==niz[i] && i!=y)
			return 1;
		else continue;
	}
	return 0;
}

int izbaci_cifre(int brojevi[],int vel_brojevi,int cifre[],int vel_cifre)
{
	int i;
	int digit,broj,rez=0,faktor=1;
	int *p=brojevi;
	int *q=cifre;

	/* Da li je niz cifara validan */
	for(i=0; i<vel_cifre; i++) {
		if(provjera(cifre[i],cifre,vel_cifre,i) || cifre[i]<0 || cifre[i]>9)
			return 0;
	}

	/* Petlja se 'vrti' dok ne prodje kroz sve clanove niza brojeva */
	while(p<brojevi+vel_brojevi) {

		/* Prolazimo kroz sve clanove niza cifara */
		while(q<cifre+vel_cifre) {
			broj=abs(*p);

			/* 'Izbacivanje' broja *q (koji je definisan u nizu cifara) iz elementa niza brojeva */
			while(broj!=0) {
				digit = broj % 10;
				broj = broj / 10;

				if(digit!=*q) {
					rez +=  digit*faktor;
					faktor *= 10;
				}
			}

			if(*p>0)
				*p=rez;
			else *p=-rez;

			q++; /* ... sljedeci element niza cifara ako ga uopste ima*/
			faktor=1;
			rez=0;
		}

		p++; /* ... sljedeci element niza brojeva ako ga uopste ima*/
		q=q-vel_cifre; /* vracamo se na pocetak niza cifara za novo ispitivanje */
	}

	return 1;
}


int main()
{
	/* Test */
	int i;
	int brojevi[]= {93,10,72,53,41,1,81,72,70,91,59,19,58,1,22,7,90,1,15,20,40,
	                35,63,25,17,895,353,712,185,728,396,237,528,526,823,308,926,241,72,616,560,
	                156,255,909,846,232,250,187,614,299,90397,80301,69157,37713,73193,96197,36182,
	                57223,78892,39906,151046,774384,102308,496411,218827,113768,228880,709598,336363,
	                119788,709842,156984,436696,707699,239819,252451,63924,546198,539310,518685,855989,
	                637554,816013,139253,835261,489074,611300,540966,253037,651523,94386,654233,233623,
	                906548,273655,115594,41922,481089,663650,758381,796993,439340,978999,518841,673298,
	                890630,492491,657853,104796
	               };

	int cifre[]= {0,3,5,2,8};
	int x = sizeof brojevi / sizeof brojevi[0];
	int y = sizeof cifre / sizeof cifre[0];

	izbaci_cifre(brojevi,x,cifre,y);

	for(i=0; i<x; i++)
		printf("%d ",brojevi[i]);

	return 0;
}
