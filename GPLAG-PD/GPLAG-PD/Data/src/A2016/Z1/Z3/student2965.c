#include <stdio.h>

int main() {
    char m;
	int c=0,b=0,s=0,v=0,p=0,ukvozila=0;
	float bc,bb,bs,bv,bp;
	printf("Unesite vozila: ");
	do {
		scanf("%c",&m);
		if(m!='c' && m!='C' && m!='p' && m!='P' && m!='s' && m!='S' && m!='b' && m!='B' && m!='v' && m!='V' && m!='k' && m!='K') {
			printf("Neispravan unos\n");
		} else if(m=='c' || m=='C' || m=='p' || m=='P' || m=='s' || m=='S' || m=='b' || m=='B' || m=='v' || m=='V') {
			ukvozila++;
		}
		if(m=='c' || m=='C') {
			c++;
		}
		if(m=='p' || m=='P') {
			p++;
		}
		if(m=='s' || m=='S') {
			s++;
		}
		if(m=='b' || m=='B') {
			b++;
		}
		if(m=='v' || m=='V') {
			v++;
		}
	} while (m!='k' && m!='K');
	printf("Ukupno evidentirano %d vozila.\n",ukvozila);
	if(ukvozila!=0) {
		if(c>=p && c>=s && c>=b && c>=v) {
			bc=(c*100.0)/ukvozila;
			printf("\nNajpopularnija boja je crna (%.2f%%).",bc);
		} else if(b>=c && b>=s && b>=p && b>=v) {
			bb=(b*100.0)/ukvozila;
			printf("\nNajpopularnija boja je bijela (%.2f%%).",bb);
		} else if(s>=c && s>=p && s>=b && s>=v) {
			bs=(s*100.0)/ukvozila;
			printf("\nNajpopularnija boja je siva (%.2f%%).",bs);
		} else if(v>=c && v>=p && v>=b && v>=s) {
			bv=(v*100.0)/ukvozila;
			printf("\nNajpopularnija boja je crvena (%.2f%%).",bv);
		} else if(p>=c && p>=b && p>=v && p>=s) {
			bp=(p*100.0)/ukvozila;
			printf("\nNajpopularnija boja je plava (%.2f%%).",bp);
		}
	} else {
		printf("Najpopularnija boja je crna (0.00%%).");
	  }
	return 0;
}
