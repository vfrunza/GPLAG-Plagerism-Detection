#include <stdio.h>
#define BR_EL 100

int main() {
	int M,N,i,j,t=1,c=1;
	int a[BR_EL][BR_EL]={0};
	do{
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if(M<1 || M>100 || N<1 || N>100) printf("Pogresan unos!\n");
	}while(M<1 || M>100 || N<1 || N>100);
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d", &a[i][j]);
		}
	}
	for(i=0;i<M-1;i++){
		for(j=0;j<N-1;j++){
			if(a[i][j]!=a[i+1][j+1]) t=0;
		}
	}
	if(t){
		for(i=0;i<M-1;i++){
			if(a[i][N-1]!=a[i+1][0]) c=0;
		}
	}
	if(t==0) c=0;
	if(c) printf("Matrica je cirkularna");
	else if(t) printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	/*printf("Zadaća 2, Zadatak 4");*/
	return 0;
}
