#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void zaokruzi1(float *a, int vel){
	int i;
	for(i=0; i<vel; i++){
		a[i]=roundf(a[i]*10)/10;
	}
}
int zbir_cifara(float br){
	br*=10;
	int x;
	x=abs(br);
	int cifra;
	int suma=0;
	while(x!=0){
		cifra=x%10;
		suma+=cifra;
		x/=10;
	}
	return suma;
}

void preslozi(float *a, int vel, int k){
	zaokruzi1(a, vel);
	int i, c;
	int brojacVecih=0;
	int brojacManjih=0;
	int pomocniNiz[10000]={0};
	float veci[10000];
	float manji[10000];
	for(i=0; i<vel; i++){
		c=zbir_cifara(a[i]);
		pomocniNiz[i]=c;
	}
	for(i=0; i<vel; i++){
		if(pomocniNiz[i]>=k){
			veci[brojacVecih]=a[i];
			brojacVecih++;
		}
		else{
			manji[brojacManjih]=a[i];
			brojacManjih++;
		}
	}
	for(i=0; i<brojacVecih; i++){
		a[i]=veci[i];
	}
	for(i=0; i<brojacManjih; i++){
		a[brojacVecih+i]=manji[i];
	}
}

int main() {
	float niz[] = { 13.1, 15.749999, 15.75, 9.222, 78.1};
		preslozi(niz, 5, 14);
		
	return 0;
}
