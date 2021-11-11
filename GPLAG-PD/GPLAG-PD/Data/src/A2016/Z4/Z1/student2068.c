#include <stdio.h>

void izbaci_rijec(char *rijec, int duzina) {
	while(*(rijec+duzina)) {
		*rijec=*(rijec+duzina);
		rijec++;
	}
	*rijec=*(rijec+duzina);
}

void izbaci(char *s, char *rijec, int duzina) {
	char a[100000], *temp=NULL;
	int i=0;
	/* Posto ce se niz mijenjati, storat cemo vrijednost nase najcesce rijeci u niz, i ispitivati redom rijeci da li su iste kao nasa rijec */
	while(i<duzina) {
		a[i]=*rijec;
		i++; rijec++;
	}
	while(*s) {
		while(*s && !((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))) s++;
		temp=s;
		for(i=0; i<duzina && *s; i++) {
			if(*s>'Z') {
				if(*s!=a[i] && *s!=a[i]+32) break;
			}
			else {
				if(*s!=a[i] && *s!=a[i]-32) break;
			}
			s++;
		}
		if(i==duzina && !((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))) {
			s-=duzina;
			/* Nasli smo rijec koja je ista kao najcesca i pozivamo funkciju za izbacivanje rijeci iz stringa */
			izbaci_rijec(temp, duzina);
		}
		while((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) s++;
	}
}

int koliko_ponavljanja(char *s, char *rijec, int duzina) {
	int i, koliko=0;
	char *temp=rijec;
	/* Prolazimo kroz string trazeci prvo slovo rijeci, onda provjeravamo da li je rijec ista kao nasa; ako jeste povecavamo counter */
	while(*s) {
		while(*s && !((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))) s++;
		for(i=0; i<duzina && *s; i++) {
			if(*s>'Z') {
				if(*s!=*rijec && *s!=*rijec+32) break;
			}
			else {
				if(*s!=*rijec && *s!=*rijec-32) break;
			}
			s++; rijec++;
		}
		rijec=temp;
		if(i==duzina && !((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))) koliko++;
		else if((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
			while(*s && ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))) s++;
		}
	}
	return koliko;
}

char *izbaci_najcescu(char *s) {
	char *niz[100000]={NULL}, *temp=s, *max_pt=NULL;
	int duzina[100000]={0}, i=0, j, max=0, x, maxduzina=0;
	/* Imacemo niz pokazivaca od kojih svaki novi pokazuje na sljedecu rijec, kao i niz koji ce cuvati duzine tih rijeci */
	
	while(*s) {
		if((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
			niz[i]=s;
			while(*s && ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))) {
				s++;
				duzina[i]++;
			}
			i++;
		}
		else s++;
	}
	
	for(j=0; j<i; j++) {
		/* Provjeravamo za svaku rijec koliko se puta ponavlja u stringu i cuvamo pointer na rijec koja se najvise puta dosad ponovila */
		x=koliko_ponavljanja(temp, niz[j], duzina[j]);
		if(x>max) {
			max=x;
			max_pt=niz[j];
			maxduzina=duzina[j];
		}
	}
	/* Kada smo nasli najcescu rijec saljemo funkciji pointer na pocetak stringa i pointer na tu rijec kao i duzinu rijeci */
	if(i>0) izbaci(temp, max_pt, maxduzina);
	return temp;
}

int main() {
	char t[]="48945648**486/-4+";
	printf("'%s'", izbaci_najcescu(t));
	return 0;
}
