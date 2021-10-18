#include <stdio.h>
#include <math.h>
// izbaciti sve kadidate koji su stariji za vise od x dana ali niposto koji se prezivaju kao on 
struct Datum {
	int dan, mjesec, godina
};
struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

//pomocna funkcija da provjerimo je li godina prestupa, vraca 1 ako jeste

int prestupna(int godina)
{
	if(godina%4==0 && (godina%400==0 || godina%100!=0))
		return 1;
	return 0;
}

//pomocna funkcija koja vraca broj dana izmedju poslatog datuma i referentnog 1.1.1.
int brojdana(struct Datum d)
{
	int ukupno=0,i;
	for(i=1; i<d.godina; i++)
		ukupno+=365+prestupna(i);
	int bdum[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(prestupna(d.godina)==1) bdum[2]++;
	for(i=1; i<d.mjesec; i++)
		ukupno+=bdum[i];
	ukupno+=d.dan;
	return ukupno;

}


int podstring(char *p1, char *p2)
{
	//osiguravamo da pom1 i pom2 pokazuju na prvo slovo prezimena bez obzira koliko imena imam
	char *pom1 = p1;
	char *pom2=p2;
	while(*p1!='\0') {
		if (*p1 == ' ') pom1  =p1;
		p1++;
	}
	pom1++;

	while(*p2!='\0') {
		if(*p2==' ')pom2=p2;
		p2++;
	}
	pom2++;

	while(*pom1!='\0') {
		char *s1=pom1;
		char *s2=pom2;
		while(*s1++==*s2++)
			if((*s2=='\0' && *s1=='\0') || (*s1=='-' && *s2=='\0') || (*s1=='\0' && *s2=='-'))
				return 1;
		pom1++;
	}
	return 0;
}


int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana)
{

	int cuvaj_vel=vel;//da sacuvamo pocetnu velicinu
	int i=0,j=0,br=0;//br pamti koliko se puta izvrsio if tj koliko ljudi treba izbacit
	int razlika=0;
	for(i=0; i<vel; i++) {
		razlika=brojdana(direktor.datum_rodjenja)-brojdana(kandidati[i].datum_rodjenja);

		if(razlika>broj_dana && podstring(direktor.ime_prezime, kandidati[i].ime_prezime)==0) {
			br++;
			for(j=i; j<vel-1; j++) {
				kandidati[j]=kandidati[j+1];
			}
			vel--;
			i--;
		}
	}
	return cuvaj_vel-br; //broj pocetnih kandidata minus oni koje smo izbacili daje one koji su ostali
}
int main()
{
	printf("Zadaća 5, Zadatak 1");
	return 0;
}
