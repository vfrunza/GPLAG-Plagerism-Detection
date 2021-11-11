#include <stdio.h>
#define visina 300
#define sirina 300


int main() {
	int m, n;
	int i, j; 
	int mat[visina][sirina];
	int temp, temp1;
	int a, b;

	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
		if(m<=0 || m>200 || n<=0 || n>200) {
			printf("Brojevi nisu u trazenom opsegu.\n");
		}
	}while((m<=0 || m>200) || (n<=0 || n>200));
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	
	//petlja za red:
	for(i=0; i<m; i++) {
		for(j=i+1; j<m; j++) {
			temp=0;
			temp1=0;
			while (temp1<n) {
				if(mat[i][temp1]!=mat[j][temp1]) {
					temp=1;
				}
				temp1++;
				}
				if(temp==0) {
					for(a=j; a<m-1; a++) {
						for(b=0; b<n; b++) {
							mat[a][b]=mat[a+1][b];
						}
					}
					m--;
					j--;
				}
		
			}
		}
		
	//petlja za kolonu:	
	for(i=0; i<n; i++) {
		for(j=i+1; j<n; j++) {
			temp=0;
			temp1=0;
			while (temp1<m) {
				if(mat[temp1][i]!=mat[temp1][j]) {
					temp=1;
				}
				temp1++;
				}
				if(temp==0) {
					for(a=j; a<n-1; a++) {
						for(b=0; b<m; b++) {
							mat[a][b]=mat[a][b+1];
						}
					}
					n--;
					j--;
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
