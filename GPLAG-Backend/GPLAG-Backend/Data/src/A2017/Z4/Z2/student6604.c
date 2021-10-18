#include <stdio.h>

void unesi(char niz[], int velicina)
{
	char znak = getchar();
	if (znak == '\n') znak=getchar();
	int i = 0;
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}

int provjeri_duzine(char *s, int *niz, int velicina)
{
	int brojac=0, i=0, razmak=1, broj_rijeci=0;;
	char *temp=s;
	
	while (*temp != '\0') {
		if ( !((*temp<='z' && *temp>='a') || (*temp<='Z' && *temp>='A')))
			razmak=1;
		else if (razmak == 1) {
			razmak=0;
			broj_rijeci++;
		}
		temp++;
	}
	if (velicina!=broj_rijeci)return 0;
	

	while (*s!=0) {
		while (((*s<='z' && *s>='a') || (*s<='Z' && *s>='A')) && *s!=0) {
			brojac++;
			s++;
		}
		if (brojac!=0) {
			if (i<velicina) {
				if (*(niz+i)!=brojac)return 0;

				if (*(niz+i)==brojac) {
					i++;
					brojac=0;
					continue;
				}
			}
		}

		s++;

	}


	return 1;
}
int main()
{
	char s[100];
	int niz[3]= {3,2,3};
	printf("Unesite string\n");
	unesi(s, 100);
	printf("%d",provjeri_duzine(s,niz,3));
	return 0;
}
