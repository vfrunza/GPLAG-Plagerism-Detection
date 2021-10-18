#include <stdio.h>
#include <math.h>

int izbaci_cifre(int brojevi[], int vel1, int cifre[], int vel2){
	int i,j,k,isti,pom,ima,vel3;
	int niz[10];
	for(i = 0; i < vel2; i++) if(cifre[i] < 0 || cifre[i] > 9) return 0;
	for(i = 0; i < vel2; i++){
		isti = 0;
		for(j = i + 1; j < vel2; j++){
			if(cifre[i]==cifre[j]) isti = 1;
		}
		if(isti) return 0;
	}
	for(i = 0; i < vel1; i++){
		pom = fabs(brojevi[i]);
		for(j = 0; j < 10; j++) niz[j] = 0;
		vel3 = 0;
		while(pom > 0){
			niz[vel3++] = pom%10;
			pom /= 10;
		}
		for(j = 0; j < vel3; j++){
			ima = 0;
			for(k = 0; k < vel2; k++){
				if(niz[j]==cifre[k]){
					ima = 1;
					break;
				}
			}
			if(ima){
				for(k = j; k < vel3 - 1; k++){
					niz[k] = niz[k+1];
				}
				vel3--;
				j--;
			}
		}
		pom = 0;
		for(j = 0; j < vel3; j++){
			pom += (niz[j]*pow(10,j));
		}
		if(brojevi[i] > 0) brojevi[i] = pom;
		else brojevi[i] = (-1 * pom);
	}
	return 1;
}

int main() {

}