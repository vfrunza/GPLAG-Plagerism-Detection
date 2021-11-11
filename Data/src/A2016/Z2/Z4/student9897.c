#include <stdio.h>

int main() {
    
    double mat[100][100]; 
    int M,N, i,j; 
    int pretp=1; 
    int pretp1=1; 
	
    for (;;) {
	printf ("Unesite M i N: ");
	do {
	scanf ("%d%d", &M,&N); 
	}    while ((M<0 || M>100) && (N<0 || N>100)); 
	
	 if (M>0 && M<=100 && N>0 && N<=100)  break; 
	 printf ("Pogresan unos!\n"); 
}
	printf ("Unesite elemente matrice: "); 
	for (i=0; i<M; i++) {
	    for (j=0; j<N; j++) {
	        scanf ("%lf", &mat[i][j]); 
	    }
	}
   if (M==1 && N>1) printf ("Matrica je cirkularna"); 
   else if (N==1 && M>1) printf ("Matrica je Teplicova"); 
   else {
	for (i=1; i<M; i++) {
	    for (j=1; j<N; j++) { 
	         if (mat[i][j]!=mat[i-1][j-1]) {
	         	pretp=0; 
	         	break; 
	         }
	         	
	   }
	}
	
	
     if (pretp) { 
     	for (i=1; i<M; i++) {
     		for (j=1; j<N; j++) {
     			if (mat[0][i]!=mat[M-i][0]) {
     				pretp1=0; 
     				break; 
     			}
     		}
     	}
     	if (pretp1) printf ("Matrica je cirkularna"); 
     	
     	else printf ("Matrica je Teplicova"); 
     	 
     }
     
	else printf ("Matrica nije ni cirkularna ni Teplicova"); 
   }
	return 0;
}