#include <stdio.h>

int main() {
	int i=0, j=0, k=0, l=0, m, n;
	int brojA=0, brojB=0, brojC=0, dbroj=0, isti=0;
	int a[100][100], b[100][100], c[100][100], d[1000];
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
	} while(m>100 || n>100);
	
	// Unos matrica
	printf("Unesite clanove matrice A: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	printf("Unesite clanove matrice B: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d", &b[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++){
			scanf("%d", &c[i][j]);
		}
	}
	
	// Provjera jednakosti i prebrojavanje
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			isti=0;
			for(k=0; k<i; k++) {
				for(l=0; l<n; l++) {
					if(a[i][j]==a[k][l])
					isti++;
				}
			}
			k=i;
			for(l=0; l<j+1; l++) {
				if(a[i][j]==a[k][l])
					isti++;
			}
			if(isti==1) {
				d[dbroj]=a[i][j];
				dbroj++;
			}
		}
	}
	for(i=0; i<dbroj; i++) {
		for(j=0; j<m; j++) {
			for(k=0; k<n; k++) {
				if(d[i]==a[j][j]) brojA++;
			}
		}
		for(j=0; j<m; j++) {
			for(k=0;k<n;k++) {
				if(d[i]==b[j][k]) brojB++;
			}
		}
			for(j=0; j<m; j++) {
			for(k=0;k<n;k++) {
				if(d[i]==c[j][k]) brojC++;
			}
		}
		if(brojA!=brojB || brojC!=brojB || brojA!=brojC) {
			printf("NE");
			return 0; 
		}
	}
	printf("DA");
	return 0;
}
