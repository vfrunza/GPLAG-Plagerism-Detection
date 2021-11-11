#include <stdio.h>
#include <math.h>

int main() {
	int a[100][100], b[100][100], c[100][100], i=0, j=0, r, k, l=0, m=0, br1=0, br2=0, br3=0;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d%d", &r, &k);
	}while((r<0 || r>100) || (k<0 || k>100));
	printf("Unesite clanove matrice A: ");
	for(i=0; i<r; i++){
		for(j=0; j<k; j++){
			scanf("%d", &a[i][j]);
		}
	}
	printf("Unesite clanove matrice B: ");
	for(i=0; i<r; i++){
		for(j=0; j<k; j++){
			scanf("%d", &b[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0; i<r; i++){
		for(j=0; j<k; j++){
			scanf("%d", &c[i][j]);
		}
	}
	for(i=0; i<r; i++){
		for(j=0; j<k; j++){
			for(l=0; l<r; l++){
				for(m=0; m<k; m++){
					if(a[i][j]==a[l][m]){ 
						br1++;
					}
					if(a[i][j]==b[l][m]){
						br2++;	
					} 
					if(a[i][j]==c[l][m]){ 
						br3++;
					}
				}
			}
			if(br2!=br1 || br3!=br1 || br3!=br2){
				printf("NE"); return 0;
			}
		}
	}
	printf("DA");
	return 0;
}
