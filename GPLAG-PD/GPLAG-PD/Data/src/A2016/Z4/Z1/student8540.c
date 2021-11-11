#include <stdio.h>

int uporedi(char *s1, char *s2, int len) {
	int i = 0;
	
	while(i < len) {
		if (*s1 > 90 && *s2 < 91) {
			if (*s1 != *s2 + 32) return 0;
		} else if (*s1 < 91 && *s2 > 91) {
			if (*s1 + 32 != *s2) return 0;
		} else {
			if (*s1 != *s2) return 0;
		}
		s1++;
		s2++;
		i++;
	}
	
	return 1;
}

/* Ispitujue da li je karakter slovo */
int slovo(char c) {
	if ((c > 64 && c < 91) || (c > 96 && c < 123)) return 1;
	return 0;
}

/* Vraca pokazivac na zadnju najcescu rijec */
char *nadji_najcescu(char *s) {
	char *zadnja1 =  s, *zadnja2 = s, *t = s, *u;
	int len1, len2, len3, brojac, max;
	len1 = len2 = len3 = brojac = max = 0;

	while (*t != 0) {
		/*printf("%c\n", *t);*/
		if (slovo(*t)) { /* Znak je slovo */
			len1++;
			t++;
		} else { /* Znak nije slovo */
			t++;
			if (len1 == 0) { /* Jos trazimo rijec */
				continue;
			} else { /* Rijec zavrsava */
				/*printf("5");*/
				/* Poredimo svaku sljedecu rijec sa trenutnom */
				u = t;
				len2 = 0;
				zadnja2 = t - len1 - 1;
				while (*(u - 1) != 0) {
					if (slovo(*u)) { /* Znak je slovo */
						len2++;
					} else { /* Znak nije slovo */
						if (len2 == 0) { /* Jos trazimo rijec */
						} else { /* Rijec zavrsava */
							if (len1 == len2) {
								if (uporedi(t - len1 - 1, u - len1, len1)) {
									brojac++;
									zadnja2 = u - len1;
								}
							}
							len2 = 0;
						}
					}
					u++;
				}
				/*printf("%.*s%d\n", len1, t - len1 - 1, brojac);*/
				if (brojac > max) { /* Nasli smo novu najcescu rijec */
					max = brojac;
					zadnja1 = zadnja2;
				}
				brojac = 0;
				len1 = 0;
			}
		}
	}
	
	return zadnja1;
}


char *izbaci_najcescu(char *s) {
	char *t = s, *zadnja = nadji_najcescu(s);
	int len1 = 0, len2 = 0, n = 0;
	
	/* Odrediti duzinu najcesce */
	while (slovo(*(zadnja +len1))) {
		len1++;
	}
	
	while (t == s || *(t - 1) != 0) {
		if (t > zadnja + len1) { /* Prosli smo zadnju instancu najcesce rijeci */
		} else {
			if (slovo(*t)) { /* Znak je slovo */
				len2++;
			} else { /* Znak nije slovo */
				if (len1 == len2) { /* Rijec zavrsava */
					if (uporedi(zadnja, t - len1, len1)) {
						n += len1;
					}
				}
				len2 = 0;
			}
		}
		*(t - n) = *t;
		t++;
	}
	
	return s;
}

int main() {
	/*char s[] = "jen Dva    jen jen dVa.DVA dva tri tri tri tri "; */
	/*printf("%s", nadji_najcescu("jen Dva jen jen dVa.DVA dva tri tri tri tri "));*/
	/*printf("%s", izbaci_najcescu(s));*/
	return 0;
}

