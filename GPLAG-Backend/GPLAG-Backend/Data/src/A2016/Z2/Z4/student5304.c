#include <stdio.h>

int main() {
double a[100][100];
int i, j;
int x,y;
pocetak:
printf("Unesite M i N: ");
	scanf("%d %d", &x,&y);
if((x>100 || x<=0) || (y>100 || y<=0)){
printf("Pogresan unos!\n");
goto pocetak;
}

printf("Unesite elemente matrice: ");
for(i=0; i<x; i++) {
	for(j=0; j<y; j++) {
		scanf("%lf", &a[i][j]);
		if(a[i][j]>10000) {
			printf("Matrica nije ni cirkularna ni Teplicova");
			return 0;
		}
	}
}
if(y==1 && x>1) {
	printf("Matrica je Teplicova");
	return 0;
}
if(x==1 && y>1) {
	printf("Matrica je cirkularna");
	return 0;
}
int tepl=1;
int cirk=1;
for(i=0; i<x-1; i++) {
	for(j=0; j<y-1; j++) {
		if(a[i][j]!=a[i+1][j+1]) {
		tepl=0;
		} 
		if(a[i][y-1]!=a[i+1][0]) {
	    cirk=0;
		}
	}
}

if(tepl==1 && cirk==0) {
	printf("Matrica je Teplicova");
} 
if(cirk==1 && tepl==1) {
	printf("Matrica je cirkularna");
} 
if(tepl==0) {
	printf("Matrica nije ni cirkularna ni Teplicova");
}
	return 0;
}