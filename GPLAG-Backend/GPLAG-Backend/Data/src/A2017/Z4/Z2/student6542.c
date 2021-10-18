#include <stdio.h>

provjeri_duzine (char* s, int niz[], int vel)
{
	int brojac_slova=0,clan_niza=0;
	while (*s!='\0') {
		if((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) brojac_slova++;
		else {
			if (brojac_slova>0) {
				if(brojac_slova==niz[clan_niza]) {
					clan_niza++;
					brojac_slova=0;
				} else return 0;
			}
		}
		s++;
	}
	s--;
	if ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
		if(brojac_slova==niz[clan_niza]) {
			clan_niza++;
		}
	}
	if (clan_niza==vel) return 1;
	else return 0;

}
int main()
{

	return 0;
}
