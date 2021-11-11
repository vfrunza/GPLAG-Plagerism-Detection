#include <stdio.h>
int main() {
	double a[200][200];
	int i,j,M,N,k,r;
	
	//unos matrice proizvoljnih dimenzija MxN
	do{
	    printf("Unesite brojeve M i N: "); 
	    
	    scanf("%d %d",&M,&N);
	     if(M>200 || N>200||N<1||M<1) 
	     printf("Brojevi nisu u trazenom opsegu.\n");
	    
	}
	while(M>200 || N>200||N<1||M<1);
	printf("Unesite elemente matrice: ");
	
	// izbacivanje redova i kolona iz matrice koji se ponavljaju
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%lf",&a[i][j]);
		}
	}
	
	 for(i=0;i<M;i++){
	     for(j=i+1;j<M;j++){
	         for(k=0;k<N;k++){
	             if(a[i][k]!=a[j][k])
	             break;
	         }
	         
	         
	         if(k==N) {
	             for(r=j;r<M-1;r++){
	                 for(k=0;k<N;k++){
	                     a[r][k]=a[r+1][k];
	                 }
	               
	             }
	             M--;
	             i--;
	             break;
	         }
	     }
	 }
	 
	 for(i=0;i<N;i++) {
	     for(j=i+1;j<N;j++){
	         for(k=0;k<M;k++){
	             if(a[k][i]!=a[k][j])
	             break;
	         }
	     
	         
	         if(k==M) {
	             for(r=j;r<N-1;r++){
	                 for(k=0;k<M;k++){
	                     a[k][r]=a[k][r+1];
	                 }
	                
	     }
	     N--;
	     i--;
	     break;
	 }
	     }
	 }
	//ispis promijenjene matrice
	    printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
         for (i=0; i<M; i++) {
         for (j=0; j<N; j++)
         printf("%5.0f", a[i][j]);
         printf("\n");
         }
         return 0;
         }