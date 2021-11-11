/*2. (0,5 bodova) Kao što znamo, uglovi mogu biti predstavljeni u radijanima ili u stepenima. 
Iz radijana se mogu dobiti stepeni tako što vrijednost pomnožimo sa 180/π. Svaki stepen se sastoji od 60 minuta,
a svaka minuta od 60 sekundi.
*/
#include <stdio.h>
#include <math.h>
#define Pi 3.1415926
#include <stdlib.h>

/*Napišite program koji omogućuje unos proizvoljnog broja (najviše 500) uglova u radijanima. 
Korisnik najprije unosi broj članova niza, a zatim članove. Program treba najprije iz niza izbaciti sve 
članove niza kod kojih je broj sekundi veći od 30 (neovisno o vrijednosti stepeni i minuta). Obavezno koristiti 
izbacivanje iz niza uz očuvanje redoslijeda elemenata niza!
*/
int main() {
	int n,i,j,stepeni[500]={0},minute[500]={0},sekunde[500]={0},negativni; 
	double uglovi;
	do {
		printf("Unesite broj uglova: ");
		scanf("%d",&n);
				if(n<1 || n>500)
		printf("Pogresan unos \n");
				else break;
	}
	while (1);
	
	for (i=0; i<n; i++){
		scanf("%lf",&uglovi);
	uglovi=uglovi*180/Pi;
	negativni=0;
				if(uglovi < 0)
				{ 
					uglovi *=-1; negativni = 1; 
					
				}
		stepeni[i]=(int)uglovi;
		uglovi -= (int)uglovi;
		minute[i]=(int)(uglovi*60);
		uglovi*=60;
		uglovi-=(int)uglovi;
		sekunde[i]=(int)round(uglovi*60);
				if(sekunde[i]==60)
				{ 
					minute[i]++; sekunde[i]=0; 
					
				}
				if(minute[i]== 60)
				{ 
					stepeni[i]++; minute[i]=0;
					
				}
				if(negativni == 1) stepeni[i]*=-1;
				}

for(i=0;i<n;i++){
	if(sekunde[i]>30){
		for(j=i;j<n-1;j++){
			stepeni[j]=stepeni[j+1];
			minute[j]=minute[j+1];
			sekunde[j]=sekunde[j+1];
		}
		i--;
		n--;
	}
}
/*Nakon toga treba na ekran ispisati preostale uglove u stepenima, minutama i sekundama, pri čemu su ove tri 
vrijednosti cijeli brojevi. Ako broj sekundi nije cijeli broj, treba ga zaokružiti (a ne odsjeći!) 
Prilikom računanja nije potrebno vršiti svođenje uglova na neki interval niti provjeru ispravnosti. 
Obavezno koristiti konstantu pod imenom PI čija je vrijednost 3.1415926.*/

printf("Uglovi su:\n");
for(i=0;i<n;i++)
printf("%d stepeni %d minuta %d sekundi\n", stepeni[i], minute[i], sekunde[i]);
	return 0;
}
	
/*
Primjer ulaza i izlaza:
	Unesite broj uglova: 3
	1.2
	2.8
	2.0
	Uglovi su:
	68 stepeni 45 minuta 18 sekundi
	114 stepeni 35 minuta 30 sekundi


Objašnjenje: 2.8 radijana je jednako 160 stepeni, 25 minuta i 41 sekundu. Broj sekundi je veći od 30 pa je 
ovaj ugao izbačen. */