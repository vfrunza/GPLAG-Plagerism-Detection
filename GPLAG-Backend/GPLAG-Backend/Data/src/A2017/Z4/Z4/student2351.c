#include <stdio.h>

int slovoIliBroj(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

/**
 * funkcija provjerava da li su dva slova ili broja ista, zanemaruje razliku izmedju
 * 	velikih i malih slova
 * @param char c1
 * @param char c2
 * @return int | bool vraca 1(true) ako su slova/brojevi ista/i, 0 (false) u suprotnom
 */
int ista_slova_ili_brojevi(char c1, char c2) {
	if (c1 == c2) return 1;
	
	if (c1 >= 'a' && c1 <= 'z' && c1 - 32 == c2) return 1;
	
	if (c1 >= 'A' && c1 <= 'Z' && c1 + 32 == c2) return 1;
	
	return 0;
}

int porediStringove(char * prvi, char * drugi) {
	while (*prvi != '\0') {
		if (*drugi == '\0') return 0;
		if (! ista_slova_ili_brojevi(*prvi, *drugi)) return 0;
		prvi++;
		drugi++;
	}
	return *drugi == '\0';
}

char * uzmiOtvarajuciTag(char * s, char * tag) {
	int tagUzet= 0;
	while (*s != '<' && *s != '\0') s++;
	if (*s != '\0') s++;
	if (*s == '/') return NULL;
	while (*s != '>' && *s != '\0') {
		while (*s != ' ' && *s != '>' && ! tagUzet && *s != '\0') {
			*tag++ = *s++;
		}
		tagUzet = 1;
		if (*s == '>') break;
		else s++;
	}
	*tag = '\0';
	return *s == '\0' ? NULL : s;
}

char * uzmiZatvarajuciTag(char * s, char * tag) {
	int tagUzet= 0;
	while (*s != '<' && *s != '\0') s++;
	if (*s != '\0') s++;
	if (*s != '/') return NULL;
	while (*s != '>' && *s != '\0') {
		s++;
		while (*s != ' ' && *s != '>' && ! tagUzet && *s != '\0') {
			*tag++ = *s++;
		}
		tagUzet = 1;
		if (*s == '>') break;
		else s++;
	}
	*tag = '\0';
	return *s == '\0' ? NULL : s;
}

int daLiJeIspravanHTML(char * s) {
	while (*s != '\0') {
		if (*s++ == '<') {
			if (*s == '/') s++;
			if (*s == ' ' || *s == '>') {
				return 0;
			}
			
			// <p>jos gore^2, xd, </p </p>
			
			// while (*s != '\0' && *s != ' ' && slovoIliBroj(*s)) s++;
			while (*s != '\0' && slovoIliBroj(*s)) s++;
		
			// if (*s != ' ' && *s != '/' && *s != '>') return 0;
			
			
			while (*s != '\0' && *s != '>') {
				while (*s == ' ') s++;
				
				if (*s == '<') {
					return 0;
				}
				if (*s != '\0' && *s != '>') s++;
			}
			if (*s != '>') {
				return 0;
			}
		}
	}
	return 1;
}

int istiBrojOtvorenihIZatvorenih(char * s) {
	char * p = s, *temp, tag[100];
	int otvorenih = 0, zatvorenih = 0;
	while (*p != '\0') {
		temp = uzmiOtvarajuciTag(p, tag);
		if (temp != NULL && ! porediStringove(tag, "")) {
			p = temp;
			otvorenih++;
		} else if (*p != '\0') {
			p++;
		}
		//printf ("\t%s\n", p);
	}
	p = s;
	while (*p != '\0') {
		temp = uzmiZatvarajuciTag(p, tag);
		if (temp != NULL && ! porediStringove(tag, "")) {
			p = temp;
			zatvorenih++;
		} else if (*p != '\0') {
			p++;
		}
		//printf ("\t%s\n", p);
	}
	
	return otvorenih == zatvorenih;
}



void kopirajString(char * s1, char * s2) {
	while (*s1 != '\0') *s2++ = *s1++;
	*s2 = '\0';
}

int provjeri(char * tekst) {
	char tag[100], tagZaPoredjenje[200];
	char * p = tekst, *temp = tekst, *q;
	int brojacOtvorenih = 0, brojacZatvorenih = 0, pronadjen = 0;
	char izvorni[500];
	kopirajString(tekst, izvorni);
	
	if (! daLiJeIspravanHTML(tekst) || ! istiBrojOtvorenihIZatvorenih(tekst)) return 0;
	
	while (*p != '\0') {
		temp = uzmiOtvarajuciTag(p, tag);
		if (temp != NULL && ! porediStringove(tag, "")) {
			p = temp;
			q = p;
			// printf("\t%s - ", tag);
			brojacOtvorenih = 0;
			brojacZatvorenih = 0;
			pronadjen = 0;
			while (*q != '\0') {
				temp = uzmiZatvarajuciTag(q, tagZaPoredjenje);
				if (temp != NULL) {
					// printf("%s,\t", tagZaPoredjenje);
					 //printf("\t'%s' poredim sa '%s'\totvorenih = %d\tzatvorenih = %d\n", 
					 //		tag, tagZaPoredjenje, brojacOtvorenih, brojacZatvorenih);
					
					if (porediStringove(tag, tagZaPoredjenje)) {
						
						if (brojacOtvorenih == brojacZatvorenih) {
							pronadjen = 1;
							break;
						}
						//return 0;
						
					}
					brojacZatvorenih++;
					q = temp;
				} else {
					temp = uzmiOtvarajuciTag(q, tagZaPoredjenje);
					if (temp != NULL) {
						// printf("\t%s\n\n", q);
						brojacOtvorenih++;
						q = temp;
					} else if (*q != '\0') {
						q++;
					}
				}
			}
			// printf("\t'%s' poredim sa '%s'\tbrojac = %d\tpronadjen = %s\n", 
			// 		tag, tagZaPoredjenje, brojac, pronadjen ? "true" : "false");
			if (! pronadjen) return 0;
			// printf("\n");
		} else if (*p != '\0') {
			p++;
		}
		//printf ("\t%s\n", p);
	}
	return 1;
}

int main() {
	char s[200] = "<div id=\"tekst\"><h2>Naslov</h2><p>Ovo je <b>četvrti</b> i <i>posljednji</i> zadatak iz <a href=\"zadaca4\">zadaće 4</a></p></div>";
    // printf("%s\n\n", s);
    // printf("\n\n%s", daLiJeIspravanHTML(s) ? "ispravan" : "nije ispravan");
    // printf("%s\n", provjeri(s) ? "dobar" : "los");
	// printf ("Provjera 1: %d\n", provjeri("<span><span><span><a href='https://etf.unsa.ba'>etf.unsa.ba stranica</a></span></span>"));
	// printf ("Provjera 2: %d\n", provjeri("<span><span><span><a href='https://etf.unsa.ba'>etf.unsa.ba stranica</a><span></span></span>"));
	// printf ("Provjera 3: %d\n", provjeri("<span><span><span><a href='https://etf.unsa.ba'>etf.unsa.ba stranica</span></span></span>"));
	// printf ("Provjera 4: %d\n", provjeri("<span><span><span><a href='https://etf.unsa.ba'>etf.unsa.ba stranica</a></span></span></span>"));
	
	// printf ("Provjera  3: %d\n", provjeri("<p>jos gore^2, xd, </p </p>"));
	
	char etfunsaba[] = "<center>"
	"<a href=\"http://icat.etf.unsa.ba/\">"
        "<p class=\"tekst\">"
        "<span class=\"linkovi\">"
		"XXVI International Conference on Information,"
		"<br></br>"
		"Communication and Automation Technologies"
		"<br></br>"
		"<br></br>"
		"<strong>ICAT 2017</strong><br></br>"
		"<br></br>"
		"Sarajevo, Bosnia and Herzegovina<br></br>"
		"October 26-28, 2017.<br></br>"
		"</span>"
        "</p>"
        "</a>"
    "</center>";
    printf ("Provjera 1: %d\n", provjeri (etfunsaba));
    //izmijenimo prvi tag <center> da bude <zenter>, pa onda nema zatvarajuceg
    etfunsaba[1] = 'z';
    printf ("Provjera 2: %d\n", provjeri (etfunsaba));
	return 0;
}
