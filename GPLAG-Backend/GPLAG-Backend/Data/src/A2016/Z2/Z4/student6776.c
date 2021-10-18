#include <stdio.h>
#define SIRINA 100
#include <math.h>

int main() {
	int i,j,a,b;
	double mat[SIRINA][SIRINA];
	do{
	printf("Unesite M i N: ");
	scanf("%d %d",&a, &b);
	if(a<=0||a>100 || b<=0 || b>100){printf("Pogresan unos!\n");}
	}while (a<=0||a>100 || b<=0 || b>100);
	
printf("Unesite elemente matrice: ");
for(i=0;i<a;i++){
for(j=0;j<b;j++){
scanf("%lf", &mat[i][j]);	
	}
}

for(i=0;i<a-1;i++){
	for(j=0;j<b-1;j++){
		if((mat[i][j]=mat[i+1][j+1]) && (mat[i][b-1]=mat[i+1][0])){
	printf("Matrica je cirkularna");
			return 0;
		}
	else if((mat[i][j]=mat[i+1][j+1]) && !(mat[i][b-1]=mat[i+1][0])){
	printf("Matrica Templicova");
	return 0;}
	
	else if(!(mat[i][j]=mat[i+1][j+1]) && !(mat[i][j]=mat[i+1][j+1])){
	printf("Matrica nije ni cirkularna ni templicova.");
	return 0;}
}
}
	printf("matrica je cirkularna.");
	return 0;
}
