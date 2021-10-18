#include <stdio.h>
#define PI 3.141592654

int main() {
	float niz[500],n;
	int i,j,m,stepen,minuta,sekunda;
	do {
		printf("Unesite broj uglova: ");
		scanf("%f", &n);
		 } while(n<1 || n>500);
		 printf("Uglovi su: ");
		 for(i=0; i<n; i++) {
		 	scanf("%f", &niz[i]);
		 
	niz[i]*=180.0/PI;
	stepen=(int) niz[i];
	niz[i]-=stepen;
	niz[i]*=60;
	minuta=(int) niz[i];
	niz[i]-=minuta;
	niz[i]*=60;
	sekunda=(int) (niz[i]+0.5);
	if(sekunda<=30)	printf("\n%d stepeni %d minuta %d sekundi", stepen, minuta, sekunda); }

	for(j=0; j<n; j++) {
		if(sekunda>30) {
			for(m=j; m<n-1; m++) {
				niz[m]=niz[m+1];
			}
			n--;
			j--;
		}
	}
	return 0;
}
