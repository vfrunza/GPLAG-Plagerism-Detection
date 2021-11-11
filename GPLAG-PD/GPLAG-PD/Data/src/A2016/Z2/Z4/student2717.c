#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define e 0.01

int main() {
	int x,m,n,i,j,cirkularna_matrica=1,teplicova_matrica=1;
	double matrica[100][100];
	printf("Unesite M i N: ");
	scanf("%d %d", &m,&n);
	if((m<1||m>100||n<1||n>100)) {
	do {printf("Pogresan unos!\n");
	printf("Unesite M i N: ");
	scanf("%d", &m);
	scanf("%d", &n);}
	while ((m<1||m>100||n<1||n>100)); }
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++) {
		for (j=0;j<n;j++)
		scanf("%lf", &matrica[i][j]);}
	x=50;
	for (j=0;j<n-1;j++) {
		for (i=0;i<m-1;i++) {
	if((fabs)(matrica[i][j]-matrica[i+1][j+1])>e)
	x=0;}}
		if (x==50) for (i=0;i<m-1;i++) {if((fabs)(matrica[i][n]-matrica[i+1][1])>e)
		break;
		else
		x++;}
		
		if(x==m+49)
		printf("Matrica je cirkularna");
		else {if (x==0) printf("Matrica nije ni cirkularna ni Teplicova");
		else printf("Matrica je Teplicova");

	}

	return 0;
}
