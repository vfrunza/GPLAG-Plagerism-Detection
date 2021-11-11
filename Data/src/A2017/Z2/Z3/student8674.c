#include <stdio.h>

int main() {
	int x,y,A,B,i,j,t=0;
	double a[100][100],b[100][100];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d%d",&x,&y);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<y; i++){
		for(j=0; j<x; j++){
			scanf("%lf", &a[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d%d",&A,&B);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<B; i++){
		for(j=0; j<A; j++){
			scanf("%lf", &b[i][j]);
		}
	}
	
	if(y!=A || x!=B) {printf("NE");}
	else
	{
		for(i=0; i<x; i++){
			for(j=y-1; j>-1; j--){
				if(a[j][i]==b[i][y-1-j])
					{t++;}
			}
			
		}if(t==x*y) printf("DA");
			else printf("NE");
	}
	
	
	return 0;
}
