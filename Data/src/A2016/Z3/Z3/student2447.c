#include <stdio.h>

int main() {
	int m,n,mat[200][200],i,j,k,l,r;
	printf("Unesite brojeve M i N: ");
	
	do{
		scanf("%d %d",&m,&n);
		
		if(m>200 || n>200){
			printf("Brojevi nisu u trazenom opsegu.\n");
			printf("Unesite brojeve M i N: ");
		
		}
		if(m<=0 || n<=0){
			printf("Brojevi nisu u trazenom opsegu.\n");
			printf("Unesite brojeve M i N: ");
		
		}
		
	}while(m>200 || n>200 || m<=0 || n<=0);
	
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&mat[i][j]);
		}
	}
	
	for(i=0;i<m;i++){
		for(j=i+1;j<m;j++){
			for(k=0;k<n;k++){
				if(mat[i][k]!=mat[j][k]){
					break;
				}
			}
			if(k==n){
				for(l=j;l<m;l++){
					for(r=0;r<n;r++){
						mat[l][r]=mat[l+1][r];
					}
				}
				m--;
				j--;
			}
		}
	}
	
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			for(k=0;k<m;k++){
				if(mat[k][i]!=mat[k][j]){
					break;
				}
			}
			if(k==m){
				for(l=j;l<n;l++){
					for(r=0;r<m;r++){
						mat[r][l]=mat[r][l+1];
					}
				}
				n--;
				j--;
			}
		}
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%5d",mat[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
