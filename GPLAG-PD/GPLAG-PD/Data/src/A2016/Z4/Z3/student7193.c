#include <stdio.h>

int duzinaRijeci(char* rijec) {
	int n = 0;
	while (*rijec != 0) {
		rijec++;
		n++;
	}
	return n;
}

int nadjiRijec(char* tekst, char* rijec) {
	char* pocetakTeksta = tekst;
	char* pocetakRijeci = rijec;
	int n = 0;
	while (*tekst != 0) {
		rijec = pocetakRijeci;
		if (*tekst == *rijec && (tekst == pocetakTeksta || *(tekst-1) == ' ')) {
			while(*tekst == *rijec) {
				tekst++;
				rijec++;
				n++;
				if (*tekst == 0 || *rijec == 0) 
					break;
			}
			if ((*(tekst) == 0 || *(tekst) == ' ') && (*rijec == 0))
				return n - duzinaRijeci(pocetakRijeci);
			tekst--;
			n--;
		}
		tekst++;
		n++;
	}
	return -1;
}

char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci) {
	char* pocetakTeksta = tekst, *krajTeksta = tekst, *x;
	int i, j, n, a, b;
	
	while (*krajTeksta != 0) {
		krajTeksta++;
	}
	
	for (i = 0; i < broj_rijeci; i++) {
		tekst = pocetakTeksta;
		while (*tekst != 0) {
			n = nadjiRijec(tekst, rijeci[i]);
			if (n != -1 && (tekst == pocetakTeksta || *(tekst-1) == ' ')) {
				a = duzinaRijeci(rijeci[i]);
				b = duzinaRijeci(zamjene[i]);
				if (a < b) {
					x = tekst;
					while (*x != 0) {
						x++;
					}
					while ((tekst+n) != x) {
						*(x + b - a) = *x;
						x--;
					}
					*(x + b - a) = *x;
					for (j = n; j < n + b; j++) {
						tekst[j] = zamjene[i][j-n];
					}

				} else if (a == b) {
					for (j = n; j < n + b; j++) {
						tekst[j] = zamjene[i][j-n];
					}
				} else if (a > b) {
					for (j = n; j < n + b; j++) {
						tekst[j] = zamjene[i][j-n];
					}
					x = tekst + n + b;
					while (*x != 0) {
						*x = *(x + a - b);
						x++;
					}
				}
				tekst += n;
			}
			tekst++;
		}
	}
	return pocetakTeksta;
}

int main() {
	

	char* rijeci[3] = {  "aaa", "b" };
	char* zamjene[3] = { "b", "cccc"};
	char tekst[100] = "aaa a aaa";
	printf(":%s:\n", zamjena_rijeci(tekst, rijeci, zamjene, 2));
	
	return 0;
}
