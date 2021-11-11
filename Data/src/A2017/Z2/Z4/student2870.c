#include <stdio.h>

int main() {
	int i,j,m,n,k,l;
	int nizA[100][100], nizB[100][100], nizC[100][100];
	
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m,&n);
	}while (m<0 || m>100 || n<0 || n>100);
	
	printf("Unesite clanove matrice A: ");
	for (i = 0; i < m; i++) {
		for (j=0;j<n;j++){
			scanf("%d", &nizA[i][j]);
		}
	}
	
	printf("Unesite clanove matrice B: ");
	for (i = 0; i < m; i++) {
		for (j=0;j<n;j++){
			scanf("%d", &nizB[i][j]);
		}
	}
	
	printf("Unesite clanove matrice C: ");
	for (i = 0; i < m; i++) {
		for (j=0;j<n;j++){
			scanf("%d", &nizC[i][j]);
		}
	}
	
	for(i=0;i<m;i++){
		for (j=0;j<n;j++)
		{
			int brojac1=0, brojac2=0, brojac3=0, clan=nizA[i][j];
			for (k=0;k<m;k++)
			{
				for (l=0;l<n;l++){
					if (nizA[k][l]==clan) brojac1++;
					if (nizB[k][l]==clan) brojac2++;
					if (nizC[k][l]==clan) brojac3++;
				}
				
			}
			
			if(brojac1!=brojac2 || brojac2!=brojac3)
			{
				printf("NE\n");
				return 1;
			}
		}
	
		
		
	}
	printf("DA\n");
	return 0;
}
