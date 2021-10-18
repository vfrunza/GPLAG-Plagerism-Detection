#include <stdio.h>
#include <math.h>
#define eps 0.000000001

int main()
{
	int i=0, j=0, M, N, control=1, p=1;
	double a[100][100];

	do {
		printf("Unesite M i N: ");
		scanf("%i %i", &M, &N);
		if((M>100 || M<1) || (N>100 || N<1)) {
			printf("Pogresan unos!\n");

		}
	} while((M>100 || M<1) || (N>100 || N<1));

	printf("Unesite elemente matrice: ");

	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%lf", &a[i][j]);
		}
	}

	for(i=1; i<M; i++) {
		for(j=1; j<N; j++) {

			if(fabs(a[i][j]-a[i-1][j-1])>eps) {
				control=0;

			}
		}
	}

	if(control==1)
		printf("Matrica je cirkularna");

	else if(control==0) {
		for(i=0; i<M; i++) {
			for(j=0; j<N; j++) {
				if(fabs(a[i][j]-a[i+1][j+1])>eps);
				p=0;
			}
		}
		if(p==1)
			printf("Matrica je Teplicova");
		else if(p==0)
			printf("Matrica nije ni cirkularna ni Teplicova");
	}




	return 0;
}
