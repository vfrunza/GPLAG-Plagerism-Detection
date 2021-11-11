#include <stdio.h>

 int main() {
 int prva_tac[20]={0},druga_tac[20]={0},mat[20][20],i,j,n;
 	printf ("Unesite broj tacaka: ");
 	scanf ("%d", &n);
 	while (n>10 || n<=0){
 		printf ("Pogresan unos");
 		printf ("\nUnesite broj tacaka: ");
 		scanf ("%d", &n);
 	}
 	for (i=0;i<n;i++){
 		printf ("Unesite %d. tacku: ",i+1);
 		scanf ("%d %d", &prva_tac[i], &druga_tac[i]);
 		while (prva_tac[i]<0 || prva_tac[i]>19 || druga_tac[i]<0 || druga_tac[i]>19){
 			printf ("Pogresan unos");
 			printf ("\nUnesite %d. tacku: ",i+1);
 			scanf ("%d %d", &prva_tac[i], &druga_tac[i]);
 		}
 	}
 	for (i=0;i<20;i++) {
 		for (j=0;j<20;j++){
 			mat[i][j]=0;
 		}
 	}
 	for (i=0;i<n;i++){
 		if (mat[druga_tac[i]][prva_tac[i]]==0)
 			mat[druga_tac[i]][prva_tac[i]]=1;
 		else continue;
 	}
 	for (i=0;i<20;i++){
 		for (j=0;j<20;j++){
 			if (mat[i][j]==1) printf ("*");
 			else if (mat[i][j]==0)
 				printf (" ");
 		}
 	printf ("\n");
 	}
 return 0;
 }
