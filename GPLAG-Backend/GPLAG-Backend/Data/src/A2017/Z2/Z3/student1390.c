#include <stdio.h>

int main() {
	int visA,sirA,visB,sirB;
	int i,j,k;
	float a[100][100],b[100][100];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sirA,&visA);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<visA;i++){
		for(j=0;j<sirA;j++){
			scanf("%f",&a[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &sirB,&visB);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<visB;i++){
		for(j=0;j<sirB;j++){
			scanf("%f",&b[i][j]);
		}
	}
	if(sirA!=visB || visA!=sirB)
	{
		printf("NE\n");
		return 0;
	}
	k=visA-1;
	for(i=0;i<visA;i++){
		for(j=0;j<sirA;j++){
			if(a[i][j] != b[j][k]){
				printf("NE\n");
				return 0;
				}
		}
		k--;
	}
	printf("DA\n");
	return 0;
}
