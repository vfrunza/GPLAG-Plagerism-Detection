#include <stdio.h>
#include <math.h>
#define eps  1e-10


int main() {
	int Ma=2,Na=2,Mb=2,Nb=2,i,j,pom;
	double mat1[100][100],mat2[100][100];

	printf("Unesite sirinu i visinu matrice A: "); scanf("%d%d",&Ma,&Na);
	printf("Unesite clanove matrice A: ");
	for(i = 0; i < Ma; i++){
		for(j =0 ; j < Na; j++)
			scanf("%lf",&mat1[i][j]);
	}
	
	printf("Unesite sirinu i visinu matrice B: "); scanf("%d%d",&Mb,&Nb);
	printf("Unesite clanove matrice B: ");
	for(i = 0; i < Mb; i++){
		for(j =0 ; j < Nb; j++)
			scanf("%lf",&mat2[i][j]);
	}
	
	if(Ma != Nb || Na != Mb) {printf("NE"); return 0;}
	pom = Nb - 1;
	
	for(i = 0; i < Ma; i++){
		for(j = 0; j < Na; j++){
			if( !(fabs(mat1[i][j] - mat2[j][pom]) <= eps * ( fabs(mat1[i][j])-fabs(mat2[j][pom])))){printf("NE");return 0;}
		}
		pom--;
	}
	
	printf("DA");
	
	return 0;
}
