#include <stdio.h>

int main() {
	int sA,dA,sB,dB,A[10][10],B[10][10],C[10][10],D[10][10],temp=0,i,j,brojac=0,brojac2=0;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf ("%d",&sA);
	scanf ("%d",&dA);
	printf ("Unesite clanove matrice A: ");
	 for (i=0;i<dA;i++){
	 	for (j=0;j<sA;j++){
	 		scanf ("%d",&A[i][j]);}}
    printf("Unesite sirinu i visinu matrice B: ");
	scanf ("%d",&sB);
	scanf ("%d",&dB);
	printf ("Unesite clanove matrice B: ");
	 for (i=0;i<dB;i++){
	 	for (j=0;j<sB;j++){
	 		scanf ("%d",&B[i][j]);}}
	 		if (sA==dB && dA==sB){
   for (i=0;i<dB;i++){
   	for (j=0;j<sB;j++){
   		temp=A[j][i];
   		C[sA-1-i][dA-1-j]=temp;}}

   	  for (i=0;i<sB;i++){
    	for (j=0;j<dB;j++){
   		temp=C[j][i];
   		D[dB-1-1*j][i]=temp;}}
		for (i=0;i<sB;i++){
   		for (j=0;j<dB;j++){
   			if (B[j][i]==D[j][i]){brojac++;}
   			
   		}}
   		if (brojac==sA*dA || brojac==sB*dB ){printf ("DA\n");}
   		else printf ("NE\n"); } else printf ("NE\n");
   /*	for (i=0;i<3;i++){
   		for (j=0;j<3;j++){
   			printf (" %d ",C[i][j]);
   		} printf ("\n");
   	}*/
	return 0;
}
