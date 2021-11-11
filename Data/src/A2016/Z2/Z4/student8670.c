#include <stdio.h>
int main() {
double B[100][100];
int m,n,i,j,s=0,p=0;
do {
	printf ("Unesite M i N: ");
	scanf("%d %d",&m,&n);
	if(m<=0 || m>100) {printf("Pogresan unos!\n"); } else if ( n<=0 || n>100) { printf("Pogresan unos!\n"); }
} while(m<=0 || m>100 || n<=0 || n>100);
printf("Unesite elemente matrice: ");
for(i=0;i<m;i++) {
	for(j=0;j<n;j++) {
		
		scanf("%lf", &B[i][j]);}
}
s=1;p=1;
		for(i=0;i<m-1;i++)
			{
				if((B[i][n-1]) != (B[i+1][0])) { s=0; break; }
			}
	for(i=0;i<m-1;i++) {
	for(j=0;j<n-1;j++) {
			if(B[i][j]!=B[i+1][j+1]) { p=0; break; } 
	}
	}
	if(m==1) {
		printf("Matrica je cirkularna"); return 0;
	} else
	if(n==1) {
		printf("Matrica je Teplicova"); return 0;
	} else
	if(s==1 && p==1) {
		printf("Matrica je cirkularna");
	} else if(p==1) { printf("Matrica je Teplicova"); } else {
		printf("Matrica nije ni cirkularna ni Teplicova"); }
	return 0;
}
