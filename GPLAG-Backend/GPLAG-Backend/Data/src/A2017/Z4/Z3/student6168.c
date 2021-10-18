#include <stdio.h>

int maksimalnaduzina(char *s1) //Ova funkcija ce vracati brojac koji kasnije koristimo u glavnoj funkciji za ogranicavanje petlje
{
	int brojac=1, i, provjera; //Brojac=1 jer najkraci podniz mora imati barem jedno slovo
	char *pocetak;
	pocetak=s1;
	pocetak++;
	while (*s1!='\0' || ((*s1>='A' && *s1<='z'))) { //Provjerava da li je trenutni char slovo
		provjera=0; //Svakim prolaskom vraca provjeru na '0' da bismo je mogli ponovo koristiti
		for(i=0; i<pocetak-s1; i++) {
			if(*pocetak==*(s1+i) || ((*pocetak==*(s1+i)-32) || (*pocetak==*(s1+i)+32)) || (!((*pocetak>='A' && *pocetak<='z')))) {
				//Ako je jednak pocetnom ili ako nije slovo prekida petlju
				provjera=1;
				break;
			}
		}
		if(provjera)
			break;

		pocetak++; //Sve dok je znak slovo i razlicito od pocetnog velicina podniza se povecava, i prelazi se na sljedeci
		brojac++;
	}
	return brojac;
}

void najduzi_bp(char *s1, char *s2)
{
	char *pocetnoslovo; //Ovdje cemo cuvati pokazivac na pocetak koji ce su updateovati ako smo dosli do duzeg podniza, a od njega se pocinje kopirati podstring u s2
	int duzina=0, maxduzina=1, i;

	while (*s1<'A' || *s1>'z')
		s1++; //Mozda string pocinje razmakom pa trebamo povecavati s1 dok ne dodjemo do prvog slova

	maxduzina = 1;
	pocetnoslovo = s1;

	while(*s1!='\0') {
		if(*s1<'A' || *s1>'z') { 
			s1++; //Ako trenutni char nije slovo treba se preskociti ostatak i povecavati s1 sve dok ne dodje do slova
			continue;
		}

		duzina = maksimalnaduzina(s1); //Ovu duzinu cemo koristiti za ogranicavanje petlje kod upisivanja podniza u s2
		if (duzina>maxduzina) { //Ako je trenutna duzina veca od dosadasnjeg maksimuma, maksimum postaje ta duzina i updateuje se pokazivac 
			maxduzina = duzina;
			pocetnoslovo = s1; //Pocetno slovo je slovo od kojeg se provjeravala duzina i on postaje pocetak najduzeg podniza
		}
		s1++; //Prelazimo na sljedeci clan da bi sve do kraja bilo provjereno
	}

	for(i=0; i<maxduzina; i++) {
		*s2++=*pocetnoslovo++; //Kada smo dobili max duzinu i pokazivac na pocetak, uobicajenim algoritmom mozemo kopirati taj podniz u s2
	}
	*s2='\0';
}

int main() //Proba
{
	char s1[100]="Ovo je neki primjer";
	char s2[100];
	najduzi_bp(s1,s2);
	printf("Glasi: %s", s2);
	return 0;
}