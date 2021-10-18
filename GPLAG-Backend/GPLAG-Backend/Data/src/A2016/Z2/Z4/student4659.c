#include <stdio.h>
#include <math.h>
#define A 0.000001

int main() {
	int i,j,m,n,br1=0,br2=0;
    double	mat[100][100]={{0}};
do{	printf("Unesite M i N: ");
	scanf("%d %d",&m,&n);
	if(m<=0 || m>100 || n<=0 || n>100 ) printf("Pogresan unos!\n");}
while(m<=0 || m>100 || n<=0 || n>100 );	

printf("Unesite elemente matrice: ");
for(i=0 ; i<m ; i++){
  for(j=0 ; j<n ; j++){
  	scanf("%lf",&mat[i][j]); }
}
if(m==1){ printf("Matrica je cirkularna");return 0;}
if(n==1){printf("Matrica je Teplicova") ;return 0;}


for(i=0 ; i<m ; i++){
  for(j=0 ; j<n ; j++){
  if(j!=n-1 && i!=m-1){if(fabs(mat[i][j]-mat[i+1][j+1])<A)br2++;}}
      
  if(fabs(mat[i][n-1]-mat[i+1][0])<A)br1++;   }

if(br1+br2==n*(m-1)){ printf("Matrica je cirkularna"); return 0;}
if(br2==(n-1)*(m-1)){printf("Matrica je Teplicova"); return 0;}

else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
