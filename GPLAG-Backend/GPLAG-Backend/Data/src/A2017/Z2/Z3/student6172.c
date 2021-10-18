#include <stdio.h>
#define MAX 100
int main() {
	double a[MAX][MAX], b[MAX][MAX];
	int i,j,sirina_a,visina_a,sirina_b,visina_b;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sirina_a,&visina_a);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<visina_a;i++){
		for(j=0;j<sirina_a;j++){
			scanf("%lf",&a[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &sirina_b,&visina_b);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<visina_b;i++){
		for(j=0;j<sirina_b;j++){
			scanf("%lf",&b[i][j]);
		}
	}
	
	if(visina_a!=sirina_b || visina_b!=sirina_a) 
		printf("NE");
		return 0;
	}
	
	for(i=0;i<visina_a;i++){
		for(j=0;j<sirina_a;j++){
			if(a[i][j]!=b[j][visina_a-1-i]) {
				printf("NE");
				return 0;
			}
		}
	}
	printf("DA");
	return 0;
}
