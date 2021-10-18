#include <stdio.h>
#include <stdlib.h>

int provjeri (const char *s)
{
	const char *p = s, *pocetak = 0;
	int brTagova = 0, dubina = 0, i, duzina = 0;
	/* char **tagovi = 0; */
	char tagovi[100][100];
	while(*p != '\0') {
		if(*p == '<') {
			/* citanje taga,provjera da li je ispravan*/
			p++;
			if(*p >= 'A' && *p <= 'Z' || *p >= 'a' && *p <= 'z' || *p >= '0' && *p <= '9') {
				/* otvoren*/
				while(*p >= 'A' && *p <= 'Z' || *p >= 'a' && *p <= 'z' || *p >= '0' && *p <= '9') {
					p++;
				}
				if(*p == '>')
					brTagova++;
				else if(*p == ' ') {
					while(*p != '>') {
						p++;
						if(*p == '<' || *p == '\0')
							return 0; /* nije ispravan!*/
					}
				} else
					return 0; /* nije ispravno!*/
			} else if(*p == '/') {
				/* zatvoren*/
				p++;
				if(*p >= 'A' && *p <= 'Z' || *p >= 'a' && *p <= 'z' || *p >= '0' && *p <= '9') {
					while(*p >= 'A' && *p <= 'Z' || *p >= 'a' && *p <= 'z' || *p >= '0' && *p <= '9') {
						p++;
					}
					if(*p == '>') {
						p++;
						continue;
					} else if(*p == ' ') {
						while(*p != '>') {
							p++;
							if(*p != ' ' && *p != '>')
								return 0; /* nije ispravan!*/
						}
					}

				}
			} else /* nije ispravan*/
				return 0;
		} else if(*p == '>')
			return 0; /* nije ispravan!*/
		p++;
	}

	p = s;
	while(*p != '\0') {
		if(*p == '<') {
			p++;
			if(*p >= 'A' && *p <= 'Z' || *p >= 'a' && *p <= 'z' || *p >= '0' && *p <= '9') {
				/* otvoreni tag,uzimanje imena i oznacavanje mjesta na kojem je otvoren */
				duzina = 0;
				pocetak = p;
				while(*p >= 'A' && *p <= 'Z' || *p >= 'a' && *p <= 'z' || *p >= '0' && *p <= '9') {
					p++;
					duzina++;
				}
				i = 0;
				while(pocetak < p) {
					if(*pocetak >= 'a')
						tagovi[dubina][i++] = (*pocetak++) + 'A' - 'a';
					else
						tagovi[dubina][i++] = *pocetak++;
				}

				tagovi[dubina++][i] = '\0';
				while(*p != '>')
					p++;
			} else {
				/* zatvoreni tag*/
				p++;
				if(dubina == 0) {
					return 0; /* nije ispravan!*/
				}
				/*Provjera da li je prvi zatvoreni tag zadnji otvoren, ako jeste prelazi na sljedeci  */
				pocetak = tagovi[dubina - 1];
				while(*p >= 'A' && *p <= 'Z' || *p >= 'a' && *p <= 'z' || *p >= '0' && *p <= '9') {
					if(*p >= 'a') {
						if(*pocetak++ != (*p++) + 'A' - 'a') {
							return 0; /* nije ispravan!*/
						}
					} else {
						if(*pocetak++ != *p++) {
							return 0; /* nije ispravno!*/
						}
					}
				}
				if(*pocetak != '\0') {
					return 0; /* nije ispravan!*/
				}
				dubina--;
			}
		}
		p++;
	}
	/* ako postoji tag koji nije zatvoren dubina>0*/
	if(dubina != 0)
		return 0; /* nije ispravan!*/
	return 1;
}


int main()
{
	printf("%d", provjeri("<b><a>proba</b></a>"));
	return 0;
}