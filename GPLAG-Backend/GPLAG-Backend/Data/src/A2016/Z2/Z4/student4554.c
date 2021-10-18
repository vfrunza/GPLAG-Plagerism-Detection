#include <stdio.h>
#include <math.h>

int main() {
	int m,n,i,j,teplicova_matrica=0, cirkularna_matrica=0;
	float mat[100][100];
	printf("Unesite M i N: ");
	scanf("%d%d", &m, &n);
	while(m<1 || m>100 || n<1 || n>100){
		printf("Pogresan unos!\nUnesite M i N: ");
		scanf("%d %d", &m, &n);
	}
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%f", &mat[i][j]);
		}
	}
		teplicova_matrica=1;
	
	for(i=1; i<m; i++){
		for(j=1; j<n; j++){
			if(fabs(mat[i][j]-mat[i-1][j-1])>0.001){
				teplicova_matrica=0;
			}
		}
	}
	if(teplicova_matrica==1){
		cirkularna_matrica=1;
		for(i=1;i<m;i++){
			for(j=0; j<n; j++){
		
		if(fabs(mat[i][0]-mat[0][n-i])>0.001 && n-i>0)cirkularna_matrica=0;}}
		if(cirkularna_matrica==1)
		{
			printf("Matrica je cirkularna"); return 0;
		}else{
		printf("Matrica je Teplicova");return 0;
	}}
	else{
		printf("Matrica nije ni cirkularna ni Teplicova ");
	}
	return 0;
}
