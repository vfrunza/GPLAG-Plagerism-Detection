#include <stdio.h>
#define brEl 10000
int main() {
	int m=0,n=0,i;
	int c=1, t=1;
	int niz[brEl]={0};
	do{
		printf("Unesite M i N: ");
		scanf("%d %d",&m,&n);
		if(m>100 || m<0|| n>100 || n<0) printf("Pogresan unos!\n");
	}while (m>100 || m<0 || n>100 || n<0);
	printf("Unesite elemente matrice: ");
	for(i=1; i<=m*n; i++){
		scanf("%d", &niz[i]);
	}
	for(i=n; i<=((m*n)-n); i+=n){
		if(niz[i]!=niz[i+1]) {
			c++; break;
		}
	}
	for(i=1; i<=((m*n)-n); i++){
		if(i%n==0) {
			 continue;
		}
		if(niz[i]!=niz[i+n+1]) {
			t++; break;
		}
	}
	if(c==1 && t==1) printf("Matrica je cirkularna");
	else if(c==2 && t==1) printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0; 
}
