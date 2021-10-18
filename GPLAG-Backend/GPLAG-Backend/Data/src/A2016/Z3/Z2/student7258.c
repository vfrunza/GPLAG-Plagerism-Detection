#include <stdio.h>
#include <stdlib.h>
/*Funkcija racuna zbir cifara broja*/
int zbir_cifara (int x) {
	int suma=0;
	while(x>0) {
		suma+=(x%10);
		x/=10;
	}
	return suma;
}
void ubaci (int p[], int vel) {
	int i,*s,*q,p2;
	/*Petlja prolazi kroz clanove niza, od zadnjeg prema prvom*/
	for(i=vel-1;i>=0;i--) {
		q=p+i;
		s=p+i*2;
		*s=*q;
	}
	/*Uzima se niz dva puta vece velicine*/
	for(i=0;i<2*vel;i=i+2) {
		s=p+i;
		q=s+1;
		p2=abs(*s);
		*q=zbir_cifara(p2);
	}
}	
int main() {
	int niz[20];
	int i,a,vel=10;
	printf("Unesite niz od 10 brojeva: ");
	/*Unos clanova niza*/
	for(i=0;i<vel;i++) {
		scanf("%d",&niz[i]);
	}
	ubaci(niz,vel);
	a=2*vel;
	printf("Modificirani niz glasi: ");
	for(i=0;i<a-1;i++) {
		printf("%d, ",niz[i]);
	}
	printf("%d.",niz[i]);
	return 0;
}
