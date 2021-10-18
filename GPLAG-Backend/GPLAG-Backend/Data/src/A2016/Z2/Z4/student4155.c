#include <stdio.h>

int main() {
	int teplicovamatrica=1;
	int cirkularnamatrica=1;
	double matrica[100][100];
	int M,N;
	do{
	printf("Unesite M i N: ");
	scanf("%d %d",&M,&N);
	if(M<1 || M>100 || N<1 || N>100) printf("Pogresan unos!\n");
	}
	while(M<1 || M>100 || N<1 || N>100);
	
	int a,b;
	printf("Unesite elemente matrice: ");
	for(a=0;a<M;a++){
		for(b=0;b<N;b++){
			scanf("%lf",&matrica[a][b]);
		}
	}
	for(a=0;a<M-1;a++){
		for(b=0;b<N-1;b++){
			if(matrica[a][b]!=matrica[a+1][b+1]) teplicovamatrica=0;
			if(matrica[a][N-1]!=matrica[a+1][0]) cirkularnamatrica=0;
		}
	}
	if(M==100 && N==1) printf("Matrica je Teplicova");
	else if(teplicovamatrica && cirkularnamatrica) printf("Matrica je cirkularna");
	else if(teplicovamatrica) printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	
	
	return 0;
}
