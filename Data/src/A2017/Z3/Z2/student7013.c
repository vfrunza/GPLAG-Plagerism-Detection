#include <stdio.h>
#include <math.h>

void zaokruzi1(float niz[], int vel){
	int i,cifra,y;
	float x;
	for(i = 0; i < vel; i++){
		cifra = ((int)(fabs(niz[i])*100))%10;
		y = ((int)(fabs(niz[i])*10))%10;
		if(cifra>=5) y++;
		x = ((int)fabs(niz[i]))+(0.1*y);
		if(niz[i] < 0) niz[i] = -1*x;
		else niz[i] = x;
	}
}

void preslozi(float niz[], int vel, int k){
	int suma,i,pom;
	int v1 = 0, v2 = 0;
	float veca[1000], manja[1000];
	zaokruzi1(niz,vel);
	for(i = 0; i < vel; i++){
		suma = 0;
		pom = (int)(niz[i]*10);
		if(pom < 0) pom *= -1;
		while(pom > 0){
			suma += pom%10;
			pom /= 10;
		}
		if(suma >= k) veca[v1++] = niz[i];
		else manja[v2++] = niz[i];
	}
	for(i = 0; i < v1; i++) niz[i] = veca[i];
	for(i = v1; i < v1+v2; i++) niz[i] = manja[i-v1];
}

int main() {
	
}
