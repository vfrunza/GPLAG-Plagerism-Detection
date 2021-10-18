#include <stdio.h>

void zaokruzi1(double *niz, int vel){
	int i, zaok, pomzaok;
	for(i=0; i<vel; i++){
		
		*(niz+i)+=0.05;
		zaok=*(niz+i)*10;
		*(niz+i)=zaok/10.;
	}
}

int main() {
	double niz[5];
	int i, vel;
	printf("Unesite članove niza: ");
	for(i=0; i<5; i++)
		scanf("%lf", &niz[i]);
	vel=i;
	zaokruzi1(niz, vel);
	printf("Nakon zaokruzivanja niz glasi: \n");
	for(i=0; i<vel; i++)
		printf("%g ", niz[i]);
	return 0;
}
