#include <stdio.h>
#include <stdlib.h>
int izbaci(int *niz, int duzinaNiza);
void ubaci(int *niz, int duzinaNiza);

int sumaCifara(int broj);
int pomjeriNiz(int *niz, int duzinaNiza, int pocetakPomjeranja);
int daLiJeFibonacijevBroj(int broj);
void zamijeniBrojeve (int *a, int *b);
void ispisiNiz(int *niz, int duzinaNiza);
void pomjeriNizNazad(int *niz, int duzina, int pocetakPomjeranja);

int main(){
	//printf("Zadaća 3, Zadatak 2");
	int broj,i,j;
	int niz[20];
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++)
		scanf("%d", niz+i);
	ubaci(niz, 10);
	broj= izbaci(niz, 20);
	printf("Modificirani niz glasi: ");
	
	ispisiNiz(niz, broj);
	
	return 0;
}

int izbaci(int *niz, int duzinaNiza){
	int i;
	for(i=0; i<duzinaNiza; i++){
		if(daLiJeFibonacijevBroj(*(niz+i))==1){
			pomjeriNizNazad(niz, duzinaNiza, i);
			duzinaNiza--;
			i--;
		}
	}
	return duzinaNiza;
}
void ubaci(int *niz, int duzinaNiza){
	int i;
	for(i=0; i<duzinaNiza; i+=2) {
		duzinaNiza= pomjeriNiz(niz, duzinaNiza, i+1);
	}
	for(i=1; i<duzinaNiza; i+=2) {
		*(niz+i)=sumaCifara(*(niz+(i-1)));
	}
}

int sumaCifara(int broj){
	int suma=0;
	broj= abs(broj);
	while(broj!=0) {
		suma+=broj%10;
		broj/=10;
	}
	return suma;
}
int pomjeriNiz(int *niz, int duzinaNiza, int pocetakPomjeranja){
	//Pomjeri niz za "1" mjesta od "pocetakPomjeranja" gdje je niz ispunjen do "duzinaNiza"
	int i;
	for(i=duzinaNiza+1; i>pocetakPomjeranja; i--)
		*(niz+i)= *(niz+i-1);
	*(niz+pocetakPomjeranja)= 0;
	return ++duzinaNiza;
}
int daLiJeFibonacijevBroj(int broj){
	int fibonacijev1= 1; 
	int fibonacijev2= 1;
	int temp;
	if(broj<1)
		return 0;
	while(broj>=fibonacijev2){
		if(broj== fibonacijev1 || broj== fibonacijev2)
			return 1;
		temp= fibonacijev1+fibonacijev2;
		fibonacijev1=fibonacijev2;
		fibonacijev2= temp;
	}
	return 0;
}
void zamijeniBrojeve (int *a, int *b){
	int temp;
	temp= *a;
	*a= *b;
	*b= temp;
}
void ispisiNiz(int *niz, int duzinaNiza){
	int i;
	for(i=0; i<duzinaNiza; i++){
		printf("%d", *(niz+i));
		if(i==duzinaNiza-1)
			break;
		printf(", ");
	}
	printf(".");
}
void pomjeriNizNazad(int *niz, int duzina, int pocetakPomjeranja){
	int i;
	for(i=pocetakPomjeranja+1; i<duzina; i++){
		*(niz+(i-1))= *(niz+i);
	}
}
