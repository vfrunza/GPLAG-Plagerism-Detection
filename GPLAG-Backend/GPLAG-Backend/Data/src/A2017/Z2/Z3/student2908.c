#include <stdio.h>

int main() {
	
	int sirina_a, visina_a, sirina_b, visina_b, i, j, p=1;
	double A[100][100], B[100][100];
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&sirina_a,&visina_a);
	printf("Unesite clanove matrice A: ");
	for(i = 0; i < visina_a; i++){
		for(j = 0; j < sirina_a; j++){
			scanf("%lf",&A[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&sirina_b,&visina_b);
	printf("Unesite clanove matrice B: ");
	for(i = 0; i < visina_b; i++){
		for(j = 0; j < sirina_b; j++){
			scanf("%lf",&B[i][j]);
		}
	}
	
	if(visina_a!=sirina_b || sirina_a!=visina_b){
	printf("NE");
	return 0;
	}
	
	for(i = 0; i < sirina_b; i++){
		for(j = 0; j < visina_b; j++){
				if(A[i][j]!=B[j][sirina_b-1-i]){
				p=0;
				break;}
			}
		}
		
		if(p)
		printf("DA");
		else
		printf("NE");
	
	return 0;
}
