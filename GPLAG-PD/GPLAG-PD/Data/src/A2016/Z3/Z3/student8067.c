#include <stdio.h>

int main() {
	int M,N,Mat[200][200],i,j,k,brojac=0,l,L,brojac2=0;
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
		if(M<0||N<0||M>200||N>200) printf("Brojevi nisu u trazenom opsegu.\n");
	} while(M<0||N<0||M>200||N>200);
	if(M>0&&M<=200||N>0||N<=200) {
		printf("Unesite elemente matrice: ");
		for(i=0;i<M;i++) {
			for(j=0;j<N;j++) {
					scanf("%d",&Mat[i][j]);
				 
			}
			
		}
		/*izbacivanje redova*/
		i=0;
		do {
			for(j=i+1;j<M;j++) {
				for(k=0;k<N;k++) {
					if(Mat[i][j]==Mat[j][k]) brojac++;
					if(brojac==N) {
						for(l=j;l<M-1;l++) {
							for(L=0;L<N;L++) {
								Mat[l][L]=Mat[l+1][L];
							}
						}
						j--;
						M--;
					}
				}
				brojac=0;
			}
			i++;
		} while(i<M);
		/*kolona*/
		j=0;
			do {
			for(i=j+1;i<M;i++) {
				for(k=0;k<N;k++) {
					if(Mat[i][j]==Mat[i][k]) brojac2++;
					if(brojac==M) {
						for(l=j;l<M-1;l++) {
							for(L=0;L<N;L++) {
								Mat[l][L]=Mat[l][L+1];
							}
						}
						i--;
						N--;
					}
				}
				brojac2=0;
			}
			j++;
		} while(i<N);
		
		printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
		for(i=0;i<M;i++) {
			for(j=0;j<N;j++) {
				printf("%5d",Mat[i][j]);
				
				
			}
			printf("\n");
		}
		
		
	}
	return 0;
}
