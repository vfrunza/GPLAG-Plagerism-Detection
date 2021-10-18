#include <stdio.h>
#include <math.h>

void zaokruzi1 (double *niz, int vel)
{
	double *p=niz;
	while(p<niz+vel){
		*p*=10;
		*p=round(*p);
		*p++/=10;
	}
}



int main(void) {
	int i,n;
	double niz[100];
	do
	 { 
	 	printf("Unesite velicinu niza: ");
	 	scanf("%d", &n);
	 }while (n<1 || n>100);
	 
	 printf("Unesite elemente niza: ");
	 
	 for (i=0;i<n;i++){
	 	scanf("%lf",&niz[i]);
	 }
	 zaokruzi1 (niz,n);
	 printf("Nakon zaokruzivanja niz glasi: ");
	 for (i=0;i<n;i++){
	printf("%g ", niz[i]);
	 }
	return 0;
}