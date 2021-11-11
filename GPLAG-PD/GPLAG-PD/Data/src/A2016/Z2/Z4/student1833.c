#include <stdio.h>

int main() {
	int m, n, i, j, s, visina, sirina;
	int tep=1;
	int cirkul=1;
	float mat[100][100]={0};
	do {
	printf("Unesite M i N: ");
	scanf("%d %d", &m, &n);
     if(m<=0 || n<=0 || m>100 || n>100) printf("Pogresan unos! \n");
	}
	while(m>100 || n>100 || m<=0 || n<=0); 
	visina=m;
	sirina=n;
	
    printf("Unesite elemente matrice: ");
	for(i=0; i<visina; i++) {
		for(j=0;j<sirina;j++) {
			scanf("%f", &mat[i][j]);
		}
	}
	for(i=1;i<visina;i++) {
		for(j=1;j<sirina;j++) {
			if(mat[i][j]!=mat[i-1][j-1]) tep=0;
		}
	
	}
	for(s=1;s<visina;s++) {
		if(mat[0][s]!=mat[visina-s][0]) cirkul=0;
	}
	if(tep==1 && cirkul==1) printf("Matrica je cirkularna "); 
	else if(tep==1) printf("Matrica je Teplicova ");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
