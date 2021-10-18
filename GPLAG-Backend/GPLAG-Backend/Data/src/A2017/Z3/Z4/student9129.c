#include <stdio.h>

/*
int max(int matrica[100][100], int visina, int sirina) {
	int hist[100000]={0},max,i,j,max_pojava;
	
	max=matrica[0][0];
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			if(matrica[i][j]>max) max=matrica[i][j];
		}
	}
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			hist[matrica[i][j]]++;
		}
	}
	max_pojava=hist[0];
	for(i=0; i<max; i++) {
		if(hist[i]>max_pojava) max_pojava=hist[i];
	}
	return max_pojava;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int n) {
	int i,j,k;
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			if(matrica[i][j]==n) {
				for(k=j; k<sirina-1; k++) {
					matrica[i][k]=matrica[i][k+1];
					sirina--;
				}
			}
		}
	}
	return sirina;
}
*/ 

int max(int mat[100][100], int visina, int sirina) {
	int max_pojava=0, i,j,k,max1,brojac=0,brojac2,ipom,jpom;

	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
				max1=mat[i][j];
				brojac2=0;
			for(ipom=0; ipom<visina; ipom++) {
				for(jpom=0; jpom<sirina; jpom++) {
					if(mat[ipom][jpom]==max1) brojac2++;
				}
			}
			if(brojac2>brojac) {
				max_pojava=max1;
				brojac=brojac2;	
			}
			else if(brojac2==brojac) {
				if(max1<max_pojava) max_pojava=max1;
				
			}
		}
	}
	return max_pojava;
}

int izbaci_kolone(int mat[100][100], int visina, int sirina, int n) {
	int i,j,k,l;
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			if(mat[i][j]==n) {
				for(k=0; k<visina; k++) {
					for(l=j; l<visina-1; l++) {
						mat[k][l]=mat[k][l+1];
					}
				}
				sirina--;
				j--;
			}
		}
	}
	return sirina;
}

int main() {
	int m,n, mat[100][100],i,j, maxi;
	printf("Unesite dimenzije: ");
	scanf("%d%d", &m, &n);
	printf("Clanovi: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	maxi=max(mat[100][100], m, n);
	printf("\n %d", maxi);
	
	return 0;
}
