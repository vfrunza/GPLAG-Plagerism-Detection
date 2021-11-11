#include <stdio.h>

int main() {
	int niz[200][200],i,j,l,m,M,N;
	int broj=0,x,y;
	do{
	    printf("Unesite brojeve M i N: ");
	    scanf("%d %d",&M,&N);
	    if(M>200 || M<=0 || N<=0 || N>200) 
	    	printf("Brojevi nisu u trazenom opsegu.\n");
	}while(M>200 || N>200 || M<=0 || N<=0);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
	    for(j=0;j<N;j++){
	        scanf("%d",&niz[i][j]);
	    }
	}
	
   
  
    for(x=0;x<M;x++){
    	for(i=1;i<M;i++){
    		for(j=0;j<N;j++){
    			if(j==0)
	    			broj=0;
    			if(niz[x][j]==niz[i][j] && x<i)
    				broj++;
    			if(broj==N){
		    		for(l=i;l<M-1;l++){
		    			for(m=0;m<N;m++){
		    				niz[l][m]=niz[l+1][m];
		    			}
		    		}
		    		i--;
			    	M--;
		    	}
    		}
    	}
    }
    	
	 for(y=0;y<N;y++){
	 	for(j=0;j<N;j++){
	 		for(i=0;i<M;i++){
	 			if(i==0)
			 		broj=0;
	 			if(niz[i][y]==niz[i][j] && y<j)
		 			broj++;
	 			if(broj==M){
	    			for(m=j;m<N-1;m++){
	    				for(l=0;l<M;l++){
	    					niz[l][m]=niz[l][m+1];
	    				}
	    			}
	    			j--;
	    			N--;
	    			}
	    		}
	 		}
	 	}
    	
    	
    printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<M;i++){
	    for(j=0;j<N;j++){
		     printf("%5d",niz[i][j]);
	       
	    }
	    printf("\n");
	}
	
	
	return 0;
}