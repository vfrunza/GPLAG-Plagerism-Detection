#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int i,j,m,n,mat1[100][100],mat2[100][100],mat3[100][100],max,vel,iste,hist1[10000]={0}, hist2[10000]={0}, hist3[10000]={0};;
	
	do {
		printf("Unesite brojeve M i N: ");
	scanf("%d%d", &m, &n);
	} while(m<0 || m>100 || n<0 || n>100);
	
	printf("Unesite clanove matrice A: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d", &mat1[i][j]);
		}
	}
	printf("Unesite clanove matrice B: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d", &mat2[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d", &mat3[i][j]);
		}
	}
	
	max=mat1[0][0];
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			if(mat1[i][j]>max) max=mat1[i][j];
		}
	}
	vel=max+1;
	

	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			hist1[abs(mat1[i][j])]++;
		}
	}
		for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			hist2[abs(mat2[i][j])]++;
		}
	}
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			hist3[abs(mat3[i][j])]++;
		}
	}
	
	iste=1;
	
	for(i=0; i<vel; i++) {
		if(hist1[i]!=hist2[i] || hist1[i]!=hist2[i] || hist2[i]!=hist3[i]) {
			iste=0;
			break;
		}
	}
	
	if(iste) printf("DA");
	else printf("NE");
	/*for(i=0; i<vel; i++) {
		printf("%d ", hist1[i]);
	}
	for(i=0; i<vel; i++) {
		printf("\n%d ", hist2[i]);
	}
	for(i=0; i<vel; i++) {
		printf("\n%d ", hist3[i]);
	}
*/
	
	return 0;
}
