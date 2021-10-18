#include <stdio.h>

int main() {
	int m,n;
	int brojac1, brojac2, brojac;
	int tacnost=1;
	int i,j,k,l;
	int a[100][100];
	int b[100][100];
	int c[100][100];
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
	}
	while(m<0 || n<0 || m>100 || n>100);
	
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
		for(j=0; j<n; j++) {
			scanf("%d", &c[i][j]);
		}
	}
	
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			brojac1=0;
			brojac2=0;
			brojac=0;
			for(k=0; k<m; k++){
				for(l=0; l<n; l++){
					if(a[i][j]==b[k][l]) brojac1++;
					if(a[i][j]==c[k][l]) brojac2++;
					if(a[i][j]==a[k][l]) brojac++;
				}
			}
			if(brojac1!=brojac2 || brojac1!=brojac || brojac2!=brojac) {
				tacnost=0;
				break;
			}
		}
		if(!tacnost) break;
	}
	
	if(tacnost) printf("DA");
	else printf("NE");
	printf("\n");
	
	
	return 0;
}
