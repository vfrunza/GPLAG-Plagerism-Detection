#include <stdio.h>
struct Datum {
	int dan,mjesec,godina;
};
struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};
int prestupna_godina (int godina)
{
	if (godina%4==0 && (godina%100!=0 ||godina%400==0))
		return 1;
	return 0;
}
int br_dana (struct Datum dtm)
{
	/*Racunamo broj dana u odnosu na referentni datum u proslosti*/
	int ukupno=0;
	int i;
	int dani_u_mjesecu[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
	/*Ako je godina prestupa,februar ce imati 29 dana*/
	if (prestupna_godina(dtm.godina))
		dani_u_mjesecu[2]++;
	for (i=1; i<dtm.godina; i++) {
		ukupno+=365+prestupna_godina(i);
	}
	for (i=1; i<dtm.mjesec; i++) {
		ukupno+=dani_u_mjesecu[i];
	}
	ukupno+=dtm.dan;
	return ukupno;
}
int uporedi (char *s1,char *s2)
{
	char* pocetak;
	char* kraj;
	char* temp;
	char* pocetak2;
	char* temp2;
	char* kraj2;
	char* cuvaj=s2;
	int logicka=1,logicka2=1;
	int isti=1;
	while (*s1!='\0') {
		/*Prezime moze biti omedjeno sa ramzakom i krajem, razmakom i crticom i crticom i krajem*/
		if (*s1==' ' || *s1=='-') {
			pocetak=s1;
			temp=s1;
			/*Kad naidjemo na razmak,prolazimo kroz string sve dok ne naidjemo na crticu ili dok ne dodjemo do kraja stringa*/
			if (*s1==' ') {
				while (*temp!='\0' && *temp!='-') {
					temp++;
					if (*temp==' ') {
						logicka=0;
						break;
					}
				}
				kraj=temp;
			}
			/*Ako smo dosli do crtice,onda je jedino moguce da se prezime zavrsava krajem stringa*/
			else if (*s1=='-') {
				while (*temp!='\0') {
					if (*temp==' ') {
						logicka=0;
						break;
					}
					temp++;
				}
				kraj=temp;
			}
			/*Ako je ispunjen jedan od ova tri uslova,pronasli smo prezime u prvom imenu i postavljamo logicku varijablu na 1*/
			if (((*pocetak==' ' && (*kraj=='-' || *kraj=='\0')) || (*pocetak=='-' && *kraj=='\0')) && logicka) {
				/*Na isti nacin trazimo prezima u drugom imenu,i uporedjujemo prvo sa svakim*/
				while (*s2!='\0') {
					pocetak2=s2;
					temp2=s2;
					if (*s2==' ' || *s2=='-') {
						if (*s2==' ') {
							while (*temp2!='\0' && *temp2!='-') {
								temp2++;
								if (*temp2==' ') {
									logicka2=0;
									break;
								}
							}
							kraj2=temp2;
						} else if (*s2=='-') {
							while (*temp2!='\0') {
								if (*temp2==' ') {
									logicka2=0;
									break;
								}
								temp2++;
							}
							kraj2=temp2;
						}
						/*Ako smo pronasli prezime u drugom imenu,logicka varijabla 2 je postavljena na 1*/
						if (((*pocetak2==' ' && (*kraj2=='-' || *kraj2=='\0')) || (*pocetak2=='-' && *kraj2=='\0')) && logicka2) {
							pocetak2++;
							pocetak++;
							while (pocetak<kraj && pocetak2<kraj2) {
								if (*pocetak!=*pocetak2) {
									isti=0;
									break;
								}
								pocetak2++;
								pocetak++;
							}
							/*Ako pronadjemo par koji je isti odmah prekidamo program*/
							if (isti && ((*pocetak=='\0' && *pocetak2=='\0') || (*pocetak=='-' && *pocetak2=='\0') || (*pocetak=='\0' && *pocetak2=='-') ||(*pocetak=='-' && *pocetak2=='-')))
								return 1;

						}
					}
					s2++;
					logicka2=1;
					isti=1;
					pocetak=s1;
				}
			}

		}
		s1++;
		logicka=1;
		isti=1;
		s2=cuvaj;
	}
	/*Ako se petlja zavrsila,a nijednom se nije prekinula,znaci da niti jedan par prezimena ne odgovara*/
	return 0;
}
int suzi_listu (struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana)
{
	int i,j;
	int razlika;
	/*Ako je broj dana veci od nule,dolaze u obzir samo starije osobe od direktora,koje ispunjavaju uslov*/
	/*AKo je broj dana manji od nule,trazimo da i razlika bude negativna*/
	for (i=0; i<vel; i++) {
		if (broj_dana>=0)
			razlika=br_dana(direktor.datum_rodjenja)-br_dana(kandidati[i].datum_rodjenja);
		else {
			razlika=br_dana(kandidati[i].datum_rodjenja)-br_dana(direktor.datum_rodjenja);
			razlika=-razlika;
		}
		/*Ako bilo koji clan niza usposlenika ispunjava oba uslova,izbacujemo ga,uz ocuvanje redoslijeda.*/
		if (razlika>broj_dana && uporedi(direktor.ime_prezime,kandidati[i].ime_prezime)==0) {
			for (j=i; j<vel-1; j++) {
				kandidati[j]=kandidati[j+1];
			}
			vel--;
			i--;
		}

	}
	return vel;
}

int main()
{

	return 0;
}
