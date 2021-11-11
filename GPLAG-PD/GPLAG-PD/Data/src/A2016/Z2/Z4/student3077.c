#include <stdio.h>
int main() {
	int M,N,i,j,teplicova,cirkularna; double matrica[100][100];
    printf("Unesite M i N: ");
    scanf("%d %d", &M,&N);
    while(M>100 || M<1 || N>100 || N<1) {
    	printf("Pogresan unos!\n");
    	printf("Unesite M i N: ");
        scanf("%d %d", &M,&N);
    } printf("Unesite elemente matrice: ");
    if(N==1 && M!=1) {printf("Matrica je Teplicova"); goto kraj;}
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
    		scanf("%lf", &matrica[i][j]);
    	} 
    } teplicova=1; cirkularna=1;
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            if(i+1<M && j+1<N && matrica[i][j]!=matrica[i+1][j+1]) {teplicova=0;
            break;}
        } if (teplicova==0) break;
    } 
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            if(i+1<M && j+1<N && (matrica[i][j]!=matrica[i+1][j+1] || matrica[i][N-1]!=matrica[i+1][0])) {cirkularna=0;
            break;}
        } if(cirkularna==0) break;
    } 
    
    if(cirkularna==1) printf("Matrica je cirkularna");
    else if(teplicova==1) printf("Matrica je Teplicova");
    else printf("Matrica nije ni cirkularna ni Teplicova");
kraj:
	return 0;
}
