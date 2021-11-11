#include <stdio.h>
int main() {
	int m=0,n=0,i=0,j=0;
	do {
	printf("Unesite M i N: ");
	scanf("%d%d",&m ,&n);
	if((m<=0||m>100)||(n<=0||n>100)) printf("Pogresan unos!\n"); }
	while((m<=0||m>100)||(n<=0||n>100));
	int niz[99][99]={0} ;
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) { 
		scanf("%d",&niz[i][j]);
		}
	}
	int x=0;
	
for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			 if(i!=0&&j!=0) { if (niz[i][j]==niz[i-1][j-1]) x++; }
			 if(i!=0&&j==0) { if (niz[i][j]==niz[i-1][n-1]) x++; }
		} }
	if (x==(m-1)*n) { printf("Matrica je cirkularna"); return 0; }
int z=1;
for(i=0;i<m-1;i++) {
		for(j=0;j<n-1;j++) { 
		if(niz[i][j]!=niz[i+1][j+1]) z=0; } }
if(z)  printf("Matrica je Teplicova"); 
if(z!=1) printf("Matrica nije ni cirkularna ni Teplicova"); 
	return 0;
}
