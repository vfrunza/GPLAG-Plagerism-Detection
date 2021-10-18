#include <stdio.h>

int main() {
	int m,n,i,j,k,l, mat[200][200], br=0;
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d", &m);
		scanf("%d", &n);
		if(m<1 || m>200 || n<1 || n>200)
		printf("Brojevi nisu u trazenom opsegu.\n");
	}
	while(m<1 || m>200 || n<1 || n>200);
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++)
	for(j=0; j<n;j++)
	scanf("%d", &mat[i][j]);
	for(i=0; i<m-1; i++)
	for(k=i+1; k<m; k++) {
		br=0;
		for(j=0; j<n; j++) 
		{
			if(mat[i][j]!=mat[k][j])
			break;
			else br++;
		}
		if(br==n) {
			for(l=k; l<m; l++)
			for(j=0; j<n;j++)
			mat[l][j]=mat[l+1][j];
			m--;
			k--;
		}
	}
	for(j=0; j<n-1; j++)
	for(k=j+1; k<n; k++) {
		br=0;
		for(i=0; i<m; i++) {
			if(mat[i][j]!=mat[i][k])
			break;
			else br++;
		}
		if(br==m) {
			for(i=0; i<m; i++)
			for(l=k; l<n; l++)
			mat[i][l]=mat[i][l+1];
			n--;
			k--;
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
