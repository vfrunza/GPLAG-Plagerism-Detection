#include <stdio.h>
#include <math.h>
#define e 0.00001
#define broj 100
int main() {
	int i,m,n,j,c=1,t=1;
	double a[broj][broj]={{0}};
	
	do{
	printf("Unesite M i N: ");
	scanf("%d %d", &m,&n);
	if(m>100 || n>100 || m<=0 || n<=0) printf("Pogresan unos!\n");
	}
	while(m>100 || n>100 || n<=0 || m<=0);
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++)
	for(j=0; j<n; j++)
	scanf("%lf", &a[i][j]);
	
	
	for(i=0; i<m-1; i++)
	for(j=0; j<n-1; j++){
	if(fabs(a[i][j]-a[i+1][j+1])>e) {c=0; t=0;}}
	

	for(i=0; i<m-1; i++)
	if(fabs(a[i][n-1]-a[i+1][0])>e) c=0;


	
	if(c==1 ) printf("Matrica je cirkularna\n");
	else if(t==1) printf("Matrica je Teplicova\n");
	else printf("Matrica nije ni cirkularna ni Teplicova\n");
	
	return 0;
}
