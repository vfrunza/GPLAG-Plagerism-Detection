#include <stdio.h>


int validan_znak(char znak){
	return znak == '(' || znak == ')' || znak == ',' || znak =='.' || znak == '-';
}

int jel_cifra(char znak){
	return znak >= '0' && znak <= '9';
}

int provjera(char znak){
	return validan_znak(znak) || jel_cifra(znak);
}

int postoji_tacka(char *p, char *k){
	for(; p < k; ++p)
		if(*p == '.')
			return 1;
	return 0;
}

float pretvori_u_broj(char *p, char *k){
	float broj = 0;
	int tezina = 1;
	if(postoji_tacka(p, k) == 0){
		--k;
		while (k >= p) {
			broj += (*k - '0') * tezina;
			tezina *= 10;
			--k;
		}
	}
	else{
		float decimalni_broj;
		--k;
		while (*k != '.') {
			decimalni_broj += (*k - '0') * tezina;
			tezina *= 10;
			--k;
		}
		while (decimalni_broj >= 1)
			decimalni_broj /= 10;
		--k;
		tezina = 1;
		while (k >= p) {
			broj += (*k - '0') * tezina;
			tezina *= 10;
			--k;
		}
		broj += decimalni_broj;
	}
	return broj;
}

float min (float x1, float x2){
	return x1 < x2 ? x1 : x2;
}

float max (float x1, float x2){
	return x1 > x2 ? x1 : x2;
}

void izbaci(char *p, char *k){
	for(;*k != '\0'; ++p, ++k)
		*p = *k;
	*p = '\0';
}

int provjera_ipsravnosti(char *t){
	char *pom, *tmp;
	int broj_tacaka = 0, broj_zareza = 0, broj_minusa = 0;
	while(*t != '\0'){
		pom = t;
		while(*pom != '\0'){
			if(*pom == ')')
				break;
			++pom;
		}
		tmp = t;
		while(tmp < pom){
			if(*tmp == '.')
				++broj_tacaka;
			if(*tmp == ',')
				++broj_zareza;
			if(*tmp =='-')
				++broj_minusa;
			++tmp;
		}
		if(broj_tacaka != 0 && broj_tacaka != 1 && broj_tacaka != 2)
			return -1;
		if(broj_minusa != 0 && broj_minusa != 1 && broj_minusa != 2)
			return -1;
		if(broj_zareza != 1)
			return -1;
		t = tmp + 1;
		broj_zareza = broj_tacaka = broj_minusa = 0;
	}
	return 1;
}

int parsiraj (char *s){
	char *p = s;
	for(; *p != '\0'; ++p)
		if(provjera(*p) == 0)
			return -1;
	p = s;
	if(*p != '(')
		return -1;
	++p;
	while(*p != '0'){
		if(*p == '(')
			if(jel_cifra(*(p + 1)) == 0|| *(p - 1) != ',')
				return -1;
		if(*p == '-'){
			if( jel_cifra(*(p + 1)) == 0 || *(p - 1) != '(')
				return -1;
		}
		if(*p == '.'){
			if(*(p+1) != ',' && *(p + 1) != ')' && jel_cifra(*(p + 1)) == 0)
				return -1;
			if(jel_cifra(*(p - 1) == 0))
				return -1;
		}
		if(*p == ','){
			if(jel_cifra(*(p + 1) == 0) && *(p + 1) != ')')
				return -1;
			if(jel_cifra(*(p - 1) == 0) && *p - 1 != '.' && *(p - 1) != '(')
				return -1;
		}
		if(*p == ')'){
			if(*(p + 1) == '\0' && (jel_cifra(*(p - 1)) == 1 || *(p - 1) == '.'))
				break;
			if(*(p + 1) != '(' && jel_cifra(*(p - 1)) == 0 && *(p - 1) != '.')
				return -1;
		}
		++p;
	}
	return provjera_ipsravnosti(s);
}

int poredi(float x1, float y1, float x2, float y2, float str_x, float str_y){
	float eps = 0.0001;
	float max_x = max(x1, x2) + eps, min_x = min(x1, x2) - eps;
	float max_y = max(y1, y2) + eps, min_y = min(y1, y2) - eps;
	if(max_x < str_x || str_x < min_x)
		return 1;
	if(max_y < str_y || str_y < min_y)
		return 1;
	return 0;
	
}

void izbacivanje_tacaka(char *po, float x1, float y1, float x2, float y2){
	char *p = po;
	int minus = 0;
	while(jel_cifra(*p) == 0)
		++p;
	if(*(po + 1) == '-')
		minus = 1;
	char *n_p = p;
	while (*n_p != ',') 
		++n_p;
	float x = pretvori_u_broj(p, n_p);
	if(minus == 1)
		x *= -1;
	minus = 0;
	p = n_p + 1;
	if(*p == '-'){
		++p;
		minus = 1;
	}
	n_p = p;
	while (*n_p != ')') 
		++n_p;
	float y = pretvori_u_broj(p, n_p);
	if(minus == 1)
		y *= -1;
	if(poredi(x1, y1, x2, y2, x, y))
		izbaci(po, n_p + 1);
}

char *obuhvat (char *tekst, float x1, float y1, float x2, float y2){
	if(parsiraj(tekst) == -1)
		return 0;
	char *p = tekst;
	while(*p != '\0'){
		char *kraj_para = p;
		while(*kraj_para != ')')
			++kraj_para;
		izbacivanje_tacaka(p, x1, y1, x2, y2);
		p = kraj_para + 1;
	}
	return tekst;
}


int main() {
	char br[] = "(1,2)(5,5)";
	printf("%s", obuhvat(br, 3,3,8,8));
	return 0;
}
