#include <stdio.h>
#include <math.h>
#define N 100
void zaokruzi1(float niz[], int vel){
	int i;
	for(i=0; i<vel; i++){
		niz[i]= niz[i]*10;
		niz[i]=round(niz[i]);
		niz[i]=niz[i]/10;
	}
}

int suma_cifara(float broj){
	int suma=0;
	int novi=0;
	broj = broj*10;
	novi = broj;
	if(novi<0) novi=-novi;
	
	do{
		suma += novi%10;
		novi /=10;
	} while(novi!=0);
	
	
	return suma;
}

void preslozi(float *niz, int vel, int k){
	float temp;
	int brojac=0;
	int i, j;
	
	zaokruzi1(niz, vel);
	
	for(i=0; i<vel; i++){
		if(suma_cifara(niz[i])>=k){
			for(j=i; j>brojac; j--){
				temp = niz[j];
				niz[j]=niz[j-1];
				niz[j-1]=temp;
			}
			brojac++;
		}
	}
	
}
int main() {
	double niz[N];
	int k, n, i;
	printf("Unesite elemente niza N: ");
	for(i=0; i<N; i++){
		scanf("%lf", &niz[i]);
		if(niz[i]==-1) break;
	}
	n=i;
	printf("Unesite broj k: ");
	scanf("%d", &k);
	
	preslozi(niz, n, k);
	printf("Novi niz je: ");
	for(i=0; i<n; i++){
		printf("%f ", niz[i]);
	}
	return 0;
}
