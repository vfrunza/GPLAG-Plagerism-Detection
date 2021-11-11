#include <stdio.h>

int main() {
	int i,j,x,y,a,b,br_redova,br_kolona,k,mat[200][200];
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &br_redova, &br_kolona);
		
		if(br_kolona<1 || br_kolona>200 || br_redova<1 || br_redova>200)
		  printf("Brojevi nisu u trazenom opsegu.\n");
	} while(br_kolona<1 || br_kolona>200 || br_redova<1 || br_redova>200);
	printf("Unesite elemente matrice: ");
	
	for(i=0; i<br_redova; i++){
	   for(j=0; j<br_kolona; j++){
	   	 scanf("%d", &mat[i][j]);
	   }
	}
	
	/*pronalazenje i izbacivanje redova koji se ponavljaju*/
	for(i=0; i<br_redova; i++){
	   for(x=i+1; x<br_redova; x++){
	   	k=0;
	   	if(x==i)
	   	continue;
	   	 for(j=0; j<br_kolona; j++){
	   	 	if(mat[i][j]==mat[x][j]){
	   	 		k++;
	   	 	}
	   	 }
	   	 
	   	 if(k==j){
	   	 	for(a=x; a<br_redova; a++){
	   	 		for(b=0; b<br_kolona; b++){
	   	 			mat[a][b]=mat[a+1][b];
	   	 		}
	   	 	}
	   	 br_redova--;
	   	 x--;
	   	 }
	   }
	}
	
	/*pronalazenje i izbacivanje kolona koje se ponavljaju*/
	for(j=0; j<br_kolona; j++){
		for(y=j+1; y<br_kolona; y++){
			k=0;
			if(y==j)
			continue;
			for(i=0; i<br_redova; i++){
				if(mat[i][j]==mat[i][y]){
				k++;
				}
			}
			if(k==i){
				
				for(a=0; a<br_redova; a++){
					for(b=y; b<br_kolona; b++){
						mat[a][b]=mat[a][b+1];
					}
				}
				br_kolona--;
				y--;
				
			}
		}
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	   for(i=0; i<br_redova; i++){
	   	for(j=0; j<br_kolona; j++){
	   		printf("%5d", mat[i][j]);
	   	}
	   	printf("\n");
	   	}
	return 0;
}
	



