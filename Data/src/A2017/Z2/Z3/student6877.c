#include <stdio.h>

#define M 100
#define N 100

int main() {
	int da=1;
	int matricaA[M][N];
	int matricaB[M][N];
	int sirA=0, sirB=0 , visA=0 , visB=0;
	int i=0,j=0;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d",&sirA);
	scanf("%d",&visA);

	printf("Unesite clanove matrice A: ");
	for(i=0;i<visA;i++){
		for(j=0;j<sirA;j++){
			scanf("%d", &matricaA[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d",&sirB);
	scanf("%d",&visB);
	
	printf("Unesite clanove matrice B: ");
	for(i=0;i<visB;i++){
		for(j=0;j<sirB;j++){
			scanf("%d", &matricaB[i][j]);
		}
	}
	if(sirA!=visB) da=0;
	if(visA!=sirB) da=0;
	if(da){
		for(i=0;i<visA;i++){
			for(j=0;j<sirA;j++){
				if(matricaA[i][j]!=matricaB[j][sirB-1-i]) da=0;
			}
		}
	}
	if (da) printf("DA\n");
	else printf("NE\n");
	
	
	
	
	return 0;
}
