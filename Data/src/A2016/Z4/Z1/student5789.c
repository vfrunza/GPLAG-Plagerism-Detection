#include <stdio.h>

int slovo(char c)   /*provjerava jel slovo*/
{
	if (c >= 'a' && c <= 'z') c -= 32;
	return (c >= 'A' && c <= 'Z');
}
char veliko_slovo(char c)
{
	if (c >= 'a' && c <= 'z') return c - 32;  /*pretvara u velika slova */
	else return c;
}
int iste(char *s1, char *s2, int duzina)
{
	int tacno = 1;
	int i;
	for (i = 0; i < duzina; i++)
		if (s1[i] != s2[i]) tacno = 0;
	return tacno;
}
char* izbaci_najcescu(char* s)
{
	int i,j,slova=0,duzina_maks=0;
	int duzina_trenutne = 0;
	int duzina_poredim = 0;
	char *p = s; /*pokazivac koji je uvijek na pocetku*/
	char *adresa = s,*q;
	int maxi = 0; /* broj ponavljanja najcesce */
	int broj_ponavljanja = 0; /* za trenutnu rijec */
	while (*p != '\0') {
		if(slovo(*p))
			slova=1;
		char *q = p; /* za prolaz kroz rijec, npr merjema ide od m do a */
		char *qq = p; /* pocetak rijeci, npr merjema ostaje na m */
		duzina_trenutne = 0;
		broj_ponavljanja = 0;
		while (slovo(*q)) {
			q++;
			duzina_trenutne++;
		}
		p = q;
		while (!slovo(*p) && *p != '\0') p++; /* p pokazuje na prvu iducu rijec (adresu) */
		char *x = p; /* kako sam zapamtila jednu rijec sa p, xx stoji na pocetku slj rijeci,a x prolazi kroz slova te rijeci*/
		while (*x != '\0') {
			char *xx = x; /* za prolaz kroz rijec */
			char *kopija_xx = x; /* pocetak rijeci */
			duzina_poredim = 0;

			while (slovo(*xx)) {
				xx++;
				duzina_poredim++;
			}
			if (duzina_poredim == duzina_trenutne) {
				int jesu_li_iste = 1;
				for (i = 0; i < duzina_poredim; i++) if (veliko_slovo(*(kopija_xx + i)) != veliko_slovo(*(qq + i))) jesu_li_iste = 0;
				if (jesu_li_iste) broj_ponavljanja++;
			}
			if (broj_ponavljanja > maxi) {
				maxi = broj_ponavljanja;
				adresa = kopija_xx;
				duzina_maks = duzina_trenutne;
			}
			x = xx;
			while (!slovo(*x) && *x != '\0') x++;

		}
	}
	p = s;
	int duzina = 0;
	while (*p != '\0') {
		p++;
		duzina++;
	}
	p--;


	p=s;
	j=0;
	char *k;

	if(slova==0) return s;


	if (duzina_maks==0 && slova) {
		while(*p!='\0') {
			if(slovo(*p)) {
				adresa=p;
				while(slovo(*p)) {
					duzina_maks++;
					p++;
				}
				break;
			}
		}
	}

	if(duzina_maks==duzina) {
		*s='\0';
		return s;
	}

	p=s;
	while(*p!='\0') {
		j=0;
		if(veliko_slovo(*p)==veliko_slovo(adresa[j])) {
			if(p!=s && slovo(*(p-1))) goto cp;
			k=p;
			q=p;




			while (veliko_slovo(*q)==veliko_slovo(adresa[j]) && j<duzina_maks) {
				q++;
				j++;

			}

			q--;
			j--;
			if((*q==adresa[j] || *q+32==adresa[j] || *q-32==adresa[j]) && !slovo(*(q+1)) && j+1==duzina_maks) {
				q++;
				while (*p++=*q++);
				adresa-=duzina_maks;
				p=k-1;

			}
		}

cp: p++;
	}
	return s;
}



int main()
{
	return 0;
}
