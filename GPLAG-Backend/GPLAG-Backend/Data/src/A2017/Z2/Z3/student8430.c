#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100
int main() {
	double A[N][N],B[N][N],C[N][N];
	int ma,na,mb,nb,i,j;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&ma,&na);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<ma;i++)
	for(j=0;j<na;j++)
	scanf("%lf",&A[i][j]);
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&mb,&nb);
	printf("Unesite clanove matrice B: ");
	for (i=0;i<mb;i++)
	for (j=0;j<nb;j++)
	scanf("%lf",&B[i][j]);
	for(i=0;i<ma;i++)
	for(j=0;j<na;j++)
	C[j][i]=A[i][j];
	

	for(i=0;i<na;i++)
	for(j=0;j<ma/2;j++){
		double temp=C[i][j];
		C[i][j]=C[i][ma-j-1];
		C[i][ma-j-1]=temp;
	}
	
	
	for(i=0;i<mb;i++)
	for(j=0;j<nb;j++)
	if(fabs(C[i][j]-B[i][j])>1e-5){
		printf("NE");
		return 0;
	}
	printf("DA");
	
	return 0;
}
