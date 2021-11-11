#include <stdio.h>

int main() {
	float mat[100][100];
	int i, j, k, M, N;
	int tep, cir;
	tep=1;
	cir=2;
	do{ 
		printf("Unesite M i N: ");
		scanf("%d%d", &M, &N);
		if((M>100)||(N>100)||(M<=0)||(N<=0)) printf("Pogresan unos!\n");
	}while((M>100)||(N>100)||(M<=0)||(N<=0));
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%f", &mat[i][j]);
		}
	}
	for(i=0;i<M-1;i++){
		for(j=0;j<N-1;j++){
			if(mat[i][j]!=mat[i+1][j+1]) tep=0;
		}
	}
	if(tep==1){
		for(i=0;i<M-1;i++){
			for(j=0;j<N;j++){
				if(cir==0) break;
				for(k=0;k<N;k++){
					
					if(mat[i][j]==mat[i+1][k]) {
						cir=1;
						break;
						
					}
					else cir=0;
				}
			}
		}
	}
	if((tep==1)&&(cir==1)) printf("Matrica je cirkularna");
	else if((tep==1)&&(cir==0)) printf("Matrica je Teplicova");
	else if((tep==0)&&(cir==0)) printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
