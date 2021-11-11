#include <stdio.h>
#include <stdlib.h>

int izbaci ( int niz[], int vel ){
	int i, fniz[10000] = {0}, j, m, k, maxint;
	
	fniz[0] = 1;
	fniz[1] = 1;
	maxint = 46;                                                    
	
	for( i = 2; i < maxint; i++ ) {                                 /*Fibonacijev niz*/
		fniz[i] = fniz[i-1] + fniz[i-2];                           
	}
		m = vel;
		for( i = 0; i < maxint; i++ ) {                             
			for( j = 0; j < m; j++ ) {                              
			  if ( niz[j] == fniz[i] ) {                            
				for( k = j; k < m-1; k++ ) {                        
				   niz[k] = niz[k+1];                               /*Izbacivanje iz niza*/
				} 
			       m--;                                             
				   j--;
			}
		}
	}
	return m;                                                     
}

void ubaci ( int niz[], int vel ) { 
	int i, scifre=0, zin, ab, c;
	zin = vel-1;                                                   
	do{
		niz[zin*2] = niz[zin];                                     
		zin--;
	} while ( zin >= 0 );
	
       for( i = 0; i < vel*2; i++ ) {                            
		   ab = abs( niz[i] );
		   if ( i%2 == 0 ) {                                       
			 do{                                                   /*Suma cifara*/
				  c = ab%10;
			      scifre = scifre+c;
			      ab = ab/10;
			} while ( ab != 0);
			 niz[i+1] = scifre;                                    
	     }
		    scifre = 0;                                           
	       	i++;
	}
}


int main() {
	
	int i, niz[100] = {0}, test;
	printf("Unesite niz od 10 brojeva: ");
	
	for ( i = 0; i < 10; i++ ) {                                   
	  scanf("%d", &niz[i]);
	}
	  ubaci( niz, 10 );
	  test=izbaci( niz, 20 );                                      /*Pozvane obje funkcije*/
      printf("Modificirani niz glasi: ");
     for( i = 0; i < test; i++) {                                  /*Ispisivanjen niza*/
		 if (i == test-1 ) { 
			 printf("%d.", niz[i]);
	          } else {
		      printf("%d, ", niz[i]);
	        }
	  }
	return 0;
}
