#include <stdio.h>

void unesi(char *s, int duzina)
{
	int znak = getchar();
	if(znak == '\n') znak = getchar();
	int i = 0;
	while(i < duzina - 1 && znak != '\n') {
		s[i] = znak;
		i++;
		znak = getchar();
	}
	s[i] = '\0';
}


int provjeri_duzine(const char *s, int niz[], int duzina)
{
	int i,brojac = 0,rez = 0,brojac2 = 0;
	const char *p = s;

	for(i = 0; i < duzina; i++) {
		while(*p != '\0') {
			if((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z'))
				brojac++;
			if(!((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z'))|| (*(p+1) == '\0')) {

				if(brojac == 0) {
					p++;
					continue;
				}

				if(brojac == niz[i]) {
					brojac = 0;
					brojac2++;
					i++;
					rez = 1;
				} else if(brojac != niz[i])
					return 0;
			}

			p++;
		}

	}
	if(brojac2 > duzina || brojac2 < duzina)
		return 0;

	if(rez)
		return 1;
	else
		return 0;

}

int main()
{

	char tekst[100];
	int niz[100],duzina,x,i;

	printf("Unesite neku recenicu: ");
	unesi(tekst,100);
	printf("Unesi duzinu niza brojeva: ");
	scanf("%d",&duzina);
	printf("Unesi niz brojeva: ");
	for(i = 0; i < duzina; i++) {
		scanf("%d",&niz[i]);
	}
	x = provjeri_duzine(tekst,niz,duzina);

	printf("Zakljucak: %d",x);
	return 0;
}
