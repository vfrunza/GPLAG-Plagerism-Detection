#include <stdio.h>

int main() {
	double A[100][100];
	double B[100][100];
	int i,j,sirA,visA,sirB,visB;
	
	    /* Unos dimenzija i elemenata matrice A */
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&sirA,&visA);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<visA;i++) {
		for(j=0;j<sirA;j++) {
			scanf("%lf",&A[i][j]);
		}
	}
	 /* Unos dimenzija i elemenata matrice B */
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&sirB,&visB);
	
	printf("Unesite clanove matrice B: ");
	for(i=0;i<visB;i++) {
		for(j=0;j<sirB;j++) {
			scanf("%lf",&B[i][j]);
		}
	}
		/* Ispitujemo formate matrica */
		
	if(visA != sirB || sirA != visB) {
		printf("NE");
	}
	
		/* Ispitujemo da li je A zarotirana jednaka B */
	else {
		int rotirana = 1;
		for(i=0;i<visA;i++) {
			if (rotirana==0)
				break;
			for(j=0;j<sirA;j++) {
				if(A[i][j] != B[j][sirB-i-1]){
					rotirana = 0;
					break;
				}
			}
		}
		
		if(rotirana==1)
			printf("DA");
		else 
			printf("NE");
	}
	
	return 0;
}
