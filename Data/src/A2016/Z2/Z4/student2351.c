#include <stdio.h>

int main() {
	int L,N,i,j;
	int Teplicova,cirkularna;
	double mat[100][100];
do {
	printf("Unesite M i N: ");
	scanf("%d %d", &L, &N);
	if (L>100 || L<=0 || N>100 || N<=0) {  printf("Pogresan unos!\n");}
} while (L>100  || N>100 || L<=0 || N<=0);

printf("Unesite elemente matrice: ");
for (i=0; i<L; i++)
for (j=0; j<N; j++)
scanf("%lf", &mat[i][j]);
Teplicova=1;  
for (i=0; i<L-1; i++) {   
	for (j=0; j<N-1; j++) {
		if (mat[i][j]!=mat[i+1][j+1])
		Teplicova=0;  
	}
}
if (Teplicova)    
{
	cirkularna=1;  
	for(i=1;i<L;i++)
	if(N-i>0)
	if(mat[i][0]!=mat[0][N-i])  cirkularna=0;
	
	if(cirkularna)
	printf("Matrica je cirkularna\n");
    else 
    printf("Matrica je Teplicova\n");
	 
}
else   
printf("Matrica nije ni cirkularna ni Teplicova"); 

return 0;
}




	

