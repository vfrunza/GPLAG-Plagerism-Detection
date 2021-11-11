#include <stdio.h>


int poredi_rijeci(char *p_rijec, char *d_rijec){
	if(*p_rijec == '\0' && *d_rijec != '\0')
		return 0;
	if(*d_rijec == '\0' && *p_rijec != '\0')
		return 0;
	while (*p_rijec != '\0' && *d_rijec != '\0') {
		if(*p_rijec != *d_rijec)
			return 0;
		++p_rijec;
		++d_rijec;
	}
	return 1;
}

void napravi_mjesto(char *mjesto, int koliko_mjesta){
	while(koliko_mjesta != 0){
		char *p = mjesto;
		while(*p != '\0')
			++p;
		while(p >= mjesto){
			*(p + 1) = *p;
			--p;
		}
		--koliko_mjesta;
	}
}


int trazi_rijec(char *s1, char *s2){
	char *pocetak = s1;
	while(*s1 != '\0'){
		while(*s1 == ' ')
			++s1;
		char *p = s1;
		char *q = s2;
		while(*p++ == *q++)
			if(*q == '\0' && (*p == ' ' || *p == '\0'))
				return s1 - pocetak;
		while(*s1 != ' ' && *s1 != '\0')
			++s1;
	}
	return -1;
}

int duzina_rijeci(char *p){
	int brojac = 0;
	while (*p != '\0') {
		++brojac;
		++p;
	}
	return brojac;
}

char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci){
	int i = 0, mjesto;
	
	while(i < broj_rijeci){
		if(poredi_rijeci(rijeci[i], zamjene[i]) == 1) {
			++i;
			continue;
		}
		int d_p = duzina_rijeci(rijeci[i]), d_d = duzina_rijeci(zamjene[i]);
		int povecaj = -1, n_duzina = 0;		
		if( d_p < d_d)
			povecaj = d_d - d_p;
		for(mjesto = trazi_rijec(tekst, rijeci[i]); ; mjesto = trazi_rijec(tekst, rijeci[i])){
			if(mjesto == -1)
				break;
			n_duzina = d_p;
			if(povecaj != -1){
				napravi_mjesto(tekst + mjesto, povecaj);
				n_duzina = d_d;
			}
			
			char *k = tekst + mjesto + n_duzina;
			char *p = tekst + mjesto;
			char *n = zamjene[i];

			while (*n != '\0') {
				*p = *n;
				++p;
				++n;
			}
			while(*k != '\0'){
				*p = *k;
				++p;
				++k;
			}
			*p = '\0';
		}
		++i;
	}
	return tekst;
}




int main() {
	char* rijeci[2] = {"beli", "sneg"};
	char* zamjene[2] = {"bijeli", "snijeg"};
	char tekst[100] = "beli sneg je pokrio beli breg";
	printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 2));
	return 0;
}
