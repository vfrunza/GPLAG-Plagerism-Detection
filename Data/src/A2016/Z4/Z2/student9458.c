#include <stdio.h>

int pozicija(char* tablica, char a){
	int br=0;
	char* t=tablica;
	while(*t!='\0'){
		if(*t==a)return br;
		else {br++;t++;}
	}
	return br;
}

char* kodiraj(char* recenica, char* tablica){
	int i=0,j;
	int niz[96];
	char* t=tablica,*c=recenica;
	char pom;
	for(i=0; i<96; i++)niz[i]=0;
	i=0;
	for(i=0; i<96; i++)*t++='a';
	i=0;
	t=tablica;
	for(i=32; i<=126; i++){
		t[i-32]=i;
	}
	t[95]=0;
	i=0;
	t=tablica;
	while(*t!='\0'){
		while(*c!='\0'){
			if(*c==*t)niz[i]++;
			c++;
		}
		c=recenica;
		i++;
		t++;
	}
	t=tablica;
	for(i = 0; i <=94; i++) {
		for(j = i+1; j <= 94; j++) {
			if((niz[j] == niz[i] && t[j] < t[i]) || niz[j] > niz[i]) {
				pom = niz[i];
				niz[i] = niz[j];
				niz[j] = pom;
				
				pom=t[i];
				t[i]=t[j];
				t[j]=pom;
			}
		}
	}

	c=recenica;
	t=tablica;
	while(*c!='\0'){
		*c=(char)126-pozicija(t, *c);
		c++;
	}
	return recenica;
}

char *dekodiraj(char *tekst, char* tablica){
	char *t=tekst;
	while(*t!='\0'){
		*t=tablica[126-*t];
		t++;
	}
	return tekst;
}

int main() {
	return 0;
}
