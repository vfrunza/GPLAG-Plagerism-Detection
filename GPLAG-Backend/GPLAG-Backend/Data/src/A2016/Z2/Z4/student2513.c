#include <stdio.h>

int main() {
	int cirk=1, tepl=1, M, N, i, j, k;
	double mat[100][100];
	
	do {
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if(M<=0 || M>100 || N<=0 || N>100) printf("Pogresan unos!\n");
	
	}
	while(M<=0 || M>100 || N<=0 || N>100);
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++) 
	{for (j=0;j<N;j++) scanf("%lf",&mat[i][j]);
		
	}
	for(i=0;i<M-1;i++) {
		for(j=0;j<N-1;j++)
		{
			if (mat[i][j]!=mat[i+1][j+1]) tepl=0;
		}
	}
	for(i=0;i<M-1;i++)
	{
		for(j=0;j<N;j++) {
			k=j+1;
			if(k==N) k=0;
			if(mat[i][j]!=mat[i+1][k]) 
			cirk=0;
		}
	}
	if(tepl==1 && cirk==0) printf("Matrica je Teplicova");
	else if(cirk==1) printf("Matrica je cirkularna");
	else printf ("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
