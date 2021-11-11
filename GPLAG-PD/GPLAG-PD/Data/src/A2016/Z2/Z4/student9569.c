#include <stdio.h>

int main() {
	double s[100][100];
	int i, j, M, N, tepl= 1, cirk= 1;
	
	do{
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if(M<=0 || M>100 || N<=0 || N>100) {
			printf("Pogresan unos!\n");
		}
	}
	while(M<=0 || M>100 || N<=0 || N>100);
	printf("Unesite elemente matrice: ");
	
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf ("%lf",&s[i][j]);
		}
	}
	
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			if(s[0][j]!=s[i][(i+j)%N]){
				
				cirk= 0; 
			}
		}
	}
	
	for(i=0;i<M-1;i++){
		for(j=0;j<N-1;j++){
			if(j+1<N){
				if(s[i][j]!=s[i+1][j+1]){
					tepl= 0;
				}
			}
		}
	}
	
		if(cirk==1) printf("Matrica je cirkularna");
		else if(cirk==0 && tepl==1) printf("Matrica je Teplicova");
		else printf("Matrica nije ni cirkularna ni Teplicova");
	

	return 0;
}
