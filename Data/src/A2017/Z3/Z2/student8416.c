#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void cijeliraj(float niz[], int velicina){
	int i;
	for(i=0; i<velicina; i++){
		niz[i]*=10;
	}
}
void zaokruzi1(float niz[], int velicina){
	int i;
	for(i=0; i<velicina; i++){
		niz[i]=niz[i]*10;
		niz[i]=round(niz[i]);
		niz[i]=(int)niz[i];
		niz[i]/=10;
	}
}

void preslozi(float niz[], int vel, int k){
	int i, suma=0, p, c, broj, tmp, j, brojac=0;
	zaokruzi1(niz, vel);
	cijeliraj(niz, vel);
	for(i=0; i<vel; i++){
		broj=niz[i];
		tmp=niz[i];
		while(broj!=0){
			c=abs(broj%10);
			broj/=10;
			suma+=c;
		}
		if(suma>=k){
			for(j=i; j>=brojac; j--){
				for(p=j-1; p>=brojac; p--){
					niz[j]=niz[p];
					j--;
				}
			}
			niz[brojac]=tmp;
			suma=0;
			brojac++;
		}else{
			suma=0;
		}
	}
	for(i=0; i<vel; i++){
		niz[i]=niz[i]/10.;
	}
}

int main() {
	
	int i;
    float niz[] = { 13.1, 15.749999, 15.75, 9.222, 78.1 };
    preslozi(niz, 5, 14);
    printf("Niz glasi: ");
    for (i=0; i<5; i++)
        printf("%g ", niz[i]);
	return 0;
}