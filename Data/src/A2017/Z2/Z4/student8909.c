#include <stdio.h>

int main() {
	int m,n,a[100][100],b[100][100],c[100][100],i,j,k,l,brojac,pom,br1,br2;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d%d",&m,&n);
	}while(m<0 || n<0 || m>100 || n>100);
	
	printf("Unesite clanove matrice A: ");
	for(i = 0; i < m; i++)
		for(j = 0; j <n; j++)
			scanf("%d",&a[i][j]);
			
			printf("Unesite clanove matrice B: ");
	for(i = 0; i < m; i++)
		for(j = 0; j <n; j++)
			scanf("%d",&b[i][j]);
		
			printf("Unesite clanove matrice C: ");
	for(i = 0; i < m; i++)
		for(j = 0; j <n; j++)
			scanf("%d",&c[i][j]);
			
			for(i = 0; i < m; i++){
				for(j = 0; j < n; j++){
					pom = a[i][j];
					brojac = 0;
					for(k = 0; k < m; k++){// k,l prolaz kroz matricu
							for(l = 0; l < n; l++){
								if
						if(pom == a[k][l])brojac++;
							}
					}
					br1 = 0;
						for(k = 0; k < m; k++){--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
							for(l = 0; l < n; l++){
						if(pom == b[k][l])br1++;
							}
					}
			
					br2 = 0;
				for(k = 0; k < m; k++){
							for(l = 0; l < n; l++){
						if(pom == c[k][l])br2++;
							}
					}	
	
					if(brojac != br2 || br2 != br1 || brojac  != br1){printf("NE"); return 0;}
				}
			}
		printf("DA");
	return 0;
}
