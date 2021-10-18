#include <stdio.h>

int main()
{
	int M ,N ,i ,j ,k ,t = 1 ,M1 = 0 ,N1 = 0 , s = 0 ;
	int matrica[200][200];
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		if(M<=0 || M>200 || N<=0 || N>200)
			printf("Brojevi nisu u trazenom opsegu.\n");

	} while(M<=0 || M>200 || N<=0 || N>200) ;

	printf("Unesite elemente matrice: ");
	for(i=0 ; i<M ; i++) {
		for(j=0 ; j<N ; j++) {
			scanf("%d",&matrica[i][j]);
		}
	}


	M1 = M;
	for(i=0 ; i<M-1 ; i++) {
		for(k=i+1 ; k<M1 ; k++) {
			for (j=0 ; j<N ; j++) {
				if (matrica[i][j] != matrica[k][j]) {
					t = 0;
					break;
				}
			}
			if(t == 1) {
				for(s=k ; s<M1 ; s++) {
					for(j=0 ; j<N ; j++) {
						matrica[s][j]=matrica[s+1][j];
					}
				}
				M1--;
				k--;
			}
			t = 1;
		}

	}



	N1 = N;
	for(j=0 ; j<N-1 ; j++) {
		t=1;
		for(k=j+1 ; k<N1 ; k++) {
			for (i=0 ; i<M1 ; i++) {
				if (matrica[i][j] != matrica[i][k] ) {
					t = 0;
					break;
				}
			}
			if (t == 1) {
				for(s=k ; s<N1 ; s++) {
					for(i=0 ; i<M ; i++) {
						matrica[i][s]=matrica[i][s+1];

					}
				}
				N1--;
				k--;
			}
			t = 1;
		}

	}


	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0 ; i<M1 ; i++) {

		for(j=0 ; j<N1 ; j++) {

			printf("%5d", matrica[i][j]);
		}
		printf("\n");

	}

	return 0;
}
