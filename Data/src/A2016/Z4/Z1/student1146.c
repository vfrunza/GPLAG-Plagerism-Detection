#include <stdio.h>

int je_slovo(char c) { /* po uslovu zadatka */
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int poredi(char x, char y) { /* case insensitive poredjenje */
	if (x >= 'a') x-= 'a' - 'A';
	if (y >= 'a') y-= 'a' - 'A';
	return x == y;
}

int strlen_moj(char *x) {
	int len = 0;
	while (*x++) len++;
	return len;
}

char *find_next(char *string, char *rijec) { /* nalazi rijec u stringu preskakajuci prvo slovo stringa */
	char *p;
	int i;
	
	for (p = string + 1; *p; ) {
		while (*p && !je_slovo(*p)) p++; /* idemo do sljedece rijeci */
		if (!*p) break;
		for (i = 0; je_slovo(p[i]) && je_slovo(rijec[i]); i++) /* idemo do prvog razlicitog znaka */
			if (!poredi(p[i], rijec[i])) break;
		if (!je_slovo(p[i]) && !je_slovo(rijec[i])) return p; /* ako je to kraj obje rijeci nasli smo */
		while (*p && je_slovo(*p)) p++; /* preskacemo ostatak trenutne rijeci */
	}
	
	return 0; /* nismo nasli rijec */
}

char *izbaci_najcescu(char *string) {
	char *najcesca = 0, *counter, *p;
	int max = -1, broj, len_stringa, za_obrisati = 0, i;
	
	for (p = string; *p; ) { /* za svaku rijec u stringu*/
		while (*p && !je_slovo(*p)) p++; /* idemo do sljedece rijeci */
		if (!*p) break;
		broj = 1;
		for (counter = p; counter; counter = find_next(counter, p)) 
			broj++; /* brojanje koliko se puta rijec pojavljuje */
		if (broj > max) { /* nova najcesca rijec */
			najcesca = p;
			max = broj;
		}
		while (*p && je_slovo(*p)) p++; /* preskacemo ostatak trenutne rijeci */
	}

	if (!najcesca) return string; /* ako string nema rijeci ne radimo nista */
	
	for (p = najcesca; je_slovo(*p); p++) za_obrisati++;
	
	p = najcesca; 
	while (*p) { /* brisemo sva ponavljanja osim prvog (treba nam za poredjenje) */
		p = find_next(p, najcesca);
		if (!p) break;
		len_stringa = strlen_moj(p);
		for (i = 0; i <= len_stringa - za_obrisati; i++)
			p[i] = p[i + za_obrisati];
	}
	p = najcesca; /* brisemo prvo ponavljanje u stringu */
	len_stringa = strlen_moj(najcesca);
	for (i = 0; i <= len_stringa - za_obrisati; i++)
		p[i] = p[i + za_obrisati];

	return string;
}

int main() {
	char string[] = "Pet plus pet plus pet daje petnaest";
	
	izbaci_najcescu(string);
	printf("%s", string);
	
	return 0;
}
