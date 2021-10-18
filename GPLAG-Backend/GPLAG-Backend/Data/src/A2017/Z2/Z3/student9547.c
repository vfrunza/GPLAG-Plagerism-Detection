#include <stdio.h>
#include <math.h>

int main() {
	
	int a,b,c,d,i=-1,j=0;
	
	double A[10][10]={{0}},B[10][10]={{0}}, temp;
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&a,&b);
	
	printf("Unesite clanove matrice A: ");
	while(++i<a){
		j=0;
		while(j<b)
		scanf("%lf",&A[i][j++]);
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&c,&d);
	printf("Unesite clanove matrice B: ");
	i=-1;
	while(++i<c){
		j=0;
		while(j<d)
		scanf("%lf",&B[i][j++]);
	}
	if(a!=d || b!=c)
	{
		printf("NE\n");
		return 0;
	}
	i=0;
	while(i<10){//transonuje matricu
		for(j=i;j<10;j++){
			temp=A[i][j];
			A[i][j]=A[j][i];
			A[j][i]=temp;
		}
		i++;
	}
	for(i=0;i<a;i++)// zamjenio mjesta elemenata u redovima
	for(j=0;j<(b)/2;j++){
		temp=A[i][j];
		A[i][j]=A[i][b-j-1];
		A[i][b-j-1]=temp;
	}
	i=c;
	while(--i>-1){// krajnjeg prema pocetku
		j=d;
		while(--j>-1){
			if(fabs(A[i][j]-B[i][j])>0.0001){
				printf("NE\n");
				return 0;
			}
		}
	}
	printf("DA\n");
	return 0;
}
