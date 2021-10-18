#include <stdio.h>

int main() {
	double mat[50][50];
	int m,n,i,j;
	double c,k;
	do{
		printf("Unesite M i N: ");
		scanf("%d %d",&m,&n);
		if(n<=0 || n>100 || m<0 || m>100)
		printf("Pogresan unos!\n");}
		while(n<=0 || n>100 || m<0 || m>100);
		printf("Unesite elemente matrice: ");
		for(i=0;i<m;i++){
		for(j=0;j<n;j++){
		scanf("%lf",&mat[i][j]);}}
		int tepl=1,cirk=1;
		for(i=0;i<m-1;i++){
		for(j=0;j<n-1;j++){
			k=mat[i+1][j+1];
			c=mat[i][j];
		if(c!=k){
			tepl=0;cirk=0;printf("Matrica nije ni cirkularna ni Teplicova");return 0;}}}
		if(tepl==1){
			for(i=0;i<m-1;i++){
			if(mat[i][n-1]!=mat[i+1][0]){cirk=0;printf("Matrica je Teplicova");return 0;}}}
			printf("Matrica je cirkularna");
	return 0;
}
