/*1. (0,5 bodova) Napisati program koji omogućuje unos jednog cijelog broja, a zatim na ekranu 
ispisuje broj koji se dobije tako što se od prve cifre (s desne strane) oduzme druga cifra, 
od druge treća, od treće četvrta itd. Ako bi neka od ovih razlika bila negativan broj, 
uzima se njegova apsolutna vrijednost. Ako korisnik unese negativan broj uzima se njegova apsolutna vrijednost, 
a ako unese jednocifren broj rezultat treba biti 0.


Primjer ulaza i izlaza:
	Unesite broj: 38279
	5652


Objašnjenje: čitajući uneseni broj s desna na lijevo imamo:
9-7=2, 7-2=5, 2-8=-6, 8-3=5
a to su cifre konačnog broja gledano s desna na lijevo po apsolutnoj vrijednosti.


Napomena: Pri rješavanju zadatka NIJE dozvoljeno koristiti nizove!
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int x,i=1,k=0,a=0,b=0;
	printf("Unesite broj: ");
	scanf("%d", &x);
	if(x<0) {
		x=abs(x);
	}
	if(x/10==0) {
		printf("0");
		return 0;
	}
	
	do
	{
		a=x%10;
		b=(x/10)%10;
		k += fabs(a-b)*i;
		i *= 10;
		x /=10;
		
	}
	while (x>10);
	
	printf("%d",k);
	
	
	return 0;
}
