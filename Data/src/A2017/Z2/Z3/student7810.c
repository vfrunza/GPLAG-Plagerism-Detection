#include <stdio.h>

int main() {
	int i,j,visa,visb,sira,sirb;
	double a[100][100], b[100][100], sumaa=0, sumab=0,sumaprvekolone=0, sumaprvogreda=0;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sira, &visa);
	printf("Unesite clanove matrice A: ");
	
	for(i=0;i<visa;i++){
		for(j=0;j<sira;j++){
			scanf("%lf", &a[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &sirb, &visb);
	printf("Unesite clanove matrice B: ");
	
	for(i=0;i<visb;i++){
		for(j=0;j<sirb;j++){
			scanf("%lf", &b[i][j]);
		}
	}
	
	
	
	
	for(i=0;i<visa;i++){
		for(j=0;j<sira;j++){
			if(i==j) sumaa+=a[i][j];
		}
	}
	
	for(i=0;i<visb;i++){
		for(j=0;j<sirb;j++){
			if(i==sirb-1-j) sumab+=b[i][j];
		}
	}
	
	
	

	if((sumaa==sumab)) printf("DA");
	else printf("NE");
	
	
	return 0;
}
