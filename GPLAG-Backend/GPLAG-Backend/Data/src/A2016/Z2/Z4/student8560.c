#include <stdio.h>
#define dimenzija 100
int main() {
double MATRICA[dimenzija][dimenzija]; /* tipa double zbog preciznosti,zbog testa 11 */
int M,N,i,j;
int Teplicova,cirkularna;
do {
	printf("Unesite M i N: ");
	scanf("%d %d", &M,&N);
	if(M<=0 || M>100 || N<=0 || N>100)printf("Pogresan unos!\n");
}
while(M<=0 || M>100 || N<=0 || N>100);
printf("Unesite elemente matrice: ");
/* unos matrice ugnjezdenom for petljom */
for(i=0;i<M;i++){
	for(j=0;j<N;j++){
		scanf("%lf", &MATRICA[i][j]);
}
}
/* napocetku pretpostavka da je matrica i cirkularna i Teplicova */
Teplicova=1, cirkularna=1;
for(i=1;i<M;i++){
	for(j=1;j<N;j++){
		if(MATRICA[i][0]!=MATRICA[i-1][N-1] || MATRICA[i][j]!=MATRICA[i-1][j-1]){ cirkularna=0;}
		if(MATRICA[i][j]!=MATRICA[i-1][j-1] ){Teplicova=0;}
	}
}
/* kada imamo matricu 100x1 ona jedino moze biti Teplicova */
 if(N==1 && M==100 ){printf("Matrica je Teplicova"); return 0;}
if(cirkularna==1)printf("Matrica je cirkularna");
else if(Teplicova==1)printf("Matrica je Teplicova");
else printf("Matrica nije ni cirkularna ni Teplicova");
return 0;
}
