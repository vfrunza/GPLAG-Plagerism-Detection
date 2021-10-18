#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int izbaci_cifre(int niz[],int vel1,int cifre[],int vel2)
{
	int *p,*q,temp,temp2,mjesto,cifra,znak;
	for(p=cifre; p<cifre+vel2; p++) {
		/*Provjera da li je unos niza cifara ispravan*/
		if(*p>9 || *p<0)
			return 0;
		for (q = cifre; q < p; q++) {
			if(*q==*p)
				return 0;
		}
	}

	for (p = niz; p < niz+vel1; p++) {
		mjesto=1;
		temp=abs(*p);
		if(*p>=0)
			znak=1;
		else
			znak=-1;
		*p=abs(*p);
		/*Prolazak korz sve cifre i poredjenje svake sa unesenim nizom*/
		do {
			cifra=temp%10;
			temp=temp/10;
			for (q = cifre; q < cifre+ vel2; q++) {
					temp2=*q;
				if(cifra==temp2) {
					/*Izbacifvanje cifre, ako je cifra zadnja broj se djeli sa 10, ako ne onda se djeli se novi broj dodatno racuna */
					if(mjesto==1) {
						*p=*p/10;
						break;

					} else {
						*p=(*p/(mjesto*10))*10+*p%mjesto;
						break;
					}
				}
			}
			if(q==cifre+vel2)
				mjesto*=10;
		} while (temp>0) ;
		*p=znak*(*p);
	}
	return 1;
}
			
