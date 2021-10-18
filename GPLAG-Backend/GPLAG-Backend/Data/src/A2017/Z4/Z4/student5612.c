#include <stdio.h>

int uporedi(char* p1, char* p2)
{
	p2++;

	if(*p1 == *p2) {
		if(*p1 == ' ' && *p2 == ' ') return 0;
		else if(*(p1 + 1) == *(p2 + 1 ))
			return 1;
		else if(*(p1 + 1) == ' ' && *(p2 + 1) == '>') {
			return 1;
		} else return 0;
	} else return 0;
}
int broj_znak(char *str)
{
	int br_z = 0;

	while(*str != '\0') {
		if(*str == '<' || *str == '>' || *str == '/')
			br_z++;
		str++;
	}
	return br_z;
}
int provjeri(char* s)
{
	char *pok2;
	char *pok3;
	char *s1 = s;
	char *pok4 = s;

	int brojac1 = 0, brojac2 = 0, broj_znakova;

	broj_znakova = broj_znak(s);
	
	if(broj_znakova == 0) return 1;

	while(*s != '\0') {
		brojac2 = 0;
		if(*s == '<') {
			pok2 = s;
			pok3 = pok2;
			pok2++;

			while(*pok3 != '\0') {
				if(*pok3 == '<' && *(pok3 + 1) != '/') {
					brojac2++;
				}
				pok3++;
			}
			while(*s1 != '\0') {
				if(*s1 == '<' && *(s1+1) == '/') {
					brojac1++;
					if(brojac1 == brojac2) {
						pok4 = s1;
						pok4++;
						if(uporedi(pok2, pok4))
							return 1;
						else
							return 0;
					}
				}
				s1++;
			}
		}
		s++;

	}
	return;
}

int main()
{
	return 0;
}
