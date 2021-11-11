#include <stdio.h>

#define je_cifra(x) ( (x) >= '0' && (x) <= '9' )

char *scan_float(char *poc, float *rez) { /* skenira float */
	char *tacka = 0, *kraj, *p;
	float radix;
	int znak = 1;

	if (*poc == '-') {
		znak = -1;
		poc++;
	}
	
	/*	poc - prvi broj u stringu (sa znakom smo se vec obracunali)
		tacka - pozicija tacke u stringu / ako nema tacke pokazuje na kraj
		kraj - pokazuje na prvi element iza zadnje cifre u stringu
	*/

	for (p = poc; ; p++) {
		if(!je_cifra(*p)) {
			if (*p == '.')
				tacka = p;
			else {
				kraj = p;
				break;
			}
		}
	}
	
	if (!tacka) tacka = kraj;
	
	*rez = 0;
	/* idemo od sredine ka krajevima i sastavljamo float */
	for (p = tacka + 1, radix = 0.1; p < kraj; p++, radix /= 10) 
		*rez += radix * (*p - '0');
		
	for (p = tacka - 1, radix = 1;   p >= poc; p--, radix *= 10) 
		*rez += radix * (*p - '0');
	
	*rez *= znak;
	return kraj;
}

#define eps 0.0001
int epsilon_interval(float donja, float x, float gornja) {
	/* epsilon test prema vani (zelimo da nam ostanu tacke koje su na granici) */
	return (x + eps > donja) && (x - eps < gornja);
}

int strlen_moj(char *x) {
	int len = 0;
	while (*x++) len++;
	return len;
}

int check_broj(char **p) {
	if (**p == '-') (*p)++; /* minus moze a i ne mora*/
	if (!je_cifra(**p)) return 0; /* mora biti bar jedna cifra ispred tacke */
	while (je_cifra(**p)) (*p)++;
	if (**p == '.') { /* tacka moze biti izmedju 2 niza cifata, a i ne mora */
		(*p)++;
		while (je_cifra(**p)) (*p)++;
	}
	return 1;
}

int check(char *s) { /* provjera stringa */
	char *p = s;
	while(*p) {
		if (*p++ != '(') return 0; /* ocekujem zagradu */
		
		if (!check_broj(&p)) return 0;
		
		if (*p++ != ',') return 0; /* ocekujem zarez izmedju dva broja */
		if (!check_broj(&p)) return 0;

		if (*p++ != ')') return 0; /* ocekujem zagradu */
		
		if (*p == '\0') return 1; /* ako je ovdje kraj dobri smo */
		if (*p++ != ',') return 0; /* ako nije ocekujem zarez i jos jedan unos */
	}
	return 0; /* ako naletim na null poslije zareza to je greska */
}

char *obuhvat(char *s, float x1, float y1, float x2, float y2) {
	float x, y;
	char *p = s, *poc;
	int k, len, za_obrisati;
	
	if(!check(s)) return 0; /* ako nije dobar format vracamo null */
	
	while (*p) {
		poc = p; /* pamtimo odakle smo krenuli */
		p++; /* zagrada */
		p = scan_float(p, &x); /* funkcija scan_float zgodno vraca pokazivac na znak iza zadnje cifre (zarez) */
		p++; /* preskocimo i taj zarez */
		p = scan_float(p, &y); /* jos jedan broj */
		p++; /* zagrada nas ne zanima */
		if (*p == ',') p++; /* ako izbacujemo svakako zelimo da pojedemo i zarez iza zagrade */
		if ( !(epsilon_interval(x1, x, x2) && epsilon_interval(y1, y, y2)) ) { /* ako nije u trazenom opsegu */
			len = strlen_moj(poc);
			za_obrisati = (p - poc);
			for (k = 0; k <= len - za_obrisati; k++) /* brisemo ga */
				poc[k] = poc[k + za_obrisati];
			p = poc;
		}
	}
	
	len = strlen_moj(s);
	if (len > 0 && s[len - 1] == ',') /* brisemo zarez na kraju */
		s[len - 1] = '\0';
	
	return s;	
}

int main() {
	char ulaz[100] = "(0,-3.1),(-15.09,4),(2.,2),(-1.1,217)";
	obuhvat(ulaz, -3, -3, 3, 3);
	printf("%s", ulaz);
	return 0;
}
