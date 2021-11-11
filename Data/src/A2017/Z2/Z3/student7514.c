#include<stdio.h>
float A[100][100],B[100][100];
int rotirano(int a,int b){
	double rot[100][100];int kolona=a-1;
	int i,j;
	for(i=0;i<a;i++){
		for(j=0;j<b;j++)
			rot[j][kolona]=A[i][j];
		kolona--;
	}
	for(i=0;i<a;i++)
		for(j=0;j<b;j++)
			if(B[i][j]!=rot[i][j])return 0;
	return 1;
}
int main(){
	int a,a1,b,b1,i,j;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&a,&a1);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<a;i++)
		for(j=0;j<a1;j++)scanf("%f",&A[i][j]);
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&b,&b1);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<b;i++)
		for(j=0;j<b1;j++)scanf("%f",&B[i][j]);
	if(rotirano(a,a1)==1)printf("DA");
	else printf("NE");
	return 0;
}