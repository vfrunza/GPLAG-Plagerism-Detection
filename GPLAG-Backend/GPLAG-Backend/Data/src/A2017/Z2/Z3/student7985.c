#include <stdio.h>

int main() {
	int yor=1; /*yes or no*/
	int i, j;
	int s, v;
	int ss, vv;
	double a[100][100], b[100][100];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d%d", &s, &v);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<v; i++){
		for(j=0; j<s; j++)
			scanf("%lf", &a[i][j]);
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d%d", &ss, &vv);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<vv; i++){
		for(j=0; j<ss; j++)
			scanf("%lf", &b[i][j]);
	}
	
	if(s!=vv || v!=ss){
		printf("NE"); 
		return 0;
	}
	
	for(i=0; i<v; i++){
		for(j=0; j<s; j++){
			if(a[i][j]!=b[j][v-i-1]) {
				yor=0;
				break;
			}
		}
		if(yor==0) break;
	}
	
	if(yor) printf("DA");
	else printf("NE");
	
	return 0;
}
