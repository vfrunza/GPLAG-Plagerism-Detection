#include <stdio.h>

int main() {
	int m,n,i,br,br1,j,p;
	double a[100][100];
	br=0;
	br1=0;
	do{
		printf("Unesite M i N: ");
		scanf("%d %d",&m,&n);
		if(m<=0 || m>100 || n<=0 || n>100){
			printf("Pogresan unos!\n");
		}
	}
	while(m<=0 || m>100 || n<=0 || n>100);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%lf",&a[i][j]);
		}
	}
	
	for(i=0;i<m-1;i++){
		if(a[i][n-1]==a[i+1][0]){
			br++;
		}
	}
	
	for(i=0;i<m-1;i++){
		for(j=0;j<n-1;j++){
			if(a[i][j]==a[i+1][j+1]){
				br1++;
			}
		}
	}
	p=m*n-m-n+1;
	
	if(br==m-1 && br1==p){
		printf("Matrica je cirkularna");
	}
	else if(br1==p){
		printf("Matrica je Teplicova");
	}
	else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
