#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
(0,5 bodova) Napisati program koji omogućuje unos jednog cijelog broja, a zatim na ekranu ispisuje broj koji se 
dobije tako što se od prve cifre (s desne strane) oduzme druga cifra, od druge treća, od treće četvrta itd. 
Ako bi neka od ovih razlika bila negativan broj, uzima se njegova apsolutna vrijednost. 
Ako korisnik unese negativan broj uzima se njegova apsolutna vrijednost, a ako unese jednocifren broj rezultat treba biti 0.

Primjer ulaza i izlaza:
	Unesite broj: 38279
	5652


Objašnjenje: čitajući uneseni broj s desna na lijevo imamo:
9-7=2, 7-2=5, 2-8=-6, 8-3=5
a to su cifre konačnog broja gledano s desna na lijevo po apsolutnoj vrijednosti.


Napomena: Pri rješavanju zadatka NIJE dozvoljeno koristiti nizove! */

int main() {
		int n;
	
		int broj1, broj2;
		printf("Unesite broj: ");
		scanf("%d", &n);
		n=abs(n);
		int x, obrni=0;
		int k=0;
		
		while(n>9){
			broj1=n%10;
			broj2=n%100/10;
			x = abs(broj1 - broj2);
			// printf("%d", x);
			obrni= obrni + x*pow(10,k); 
			 
			
			k++;
			
			//if(broj2==0) break;
			//printf("%d", x); 
			
			
		/*	obrni=x*10;
			obrni+=n%10;
			printf("%d ", obrni); */
			
			n/=10;
			
		}
		
		printf("%d", obrni);
		
	return 0;
}
