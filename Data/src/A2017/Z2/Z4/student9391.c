#include <stdio.h>

int main() {
	int m,n,i,j,k,l,brojac_a,brojac_b,brojac_c,broj,a[100][100],b[100][100],c[100][100];
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m,&n);
	}while(m>100 || n>100);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d", &a[i][j]);
		}
	}
	printf("Unesite clanove matrice B: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d", &b[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d", &c[i][j]);
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			
			broj=a[i][j];
			brojac_a=0;
			brojac_b=0;
			brojac_c=0;
			for(k=0;k<m;k++){
				for(l=0;l<n;l++){
					if(a[k][l]==broj) brojac_a++;
					if(b[k][l]==broj) brojac_b++;
					if(c[k][l]==broj) brojac_c++;
				}
			}
			if(brojac_a!=brojac_b || brojac_b!=brojac_c || brojac_a!=brojac_c) {
				printf("NE");
				return 0;
			}
		}
	}
	printf("DA");
	return 0;
}
