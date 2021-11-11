#include <stdio.h>

int main() {
	int i,j,k,l,mat[200][200],m,n,red,kola;
	do{
		printf("\nUnesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
		if((m<1)||(n<1)||(m>200)||(n>200))
			printf("Brojevi nisu u trazenom opsegu.");
	}while((m<1)||(n<1)||(m>200)||(n>200));
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++)
			scanf("%d",&mat[i][j]);
	}
	for(i=0; i<m-1; i++){
		for(k=i+1; k<m; k++){
			red=1;
			for(j=0; j<n; j++){
				if(mat[i][j]!=mat[k][j])
					red=0;
			}
			if(red){
			for(j=k; j<m-1; j++)
				for(l=0; l<n;l++){
				mat[j][l]=mat[j+1][l];
		
		}
			m--;
			i--;
			break;
			}
		}
	}
	for(i=0; i<n-1; i++){
		for(j=i+1; j<n; j++){
			kola=1;
			for(k=0; k<m; k++){
				if(mat[k][i]!=mat[k][j])
					kola=0;
			}
			if(kola){
				for(k=j; k<n-1; k++){
					for(l=0; l<m; l++){
						mat[l][k]=mat[l][k+1];
					}
				}
				n--;
				i--;
				break;
			}
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi:");
	for(i=0; i<m;i++){
		for(j=0; j<n; j++){
			if((i==0)&&(j==0))
				printf("\n");
			printf("%5d",mat[i][j]);
		}
			printf("\n");
	}
	return 0;
}
