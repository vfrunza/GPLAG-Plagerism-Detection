#include <stdio.h>
#define k 101
#define r 101
int main() {
	
double mat[r][k];
int a, b, g=0, c=1, p=1, i, j; 
do
{
	if(g!=0)
	printf("Pogresan unos!\n");
	printf("Unesite M i N: ");
	scanf("%d %d",&a, &b); 
	g++;
}
	while(a<1||a>100||b>100||b<1); 
	printf("Unesite elemente matrice: ");           
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			scanf("%lf", &mat[i][j]); 
		}
}
	for(i=0;i<a-1;i++){
		for(j=0;j<b-1;j++){
			if(mat[i][b-1]!=mat[i+1][0]){
				p=0;
			}
		} 
	}
	 
	for(i=0;i<a-1;i++){
		for(j=0;j<b-1;j++){
			if(mat[i][j]!=mat[i+1][j+1]){  
				c=0;}
				if(mat[i][b-1]!=mat[i+1][0]){
				c=0;}
				
			}
		}
	
	
	if(a==1&&b==1)
	printf("Matrica je cirkularna");
	else if(b==1)
	printf("Matrica je Teplicova");
else{
	
	if(c==1)
	printf("Matrica je cirkularna");
	else if(p==1)
	printf("Matrica je Teplicova");
	else 
	printf("Matrica nije ni cirkularna ni Teplicova");
}


	return 0;
}
