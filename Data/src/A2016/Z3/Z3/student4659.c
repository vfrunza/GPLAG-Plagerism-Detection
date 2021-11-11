#include <stdio.h>
int main() {
	int mat[200][200]={{0}}, M, N, i, j, br=0, red, p, k, z, temp, kol;
	
	/*Unos formata matrice*/
	
	do{
		printf("Unesite brojeve M i N: ");
	    scanf("%d %d", &M, &N);
	    if(M>200 || M<=0 || N>200 || N<=0) printf("Brojevi nisu u trazenom opsegu.\n");
	}while(M>200 || M<=0 || N>200 || N<=0);
	
	/*unos elemenata matrice*/
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d", &mat[i][j]);
		}
	}
   
 
    /*izbacuje iste redove iz matrice*/

for(z=0;z<M;z++){ 
    for(i=z+1;i<M;i++){
    	br=0;
    	for(j=0;j<N;j++){
    		if(mat[z][j]==mat[i][j])br++;
    		if(br==N){
    			red=i;
    			for(k=red;k<M;k++){
    				for(p=0;p<N;p++){
    					temp=mat[k][p];
    					mat[k][p]=mat[k+1][p];
    					mat[k+1][p]=temp;
    				}
    		    }
    		M--;
    		i--;	
    		}
    	}
    }
}		
   
    /*izbacuje iste kolone iz matrice*/
    
for(j=0;j<N;j++){ 
    for(i=j+1;i<N;i++){
    	br=0;
    	for(z=0;z<M;z++){
    		if(mat[z][j]==mat[z][i])br++;
    		if(br==M){
    			kol=i;
    			for(k=0;k<M;k++){
    				for(p=kol;p<N;p++){
    					temp=mat[k][p];
    					mat[k][p]=mat[k][p+1];
    					mat[k][p+1]=temp;
    				}
    		    }
    		N--;
    		i--;	
    		}
    	}
    }
}		
   
	/*ispis matrice*/
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			printf("%5d", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
