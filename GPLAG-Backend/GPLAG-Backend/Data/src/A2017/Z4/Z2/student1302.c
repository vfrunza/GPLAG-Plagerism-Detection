#include <stdio.h>

void unesi (char niz[], int velicina)
{
	int i=0;
	char znak=getchar();
	if (znak == '\n') znak=getchar();
	while (i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

int provjeri_duzine (char *s, int *niz, int velicina)
{
	int duzina_rijeci=0, broj_rijeci=0, nije_rijec=1;
	char *p;
	p=s;
	while (*p!='\0') {
		if (!((*p>='A' && *p<='Z') || (*p>='a' && *p<='z'))) {
			nije_rijec=1;
		} else if (nije_rijec==1) {
			nije_rijec=0;
			broj_rijeci++;
		}
		p++;
	}
	if (broj_rijeci==velicina) {
		while (*s!='\0') {
			if (!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))) {
				nije_rijec=1;
			} else {
				nije_rijec=0;
			}
			if (nije_rijec==0) {
				duzina_rijeci++;
			}
			if (nije_rijec==1 && duzina_rijeci!=0) {
				if (duzina_rijeci==*niz) {
					duzina_rijeci=0;
					niz++;
				} else if (duzina_rijeci!=*niz) {
					return 0;
				}
			}
			s++;
		}
	} else {
		return 0;
	}
	return 1;
}

int main()
{
	char tekst[200];
	int niz[100], n, i;

	printf ("Unesite tekst: ");
	unesi(tekst,200);

	printf("Unesite niz brojeva: ");
	for (i=0; i<100; i++) {
		scanf ("%d", &niz[i]);
	}
	n=i;

	provjeri_duzine(tekst, niz, n);
	return 0;
}
