#include <stdio.h>
#include <math.h>
#define DUZINA 100



void zaokruzi1(float niz[],int vel) {
	int i;
	for(i=0;i<vel;i++) {
		niz[i]=niz[i]*10; 
		niz[i]=round(niz[i]); 
		niz[i]=niz[i]/10; 
	}
}


void preslozi(float niz[],int velicina,int k) {
	int i,j,broj,cifra,niz_suma[DUZINA]={0},vel_veci=0,vel_manji=0,pozicija=0;
	float veci[DUZINA],manji[DUZINA];
	
	zaokruzi1(niz,velicina);
	
	for(i=0;i<velicina;i++) {
		broj=niz[i]*10;
		for(j=0;j<velicina;j++){
			while(broj!=0) {
				cifra=fabs(broj%10);
				broj=broj/10;
				niz_suma[i]=niz_suma[i]+cifra;
			}
		}
	}
	
	for(i=0;i<velicina;i++) {
		if(niz_suma[i]>=k) {
			veci[vel_veci]=niz[i];
			vel_veci++;
			pozicija++;
		}
		else {
			manji[vel_manji]=niz[i];
			vel_manji++;
		}
	}
	
	for(i=0;i<pozicija;i++) {
		niz[i]=veci[i];
	}
	
	for(i=pozicija;i<pozicija+vel_manji;i++) {
		niz[i]=manji[i-pozicija];
	}
	
	/*for(i=0;i<pozicija;i++) {
	printf("%f ",veci[i]);
	}*/
	
	
}


int main() {
	int i,duuzina,k;
	float niz[DUZINA];
	
	printf("Unesite duzinu niza: ");
	scanf("%d",&duuzina);
	printf("Unesite elemente niza: ");
	for(i=0;i<duuzina;i++) {
		scanf("%f",&niz[i]);
	}
	
	printf("Unesite k: ");
	scanf("%d",&k);
	
	printf("Niz glasi:\n");
	preslozi(niz,duuzina,k);
	
	return 0;
}
