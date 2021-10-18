#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina){
	int i,j,maxPonavljanja=0,temp[100000]={0},temp_negativni[100000]={0}; /*pretpostavljamo da nece biti vise od 100000*/
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			if(matrica[i][j]<0)
			    temp_negativni[matrica[i][j]*-1]++;
			else
			    temp[matrica[i][j]]++;
		}
	}
	for(i=0;i<100000;i++){
		if(temp_negativni[i]>temp[maxPonavljanja]) maxPonavljanja=-i; 
		if(temp[i]>temp[maxPonavljanja]) maxPonavljanja=i;
		
	}
	return maxPonavljanja;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N){
	int i,j,k,l, nova_sirina=sirina;
	for(i=0; i<visina; i++){
		for(j=0; j<nova_sirina; j++){
			/*ako smo pronasli taj broj*/
			if(matrica[i][j]==N){
				/*brisemo svaku kolonu osim zadnje jer ako je zadnja kolona tad samo smanjujemo sirinu matrice*/
				if(j!=nova_sirina-1){
				    for(k=0;k<visina;k++){
					    for(l=j; l<nova_sirina-1; l++){
						    matrica[k][l]=matrica[k][l+1];
					    }
				    }
				    j--;
				}
				nova_sirina--;
			}
		}
	}
	
	return nova_sirina;
}
int main() {
	int mat[100][100]={{0}};
	int i,j,k,l,s,v,brojac=0;
	
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &s, &v);
	
	for(i=0;i<v;i++){
		printf("Unesite elemente %d. reda: ", i+1);
		for(j=0;j<s;j++){
			scanf("%d", &mat[i][j]);
		}
	}
	
	do{
		s=izbaci_kolone(mat,v,s,max(mat,v,s));
		brojac++;
		if(s==0){
			printf("\nNakon %d. prolaza matrica je prazna!", brojac);
			break;
		}
		printf("\nNakon %d. prolaza matrica glasi:\n",brojac);
		for(k=0;k<v;k++){
			for(l=0;l<s;l++){
				printf("%5d", mat[k][l]);
			}
			printf("\n");
		}
	}while(s!=0);
	
	return 0;
}
