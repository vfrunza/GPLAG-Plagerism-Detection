#include <stdio.h>
#define visina 200
#define sirina 200
int main() {
	int i=0,j=0,M=0,N=0,k=0,l=0,z=0,c=0,mat[visina][sirina],jednakost;
	
	do {
		printf ("Unesite brojeve M i N: ");
		scanf ("%d %d",&M,&N);
		if (N>200 || M>200 || N<1 || M<1) printf ("Brojevi nisu u trazenom opsegu.\n");
		else break;
	} while(1);
	
	printf("Unesite elemente matrice: ");
	for (i=0;i<M;i++){
 		for(j=0;j<N;j++){
			scanf("%d",&mat[i][j]);
		}
	}
	/* Provjera jednakosti redova i izbacivanje*/
	for(i=0;i<M;i++){
		for(k=i+1;k<M;k++){
			jednakost=1;
			for(j=0;j<N;j++){
				if(mat[i][j]!=mat[k][j])
				jednakost=0;
			}
			if(jednakost==1) {
				for(z=k+1;z<M;z++){
					for(j=0;j<N;j++){
						mat[z-1][j]=mat[z][j];
					}
				}
				M--;
				k--;
			}
			
		}
	}
	/*Provjera jednakosti kolona i izbacivanje*/
	for(j=0;j<N;j++){
		for(l=j+1;l<N;l++){
			jednakost=1;
				for(i=0;i<M;i++){
					if(mat[i][j]!=mat[i][l]) 
					jednakost=0;
				}
				if(jednakost==1) {
					for(c=l+1;c<N;c++){
						for(i=0;i<M;i++){
							mat[i][c-1]=mat[i][c];
						}
					}
				N--;
				l--;
				}
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++) {
			printf("%5d", mat[i][j]);
		}
			printf("\n");
	}
	return 0;
}
