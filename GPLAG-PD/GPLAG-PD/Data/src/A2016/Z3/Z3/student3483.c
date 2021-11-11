#include <stdio.h>

int main() {
	int a[200][200], m, n, i, j, k, t, jednak;
	
	/* Unos dimenzija matrice */
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
		if(m<1 || m>200 || n<1 || n>200)
			printf("Brojevi nisu u trazenom opsegu.\n");
	}
	while(m<1 || m>200 || n<1 || n>200);
	
	/* Unos elemenata matrice*/
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			scanf("%d", &a[i][j]);
			
	/* Izbacivanje redova koji se ponavljaju */
	for(i=0; i<m; i++)
		for(k=i+1; k<m; k++){
			jednak=1;
				for(j=0; j<n; j++)
					if(a[i][j]!=a[k][j]){
						jednak=0;
						break;
				}
			if(jednak==1){
				for(t=k; t<m-1; t++)
					for(j=0; j<n; j++)
						a[t][j]=a[t+1][j];
				m--;
				k--;
			}
		}
		
	/* Izbacivanje kolona koje se ponavljaju */
	for(j=0; j<n; j++)
		for(k=j+1; k<n; k++){
			jednak=1;
				for(i=0; i<m; i++)
					if(a[i][j]!=a[i][k]){
						jednak=0;
						break;
					}
				if(jednak==1){
					for(t=k; t<n-1; t++)
						for(i=0; i<n; i++)
							a[i][t]=a[i][t+1];
					n--;
					k--;
			}
		}
		
	/* Ispis matrice */
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}
	return 0;
}
