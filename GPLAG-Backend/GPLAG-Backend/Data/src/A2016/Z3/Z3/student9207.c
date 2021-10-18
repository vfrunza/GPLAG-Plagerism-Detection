#include <stdio.h>
int main() {
int i,j,mat[202][202]={{0}},M,N,k,p,a,b,n,m;
greska:
printf("\nUnesite brojeve M i N: ");
scanf("%d %d",&M,&N);
if(M>200 || M<0 || N>200 || N<0){
	
 printf("Brojevi nisu u trazenom opsegu.");
goto greska;
}
printf("Unesite elemente matrice: ");
for(i=0;i<M;i++){
	for(j=0;j<N;j++){
		scanf("%d",&mat[i][j]);
		
	}
}

for(b=0;b<N;b++){ 
	for(a=0;a<M;a++){
		for(n=a+1;n<M-1;n++){
		
			if(mat[b][a]==mat[n][b] ){
		
				for(m=n;m<M-1;m++){
					mat[m][b]=mat[m+1][b];
				
				}
				n--;
				M--;
				
			}
			}
		}
	}
for(i=0;i<M;i++){ 
	for(j=0;j<N;j++){
		
		for(k=j+1;k<N;k++){
			
			
			
			if(mat[i][j]==mat[i][k] ){
		
		         for(p=k;p<N-1;p++){
					mat[i][p]=mat[i][p+1];
				
				
				}
				
				
				k--;
				N--;
				
			
		     }
	
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
