#include <stdio.h>
#define M 100
#define N 100


int main() {

	int i,j,m,n,k,l,p,o,g,r;
	int trigger=0;
	int A[M][N],B[M][N],C[M][N];
	int brojacA=0,brojacB=0, brojacC=0;
   
	
  /*Unos brojeva M i N*/
  
  do {
  	printf("Unesite brojeve M i N: ");
  	scanf("%d", &m);
  	scanf("%d", &n);
  	
  } while(m>M || m<0 || n>N || n<0 );
  
  /*Unos matrice A*/
  
  printf("Unesite clanove matrice A: ");
  for(i=0; i<m; i++) {
      for(j=0; j<n; j++) {
          scanf("%d", &A[i][j]);
      }
  }
         /*Unos matrice B*/
          	printf("Unesite clanove matrice B: ");
          	for(i=0;i<m;i++) {
          	    for(j=0; j<n; j++) {
          	
          	scanf("%d", &B[i][j]);
          	    
          	}}
          	/*Unos matrice C*/
          	
          	printf("Unesite clanove matrice C: ");
          	for(i=0;i<m;i++) {
          	    for(j=0; j<n; j++) {
  	        scanf("%d", &C[i][j]);
      }
	} /*unos zavrsen*/
	

	  for(i=0; i<m; i++) {
		  for(j=0; j<n; j++){ /*Glavni kroz A*/
			  brojacA=0; brojacB=0; brojacC=0;
			  
			  for(k=0; k<m; k++){ /*Kroz A*/
				  for(l=0; l<n; l++){
					  if(A[k][l]==A[i][j]) brojacA++;
				  }
			  }
			  
			  for(g=0; g<m; g++){ /*Kroz B*/
				  for(r=0; r<n; r++){
					  if(B[g][r]==A[i][j]) brojacB++;
				  }
			  }
			  
			  for(o=0; o<m; o++){ /*Kroz C*/
				  for(p=0; p<n; p++){
					  if(C[o][p]==A[i][j]) brojacC++;
				  }
			  }
			  
			  if(brojacA!=brojacB || brojacA!=brojacC){trigger++;
			  	break;
			  }
		  }
		  if(trigger==1) break;
	  }
	  if(trigger==1) printf("NE\n"); else printf("DA\n");
	return 0;
}
