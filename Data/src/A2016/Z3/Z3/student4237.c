#include <stdio.h>
#define B 200

int main() {
	int M,N;
	int mat[B][B];
	int i1, i2, i3, i4, i5;
	int pomocni_b=0;
	
	do{
		printf("\nUnesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		if(M>200 || M<=0 || N>200 || N<=0)
			printf("Brojevi nisu u trazenom opsegu.");
		
	}while(M>200 || M<=0 || N>200 || N<=0);
	
	printf("Unesite elemente matrice: ");
	
	for(i1=0; i1<M; i1++){
		for(i2=0; i2<N; i2++){
			scanf("%d", &mat[i1][i2]);
		}
	}
	
	/*Izbacivanje redova */
	
	for(i1=0; i1<M; i1++){
		for(i2=i1+1; i2<M; i2++){
			for(i3=0; i3<N; i3++){
				if(mat[i1][i3]==mat[i2][i3])
					pomocni_b++;
			}
			if(pomocni_b==N){
				for(i4=i2; i4<M-1; i4++){
					for(i5=0; i5<N; i5++){
						mat[i4][i5]=mat[i4+1][i5];
					}
				}
		    	M--;
				i2--;
			}
			pomocni_b=0;
		}
	}

	/*Izbacivanje kolona */
	
	for(i1=0; i1<N; i1++){
		for(i2=i1+1; i2<N; i2 ++){
			for(i3=0; i3<M; i3++){
				if(mat[i3][i1]==mat[i3][i2])
					pomocni_b++;
			}
			if(pomocni_b==M){
				for(i4=i2; i4<N-1; i4++){
					for(i5=0; i5<M; i5++){
						mat[i5][i4]=mat[i5][i4+1];
					}
				}
				N--;
				i2--;
			}
			pomocni_b=0;
		}
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i1=0; i1<M; i1++){
		for(i2=0; i2<N; i2++){
			printf("%5d", mat[i1][i2]);
		}
		printf("\n");
	}
	return 0;
}
