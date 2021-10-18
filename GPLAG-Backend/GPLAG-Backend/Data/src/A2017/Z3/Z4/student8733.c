#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina){
	int i,j,brojac[20000]={0}, max;
	/* Trazimo broj koji se najvise puta ponavlja */
	for (i=0;i<visina;i++){
		for(j=0;j<sirina;j++){;
				brojac[10000+matrica[i][j]]++;
		}
	}
	max=0;
	for(i=0;i<20000;i++){
		if(brojac[i]>max) max=brojac[i];
	}
	/* Vracamo najmanji broj koji se najvise puta ponavlja */
	
	for(i=0;i<20000;i++){
		if(brojac[i]==max) return i-10000;
	}
}

void izbaci (int matrica[100][100], int sirina, int visina, int rb_k){	/*Posebna funkcija za izbacivanje kolone */
	int i,j,x;
	for(i=0;i<visina;i++){
		if(rb_k==sirina-1) break;
		for(j=rb_k;j<sirina;j++){
			if(j+1!=sirina){
				x=matrica[i][j+1];
				matrica[i][j+1]=matrica[i][j];
				matrica[i][j]=x;
			}
		}
	}
}

int izbaci_kolone (int matrica[100][100], int visina, int sirina, int n){
	int i,j;
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			if(matrica[i][j]==n){
				if(j!=sirina-1){
					izbaci(matrica,sirina,visina,j);
					sirina--;
					j--;
				}
				if(j==sirina-1) sirina--;
			}
		}
	}
	return sirina;
	}	
int main() {
	int matrica[100][100],visina,i,j,sirina,k;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sirina,&visina);
	for(i=0;i<visina;i++){
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0;j<sirina;j++){
			scanf("%d",&matrica[i][j]);
		}
	}
	k=0;
	int n;
	while(1){
		n=max(matrica,visina,sirina);
		sirina=izbaci_kolone(matrica,visina,sirina,n);
		if(sirina==0){
			printf("\nNakon %d. prolaza matrica je prazna!",k+1);
			break;
		}
		else printf("\nNakon %d. prolaza matrica glasi: \n",k+1);
		for(i=0;i<visina;i++){
			for(j=0;j<sirina;j++){
				printf("%5d",matrica[i][j]);
			}
			printf("\n");
		}
		k++;
	}
	return 0;
}
