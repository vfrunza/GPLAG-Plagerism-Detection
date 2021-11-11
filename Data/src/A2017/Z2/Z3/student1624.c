#include <stdio.h>

int main() {
	
	int i,j,a,b,c,d,matA[100][100],matB[100][100],brojac=0;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d%d",&a,&b);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			scanf("%d",&matA[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d%d",&c,&d);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<c;i++){
		for(j=0;j<d;j++){
			scanf("%d",&matB[i][j]);
		}
	}
	
	/*if( (b==c && a==d)){*/
		
		for(i=0;i<a;i++){
			for(j=0;j<d;j++){
				if(matA[i][j]==matB[j][d-1-i]) brojac++;
				
			}
		}
		
		if(brojac==a*b) printf("DA");
		else printf("NE");
	/*}*/

	return 0;

}
