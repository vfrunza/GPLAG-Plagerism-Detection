#include <stdio.h>
#include <math.h>

void zaokruzi1 (float niz[], int vel){
	int i;
	for (i=0; i<vel; i++){
		niz[i] *= 10;
		niz[i] = round(niz[i]);
		niz[i] /= 10;
	}
}


void preslozi (float niz[], int vel, int k){
	float niz2[1000];
	int j=0;
	zaokruzi1(niz, vel);
	int i, cifra=0;
	
	for (i=0; i<vel; i++){
		int broj=niz[i]*10;
		if (broj<0){                 //pretvara negativne u pozitivne brojeve
			broj= broj*(-1);
		}
		int suma=0;
			do{
			cifra=broj%10;           //racuna sumu cifara
			suma=suma+cifra;
			broj=broj/10;
		}while (broj>0);
	
		if (suma>=k){                //ako je suma >=k onda pise u niz
			niz2[j]=niz[i];
			j++;
		}
	}
	
	for (i=0; i<vel; i++){
		int x=0, m;
		for (m=0; m<j; m++){
			if (niz2[m]==niz[i]){
				x=1;
			}
		}
		if(x==0){
			niz2[j]=niz[i];
			j++;
		}
	}
	
	for (i=0; i<vel; i++){
		niz[i]=niz2[i];
	}
}


int main() {
	float niz[10];
	int  i, k=20;
	
	zaokruzi1(niz, 10);
	preslozi(niz, 10, 20);
	
	for(i=0; i<9; i++){
		printf ("%g", niz[i]);
	}
	
	return 0;
}
