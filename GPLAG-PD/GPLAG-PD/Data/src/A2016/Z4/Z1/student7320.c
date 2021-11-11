#include <stdio.h>
#include <string.h>

int duzina_stringa(char *s) {
	int duz = 0;
	while (*s != '\0') {
		duz++;
		s++;
	}
	return duz;
}

int jednakost_stringova(char *s1, char *s2) { // FUNKCIJA KOJA VRACA KEC AKO SU JEDNAKI, NULA AKO NISU
	char *p1 = s1;
	char *p2 = s2;
	int i;
	int d1 = duzina_stringa(p1);
	int d2 = duzina_stringa(p2);
	if (d1 != d2) return 0;
	for (i = 0; i < d1; i++) 
	if (s1[i] != s2[i]) return 0;
	return 1;
}

int slovo(char c) {
	return (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z');
}
void ocisti(int *niz) {
	int i;
	for (i = 0; i < 30; i++)
		niz[i] = 0;
}

char pretvori_u_veliko(char c) {
	if (c >= 'a' && c <= 'z') return c - 32;
	else return c;
}
char* izbaci_najcescu(char s[]) {
	char *p = s;
	char *trenutna_rijec = s;
	int znakovi1[30], znakovi2[30];
	ocisti(znakovi1);
	ocisti(znakovi2);
	int maks = 0, i, duzina_maks_rijeci = 0, duzina_trenutne_rijeci;
	char *pok_na_najvecu = s;
	int posebni_slucaj = 0;
	while (*p != '\0') {
		duzina_trenutne_rijeci = 0;
		while (*trenutna_rijec != '\0') {
			int ponavljanje_rijeci = 1;
			
			if (slovo(*trenutna_rijec)) {
				//printf("%c", *trenutna_rijec);
				duzina_trenutne_rijeci++;
				znakovi1[pretvori_u_veliko(*trenutna_rijec) - 'A']++;
			}
			else {
				posebni_slucaj++;
				if (duzina_trenutne_rijeci > 0) {
					//printf(" duzina je %d\n", duzina_trenutne_rijeci);
					
					char *trazim_je = trenutna_rijec;
					
					while (*trazim_je != '\0') {
						if (slovo(*trazim_je)) {
							znakovi2[pretvori_u_veliko(*trazim_je) - 'A']++;
						}
						else {
							int jesu_iste = 1;
							for (i = 0; i < 30; i++) {
								if (znakovi1[i] != znakovi2[i]) {
									jesu_iste = 0;
									break;
								}
							}
							if (jesu_iste) {
								ponavljanje_rijeci++;
								//printf("NASO JEDNU KOJA SE PODUDARA SA %c\n", *(trenutna_rijec - duzina_trenutne_rijeci));
							}
							ocisti(znakovi2);
						}
						trazim_je++;
					}
					if (ponavljanje_rijeci > maks) {
						maks = ponavljanje_rijeci;
						pok_na_najvecu = trenutna_rijec - duzina_trenutne_rijeci;
						duzina_maks_rijeci = duzina_trenutne_rijeci;
					}
					ocisti(znakovi1);
				}
				duzina_trenutne_rijeci = 0;
				
			}
			trenutna_rijec++;
		}
		p++;
	}
	if (posebni_slucaj == 0) {
		*s = '\0';
		return s;
	}
	// pokazivac na rijec koja se najvise puta ponavlja se nalazi u pok_na_najvecu
	// duzina te rijeci je duzina_maks_rijeci
	// i ponavlja se maks puta
	//printf("%d %c %d\n", maks, *pok_na_najvecu, duzina_maks_rijeci);
	//p = s;
	int dodat = 0;
	if (pok_na_najvecu == s) {
		dodat = 1;
	}
	p--;
	char *spasen1 = p;
	trenutna_rijec = p;
	char *najveca = pok_na_najvecu + duzina_maks_rijeci - 1;
	while (p != s) {
		duzina_trenutne_rijeci = 0;
		int guess = 0;
		char *moja_losa_kopija = trenutna_rijec;
		while (trenutna_rijec != s) {
			if (slovo(*trenutna_rijec)) {
				if (pretvori_u_veliko(*trenutna_rijec) == pretvori_u_veliko(*najveca)) {
					guess++;
					najveca--;
				}
				duzina_trenutne_rijeci++;
			}
			
			else {
				if (guess == duzina_maks_rijeci && guess == duzina_trenutne_rijeci) {
					//printf("\nNASO JE\n");
					//printf("ovaj pokazuje na %c\n a ovaj na %c\n-----------\n", *(trenutna_rijec + 1), *(trenutna_rijec + 1 + guess));
					maks--;
					char *cpy = trenutna_rijec + 1;
					char *moveam = trenutna_rijec + guess + 1;
					while (*moveam != '\0') {
						*cpy = *moveam;
						moveam++;
						cpy++;
					};
						//printf("%c, %c\n", *cpy, *moveam);
					moveam -= duzina_maks_rijeci;
					*moveam = '\0';
					moja_losa_kopija--;
				}
					//printf("-----------\nPokazivac pokazuje na %c\n", *(trenutna_rijec - 1));
				najveca = pok_na_najvecu + duzina_maks_rijeci - 1;
				
				duzina_trenutne_rijeci = 0;
				guess = 0;
			} 
			
			trenutna_rijec--;
		}
		p--;
	}
	p = s;
	int cnt = 0;
	najveca = pok_na_najvecu;
	int sacuvao = duzina_maks_rijeci;
	while (duzina_maks_rijeci--) {
		//printf("%c, %c\n", *najveca, *s);
		if (pretvori_u_veliko(*s) == pretvori_u_veliko(*najveca)) {
			cnt++;
		}
		najveca++;
		s++;
	}
	if (cnt==sacuvao) return p + cnt;
	return p;
}
int main() {
	printf("%s", izbaci_najcescu(" je  ovoa neki ovoa bezvezni tekst"));
	return 0;
}

/* BUG FIX ZA DODATI :

RIJEC ej je isto sto i rijec je (ubaciti bolji nacin od brojanja znakova)

*/