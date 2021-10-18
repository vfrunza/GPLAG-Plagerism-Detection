#include <stdio.h>
struct Datum {
	int dan, mjesec, godina;
};
struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};
int prestupna(int godina)
{
	if((godina%4==0 && godina%100!=0) || (godina%400==0)) return 1;
	else return 0;
}

int dani_u_mjesecu(int mjesec, int godina)   //radi
{
	if((mjesec%2==1 && mjesec<8) || (mjesec>=8 && mjesec%2==0)) return 31;
	else if(mjesec==2 && !prestupna(godina)) return 28;
	else if (mjesec==2 && prestupna(godina)) return 29;
	else return 30;
}
struct Datum granicni_datum(struct Uposlenik sef, int broj_dana)
{

	struct Datum poredbeni=sef.datum_rodjenja;
	int brdana=dani_u_mjesecu(poredbeni.mjesec, poredbeni.godina);
	if(broj_dana<0) {
		while(broj_dana!=0) {
			poredbeni.dan++;
			broj_dana++;
			if(poredbeni.dan==brdana+1) {
				if(poredbeni.mjesec==12) {
					poredbeni.dan=1;
					poredbeni.mjesec=1;
					poredbeni.godina++;
				} else {
					poredbeni.mjesec++;
					poredbeni.dan=1;
				}
				brdana=dani_u_mjesecu(poredbeni.mjesec, poredbeni.godina);
			}
		}
	} else if(broj_dana>0) {
		while(broj_dana!=0) {
			poredbeni.dan--;
			broj_dana--;
			if(poredbeni.dan==0) {
				if(poredbeni.mjesec==1) {
					poredbeni.mjesec=12;
					poredbeni.godina--;
					poredbeni.dan=31;
				} else {
					poredbeni.mjesec--;
					poredbeni.dan=dani_u_mjesecu(poredbeni.mjesec, poredbeni.godina);
				}
			}
		}
	}
	return poredbeni;

}

void izbaci(struct Uposlenik* redundant, int pozicija, int velicina)
{
	struct Uposlenik *kopija=redundant;
	int i;
	for(i=pozicija+1; i<velicina; i++) {

		*(kopija+i-1)=*(kopija+i);
		//ovde razmisli hoce li doci do nekih nevalidnih pristupanja

	}

}

int da_li_je_stariji(struct Datum d1, struct Datum d2)   //obrati paznju sta ces ako 0 dana razlika a u donjoj funkciji ti posalju 0
{
	if(d1.godina<d2.godina) return 1;
	if(d1.godina>d2.godina) return 0;
	if(d1.godina==d2.godina && d1.mjesec<d2.mjesec) {
		return 1;
	}
	if(d1.godina==d2.godina && d1.mjesec>d2.mjesec) {
		return 0;
	}
	if(d1.godina==d2.godina && d1.mjesec==d2.mjesec && d1.dan<d2.dan) return 1;
	return 0;
}

char* zadnja_rijec(char *pok) //testiraj nekad
{
	char *s=pok;
	char *poknarijec=pok;
	int razmak=1;
	int broj_rijeci;
	while(*s!='\0') {
		if(*s==' ') razmak=1;
		else {
			if(razmak) {
				broj_rijeci++;
				poknarijec=s;
			}
			razmak=0;
		}
		s++;
	}
	return poknarijec;

}
int da_li_su_isti(char *pocetak1, char *kraj1, char *pocetak2, char *kraj2)   //testiraj
{
	char *poc1=pocetak1;
	char *kr1=kraj1;
	char *poc2=pocetak2;
	char *kr2=kraj2;
	while(poc1<kr1) {
		if(*poc1!=*poc2) return 0;
		poc1++;
		if(poc2>=kr2 && poc1<kr1) {
			break;
			return 0;
		}
		poc2++;
	}
	return 1;
}
int nepotizam(char *s1, char *s2)
{
	char *pok1=zadnja_rijec(s1);
	char *pok2=zadnja_rijec(s2);
	int prviimadva=0;
	int drugiimadva=0;
	char *kraj1=pok1;
	char *kraj2=pok2;
	char *drugiprvog=pok1;
	char *drugidrugog=pok1;
	while(*kraj1!='\0') {
		if(*kraj1=='-') {
			prviimadva=1;    //ovde pretpostavljam da je prezime drugo uneto
			drugiprvog=kraj1;
		}
		kraj1++;
	}
	while(*kraj2!='\0') {
		if(*kraj2=='-') {
			drugiimadva=1;
			drugidrugog=kraj2;
		}
		kraj2++;
	}

	if(prviimadva && !drugiimadva) {
		if(da_li_su_isti(pok1, drugiprvog, pok2, kraj2)==1) return 1;
		if(da_li_su_isti(drugiprvog+1, kraj1, pok2, kraj2)==1) return 1;
		return 0;
	} else if(drugiimadva && !prviimadva) {
		if(da_li_su_isti(pok1, kraj1, pok2, drugidrugog)==1) return 1;
		if(da_li_su_isti(pok1, kraj1, drugidrugog+1, kraj2)==1) return 1;
		return 0;
	}

	else if(!drugiimadva && !prviimadva) {
		if(kraj1-pok1!=kraj2-pok2) return 0;
		if(da_li_su_isti(pok1, kraj1, pok2, kraj2)==1) return 1;
		return 0;
	} else {
		if(da_li_su_isti(pok1, drugiprvog, pok2, drugidrugog)==1) return 1;
		if(da_li_su_isti(pok1, drugiprvog, drugidrugog+1, kraj2)==1) return 1;
		if(da_li_su_isti(drugiprvog+1, kraj1, pok2, drugidrugog)==1) return 1;
		if(da_li_su_isti(drugiprvog+1, kraj1, drugidrugog+1, kraj2)==1)return 1;
		return 0;
	}
	return 0;

}

int suzi_listu(struct Uposlenik* kandidat, int velicina, struct Uposlenik direktor, int broj_dana)
{
	int nova_velicina=velicina;
	if(nova_velicina==0) return nova_velicina;
	struct Datum referentni=granicni_datum(direktor, broj_dana);
	int i=0;
	for(i=0; i<nova_velicina; i++) {
		if(nepotizam(direktor.ime_prezime, kandidat[i].ime_prezime)) {
			 continue;
		}
		if(broj_dana>0) { //treba eliminisati starije
			if(da_li_je_stariji(kandidat[i].datum_rodjenja, referentni)) {
				izbaci(kandidat,i,nova_velicina);
				nova_velicina--;
				i--;
			}
		} else { //treba eliminisati mladje
			if(da_li_je_stariji(kandidat[i].datum_rodjenja, referentni)) {
				izbaci(kandidat,i, nova_velicina);
				nova_velicina--;
				i--;
			}
		}
	}
	return nova_velicina;
}

int main()
{

	return 0;
}
