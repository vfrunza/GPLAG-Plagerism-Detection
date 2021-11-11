#include <stdio.h>

int main() {
	int c=0,b=0,s=0,v=0,p=0;
	int n=0, u;
	
	printf("Unesite vozila: ");
	
	while ((u = getchar()) != '\n') {
#define jel(a) (u == a || u == a - 32)
		if jel('k') break;
		n++;
		if jel('c') c++;
		else if jel('b') b++;
		else if jel('s') s++;
		else if jel('v') v++;
		else if jel('p') p++;
		else {
			printf("Neispravan unos\n");
			n--;
		}
	}
	
	printf("Ukupno evidentirano %d vozila.\n", n);
	
	if (n == 0) {
		printf("Najpopularnija boja je crna (0.00%).\n");
		return 0;
	}
	
#define najveci(x) (x >= c && x >= b && x >= s && x>= v && x >= p)
#define gotovo(znak, color) if (najveci(znak)) {printf("Najpopularnija boja je "#color" (%.2f%%).", 100.*znak/n); return 0; }
	gotovo(c, crna)
	gotovo(b, bijela)
	gotovo(s, siva)
	gotovo(v, crvena)
	gotovo(p, plava)

	return 0;
}
