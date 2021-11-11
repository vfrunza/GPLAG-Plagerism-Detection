#include <stdio.h>
/*Funkcija sumaCifara vraca sumu cifara cijelog broja.*/
int sumaCifara(int broj){
    int suma=0;
    while(broj!=0){
        suma+=broj%10;
        broj/=10;
    }
    if (suma<0) return -suma; else return suma;
}
/*Funkcija jelFibonacci vraca 1 ako je primljeni broj Fibonaccijev,
 u suprotnom vraca 0.*/
int jelFibonacci(int broj){
    int clan1=1, clan2=1, tmp;
    /*Racunanje Fibonaccijevih brojeva pomocu prva dva (1 i 1) sve dok je veci 
    broj (clan2) manji od primljenog broja.*/
    while(broj>clan2){
        tmp=clan2;
        clan2=clan1+clan2;
        clan1=tmp;
    }
    if(broj==clan1 || broj==clan2) return 1; else return 0;
}
void ubaci(int* niz, int vel){
	int i, j, k=0;
	/*Ubacivanje suma cifara clanova u niz.*/
	for(i=0;i<(2*vel);i+=2){
	    for(j=vel+k;j>i+1;j--) niz[j]=niz[j-1];
	    niz[i+1]=sumaCifara(niz[i]);
	    k++;
	}
}
int izbaci(int* niz, int vel){
    int i, j;
    for(i=0;i<vel;i++){
        /*Izbacivanje clana iz niza ako je on clan Fibonaccijevog niza.*/
        if(jelFibonacci(niz[i])){
            for(j=i;j<(vel-1);j++){
                niz[j]=niz[j+1];
            }
            vel--;
            i--;
        }
    }
	return vel;
}
int main() {
	int niz[20], vel=10, i;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<vel;i++){
	    scanf("%d", &niz[i]);
	}
	ubaci(niz,vel);
	vel=izbaci(niz,vel*2);
	printf("Modificirani niz glasi:");
	for(i=0;i<vel;i++){
	    if (i!=vel-1) printf(" %d,", niz[i]);
	        else printf(" %d.", niz[vel-1]);
	}
	return 0;
}