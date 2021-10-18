#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Funkcija ubaci preuređuje poslani niz tako da: nakon svakog clana niza, pocevsi od prvog ubacuje novi clan,
							koji je jednak sumi cifara prethodnog clana */
void ubaci(int *niz,int vel) {
	int i, x, y, suma=0;
	int *a;
	a=niz;
	for(i=vel-1;i>=0;i--){
		*(a+(i*2))=*(a+i);
	}
	
	for(i=0;i<2*vel;i++){
		if(i%2!=0){
		
		x=*(a+i-1);
		
		while(x!=0){
		y=x%10;
		suma=suma+y;
		x=x/10;
		}
		
		suma=abs(suma);
		*(a+i)=suma;
		suma=0;
		}
	}
}

/* Funkcija fib provjerava da li je neki broj clan fibonacijevog niza, sto je potrebno u funkciji izbaci */
int fib(int a){
	int prvi=0, drugi=1, treci=0, br=0;
	while(1){
		treci=prvi+drugi;
		prvi=drugi;
		drugi=treci;
		 if(a==treci){br++;break;}
	else if(a<treci)break;
	}
	if(br>0)return 1;
	else return 0;
}

/* Funkcija izbaci koristi funkciju fib u petlji jer mora izbaciti clanove fibonacijevog niza iz poslanog joj niza */
int izbaci(int *niz,int vel){
	int *a, i, j;
	a=niz;
	for(i=0;i<vel;i++){
			if(fib(*(a+i))==1){
				
				for(j=i;j<vel-1;j++){
				*(a+j)=*(a+j+1);
				}
				vel--;
				i--;
			}
		}
	return vel;
}	

int main() {
	int i, niz[20], vel;
	
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++){
		scanf("%d", &niz[i]);
	}
	
	/* Povivaju se 2 funkcije koje preuređuju niz po opisima funkcija. 
		(date funkcije su objasnjene svojim komentarima iznad) */
	ubaci(niz,10);
	vel = izbaci(niz,20);
	
	printf("Modificirani niz glasi: ");
	for(i=0;i<vel;i++){
		if(i<(vel-1)){
		printf("%d, ",niz[i]);
		}
		else{
			printf("%d.", niz[i]);
		}
	}
	return 0;
}
