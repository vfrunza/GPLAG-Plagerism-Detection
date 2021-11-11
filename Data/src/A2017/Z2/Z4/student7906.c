#include <stdio.h>

int main()
{
	int a[250][250],b[250][250],c[250][250],i,j,m,n,k,g,brojac1=0,brojac2=0,brojac3=0,x;


	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
	} while(m>100 || m<0 || n>100 || n<0);

	printf("Unesite clanove matrice A: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d",&a[i][j]);
		}
	}
	printf("Unesite clanove matrice B: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d",&b[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d",&c[i][j]);
		}
	}
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			for(k=0; k<m; k++) {
				for(g=0; g<n; g++) {
					x=a[i][j];
					if(x==b[k][g]) brojac1++;
					if(x==c[k][g]) brojac2++;
					if(x==a[k][g]) brojac3++;
				}
			}
			if(brojac1!=brojac2 || brojac1!=brojac3 || brojac2!=brojac3) {
				printf("NE");
				return 0;
			}
			brojac1=0;
			brojac2=0;
			brojac3=0;
		}
	}
	printf("DA");
	return 0;
}
