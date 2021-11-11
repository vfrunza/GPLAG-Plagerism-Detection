#include <stdio.h>
#define A 100

int main() {

	double matrica[A][A];
	int brojac1,brojac2;
	int i,j;
	int M;
	int N;
	do{
		printf("Unesite M i N: ");
		scanf("%d %d",&M,&N);
		if(M>100 || M<1 || N>100 || N<1) printf("Pogresan unos!\n");
		}
	while(M<1 || M>100 || N<1 || N>100);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%lf",&matrica[i][j]);
		}
	}
	
	int cirkularna_matrica=1;
	int teplicova_matrica=1;
	
	for(i=0;i<M-1;i++){
		for(j=0;j<N-1;j++){
		if(matrica[i+1][j+1]!=matrica[i][j]) teplicova_matrica=0;
		}
	}
	
	for(i=0;i<M-1;i++){
		for(j=0;j<N-1;j++){
			if(matrica[i+1][0]!=matrica[i][N-1]) cirkularna_matrica=0;
		}
	}
	
	if(M==100 && N==1 && teplicova_matrica) printf("Matrica je Teplicova");
	else if(teplicova_matrica && cirkularna_matrica) printf("Matrica je cirkularna");
	else if(teplicova_matrica) printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");



	return 0;
}
