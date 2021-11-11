/*1. (0,5 bodova) Napišite funkciju pod imenom daj_prost koja nema parametara, a svaki put kada se pozove vraća sljedeći prost broj. 

Kada prvi put pozovete funkciju, ona treba vratiti broj 2, drugi put treba vratiti broj 3, zatim broj 5, 7, 11 itd.*/


/* Ovu funkciju iskoristite u programu koji omogućuje korisniku da unese prirodne brojeve A i B takve da je A<B, a zatim ispisuje sumu 
svih prostih brojeva strogo većih od A a strogo manjih od B. U ovom programu se obavezno mora iskoristiti napravljena funkcija daj_prost, 
ne smiju se računati prosti brojevi na neki drugi način. */

#include <stdio.h>
#include <math.h>

int daj_prost (){
	static int x=1;
	int j,prost;
	do{
		prost=1;
		x++;
		if (x==2) 
		break;
		else {
	     for(j=2;j<x; j++)
				if(x%j==0){
				 prost=0;
				 break;}}}
				 while (prost==0);
	return x;
}

int main() {
	int A,B,suma=0,y=0;
	do{
	printf("Unesite brojeve A i B: ");
	scanf("%d %d",&A,&B);
		if (A<=0)
			printf("A nije prirodan broj.\n");
		if (A>=B)
			printf("A nije manje od B.\n");
	}
	while (A<=0 || B<=0 || A>=B);
	
	while (y<B){
	y=daj_prost();
	
	if (y>A && y<B)
	suma += y;
	}
	

	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	
	return 0;
}

/*Primjer ulaza i izlaza:
	Unesite brojeve A i B: 0 15
	A nije prirodan broj.
	Unesite brojeve A i B: 5 -5
	A nije manje od B.
	Unesite brojeve A i B: 10 10
	A nije manje od B.
	Unesite brojeve A i B: -5 -7
	A nije prirodan broj.
	Unesite brojeve A i B: 2 10
	Suma prostih brojeva izmedju 2 i 10 je 15.


Objašnjenje: 3+5+7 = 15. 


Napomena: Pri rješavanju zadatka NIJE dozvoljeno koristiti globalne promjenljive! Dakle, pošto funkcija daj_prost nema parametara, 
u njoj trebate koristiti statičke promjenljive.*/