#include <stdio.h>

int max(int m[100][100],int visina,int sirina){
	int i,j, brojac=1, maxBrojac=0, maxElement,poredjenje,k=0,niz[10000];
	/*prepisivanje matrice u niz*/
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
		niz[k++]=m[i][j];
		}
	}
	/*trazenje clana koji se ponavlja najvise puta*/
	maxElement=niz[0];
	for(j=0;j<k;j++){
		poredjenje=niz[j];
		for(i=j+1;i<k;i++){
			if(poredjenje!=niz[i]) {
				continue;
			}
			if(poredjenje==niz[i]) {
				brojac++;
			}
		}
		if(maxBrojac==brojac){
			if(poredjenje<maxElement)
			maxElement=poredjenje;
		}
		else if(brojac>maxBrojac) {
			maxBrojac=brojac;
			maxElement=poredjenje;
		}
		
		brojac=1;
	}
	return maxElement;
	
}
int izbaci_kolone(int mat[100][100],int visina,int brkolona,int maxElement){
	int i,j,k,l,temp;
	/*trazenje kolone sa maxElementom i njeno izbacivanje*/ 
	for(i=0;i<visina;i++){
		for(j=0;j<brkolona;j++){
			if(mat[i][j]==maxElement){
				for(k=j;k<brkolona;k++){
					for(l=0;l<visina;l++){
						temp=mat[l][k];
						mat[l][k]=mat[l][k+1];
						mat[l][k+1]=temp;
					}
					
				}
				brkolona--;
				j--;
			}
		}
	}
	return brkolona;
}

int main() {
	int niz[100][100];
	int i,j,sirina,visina,brkolona,k;
	printf ("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sirina,&visina);
	for(i=0;i<visina;i++){
		printf("Unesite elemente %d. reda: ", i+1);
		for(j=0;j<sirina;j++){
		scanf("%d",&niz[i][j]);
		
		}
	}

	k=1;
	brkolona=sirina;
	/*pozivanje funkcije sve dok matrica ne ostane prazna*/
	while(brkolona!=0){
    	brkolona=izbaci_kolone(niz,visina,brkolona,max(niz,visina,brkolona));
		if(brkolona==0) break;
		printf("\nNakon %d. prolaza matrica glasi:\n",k);
		k++;
		for(i=0;i<visina;i++){
			for(j=0;j<brkolona;j++){
				printf(" %4d",niz[i][j]);
			}
			printf("\n");
		}
	
	}
		printf("\nNakon %d. prolaza matrica je prazna!",k);
	
	return 0;
}
