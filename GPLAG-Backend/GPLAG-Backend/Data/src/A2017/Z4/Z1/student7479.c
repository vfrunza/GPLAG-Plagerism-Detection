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

char* ubaci_broj (char *tekst, int broj)
{
	char *p=tekst;
	char *kraj, *razmak;
	int rijec=0, temp, tmp1=broj, duzina1=0, duzina=0, tempduzina=0;
	temp=broj;
	if(broj<0) temp=-temp;
	while (temp>0) {
		duzina1++;
		temp/=10;
	}
	if(broj<0) {
		duzina=duzina1+2;
	} else {
		duzina=duzina1+1;
	}
	while (*tekst!='\0') {
		tempduzina=duzina;
		if(*tekst!=' ') {
			rijec=1;
		} else if (*tekst==' ' && rijec==1) {
			razmak=tekst;
			while (*razmak!='\0') {
				if (*razmak!=' ') {
					break;
				}
				razmak++;
			}
			if (*razmak=='\0') {
				return p;
			}
			if(*(tekst+1)==' ') {
				tempduzina--;
			}
			rijec=0;
			kraj=tekst;
			if (broj<0) {
				tmp1=-broj;
			} else {
				tmp1=broj;
			}
			while (*kraj!='\0') {
				kraj++;
			}
			while (kraj>tekst) {
				*(kraj+tempduzina)=*kraj;
				kraj--;
			}
			tekst+=duzina;
			*tekst=' ';
			tekst--;
			while (tmp1!=0) {
				*tekst=tmp1%10 + '0';
				tekst--;
				tmp1/=10;
			}
			if (broj<0) {
				*tekst='-';
				tekst--;
			}
			tekst+=duzina;
		}
		tekst++;
	}
	return p;
}

int main()
{
	char tekst[300];
	int broj;

	printf ("Unesite neki tekst: ");
	unesi(tekst,300);
	printf ("Unesite broj: ");
	scanf ("%d", &broj);

	ubaci_broj(tekst,broj);
	printf ("%s", tekst);

	return 0;
}
