#include <stdio.h>
#include <stdlib.h>

int max (int matrica[100][100], int visina, int sirina){
	int temp, i, j, pozitivni[10000], negativni[10000], maxp, maxn, indexn=0, indexp=0;
	
	for(i=0; i<10000; i++){
		pozitivni[i]=0;
		negativni[i]=0;
	}
	
	for(i=0; i<visina; i++){
		for(j=0; j<sirina; j++){
			if(matrica[i][j]<0){
				temp=abs(matrica[i][j]);
				negativni[temp]++;
			}
			else if(matrica[i][j]>=0){
				pozitivni[matrica[i][j]]++;
			}
		}
	}
	
	for(i=0; i<10000; i++){
		negativni[i]=abs(negativni[i]);
	}
	
	maxn=negativni[0];
	maxp=pozitivni[0];
	indexp=0;
	indexn=0;
	
	for(i=0; i<10000; i++){
		if(negativni[i]>maxn){
			maxn=negativni[i];
			indexn=i;
		}
	}
	
	for(i=0; i<visina*sirina; i++){
		if(pozitivni[i]>maxp){
			/* i je vrijednost */
			/* pozitivni[i] su kolicina*/ 
			maxp=pozitivni[i];
			indexp=i;
		}
	}
	
	if(indexp>=indexn){
		return indexp;
	}
	
	else if(indexn>indexp){
		indexn=-indexn;
		return indexn;
	}
	return 29;
}

int izbaci_kolone(int mat[100][100], int visina, int sirina, int n){
	int i, j, k, l;
	
	for(i=0; i<visina; i++){
		for(j=0; j<sirina; j++){
			if(mat[i][j]==n){
				for(k=0; k<visina; k++){
					for(l=j; l<sirina; l++){
						mat[k][l]=mat[k][l+1];
					}
					l--;
				}
				sirina--;
			}
		}
	}
	
	return sirina;
}




int main() {
	int v, s, mat[100][100], i, j, k=0, test, m;
	
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &s, &v);
	
	for(i=0; i<v; i++){
		printf("Unesite elemente %d. reda: ", i+1);
		for(j=0; j<s; j++){
			scanf("%d", &mat[i][j]);
		}
	}
	test=s;
	
	do{
		printf("\nNakon %d. prolaza matrica glasi:\n", k+1);
		m=max(mat, v, test);
		test=izbaci_kolone(mat, v, test, m);
		for(i=0; i<v; i++){
			for(j=0; j<test; j++){
				printf("%5d", mat[i][j]);
			}
			printf("\n");
		}
		k++;
	} while(test!=1);
	
	printf("\nNakon %d. prolaza matrica je prazna!", k+1);
	
	return 0;
}
