#include <stdio.h>
int main() {
    int M, N, jednaki, brojac_reda=0, brojac_kolone=0;
	int i, j, z, mat[200][200];
	do{
		/*provjerava ispravnost unesenih dimenzija*/
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		if(M<0 || M>200 || N<0 || N>200) 
		printf("Brojevi nisu u trazenom opsegu.\n");
	}while(M<0 || M>200 || N<0 || N>200);

	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++)
	   for(j=0; j<N; j++)
	   scanf("%d", &mat[i][j]);	
	
	/*poredi redove matrice i brise sve osim prvog reda odozgo*/
	for(i=0; i<M; i++)   
		for(j=i+1; j<N; j++){
	   		if (mat[i][0] == mat[j][0]){
	      		jednaki=1;
                for(z=0; z<N; z++)
              		if(mat[i][z] != mat[j][z]) jednaki=0;
	            if(jednaki==1){  
         	 		
         			int k,l;
              		for (k=j; k<M; k++)
	          		for (l=0; l<N; l++)
	          			mat[k][l]=mat[k+1][l];
         	  		brojac_reda++;
         	  		j--;
	     	  		M--;
	   	        }   
	        }
        }
    
    /*poredi kolone matrice i brise sve osim prve sa lijeve strane*/
    for(i=0; i<M; i++)   
		for(j=i+1; j<N; j++){
		    if (mat[0][i]==mat[0][j]){
		     	jednaki=1;
		 	    for(z=0; z<M; z++)
		           if(mat[z][i] != mat[z][j]) jednaki=0;
	            if(jednaki==1){
         	        
         	        int k,l;
              		for (k=0; k<N; k++)
	          		for (l=j; l<M; l++)
	        	 		mat[l][k]=mat[l][k+1];
        	 		brojac_kolone++;
	    	  	    i--;
			   	    N--;
	   	        }   
	        }
        }
    
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0; i<M; i++){
	   for(j=0; j<N; j++)
		   printf("%5d", mat[i][j]);
    	printf("\n");
	}   
	return 0;
}
