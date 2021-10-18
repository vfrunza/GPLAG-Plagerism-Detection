#include <stdio.h>


int mat[200][200] = {{0}};
int main() {
	int  i, j, z, p, M, N, k, brojac = 0, brojac2 = 0;
	
	printf( "Unesite brojeve M i N: " );
	do{
		scanf( "%d %d", &M, &N );
		  if ( M > 200 || N > 200 || N <= 0 || M <= 0) {                        /*Dimenzije matrice*/
			printf( "Brojevi nisu u trazenom opsegu.\n" );
			printf( "Unesite brojeve M i N: " );		}
   } while ( M > 200 || N > 200 || M <= 0 || N <= 0 );

   printf( "Unesite elemente matrice: " );
            
   for ( i = 0; i < M; i++ ) {                               
   		for( j = 0; j < N; j++ ){
  	        scanf( "%d", &mat[i][j] );
    	}
   }
  
  for( i = 0; i < M-1; i++ ){                                                   /*Uporedjuje i izbacuje iste kolone*/
  	    for( j = i+1;  j < M;  j++ ) {
  	      brojac=0;
  	      for( k = 0; k < N; k++ ){                          
  			 if ( mat[i][k] == mat[j][k] ) { 
  			  	brojac++;
  			    }
  	}
  	         if ( brojac == N ) {                            
  		    	for( p = j; p < M-1; p++){              
  	    		    for( z = 0; z < N; z++ ){                
  		               mat[p][z] = mat[p+1][z];
  			 	}  	
  		   }
  		    	j--;                                         
  		        M--;
  	   	}
    }
}

  
  for( i = 0; i < N-1; i++ ){                                                   /*Uporedjuje i izbaca iste redove*/
  	for( j = i+1; j < N; j++){
  		brojac2 = 0;
  	 	for( k = 0; k < M; k++){
  			if ( mat[k][i] == mat[k][j] ) {
            brojac2++;
  	     	}
  			
      }
  			if ( brojac2 == M ) {
  		    	for( k = j; k < N-1; k++ ){
  			      	for( z = 0; z < M; z++){
  		                mat[z][k] = mat[z][k+1];
  		           }
  		       }
           	       j--;
  		  	       N--;
        	}
       }
}
  
 printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
 
  for( i = 0; i < M; i++ ){                                                     /*Ispis nove matrice*/
  	 for( j = 0; j < N; j++){
  	 	printf( "%5d",  mat[i][j] );
  	 }
      	printf("\n");
  }
  
	return 0;
}
