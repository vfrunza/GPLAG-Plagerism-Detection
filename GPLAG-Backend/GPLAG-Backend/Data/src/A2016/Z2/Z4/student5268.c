#include <stdio.h>

int main() {

	double mat[100][100];
	int j, k, m, n, cirk=1, tepl=1;

	do {
		printf("Unesite M i N: ");
		scanf("%d%d",&m, &n);
		if((m<1 || m>100) || (n>100 || n<1)) 
			printf("Pogresan unos!\n");
		
	} while(m<1 || m>100 || n<1 || n>100);
	printf("Unesite elemente matrice: ");
	for(j=0; j<m; j++) {
		for(k=0; k<n; k++) {
			scanf("%lf", &mat[j][k]);
		}
	}
	for(j=0; j<m-1; j++){
		for(k=0; k<n-1; k++){
			if(mat[j][n-1]!=mat[j+1][0]){
				cirk=0;
				break;
			}
		}
	}

	for(j=0; j<m-1; j++){
		for(k=0; k<n-1; k++){
			if(mat[j][k]!=mat[j+1][k+1]){
				tepl=0;
				break;
			}
		}
	}
    if(n==1 && m>1){
    	printf("Matrica je Teplicova");
    	return 0;
    }
	if(tepl==1) {
		if(cirk==1) {
			printf("Matrica je cirkularna");
		} else {
			printf("Matrica je Teplicova");
		}

	} else {
		printf("Matrica nije ni cirkularna ni Teplicova");
	}
	return 0;
}
