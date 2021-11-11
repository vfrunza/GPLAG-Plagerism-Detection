#include <stdio.h>

int main() {
	int M,N,mat[200][200],i,j,k,l,pret;
	/*Provjeravamo da li su M i N prirodni brojevi i da li su manji od 200.
	Ako nisu, ispisuje se poruka da brojevi nisu u trazenom opsegu i korisnik ponovo unosi dimenzije matrice*/
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d",&M,&N);
	if(M>200 ||M<=0 || N>200 || N<=0) printf("Brojevi nisu u trazenom opsegu.\n");
	}
	while(M>200 || M<=0 || N>200 || N<=0);
	/* Unos matrice */
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d", &mat[i][j]);
		}
	}
	
    /*Poredimo i-ti i k-ti red matrice.*/
   	for(i=0;i<M;i++){
		for(k=i+1;k<M;k++){
           pret=1; 
			for(j=0;j<N;j++){ 
				if(mat[i][j]!=mat[k][j])
				pret=0; 
			}
	/*Ukoliko su redovi isti, znaci da se red ponavlja i treba ga izbaciti */		
	       if(pret==1){
	         for(l=k;l<M-1;l++){
		       for(j=0;j<N;j++){
			     mat[l][j]=mat[l+1][j];
		       }
	          }
	          M--;
	          k--;
	       }
	    }
	}
			
	/*Analogno kao sa redovima, postupak se ponavlja sa kolonama */
	for(j=0;j<N;j++){
		for(k=j+1;k<N;k++){
			pret=1;
			for(i=0;i<M;i++){
				if(mat[i][j]!=mat[i][k])
				pret=0;
			}
				if(pret==1){
					for(l=k;l<N-1;l++){
						for(i=0;i<M;i++){
							mat[i][l]=mat[i][l+1];
						}
						
					}
					N--;
				    k--;
				}
				
		}
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			printf("%5d",mat[i][j]);
		}
		printf("\n");
	}
	
	
	
	return 0;
}
