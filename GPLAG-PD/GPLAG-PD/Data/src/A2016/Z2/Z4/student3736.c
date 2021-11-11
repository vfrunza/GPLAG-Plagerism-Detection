#include <stdio.h>
#define VISINA 100
#define SIRINA 100

int main() {
	int brojac=0;
	int a=0,b=0;
	int matrica[VISINA][SIRINA];
	int i,j,M,N;
	do {
		printf("Unesite M i N: ");
		scanf("%d%d", &M, &N);
		if((M<1 || M>100 || N<1 || N>100))
			printf("Pogresan unos!\n");
	} while(M<1 || M>100 || N<1 || N>100);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++) {
		for(j=0;j<N;j++) {
			scanf("%d", &matrica[i][j]);
		}
	}
	
			
	for(i=0;i<M-1;i++) {
		for( j=0;j<N-1;j++) {
			if(i==M-1 || j==N-1){
				b++;
			} 
			else if (matrica[i][j]==matrica[i+1][j+1]) {
				a++;
			}
		}
	}
	if(a==M*N-M-N+1) {
		b=1;
	}
    for(j=0;j<M;j++) {
    	if(j!=0) {
    		if(matrica[j][0]==matrica[j-1][N-1]) {
    			brojac++;
    		}
    	}
    }
    
    if(brojac==M-1 && b==1) {
    	printf("Matrica je cirkularna\n");}
    else if(b==1) {
    	printf("Matrica je Teplicova\n");}
    else {
    	printf("Matrica nije ni cirkularna ni Teplicova\n");}
	return 0;
}
