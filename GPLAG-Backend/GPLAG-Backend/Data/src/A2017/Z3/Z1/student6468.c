#include <stdio.h>
#define DUZINA 200

int dva_od_tri(int *niz1,int duzina1,int *niz2,int duzina2,int *niz3,int duzina3) {
	int i,j,k;
	int brojac=0;
	int brojevi_nizaA[DUZINA]={0},brojevi_nizaB[DUZINA]={0},brojevi_nizaC[DUZINA]={0};

	/*Ubacivanje elemenata u njima ekvivalentne histograme*/
	for(i=0;i<duzina1;i++) {
		for(j=0;j<DUZINA;j++) {
			if(niz1[i]==j) brojevi_nizaA[j]++;
		}
	}

	for(i=0;i<duzina2;i++) {
		for(j=0;j<DUZINA;j++) {
			if(niz2[i]==j) brojevi_nizaB[j]++;
		}
	}
	for(i=0;i<duzina3;i++) {
		for(j=0;j<DUZINA;j++) {
			if(niz3[i]==j) brojevi_nizaC[j]++;
		}
	}
	
	/*Izbacivanje duplih elemenata iz histograma*/
	for(i=0;i<DUZINA;i++) {
		if(brojevi_nizaA[i]>1) brojevi_nizaA[i]=1;
	}
	for(i=0;i<DUZINA;i++) {
		if(brojevi_nizaB[i]>1) brojevi_nizaB[i]=1;
	}
	for(i=0;i<DUZINA;i++) {
		if(brojevi_nizaC[i]>1) brojevi_nizaC[i]=1;
	}
	
	for(i=0;i<DUZINA;i++) {
		for(j=0;j<DUZINA;j++) {
			for(k=0;k<DUZINA;k++) {
				if(i==j && i==k) {
					if(brojevi_nizaA[i]==1 && brojevi_nizaB[j]==1 && brojevi_nizaC[k]==0) brojac++;
					if(brojevi_nizaA[i]==1 && brojevi_nizaB[j]==0 && brojevi_nizaC[k]==1) brojac++;
					if(brojevi_nizaA[i]==0 && brojevi_nizaB[j]==1 && brojevi_nizaC[k]==1) brojac++;
				} 
			}
		}
	}
	
	return brojac;
}


int main() {
	int i,niz1[DUZINA],duzina1,niz2[DUZINA],duzina2,niz3[DUZINA],duzina3,rez;
	
	printf("Unesite duzine nizova: ");
	scanf("%d %d %d",&duzina1,&duzina2,&duzina3);
	
	printf("Unesite nizove: ");
	for(i=0;i<duzina1;i++) {
		scanf("%d",&niz1[i]);
	}
	
	for(i=0;i<duzina2;i++) {
		scanf("%d",&niz2[i]);
	}
	
	for(i=0;i<duzina3;i++) {
		scanf("%d",&niz3[i]);
	}

	rez=dva_od_tri(niz1,duzina1,niz2,duzina2,niz3,duzina3);
	printf("%d",rez);
	
	return 0;
}