#include <stdio.h>
int main() {
	int M,N,i,j,k,l,m,pretp;
	int mat[200][200];
	do
	{
	 printf("Unesite brojeve M i N: ");
	 scanf("%d %d", &M, &N);
	 if(M>200 || N>200) printf("Brojevi nisu u trazenom opsegu.\n");
	 if(M<0 || N<0) printf("Brojevi nisu u trazenom opsegu.\n");
	} while(M>200 || N>200 || N<0 || M<0);
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d", &mat[i][j]);
		}
	}
	for(i=0;i<M;i++){
		for(k=i+1;k<M;k++){
		   pretp=1;
		   for(j=0;j<N;j++)
	   	    if(mat[i][j]!=mat[k][j]) pretp=0;
		    if(pretp==1) {
		      for(l=k+1;l<M;l++){
		       for(m=0;m<N;m++){
		        mat[l-1][m]=mat[l][m];}
	         }
	      M--;
	      k--;
	   }
     }
    } 
	for(i=0;i<N;i++){
		for(k=i+1;k<N;k++){
			pretp=1;
			for(j=0;j<M;j++)
			if(mat[j][i]!=mat[j][k])
			pretp=0;
		      if(pretp==1){
				for(l=k+1;l<N;l++){
				 for(m=0;m<M;m++){
				  mat[m][l-1]=mat[m][l];}
				}
				N--;
				k--;
			}
		}
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n" );
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			printf("%5d", mat[i][j]);
		}
		printf("\n");
	}
		return 0;
}
