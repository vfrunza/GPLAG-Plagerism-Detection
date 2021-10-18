#include <stdio.h>
#include <math.h>

int main() {
	int A[100][100],B[100][100],C[100][100],BrojacA=0,BrojacB=0,BrojacC=0,max=0,ponavljanje=0,max2=0,max3=0,ponavljanje2=0,ponavljanje3=0,suma=0;
	int M,N,temp=0,i,j,AB=0,CB=0,BB=0,s,l,sumaA=0,sumaB=0,sumaC=0;
	do{
	printf("Unesite brojeve M i N: ");
	scanf ("%d",&M);
	scanf ("%d",&N);}while(M<0 || M>100 || N<0 || N>100 ) ;
	printf ("Unesite clanove matrice A: ");
	 for (i=0;i<M;i++){ 
	 	for (j=0;j<N;j++){
	 	scanf ("%d",&A[i][j]);
	 } }
	 	printf ("Unesite clanove matrice B: ");
	 for (i=0;i<M;i++){ for (j=0;j<N;j++){
	 	scanf ("%d",&B[i][j]);
	 } }
	 	printf ("Unesite clanove matrice C: ");
	 for (i=0;i<M;i++){ for (j=0;j<N;j++){
	 	scanf ("%d",&C[i][j]);
	 } }
	 for (l=0;l<M;l++){
	     for (s=0;s<N;s++){
	 max=A[l][s];
	 max2=B[l][s];
	 max3=C[l][s];
     AB=A[l][s];
     AB=B[l][s];
     AB=C[l][s];
	 for (i=0;i<M;i++){
	 	for (j=0;j<N;j++){
	 	if (A[i][j]>max ){max=A[i][j];}
	 	if (B[i][j]>max2 ){max2=B[i][j];}
	 	if (C[i][j]>max3 ){max3=C[i][j];}
	 	if (A[i][j]==AB){ponavljanje++;}
	 	if (B[i][j]==AB){ponavljanje2++;}
	 	if (C[i][j]==AB){ponavljanje3++;}
	 	sumaB=B[i][j]+sumaB;
	 	sumaA=A[i][j]+sumaA;
	 	sumaC=C[i][j]+sumaC;
	 	}}}}
	 	if (max==max2 && max2==max3 && ponavljanje==ponavljanje2 && ponavljanje2==ponavljanje3 && sumaA==sumaB && sumaC==sumaB){printf ("DA\n");}
	 	else printf("NE\n");
	 //printf ("max %d\n max2 %d\n max3 %d\n ponavljanje %d\n ponavljanje2 %d\n ponavljanje3 %d\n suma %d %d %d\n",max,max2,max3,ponavljanje,ponavljanje2,ponavljanje3,sumaA,sumaB,sumaC);
	return 0;
}
