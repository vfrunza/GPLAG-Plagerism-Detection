#include <stdio.h>
#include <math.h>

int izbaci(char *niz, int daLiJePrva) {
	char *temp=niz;
	int broj_clanova=2;
	
	while(*niz!=')') {
		broj_clanova++;
		niz++;
	}
	niz++;
	/* Poseban slucaj ako se radi o zadnjim koordinatama */
	if(!*niz) {
		if(daLiJePrva) {
			niz=temp;
			*niz='\0';
			return 1;
		}
		else {
			niz=temp;
			*(niz-1)='\0';
			return 1;
		}
	}
	
	niz=temp;
	while(*(niz+broj_clanova)) {
		*niz=*(niz+broj_clanova);
		niz++;
	}
	*niz=*(niz+broj_clanova);
	return 0;
}

float pretvori(char *niz) {
	/* Pretvaranje stringa u float prije poredjenja */
	float x=0.;
	int minus=0, tacka=0, q=10;
	char *temp=niz;
	
	if(*niz=='-') {
		minus=1;
		niz++;
	}
	
	while(*niz!=',' && *niz!=')') {
		if(*niz=='.') {
			tacka=1;
			break;
		}
		niz++;
	}
	niz++;
	
	if(tacka) {
		while(*niz!=',' && *niz!=')') {
			x+=((float)(*niz-48))/q;
			q*=10;
			niz++;
		}
	}
	
	niz=temp;
	while(*niz!='.' && *niz!=',' && *niz!=')') niz++;
	niz--;
	q=1;
	while(*niz!='(' && *niz!=',' && *niz!='-') {
		x+=(*niz-48)*q;
		q*=10;
		niz--;
	}
	if(minus) x*=-1;
	return x;
}

int daLiJeVan(char *niz, float x1, float y1, float x2, float y2) {
	float eps=0.0001, broj1, broj2;
	if(x1>x2 || y1>y2) return 1;
	
	broj1=pretvori(niz);
	if((broj1<x1 && fabsf(broj1-x1)>eps) || (broj1>x2 && fabsf(broj1-x2)>eps)) {
		return 1;
	}
	while(*niz!=',') niz++;
	niz++;
	broj2=pretvori(niz);
	if((broj2<y1 && fabsf(broj2-y1)>eps) || (broj2>y2 && fabsf(broj2-y2)>eps)) {
		return 1;
	}
	return 0;
}

char *obuhvat(char *niz, float x1, float y1, float x2, float y2) {
	char *temp=niz;
	int tacka, minus, broj, zadnji, daLiJePrva=1;
	
	
	/* Provjera ispravnosti stringa */
	
	if(!*niz) return niz;
	while(*niz) {
		
		/* Prva koordinata */
		
		if(*niz!='(') return NULL;
		niz++;
		tacka=0; minus=0; broj=0;
		while(*niz!=',' && *niz) {
			if(*niz<48 || *niz>57) {
				if(*niz=='-' && minus) return NULL;
				else if(*niz=='.' && tacka) return NULL;
				else if(*niz=='.') tacka=1;
				else if(*niz!='-') return NULL;
				if(*niz=='.' && (*(niz-1)<48 || *(niz-1)>57)) return NULL;
			}
			else broj=1;
			niz++;
			minus=1;
		}
		/* Izmedju mora biti zarez */
		
		if(!broj) return NULL;
		if(*niz!=',') return NULL;
		
		/* Druga koordinata */
		niz++;
		tacka=0; minus=0; broj=0;
		
		while(*niz!=')' && *niz) {
			if(*niz<48 || *niz>57) {
				if(*niz=='-' && minus) return NULL;
				else if(*niz=='.' && tacka) return NULL;
				else if(*niz=='.') tacka=1;
				else if(*niz!='-') return NULL;
				if(*niz=='.' && (*(niz-1)<48 || *(niz-1)>57)) return NULL;
			}
			else broj=1;
			niz++;
			minus=1;
		}
		
		if(!broj) return NULL;
		if(*niz!=')') return NULL;
		niz++;
		if(*niz==',') {
			if(!*(niz+1)) return NULL;
		}
		if(*niz) niz++;
	}
	
	/* Provjera i eventualno izbacivanje iz niza */
	
	niz=temp;
	while(*niz) {
		niz++;
		if(daLiJeVan(niz, x1, y1, x2, y2)) {
			zadnji=izbaci(niz-1, daLiJePrva);
			if(zadnji) break;
			niz--;
		}
		else {
			while(*niz && *niz!='(') niz++;
			daLiJePrva=0;
		}
	}
	
	return temp;
}

int main() {
	char s[] = "(-3,2.7)";
	if(!obuhvat(s,-3,-3,-3,-3)) printf("0");
	else printf("1");
	return 0;
}
