#include <stdio.h>
int duzinaR(char *p)
{
	// obicna strlen funckija
	int duzina=0;
	while(*p!='\0') {
		duzina++;
		p++;
	}

	return duzina;
}

void ubaci_rijec(char *tekst, char *rijec, int vel)
{
	// obicna funkcija za ubacivanje
	char *pomocni = tekst;
	char *rec = rijec;
	char *kraj2 = tekst;

	while(*kraj2!='\0') kraj2++;

	while(kraj2>=pomocni) {
		*(kraj2+vel) = *kraj2;
		kraj2--;
	}

	while(*rec!='\0') {
		*pomocni = *rec;
		pomocni++;
		rec++;
	}
}


void izbaci_rijec(char *tekst, int vel)
{
	// obicna funkcija za izbacivanje
	char *pomocni = tekst;
	char *kraj = tekst+vel;
	while(*kraj!='\0') {
		*pomocni = *kraj;
		pomocni++;
		kraj++;
	}

	*pomocni='\0';

}


int uporedi(char *s1, char *s2)
{
	// uporedujemo 2 rijeci tj. u tekstu i rijeci[];

	while((*s1!='\0' || *s2!='\0') && (*s1 == *s2)) {
		s1++;
		s2++;
	}
	if(*s1=='\0' && *s2 =='\0') return 1;
	return 0;

}

char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci)
{
	char *s = tekst;
	if(broj_rijeci==0 || *tekst=='\0') return tekst;

	while(*tekst!='\0') {

		while(*tekst==' ') tekst++;
		if(*tekst=='\0') break;

		char *kraj = tekst;
		char temp; // ovo cemo iskoristiti pri uporedivanju rijeci

		while(*kraj!=' ' && *kraj!='\0') kraj++;
		temp = *kraj;
		*kraj='\0'; // stavljamo da je '\0' i onda poslije moramo vratiti

		int index=-1, brojac=0;
		while(brojac<broj_rijeci) {

			if(uporedi(tekst, rijeci[brojac])) {
				index = brojac;
				break;
			}
			brojac++;

		}
		*kraj=temp; // sad vracamo

		if(index!=-1) {
			// ukoliko je index razlicit od -1 onda izbacujemo
			// pri tome moramo pokazivac teksta povecati za duzinu rijeci koju ubacujemo

			izbaci_rijec(tekst, duzinaR(rijeci[index]));
			ubaci_rijec(tekst, zamjene[index], duzinaR(zamjene[index]));
			tekst += duzinaR(zamjene[index]);


		} else tekst = kraj; // ako jest -1, samo prebacujemo na kraj pokazivac
	}
	return s;
}

int main()
{
	char* rijeci[2] = { "test" };
char* zamjene[2] = { "zamjena" };
char tekst[100] = "test protest testiranje protestiranje test";
printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 1));
	return 0;
}
