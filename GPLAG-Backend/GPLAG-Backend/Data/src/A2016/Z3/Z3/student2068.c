#include <stdio.h>

int main() {
	int i, j, k, l, o, m, n, a[210][210];
	/* Unos matrice */
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
		if(m<1||m>200||n<1||n>200) printf("Brojevi nisu u trazenom opsegu.\n");
	} while(m<1||m>200||n<1||n>200);
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	/* Izbacivanje redova */
	for(i=1; i<m; i++) {
		for(j=0; j<i; j++) {
			for(k=0; k<n; k++) {
				if(a[i][k]!=a[j][k]) break;
			}
			if(k==n) /*red 'j' i red 'i' su isti...red i se brise...*/ {
				for(l=i; l<m-1; l++) {
					for(o=0; o<n; o++) {
						a[l][o]=a[l+1][o];
					}
				}
				m--;
				i--;
				break;
			}
		}
	}
	/* Izbacivanje kolona */
	for(i=1; i<n; i++) {
		for(j=0; j<i; j++) {
			for(k=0; k<m; k++) {
				if(a[k][i]!=a[k][j]) break;
			}
			if(k==m) /*kolona 'j' i kolona 'i' su iste...kolona i se brise...*/ {
				for(l=i; l<n-1; l++) {
					for(o=0; o<m; o++) {
						a[o][l]=a[o][l+1];
					}
				}
				n--;
				i--;
				break;
			}
		}
	}
	/* Ispis */
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
