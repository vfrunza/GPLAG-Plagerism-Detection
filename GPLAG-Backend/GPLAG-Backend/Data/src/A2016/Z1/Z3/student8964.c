#include <stdio.h>

int main() {
	int i=0, j=0, k=0, m=0, n=0, p;
	char a;
	printf("Unesite vozila: ");
	do {
		scanf ("%c", &a);
		if (a=='C' || a=='c') {
			i++;
		} else {
			if (a=='B' || a=='b') {
				j++;
			} else {
				if (a=='S' || a=='s') {
					k++;
				} else {
					if (a=='V' || a=='v') {
						m++;
					} else {
						if (a=='P' || a=='p') {
							n++;
						} else {
							if (a!='k' && a!='K' && a!='\n') {
								printf ("Neispravan unos\n");
							}
						}
					}
				}
			}
		}
	} while (a!='k' && a!='K');
	p=i+j+k+m+n;
	printf ("Ukupno evidentirano %d vozila.\n", p);
	if (i>=j && i>=k && i>=m && i>=n) {
		printf ("Najpopularnija boja je crna (%.2f%%).", (float) i*100/p);
	} else {
		if (j>=i && j>=k && j>=m && j>=n) {
			printf ("Najpopularnija boja je bijela (%.2f%%).", (float) j*100/p);;
		} else {
			if (k>=i && k>=j && k>=m && k>=n) {
				printf ("Najpopularnija boja je siva (%.2f%%).", (float) k*100/p);
			} else {
				if (m>=i && m>=j && m>=k && m>=n) {
					printf ("Najpopularnija boja je crvena (%.2f%%).", (float) m*100/p);
				} else {
					if (n>=i && n>=j && n>=k && n>=m) {
						printf ("Najpopularnija boja je plava (%.2f%%).", (float) n*100/p);
					}
				}
			}
		}
	}
	return 0;
}
