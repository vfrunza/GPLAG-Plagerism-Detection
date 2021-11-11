#include <stdio.h>
int main() {
	double A[100][100],B[100][100];
	int sirina_a,visina_a,sirina_b,visina_b/*dimenzije matrica*/,i,j/*za petlje*/;
	/*unos matrice A*/
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d%d",&sirina_a,&visina_a);
	printf("Unesite clanove matrice A: ");
	for(j=visina_a-1;j>=0;j--) {
		for(i=0;i<sirina_a;i++) scanf("%lf",&A[i][j]);
	}
	/*unos matrice B*/
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d%d",&sirina_b,&visina_b);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<visina_b;i++) {
	    for(j=0;j<sirina_b;j++) scanf("%lf",&B[i][j]);
	}
	/*provjera*/
	if(sirina_a!=visina_b || visina_a!=sirina_b) {
		printf("NE\n");
		return 0;
	}
	for(i=0;i<visina_b;i++) {
	    for(j=0;j<sirina_b;j++) {
	        if(A[i][j]!=B[i][j]) {
	            printf("NE\n");
	            return 0;
	        }
	    }
	}
	printf("DA\n");
	return 0;
}