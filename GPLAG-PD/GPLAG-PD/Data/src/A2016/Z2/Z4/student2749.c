#include <stdio.h>

int main() {
	int m=0, n=0,i=0,j=0,tep = 1, cik = 1, matrica[100][100] = {0};
	do{
		printf("Unesite M i N: ");
		scanf("%d %d",&m,&n);
		if(m > 100 || m <= 0 || n <= 0 || n > 100){
			printf("Pogresan unos!\n");
			continue;
		}else break;
	}while(1);
	printf("Unesite elemente matrice: ");
	for(i = 0; i < m; i++){
		for(j = 0;j < n; j++){
			scanf("%d", &matrica[i][j]);
		}
	}
	/*printf("\n");
	for(i = 0; i < m; i++){
			for(j = 0;j < n; j++){
				printf("%d", matrica[i][j]);
			}
			printf("\n");
		}
	*/		
	for(i = 1; i < m; i++){
		for(j = 0;j < n; j++){
			if(j > 0){
				if(matrica[i][j] != matrica[i-1][j-1]) {
					cik = 0;
					break;
				}
			} else {
				if(matrica[i][j] != matrica[i-1][n-1]) {
					cik = 0;
					break;
				}
			}
		}
	}
	
	if (!cik) { 
		for(i = 1; i < m; i++){
			for(j = 1;j < n; j++){
				if(matrica[i][j] != matrica[i-1][j-1]){
					tep = 0;
					break;
				}
			}
		}
	}
	
			
	/*if(tep == 1 && cik == 1) printf("Matrica nije ni cirkularna ni Teplicova\n");*/
	if(tep == 0 && cik == 0) printf("Matrica nije ni cirkularna ni Teplicova\n");
	else if(cik == 1)printf("Matrica je cirkularna\n");
	else if(tep == 1)printf("Matrica je Teplicova\n");
	return 0;
}
