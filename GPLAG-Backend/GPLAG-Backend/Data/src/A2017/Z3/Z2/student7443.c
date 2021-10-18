#include <stdio.h>
#include <math.h>

void zaokruzi1(float *niz, int vel){
	float *p=niz;
	while(p<niz + vel){
		*p*=10;
		*p=round(*p);
		*p++/=10;
	}

}

int main(){
	int i,vel;
	float niz[100];
	do{
		printf("Unesite velicinu niza: ");
		scanf("%f", &vel);
	}
	while (vel<1 || vel>100);
	
	printf("Unesite elemente niza: ");
	for(i=0;i<vel;i++){
		scanf("%lf", &niz[i]);
	}
	zaokruzi1(niz,vel);
	printf("Nakon zaokruzivanja niz glasi: ");
	for(i=0;i<vel;i++){
		printf("%g", niz[i]);
	}
	return 1;

double preslozi(float *nizc, int vel, int k){
	double s=0;
	int c;
	int niz[100];
	double nizvec[100],nizmanj[100];
	int brojaca=0,brojacb=0;
	double temp;

	

	


}
	return 0;
}
