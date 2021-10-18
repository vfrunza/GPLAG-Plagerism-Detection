#include <stdio.h>

int main()
{

	int i, j, m, n, matA[100][100], matB[100][100], matC[100][100], x, brojacA[1000]={0}, brojacB[1000]={0}, brojacC[1000]={0}, brojacAneg[1000]={0}, brojacBneg[1000]={0}, brojacCneg[1000]={0};

	//UNOS DIMENZIJA

	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
	} while(n<0 || n>100 || m>100 || m<0);


	
	//UNOS MATRICA

	printf("Unesite clanove matrice A: ");

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++){
			scanf("%d", &matA[i][j]);
			
			if (matA[i][j]<0) {
				x=matA[i][j]*(-1);
				brojacAneg[x]++;
			}
			else brojacA[matA[i][j]]++;
		}
	}
	printf("Unesite clanove matrice B: ");
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++){
			scanf("%d", &matB[i][j]);
				if (matB[i][j]<0) {
				x=matB[i][j]*(-1);
				brojacBneg[x]++;
			}
			else brojacB[matB[i][j]]++;
		}
	}
	printf("Unesite clanove matrice C: ");
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++){
			scanf("%d", &matC[i][j]);
				if (matC[i][j]<0) {
				x=matC[i][j]*(-1);
				brojacCneg[x]++;
			}
			else brojacC[matC[i][j]]++;
		}
	}


	x=1;
	for (i = 0; i < 1000; i++) {
			if(brojacA[i]!=brojacB[i] || brojacA[i]!=brojacC[i] || brojacAneg[i]!=brojacBneg[i] || brojacAneg[i]!=brojacCneg[i]){
				x=0;
				break;
		}
	}
	
	if (x==1) printf("DA");
	else printf("NE");
	
	return 0;
}
