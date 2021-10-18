#include <stdio.h>


int main() {
	int i,j;
	int tep=1;
	int cirk=1;
	double mat[100][100];
	int m,n;
	do{
		printf("Unesite M i N: ");
		scanf("%d %d",&m,&n);
		if(m<1 || n<1 || m>100 || n>100) printf("Pogresan unos!\n");
	}
	while(m<1 || n<1 || m>100 || n>100);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%lf",&mat[i][j]);
			}
	}
	
	for(i=0;i<m-1;i++){
		for(j=0;j<n-1;j++){
			if(mat[i][j]!=mat[i+1][j+1]) {tep=0;}
		}
	}
	
	for(i=0;i<m-1;i++){
			if(mat[i][n-1]!=mat[i+1][0]) {cirk=0;}
		
	}
	
	if(cirk && tep) {printf("Matrica je cirkularna");}
	else if(tep) {printf("Matrica je Teplicova");}
	else {printf("Matrica nije ni cirkularna ni Teplicova");}
	
	
	return 0;
}
