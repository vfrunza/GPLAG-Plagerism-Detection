#include <stdio.h>

int main()
{
	int matA[100][100],matB[100][100],matC[100][100],i,j,m,n,counter1=0,counter2=0,counter3=0;

	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m,&n);
	} while (m<0 || m>100 || n<0 || n>100 );
	
	printf ("Unesite clanove matrice A: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%d", &matA[i][j]) ;
		}
	}
	
	printf("Unesite clanove matrice B: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%d", &matB[i][j]) ;
			if(matB[i][j]==matA[i][j])
		}
	}
  
    printf("Unesite clanove matrice C: ");
    for(i=0; i<m; i++){
    	for(j=0; j<m; j++){
    	scanf("%d", &matC[i][j]) ;
    	counter3++;
    	}
    }
    
    
    
    


	return 0;
}
