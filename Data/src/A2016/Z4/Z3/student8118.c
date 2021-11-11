#include <stdio.h>
char* zamjena_rijeci (char* tekst, char** rijeci, char** zamjene, int broj_rijeci) {
	char* kraj_teksta;
	char* trenutna_r;
	char* zamijeni;
	char* sacuvan_kraj;
	char* sacuvan_poc;
	char* sacuvana_tre;
	char* sacuvana_zamj;
	char* start;
	char* stop;
	char* sacuvan_start;
	char* reset;
	int duzina=0, duzina1=0, brojac=0, i, a, j, duzina2=0;
	sacuvan_poc=tekst;
	reset=tekst;
		while (*tekst!='\0') {
			tekst++;
		}
	tekst--;
	kraj_teksta=tekst;
	tekst=sacuvan_poc;
	for (i=0; i<broj_rijeci; i++) {
		tekst=sacuvan_poc;
		trenutna_r=rijeci[i];
		zamijeni=zamjene[i];
		sacuvana_tre=trenutna_r;
		sacuvana_zamj=zamijeni;
    	duzina=0;
    /*Odredjivanje duzina rijeci u stringu, i rijeci kojom bi se te rijeci mogle zamijeniti*/
		while (*trenutna_r!='\0' && *trenutna_r!='\0') {
			duzina++;
			trenutna_r++;
		}
		duzina1=0;
		while (*zamijeni!='\0' && *zamijeni!='\0') {
			duzina1++;
			zamijeni++;
		}
		/*Postavljanje pokazivaca na pocetak i kraj rijeci u stringu koja bi mogla biti zamijenjena*/
		while (*tekst!='\0') {
			sacuvan_kraj=kraj_teksta;
			zamijeni=sacuvana_zamj;
			while (*tekst==' ') {
				tekst++;
			}
			start=tekst;
			sacuvan_start=start;
			while (*tekst!=' ' && *tekst!='\0') {
				tekst++;
			}
			stop=tekst;
			a=stop-start;
			brojac=0;
			trenutna_r=sacuvana_tre;
			duzina2=duzina1-duzina;
		/*Provjera da li je odabrana rijec u stringu iste duzina kao i rijec koja treba biti zamijenjena*/
			if (duzina==a) {
				while (start!=stop) {
					if (*start==*trenutna_r)
						brojac++;
					start++;
					trenutna_r++;
				}
				start=sacuvan_start;
		/*Zamjena rijeci*/
		/*Zamjena rijeci koja je duza od rijeci kojom se mijenja*/
				if (brojac==duzina) {
					if (duzina<=duzina1) {
					while (kraj_teksta>start) {
						*(kraj_teksta+duzina2)=*kraj_teksta;
						kraj_teksta--;
					}
					for (j=0; j<duzina1; j++) {
						*start++ = *zamijeni++;
					}
						kraj_teksta=sacuvan_kraj+duzina2;
					}
			/*Zamjena rijeci koja je kraca od rijeci kojom se mijenja*/
					if (duzina>duzina1) {
						for (j=0; j<duzina1; j++) {
						*start++ = *zamijeni++;
						}
						while (*start!='\0') {
							*start=*(start+duzina-duzina1);
							start++;
						} 
					}
				}
			}
		}
	}
	return reset;
}

int main() {
	char* rijeci[2] = {"beli", "sneg"};
    char* zamjene[2] = {"bijeli", "snijeg" };
    char tekst [100]= {"beli sneg je pokrio beli breg"};
	printf("%s",zamjena_rijeci(tekst,rijeci,zamjene,2));
	return 0;
}
