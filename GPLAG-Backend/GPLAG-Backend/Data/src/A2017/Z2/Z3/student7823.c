#include <stdio.h>

int main() {
	int a_sirina, a_visina, b_sirina, b_visina, i,j;
	float a[100][100], b[100][100];
	int da=1;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &a_sirina, &a_visina);
	
	printf("Unesite clanove matrice A: "); 
	for(i=0; i<a_visina; i++){
		for(j=0; j<a_sirina; j++){
			scanf("%f", &a[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &b_sirina, &b_visina);
	
	printf("Unesite clanove matrice B: ");
	for(i=0; i<b_visina; i++){
		for(j=0; j<b_sirina; j++){
			scanf("%f", &b[i][j]);
		}
	}
	
	
	if(a_sirina==b_visina && a_visina==b_sirina){
	for(i=0; i<b_sirina; i++){
		for(j=0; j<b_visina;j++){
			if(a[i][j]!=b[j][a_visina-i-1]) da=0;
		}
	}
	
	if(da) printf("DA\n");
	else printf("NE\n"); 
	}
	else printf("NE\n");
	return 0;
}
