#include <stdio.h>

int main() {
	
	int redA,kolonaA,redB,kolonaB,i,j,brojac=0;
	double broj1,broj2,A[100][100],B[100][100], C[100][100];
	double tempC;
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d%d", &kolonaA, &redA);
	

	
	printf("Unesite clanove matrice A: ");
	
	for(i=0;i<redA;i++){
		for(j=0;j<kolonaA;j++){
			scanf("%lf",&broj1);
	A[i][j]=broj1;
		}
	}
		printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d%d", &kolonaB, &redB);
	
	
	printf("Unesite clanove matrice B: ");
	
	
	for(i=0;i<redB;i++){
		for(j=0;j<kolonaB;j++){
			scanf("%lf",&broj2);
	B[i][j]=broj2;
		}
	}
	
	
		for(i=0;i<kolonaA;i++){
		for(j=0;j<redA;j++){
	C[i][j]=A[j][i];
	
		}
	}


	
	for(i=0;i<kolonaA;i++){
		for(j=0;j<redA/2;j++){
			tempC=C[i][j];
	C[i][j]=C[i][redA-j-1];
	C[i][redA-j-1]=tempC;
		}
	}

	if(kolonaA!=redB || redA!=kolonaB) printf("NE");
	else {
   for(i=0;i<kolonaA;i++){
   	for(j=0;j<redA;j++){
   	if(C[i][j]==B[i][j]) brojac++;
   }
   }
   if(brojac!=redA*kolonaA) printf("NE");
   else printf("DA");
	}

	return 0;
}
