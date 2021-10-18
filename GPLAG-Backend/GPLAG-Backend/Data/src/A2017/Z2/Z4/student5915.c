#include <stdio.h>

int main() {
	int A[100][100],B[100][100],C[100][100];
	int i,j,k,l,M,N,temp,mini,minj,identicne_mat=1;
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
	} while(M<=0 || M>100 || N<=0 || N>100);
	
	printf("Unesite clanove matrice A: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%d", &A[i][j]);
		}
	}
	printf("Unesite clanove matrice B: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%d", &B[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%d", &C[i][j]);
		}
	}
	
	for(i=0; i<M; i++){
		mini=i;
		for(j=0; j<N; j++){
			minj=j;
	       for(k=i; k<M; k++){
		      for(l=j; l<N; l++){
				if(A[k][l]<A[mini][minj]) {
					mini=k;
					minj=l;
		   	      }
		        }
        	}
				temp=A[i][j];
				A[i][j]=A[mini][minj];
				A[mini][minj]=temp;
			}
		}
		
		for(i=0; i<M; i++){
			mini=i;
		 for(j=0; j<N; j++){
			minj=j;
	       for(k=i; k<M; k++){
		      for(l=j; l<N; l++){
				if(B[k][l]<B[mini][minj]) {
					mini=k;
					minj=l;
		   	      }
		        }
        	}
				temp=B[i][j];
				B[i][j]=B[mini][minj];
				B[mini][minj]=temp;
			}
		}
		
		for(i=0; i<M; i++){
			mini=i;
		 for(j=0; j<N; j++){
			minj=j;
	       for(k=i; k<M; k++){
		      for(l=j; l<N; l++){
				if(C[k][l]<C[mini][minj]) {
					mini=k;
					minj=l;
		   	      }
		        }
        	}
				temp=C[i][j];
				C[i][j]=C[mini][minj];
				C[mini][minj]=temp;
			}
		}
		
		for(i=0; i<M; i++){
			for(j=0; j<N; j++){
				if(A[i][j]!=B[i][j] || A[i][j]!=C[i][j]) {
					identicne_mat=0;
					break;
				}
			}
		}
	
	if(identicne_mat) printf("DA");
	else printf("NE");
		
	return 0;
}
