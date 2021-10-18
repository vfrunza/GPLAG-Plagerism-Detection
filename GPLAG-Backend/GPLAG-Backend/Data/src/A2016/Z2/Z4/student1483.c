#include <stdio.h>
#define brojel 100

int main() {
	int mat_teplica;
	int mat_cirk;
	double matrica1[brojel][brojel];
	int M,N;
	int i,j;
	
	do{printf("Unesite M i N: ");
	scanf("%d %d",&M,&N);
	if(M<1 || M>100 || N<1 || N>100)printf("Pogresan unos!\n");
	}
	while(M<1 || M>100 || N<1 || N>100);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%lf",&matrica1[i][j]);
		}
	}
	
	mat_teplica=1;
	mat_cirk=1;
	
	for(i=0;i<M-1;i++){
		for(j=0;j<N-1;j++){
			if(matrica1[i][j]!=matrica1[i+1][j+1]) {mat_teplica=0; break;}
		}
	}
	
	for(i=0;i<M-1;i++){
		for(j=0;j<N-1;j++){
			if(matrica1[i][N-1]!=matrica1[i+1][0]) {mat_cirk=0; break;}
		}
	}
	
	if(mat_teplica && mat_cirk==0){printf("Matrica je Teplicova");}
	else if(M==100 && N==1) printf("Matrica je Teplicova");
	else if (mat_teplica && mat_cirk) {printf("Matrica je cirkularna");}
	else printf("Matrica nije ni cirkularna ni Teplicova");
	
	
	return 0;
}
