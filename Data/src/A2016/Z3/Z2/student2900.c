#include <stdio.h>

#define Vel 200
/* Ubacuje u niz pozotovan broj koji predstavlja sumu cifara predhodnog clana*/
void ubaci(int niz[], int brojClanova){
	int i = 0;
	for(; i<brojClanova; i++){
		niz[i * 2] = niz[i];	
	}
	for(i = 0; i<brojClanova*2; i+=2){
		int zaUbacaj = 0;
		int trVr = niz[i];
		while(trVr != 0){
			zaUbacaj += trVr%10;
			trVr/=10;
		}
		niz[i + 1] = zaUbacaj;
	}
}
/*provjerava da li je broj fibonacijev*/
int fibonacijevJe(int broj){
	int vrPrije = 1, vrNova = 1;
	while(1){
		if(broj == vrNova) return 1;
		if(broj < vrNova) return 0;
		int temp = vrPrije + vrNova;
		vrPrije = vrNova;
		vrNova = temp;
	}
}

int izbaci(int niz[], int brojClanova){
	int i = 0, j;
	for(; i < brojClanova; i++){
		if(fibonacijevJe(niz[i])){
			for(j = i; j < brojClanova-1; j++){
				int temp = niz[j];
				niz[j] = niz[j+1];
				niz[j+1] = temp;
			}
			brojClanova--;
			i--;
		}
	}
	return brojClanova;
}

int main() {
int i;
int niz[2*Vel], noviniz;
printf("Unesi niz od 10 brojeva: ");
for (i = 0; i < Vel; i++){
	scanf("%d",&niz[i]);
}
noviniz=izbaci(niz, 20);
printf ("Modificirani niz glasi: ");
for (i = 0; i < noviniz; i++){
   	if(i == noviniz - 1){
   		printf("%d.",niz[i]);
   	}
   	else printf("%d,",niz[i]);
   }

	return 0;
}
