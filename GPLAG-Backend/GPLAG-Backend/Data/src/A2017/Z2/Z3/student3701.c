#include <stdio.h>

int main() {
	int matA[100][100],matB[100][100];
	int i,j,m,n,k,l,brojac=0;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&m,&n);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&matA[i][j]);
			
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&k,&l);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<l;i++){
		for(j=0;j<k;j++){
			scanf("%d",&matB[i][j]);
		}
	}
	if(n!=k || m!=l) {
		printf("NE");
		return 0;
	}
		for(i=0;i<n;i++){
			for(j=0;j<l;j++){
			/*	temp=m;
				m=n;
				n=temp;*/
				if(matA[i][j]==matB[j][n-1-i]){
					brojac++;
					
				}
			//	else printf("NE");
				
		}
	}
		
	
	if (brojac==(m*n)) {
		printf("DA");
	}
	else printf("NE");
	

	return 0;
}
