#include <stdio.h>

int main() {
	int a,b,i,j,d,e,isti;
	double matB[100][100],matA[100][100];
	printf("Unesite sirinu i visinu matrice A: " );
	scanf("%d %d" ,&a,&b);
	
	printf("Unesite clanove matrice A: ");
	for(i=0;i<b;i++){
	for(j=0;j<a;j++){
	
	scanf("%lf", &matA[i][j]);
	
	}

	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &d,&e);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<e;i++){
	for(j=0;j<d;j++){
		scanf("%lf", &matB[i][j]);
		
		
	}
	}
	 if (a!=e || b!=d)
	 printf("NE\n");
	 else{
	isti=1;
	
	for(i=0;i<a;i++)
	for(j=0;j<b;j++)
	{
		if((matA[b-1-j][i])!=(matB[i][j])){
		isti=0;
		break;}
		
		
	}
	if(isti)
	printf("DA\n");
	else
	printf("NE\n");
	 }
	return 0;
	 
}
