#include <stdio.h>

int main(){
	int M,N;
	
	
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
		if(M<0 || M==0 || M>200 || N<0 || N==0 || N>200){
			printf("Brojevi nisu u trazenom opsegu.\n");
		}
	} while(M<0 || M==0 || M>200 || N<0 || N==0 || N>200);
	
	int mat[200][200];
	int i,j;
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%d",&mat[i][j]);
		}
	}
	i=0;
	while(i<M){
		j=0;
		while(j<M){
			if(i!=j){
				int k=0,da_li_su_isti=1;
				while(k<N){
					if(mat[i][k]!=mat[j][k]){
						da_li_su_isti=0;
						break;
					}
					k++;
				}
				if(da_li_su_isti==1){
					int l=j;
					while(l<M-1){
						k=0;
						while(k<N){
							mat[l][k]=mat[l+1][k];
							k++;
						}
						l++;
					}
					M--;
					j--;
				}
			}
			j++;
		}
		i++;
	
	}
	i=0;
	while(i<N){
		j=0;
		while(j<N){
			if(i!=j){
				int k=0,da_li_su_isti=1;
				while(k<M){
					if(mat[k][i]!=mat[k][j]){
						da_li_su_isti=0;
						break;
					}
					k++;
				}
				if(da_li_su_isti==1){
					int l=j;
					while(l<N){
						k=0;
						while(k<M){
							mat[k][l]=mat[k][l+1];
							k++;
						}
						l++;
					}
					N--;
					j--;
				}
			}
			j++;
		}
		i++;
		
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			printf("%5d",mat[i][j]);
		}
		printf("\n");
	}
	return 0;
	
}
