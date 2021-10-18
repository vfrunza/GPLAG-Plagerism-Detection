#include <stdio.h>
#include <stdlib.h>
int br_ponavljanja(int matrica[100][100], int visina, int sirina, int broj){
	int brojac=0;
	int i,j;
	for(i=0; i<visina; i++){
		for(j=0; j<sirina; j++)
			if(matrica[i][j]==broj) brojac++;
	}
	return brojac;
}
int max(int matrica[100][100], int visina, int sirina){
	int br_pon=0,ponavljanje,pozi=0,pozj=0;
	int broj;
	int i,j;
	int najveci_broj, najveci_broj1;
	for(i=0; i<visina; i++){
		for(j=0; j<sirina; j++){
			broj=matrica[i][j];
			ponavljanje=br_ponavljanja(matrica,visina,sirina,broj);
			if(ponavljanje>br_pon){
				br_pon=ponavljanje;
				pozi=i;
				pozj=j;
				najveci_broj=matrica[pozi][pozj];
			}
			
		}
	}
	return najveci_broj;
}
int postoji_br(int matrica[100][100],int visina, int sirina, int N){
	int postoji=0, i,j;
	for(i=0; i<visina; i++){
		for(j=0; j<sirina; j++)
		if(matrica[i][j]==N) postoji=1;
	}
	return postoji;
}
int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N){
	int i,j,l,m;
	/*trazimo indeks kolone u kojoj se nalazi br koji treba izbaciti*/
	for(i=0; i<visina; i++){
		for(j=0; j<sirina; j++){
			if(postoji_br(matrica,visina,sirina,matrica[i][j])==1){
				for(m=i; m<visina; m++){
					for(l=j; l<sirina-1; l++)
						matrica[m][l]=matrica[m][l+1];
				}
			    sirina--;
	            j--;
				}
		}
	}
	return sirina+1;
}

int main() {
	int visina, sirina,i,j,najveci_el,nova_sirina;
	int matrica[100][100];
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d", &sirina);
	scanf("%d", &visina);
    for(i=0; i<visina; i++){
    	printf("Unesite elemente %d. reda: ", i+1);
    	for(j=0; j<sirina; j++){
    	scanf("%d", &matrica[i][j]);}
    }
    najveci_el=max(matrica,visina,sirina);
    	   
    	    for(i=0; i<visina; i++){
    	    	for(j=0; j<sirina; j++){
    	    		najveci_el=max(matrica,visina,sirina);
    	            nova_sirina=izbaci_kolone(matrica,visina,sirina,najveci_el);
    	    		if(j==nova_sirina-1) {
    	    		printf("\nNakon %d. prolaza matrica je prazna!", j+1);
    	    		return 0;
    	    		}
    	    		if(j!=nova_sirina-1) { 
    	    	printf("Nakon %d. prolaza matrica glasi: \n ", i+1);
    	    	   for(i=0; i<visina; i++){
    	    	   	for(j=0; j<nova_sirina; j++)
    	    		printf("%d ", matrica[i][j]);
                    printf("\n");}
    	    		}
    	    		
     	    }
    	printf("\n");
    }
	return 0;

}
