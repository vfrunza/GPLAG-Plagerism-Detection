 #include <stdio.h>

int main() {
    int M,N,i,j,Teplicova=1, Cirkularna=1;
    double mat[101] [101];
    do
    {
	printf("Unesite M i N: ");
	scanf("%d%d",&M,&N);
	if(M<1 || M>100 || N<1 || N>100) printf("Pogresan unos!\n"); else break;
    }while(M<1 || M>100 || N<1 || N>100);
    printf("Unesite elemente matrice: ");
    for(i=0; i<M; i++)
    for (j=0; j<N; j++)
    scanf ("%lf",&mat[i][j]);

    for(i=0; i<M-1; i++)
    for (j=0; j<N-1; j++)
    if ((mat[i][j]!=mat[i+1][j+1])||(mat[i][N-1]!=mat[i+1][0])) {Cirkularna=0; i=j=101;}
    
    if (Cirkularna==0)
    {
    for(i=0; i<M-1; i++)
    for (j=0; j<N-1; j++)
    if(mat[i][j]!=mat[i+1][j+1]) {Teplicova=0; i=j=101;}
    }
    if (M==1 && N!=1) {Teplicova=0; Cirkularna=1;}
    if (N==1 && M!=1) {Teplicova=1; Cirkularna=0;}

if(Cirkularna) printf("Matrica je cirkularna");
else if (Teplicova) printf("Matrica je Teplicova");
else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
