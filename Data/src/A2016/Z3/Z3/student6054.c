#include <stdio.h>
#include <stdlib.h>

int main() {
int mat[200][200],M,N,i,j,k,x,z,istiredovi,istekolone;
do{
printf("Unesite brojeve M i N: ");
scanf("%d%d", &M, &N);
if(M>200||N>200||M<=0||N<=0){
	printf("Brojevi nisu u trazenom opsegu.\n");
}}while(M>200||N>200||M<=0||N<=0);
printf("Unesite elemente matrice: ");
for (i=0;i<M;i++){
	for(j=0;j<N;j++){
	scanf("%d",&mat[i][j]);
}}
for(i=0;i<M;i++){
	for(k=i+1;k<M;k++){
	int	istiredovi=1;
		for(j=0;j<N;j++){
			
			if(mat[i][j]!=mat[k][j]){
				istiredovi=0;
				break;
			}
		}
		if(istiredovi==1){
			for(z=k+1;z<M;z++){
				for(x=0;x<N;x++){
					mat[z-1][x]=mat[z][x];
					
				}
		}
		M--;
	   	k--;
		
	}
}}
for(j=0;j<N;j++){
	for(k=j+1;k<N;k++){
		int istekolone=1;
		for(i=0;i<M;i++){
			if(mat[i][j]!=mat[i][k]){
				istekolone=0;
				break;
			}
		}
		if(istekolone==1){
			for(z=k+1;z<N;z++){
				for(x=0;x<M;x++){
					mat[x][z-1]=mat[x][z];
				}
			}
			N--;
			k--;
		}
	}
}
printf("Nakon izbacivanja redova/kolona matrica glasi: ");
printf("\n");
for(i=0;i<M;i++){
	for(j=0;j<N;j++){
		printf("%5d", mat[i][j]);}
		printf("\n");
	}

return 0;
}
