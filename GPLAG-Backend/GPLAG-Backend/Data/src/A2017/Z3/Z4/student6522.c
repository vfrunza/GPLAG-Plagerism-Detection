#include <stdio.h>
#include <stdlib.h>

int max(int matrica[100][100], int visina, int sirina){
	int i,j,clanovimatrice[10000]={0},k=0,maksi=0,temp,brojac=1,maxbrojac=1,maxbroj;
	for(i=0; i<visina; i++){
		for(j=0; j<sirina; j++){
			clanovimatrice[k]=matrica[i][j];
			k++;
		}
	} /*Nakon sto smo unijeli elemente matrice u jedan niz(da bismo lakse posmatrali), sada cemo taj niz sortirati, tako da na prvom mjestu bude maksimalan broj */
	for(i=0; i<(k-1); i++){
		maksi=i;
		for(j=i+1; j<k; j++){
			if(clanovimatrice[maksi]<clanovimatrice[j])
			maksi=j;
		}
		if(maksi!=i){
			temp=clanovimatrice[i];
			clanovimatrice[i]=clanovimatrice[maksi];
			clanovimatrice[maksi]=temp;
		}
	} /*Postavimo da je prvi clan maksimalan i pamtimo njegovu vrijednost u varijabli maxbroj.U petlji postavljamo uslov da se brojac povecava, sve dok je trenutni jednak
	prethodnom. Kada to nije slucaj, onda maksbrojac pamti dotadasnju vrijednost brojaca,jer se brojac mora postaviti na 1 */
	maxbroj=clanovimatrice[0];
	for(i=1; i<=k; i++){
		if(clanovimatrice[i]==clanovimatrice[i-1]) {
		brojac++;
		if((brojac>maxbrojac) && (clanovimatrice[i]<maxbroj)){
			maxbrojac=brojac;
			maxbroj=clanovimatrice[i];
		}
		}
		else {
			if(brojac>=maxbrojac){
				maxbrojac=brojac;
				maxbroj=clanovimatrice[i-1];
				brojac=1;
		}
		}
    }
    return maxbroj;
}
int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N){
	int i,j,k,t,izbacena=-1;
	for(i=0; i<visina; i++){
		for(j=0; j<sirina; j++){
			if(matrica[i][j]==N) {
			izbacena=j;
			break;
			}
		}
		if(izbacena==-1) continue;
		else {
	for(k=izbacena; k<sirina-1; k++){
		for(t=i; t<visina; t++){
			matrica[t][k]=matrica[t][k+1];
			}
		}
		sirina--;
		izbacena=-1;
		}
	}
	return sirina;
}

int main() {
	int A[100][100], visina, sirina, i,j,a;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d%d", &sirina, &visina);
	for(i=0; i<visina; i++){
		a=i+1;
		printf("Unesite elemente %d. reda: ", a);
		for(j=0; j<sirina; j++){
			scanf("%d", &A[i][j]);
		}
	}
	int kolona = sirina;
	int prolaz=1;
	int N;
	while(kolona >0){
		 N=max(A,visina,kolona);
		 kolona=izbaci_kolone(A,visina,kolona,N);
		 if(kolona==0) {
		 	printf("\nNakon %d. prolaza matrica je prazna!", prolaz);
		 	break;
		 }
		 	printf("\nNakon %d. prolaza matrica glasi:\n", prolaz);
		 	for(i=0; i<visina; i++){
		 	for(j=0; j<kolona; j++){
		 		printf("%5d", A[i][j]);
		 	} 
		 	printf("\n");
		 	}
		 prolaz++;
	}	 
	return 0;
}
