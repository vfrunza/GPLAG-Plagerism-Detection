#include <stdio.h>
int max(int matrica[100][100], int visina, int sirina){
	int i,j,k=0,niz[100],brojac;
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			niz[k]=mat[i][j];
			k++;
		}
	}
	for(i=0;i<k;i++){
		brojac=0;
		for(j=0;j<k;j++){
			if(niz[i]==niz[j])brojac++;
			
		}
		
}
int main() {
	printf("Zadaća 3, Zadatak 4");
	return 0;
}
