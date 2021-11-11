#include <stdio.h>
#define visina 100
#define sirina 100

int main() {
	int i=0,j=0,matricaA[visina][sirina], matricaB[visina][sirina], matricaC[visina][sirina],m=0,n=0,niz[100],a=0;
	int brojacA[101]={0},brojacB[101]={0},brojacC[101]={0};
	do {
		printf ("Unesite brojeve M i N: ");
		scanf ("%d %d",&m,&n);
	}
	while (m>visina || n>sirina );
	printf ("Unesite clanove matrice A: ");
	for (i=0;i<visina;i++) {
		for(j=0;j<sirina;j++){
			scanf ("%d",&matricaA[i][j]);
			
		}
	}
	printf ("Unesite clanove matrice B: ");
	for (i=0;i<visina;i++) {
		for (j=0;j<sirina;j++) {
			scanf ("%d", &matricaB[i][j]);
		}
	}
	printf ("Unesite clanove matrice C: ");
	for (i=0;i<visina;i++) {
		for (j=0;j<sirina;j++) {
			scanf ("%d",&matricaC[i][j]);
		}
	}
	for (i=0;i<visina;i++) {
		for(j=0;j<sirina;j++) {
			for (a=0;a<100;a++) {
				brojacA[niz[a]]++;
			}}}
			
	for (i=0;i<visina;i++) {
		for (j=0;j<sirina;j++) {
			for(a=0;a<100;a++) {
				brojacB[niz[a]]++;
			}
		}
	}
	for (i=0;i<visina;i++) {
		for(j=0;j<sirina;j++) {
			for(a=0;a<100;a++) {
				brojacC[niz[a]]++;
			}
		}
	}

	if (brojacA[niz[i]]!=brojacB[niz[i]] || brojacA[niz[i]]!=brojacC[niz[i]] || brojacC[niz[i]]!=brojacB[niz[i]]) {
		printf ("NE\n");
	}
	else printf ("DA\n");
	return 0;
}
