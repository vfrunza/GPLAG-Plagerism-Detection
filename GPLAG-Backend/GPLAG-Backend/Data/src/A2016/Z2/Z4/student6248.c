#include <stdio.h>

int main() {
	int mat[100][100]={{0}};
	int m,n,i,j,tep=1,cirk=1,negativni=1;
	do{
		printf("Unesite M i N: ");
		scanf("%d %d",&m,&n);
		if(m>100 || m<1 || n>100 || n<1) printf("Pogresan unos!\n");
	} while(m>100 || m<1 || n>100 || n<1);
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%d",&mat[i][j]);
		}
	}
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			if(mat[i][j]<0) { negativni=0; break; }
		}
	}
	if(m==1 && n==1) printf("Matrica je cirkularna");
	else if(m==1) printf("Matrica je cirkularna");
	else if(n==1) printf("Matrica je Teplicova");
	else {
	for(i=0; i<m-1; i++){
		for(j=0; j<n-1; j++){
			if(mat[i][j]!=mat[i+1][j+1]) { tep=0; break; }
		}
	}
	if (tep==1){
	for(i=0; i<m-1; i++){
		for(j=0; j<n; j++){
			if(mat[i][n-1]!=mat[i+1][0]) { cirk=0; break; }
		}
	}
	}
	if(negativni==0 || tep==0) printf("Matrica nije ni cirkularna ni Teplicova");
    else if(cirk==1 ) printf("Matrica je cirkularna");
	else if(tep==1 || (tep==1 && cirk==0)) printf("Matrica je Teplicova");
	}

	return 0;
}
