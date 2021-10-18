#include <stdio.h>

int max (int mat[100][100], int visina, int sirina) {
	int pom[1000]={0};
	int i, j, maxe, k;
	for (i=0; i< visina; i++) {
		for (j=0; j<sirina; j++) {
			pom[mat[i][j]]++;
		}
	}
	maxe=pom[0];
	for (i=0; i<1000; i++) {
		if (pom[i]>maxe) {
			maxe=pom[i];
			k=i;
		}
	}
	return k;
}
 int izbaci_kolone (int mat[100][100], int visina, int sirina,  int N) {
 	int i,j, k, m ,n;
 	for (i=0; i<sirina; i++) {
 		for (j=0; j<visina; j++) {
 			if (mat[j][i]==N) {
 				k=i;
 				for (m=k; m<sirina-1; m++) {
 					for (n=0; n<visina; n++) {
 						mat[n][m]=mat[n][m+1];
 					}
 					sirina--;
 		
 				}
 			}
 		}
 	}
 	
 	return sirina;
 }

int main() {
	int i, j, maxe, v=3, s=4, mat[100][100];
	for (i=0; i<v; i++) {
		for (j=0; j<s; j++) {
			scanf ("%d", &mat[i][j]);
		}
	}
	maxe=max (mat, v,s);
	printf ("%d", maxe);
	return 0;
}
