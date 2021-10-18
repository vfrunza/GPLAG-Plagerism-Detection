#include <stdio.h>
void unesi (char *s, int velicina) {
	int i=0;
	char tekst = getchar();
	if (tekst == '\0') {
		tekst=getchar();
	}
	while (i < velicina-1 && tekst != '\n') {
		s[i]=tekst;
		i++;
		tekst=getchar();
	}
	s[i]='\0';
}
char *izbaci_najcescu (char *s) {
	char *pocetak_rijeci=s, *pocetak_druge_rijeci, *pocetak_prve_rijeci;
	char *pocetak=s;
	char *p, *p1;
	char *adresa=s;
   
	if (*pocetak_rijeci == ' ') {
		while ( *pocetak_rijeci== ' ') {
			pocetak_rijeci++;
		} 
	}
	pocetak_prve_rijeci=pocetak_rijeci;
	
    while (*pocetak_prve_rijeci != '\0') {
        p=pocetak_prve_rijeci;
        if (*p != ' ') {
			p++;}
			if (*p == ' ') {
		while (*p == ' ') {
			p++; 
		}
    }
			pocetak_druge_rijeci=p;
			p1=p;
			
		
	
	while (*pocetak_druge_rijeci != '\0') {
	if (*pocetak_prve_rijeci==*pocetak_druge_rijeci) {
		
		while (*pocetak_prve_rijeci==*pocetak_prve_rijeci) {
			
			if ((*pocetak_prve_rijeci == ' ') && (*pocetak_druge_rijeci == ' ')) {
				while (pocetak_prve_rijeci>pocetak) {
					pocetak_prve_rijeci=pocetak_druge_rijeci;
					pocetak_prve_rijeci--;
					pocetak_druge_rijeci--;
				}
			}
		else {
				pocetak_druge_rijeci++;
				pocetak_prve_rijeci++;}
		}
	}
	pocetak_prve_rijeci=pocetak_rijeci;
	    if (*pocetak_druge_rijeci == ' ') {
	    	while (*pocetak_druge_rijeci==' ') {
	    		pocetak_druge_rijeci++;
	    	}
	    }
	    else pocetak_druge_rijeci++;
	}

    pocetak_prve_rijeci=p1;
	}
	return adresa;
}

int main () {
	char tekst[50],vel=50;;
	printf("Unesite tekst: ");
	unesi (tekst, vel);
	printf ("%s",izbaci_najcescu(tekst));
	return 0;
}













