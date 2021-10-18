#include <stdio.h>

int strlen_moj(char *x) {
	int len = 0;
	while (*x++) len++;
	return len;
}

char *zamjena_rijeci(char *tekst, char **rijeci, char **zamjene, int broj_rijeci) {
	int i, j, k, len, len_rijeci, za_pomjeriti;
	char *p;
	
	for (p = tekst; *p; ) {
		while (*p && *p == ' ') p++; /* idemo do pocetka sljedece rijeci */	
		if (!*p) break;
		for (i = 0; i < broj_rijeci; i++) {
			for (j = 0; p[j] && rijeci[i][j]; j++) /* idemo do prvog razlicitog znaka */
				if (p[j] != rijeci[i][j]) break;
			
			if ((p[j] == '\0' || p[j] == ' ') && rijeci[i][j] == '\0') { /* ako je taj znak kraj prve i druge rijeci */
				len = strlen_moj(p);
				len_rijeci = strlen_moj(zamjene[i]);
				za_pomjeriti = len_rijeci - j;
				
				if (za_pomjeriti > 0) 
					for (k = len; k >= 0; k--) /* pravimo prostor za novu rijec */
						p[k + za_pomjeriti] = p[k];
				else if (za_pomjeriti < 0) 
					for (k = 0; k <= len + za_pomjeriti; k++) /* brisemo dio koji je viska */
						p[k] = p[k - za_pomjeriti];

				for (k = 0; k < len_rijeci; k++) /* upisujemo novu rijec */
					p[k] = zamjene[i][k];
				
				p += len_rijeci;
				break;
			}
		}
		
		while (*p && *p != ' ') p++; /* idemo dalje */
	}
	
	return tekst;
}

int main() {
	char *rijeci[] = { "test", "jedan" };
    char *zamjene[] = { "", "oooooooooooooo" };
    char tekst[100] = " a c test jedan  b ";
    printf("'%s'", zamjena_rijeci(tekst, rijeci, zamjene, 2));
    
    return 0;
}
