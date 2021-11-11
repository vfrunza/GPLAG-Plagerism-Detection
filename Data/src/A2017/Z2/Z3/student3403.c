#include <stdio.h>

int main() {
/*	printf("Zadaća 2, Zadatak 3");*/
	int a,b,c,d,i,j,q;
	float A[10][10], B[10][10], pom[10][10]={{0}};
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&b,&a);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<a; i++)
		for(j=0; j<b; j++)
			scanf("%f",&A[i][j]);
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&d,&c);
	printf("Unesite clanove matrice B: ");
		for(i=0; i<c; i++)
		for(j=0; j<d; j++)
		scanf("%f",&B[i][j]);
	if(b!=c || d!=a){
		printf("NE\n");
		return 0;
	}
	else{
		q=a-1;
		for(i=0; i<a; i++){
			for(j=0; j<b; j++){
				pom[j][q]=A[i][j];
			}
			q--;
		}
		for(i=0; i<c; i++)
			for(j=0; j<d; j++) 
			if(B[i][j]!=pom[i][j]){
				printf("NE\n");
				return 0;
			}
		printf("DA\n");
	}
	return 0;
}
