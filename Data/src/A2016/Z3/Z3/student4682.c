#include <stdio.h>

int main() {
	int i,j,m,n,mat[200][200],isti_r,iste_k,k=0,l=0,a=0,b=0;
	do {
	printf("Unesite brojeve M i N: ");
	scanf("%d %d",&m,&n);
		if(m>200 || n>200 || m<=0 || n<=0)
		printf("Brojevi nisu u trazenom opsegu.\n");
	} while (m>200 || n>200 || m<=0 || n<=0);
	
	printf("Unesite elemente matrice: ");
		for(i=0; i<m; i++) {
			for(j=0; j<n; j++) {
			scanf("%d",&mat[i][j]);
			}
		}
	
	for(i=0; i<m-1; i++) {
		for(j=i+1; j<m; j++) {
			isti_r=1;
			for(k=0; k<n; k++) 
				if (mat[i][k]!=mat[j][k])
				isti_r=0;
				
			if(isti_r==1) {
				l=0;
				for(k=j; k<m; k++) {
					for(l=0; l<n; l++) 
						mat[k][l]=mat[k+1][l];
					}	
			m--;
			i--;
			break;
			}
		}
	}
	
	for(j=0; j<n-1; j++) {
		for(i=j+1; i<n; i++) {
			iste_k=1;
			for(a=0; a<m; a++)
			if (mat[a][i]!=mat[a][j])
			iste_k=0;
			
			if(iste_k==1) {
		
				for(a=i; a<n; a++) {
					for(b=0; b<m; b++) 
						mat[b][a]=mat[b][a+1];
					}
			n--;
			j--;
			break;
			}	
		}	
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
		printf("%5d", mat[i][j]);
		}
		printf("\n");
		
	}	
	return 0;
}
