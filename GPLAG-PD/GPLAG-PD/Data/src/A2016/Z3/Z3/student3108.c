#include <stdio.h>
#define M 200
#define N 200


int main() {
	int m,n,i,j,l,k;
	int mat[M][N], isti=1;
	do {
	printf("Unesite brojeve M i N: ");
	scanf("%d %d", &m, &n);
	
	if(m>0 && m<=200 && n>0 && n<=200)
	break;
	else 
	printf("Brojevi nisu u trazenom opsegu.\n");
	}
	
	while(m>0 && m<=200 || n>0 && n<=200); {
	
	printf("Unesite elemente matrice: ");
	
		for(i=0; i<m; i++) {
			for(j=0; j<n; j++) {
				
				scanf("%d", &mat[i][j]);
			}
			
		}
		
		
			for(i=0;i<m;i++) {
				
				for(j=i+1; j<m;j++) {
					isti=1;
					
					for(k=0; k<n; k++) {
						
						if(mat[i][k]!=mat[j][k]) {
							isti=0;
					
							break;}
					}
						if(isti==1) {
						for(k=j; k<m-1; k++) {
							for(l=0;l<n; l++){
							
						mat[k][l]=mat[k+1][l];	
						} }
						m--;
						j--;
					}} }
					
					for(i=0;i<n;i++) {	
						for(j=i+1; j<n; j++) {
							isti=1;
							for(k=0; k<m; k++) {
								if(mat[j][k]!=mat[i][k]) {
									isti=0;
									break;
								}
							}
							if(isti==1) {
								for(k=i; k<n-1;k++) {
									for(l=0; l<m; l++) {
										mat[k][l]=mat[k][l+1];
									}
								}
								n--;
								i--;
							}
						}
						
					}
					
				
		}
		
		printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
		for(i=0; i<m; i++) {
			for(j=0; j<n; j++) {
				printf("%5d", mat[i][j]);
			}
			printf("\n");
		}
		
	
	
	return 0;
}
