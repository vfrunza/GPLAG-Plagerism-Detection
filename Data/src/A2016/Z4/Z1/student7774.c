#include <stdio.h>

void unesi(char niz[], int velicina) {
    int i = 0;
	    char znak = getchar();
	    if (znak == '\n') znak=getchar();
	    while (i < velicina-1 && znak != '\n') {
		    niz[i] = znak;
		    i++;
	    	znak = getchar();
    	}
	    niz[i]='\0';
}

int je_li_slovo(char s){
	
	if ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z'))
		return 1;
		
	return 0;
}

char u_malo (char p) {
	
	if (p >= 'A' && p <= 'Z')
		p += 'a' - 'A';
	
	return p;	
}

int je_li_ista_rijec (char *s1, char *s2) {
	char *p=s1;
	char *q=s2;
	
	while (u_malo(*p) == u_malo(*q)) {
		
		if (!je_li_slovo(*p) && !je_li_slovo(*q))
			return 1;
		p++;
		q++;
	}
	if (!je_li_slovo(*p) && !je_li_slovo(*q))
			return 1;
	
	return 0;
}

void izbaci_rijeci (char* s) {
	char *p=s, *brisac;	
	int duz=0;

// izbaciti sve osim prve koje se ponavljaju

	while(je_li_slovo(*p)) {
		p++;
		duz++;
	}
	while (*p != '\0') {
		
		while(je_li_slovo(*p) && *p != '\0') 
			p++;
		
		while(!je_li_slovo(*p) && *p != '\0') {
			p++;
		}
			
		if (*p != '\0' && je_li_ista_rijec(s,p)) {
			brisac = p;	
				while (*(brisac+duz) != '\0') {
					*brisac = *(brisac+duz);
					brisac++;
				}	
				*brisac = '\0';
		}
	}

// izbaciti prvu i zadatak je rijesen

	while (*(s+duz) != '\0') {
		*s = *(s+duz);
		s++;
	}
	*s = '\0';
}

char* izbaci_najcescu (char* s) {
	char *reset = s, *p, *max_pok = 0;
	int trenutni_puta = 1, max_puta = 0;
	
	while (*s != '\0') {
		
		while(!je_li_slovo(*s) && *s != '\0'){
			s++;
		}
		p=s;
		
		// dosli smo do nove rijeci, s pokazuje na rijec
		trenutni_puta = 1;
		
		while (*p != '\0') {
			
			while(je_li_slovo(*p) && *p != '\0'){
				p++;
			}
			
			while(!je_li_slovo(*p) && *p != '\0'){
				p++;
			}
			
			if (*p != '\0' && je_li_ista_rijec(s,p)) {
				trenutni_puta++;
			}
		}
		
		// ovdje ide logika za max
		// trenutni puta sa max puta i postavljanje max pokazivaca
	
		if (trenutni_puta > max_puta) {
			max_puta = trenutni_puta;
			max_pok = s;
		}
		while(je_li_slovo(*s) && *s != '\0'){
			s++;
		}
	}
	
	// izbacivanje najcesce rijeci iz stringa
	if(max_puta > 0)
		izbaci_rijeci(max_pok);
	
	return reset;
}

int main() {
	
	char t[]="JednaVeeeeeeeeeelikaRiiiiiiiiijec";
	izbaci_najcescu(t);
	//izbaci_rijeci(t);
	printf("%d '%s'", t[0], t);
	return 0;
	
	char tekst[100];
	
	unesi (tekst, 100);
	printf ("%s", izbaci_najcescu(tekst));
	
	return 0;
}
