#include <stdio.h>
#include <stdbool.h>
int main()
{
	int min, temp, m=-1, n=-1, i, j;
	int matrica_a[100][100], matrica_b[100][100], matrica_c[100][100], niz_a[10000], niz_b[10000], niz_c[10000];
	bool kljuc=true;
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
	} while(m<0 || n<0 || n>100 || m>100);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d", &matrica_a[i][j]);
		}
	}
	printf("Unesite clanove matrice B: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d", &matrica_b[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d", &matrica_c[i][j]);
		}
	}
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			niz_a[n*i + j]=matrica_a[i][j];
		}
	}
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			niz_b[n*i+j]=matrica_b[i][j];
		}
	}
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			niz_c[n*i + j]=matrica_c[i][j];
		}
	}
	for(i=0; i<m*n-1; i++) {
		min=i;
		for(j=i+1; j<m*n; j++) {
			if(niz_a[min]>niz_a[j]) {
				min=j;
			}
		}
		temp=niz_a[i];
		niz_a[i]=niz_a[min];
		niz_a[min]=temp;

	}
	for(i=0; i<m*n-1; i++) {
		min=i;
		for(j=i+1; j<m*n; j++) {
			if(niz_b[min]>niz_b[j]) {
				min=j;
			}
		}
		temp=niz_b[i];
		niz_b[i]=niz_b[min];
		niz_b[min]=temp;

	}
	for(i=0; i<m*n-1; i++) {
		min=i;
		for(j=i+1; j<m*n; j++) {
			if(niz_c[min]>niz_c[j]) {
				min=j;
			}
		}
		temp=niz_c[i];
		niz_c[i]=niz_c[min];
		niz_c[min]=temp;

	}
	for(i=0; i<m*n; i++) {
		if(niz_a[i]!=niz_b[i] || niz_b[i]!=niz_c[i]) {
			kljuc=false;
			printf("NE");
			break;
		}
	}
	if(kljuc==true)
		printf("DA");
	return 0;
}
