#include <stdio.h>

int main() {
	int ci=1, tp=1, a, b, i, j;
	double niz[20][20];
	printf("Unesite M i N: ");
	do{
		scanf("%d %d", &a, &b);

	} while (a<0 || a>100 || b<0 || b>100);
	printf("Unesite elemente matrice: ");
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			scanf("%lf", &niz[i][j]);
		}
	}
	for(i=0;i<a-1;i++){
		for(j=0;j<b-1;j++){
			if (niz[i][j]!=niz[i+1][j+1])
			ci=0;
			if((double)niz[i][b-1]!=niz[i+1][0])
			ci=0;
			if(niz[i][j]!=niz[i+1][j+1])
			tp=0;
		}
	}
	if(ci==1)
	printf("Matrica je cirkularna");
	else if (tp==1)
	printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
