#include <stdio.h>
#include <math.h>
#define BROJ_EL 100
void zaokruzi1(float niz[], int velicina){
	int i;
	for(i=0; i<velicina; i++){
		niz[i]=round(niz[i]*10)/10;
	}
}
void preslozi(float niz[], int velicina, int k){
	int i,j,suma=0,brojac=0,p;
	float *p1;
	
	for(i=0; i<velicina; i++){
		p1=&niz[i];
		p=*p1*10;
	while(brojac<3){
		suma+=p%10;
		p=p/10;
		brojac++;
	}	
	if(suma<=k){
		for(j=0; j<velicina-1; j++){
			niz[j]=niz[j+1];
		}
		niz[velicina-1]=*p1;
		i--;
	}
	suma=0;
	brojac=0;
	}
}
int main() {
int i,k,velicina;
float niz[BROJ_EL];

printf("Unesite duzinu niza: ");
scanf("%d", &velicina);
printf("Unesite niz: ");
for(i=0; i<velicina; i++){
	scanf("%f", &niz[i]);
}
printf("Unesite broj k: ");
scanf("%d", k);
zaokruzi1(niz, velicina);
preslozi(niz, velicina, k);
printf("Nakon transformacije: ");
for(i=0; i<velicina; i++){
	printf("%g", niz[i]);
}
	return 0;
}
