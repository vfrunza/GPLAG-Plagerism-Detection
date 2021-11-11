#include <stdio.h>

int main() {
	
	int niz1[100][100],niz2[100][100],niz3[100][100];
	int i,j,k,l,m,n;
	
	do
	{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m,&n);
	}while((m<0||m>100)||(n<0||n>100));
	
	printf("Unesite clanove matrice A: ");
	
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &niz1[i][j]);
		}
	}
	printf("Unesite clanove matrice B: ");
		
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &niz2[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
	
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &niz3[i][j]);
		}
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			int novi_niz=niz1[i][j];
			int br1=0,br2=0,br3=0;
			for (k = 0; k < m; k++) {
				for (l = 0; l < n; l++) {
					if(niz1[k][l]==novi_niz) br1++;
					if(niz2[k][l]==novi_niz) br2++;
					if(niz3[k][l]==novi_niz) br3++;
				}
			}
			if(br1!=br2 || br2!=br3)
			{
				printf("NE\n");
				return 1;
			}
		}
	}
	
	printf("DA\n");
	
	return 0;
}
