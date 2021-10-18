#include <stdio.h>
#include <string.h>

struct Datum {
	int dan, mjesec, godina;
};

struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

int duzina(char*s1,char*s2)
{
	int br=0;
	while(s1>s2) {
		s1++;
		br++;
	}
	return br;
}

/*Pronalazenje podstringova sa formatom prezimena*/
int Uporedi_ime(char*s, char*s2)
{
	char*pok1=NULL,*pok2=NULL;
	int duzina1=0,duzina2=0;
	while(*s!='\0') s++;
	while(*s2!='\0') s2++;
	while(*s2!=' ') {
		s2--;
		if(*s2=='-') pok2=s2+1;
	}
	s2++;

	while(*s!=' ') {
		s--;
		if(*s=='-') pok1=s+1;
	}
	s++;

	if(pok1!=NULL && pok2!=NULL) {
		duzina1=duzina(s,pok1);
		duzina2=duzina(s2,pok2);
		if(!strcmp(pok1,pok2)) return 0;
		if(strncmp(s,s2,duzina1)==0 || strncmp(pok1,s2,duzina2)==0 || strncmp(s,pok2,duzina1)==0) return 0;
	}
	if(pok2!=NULL) {
		duzina1=strlen(s);
		if(strncmp(s,s2,duzina1)==0 || strncmp(s,pok2,duzina1)==0) return 0;
	}
	if(pok1!=NULL) {
		duzina2=strlen(s2);
		if(strncmp(s,s2,duzina2)==0 || strncmp(pok1,s2,duzina2)==0) return 0;
	}

	if(pok1==NULL && pok2==NULL && strcmp(s,s2)==0) return 0;

	return 1;

}
/*racuna broj dana do odredjenog mjeseca)*/
int izbroji_dane(int mjeseci, int godina)
{
	int i=0,ukupno=0;

	for(i=1; i<mjeseci; i++) {
		if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10) ukupno+=31;
		else if(i==2) ukupno+=28;
		else ukupno+=30;
	}

	if(((godina%4==0 && godina%100!=0)|| godina%400==0)&& mjeseci>2) ukupno++;
	return ukupno;


}
/*Racuna broj dana izmedju mladjeg i starijeg do godine u kojoj je rodjen mladji*/
int dio_razlike(struct Datum stariji, struct Datum mladji)
{
	int ukupno=0,i=0,br=0;
	while(stariji.godina<mladji.godina) {

		for(i=stariji.mjesec; i<=12; i++) {
			if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12) ukupno+=31;
			else if(i==2) ukupno+=28;
			else ukupno+=30;
			br++;
		}
		if(((stariji.godina%4==0 && stariji.godina%100!=0)|| stariji.godina%400==0)&& br>=11) ukupno++;
		stariji.godina++;
		stariji.mjesec=1;
		br=0;
	}
	return ukupno-stariji.dan;

}
/*Racuna konacan broj dana sa godinom rodjenja mladjeg*/
int poredjenje(struct Datum stariji, struct Datum mladji)
{
	int stari=0;

	if(stariji.godina<mladji.godina)
		stari=dio_razlike(stariji,mladji)+izbroji_dane(mladji.mjesec,mladji.godina)+mladji.dan;
	else if(stariji.godina==mladji.godina)
		stari=izbroji_dane(mladji.mjesec,mladji.godina)-izbroji_dane(stariji.mjesec,stariji.godina)+mladji.dan-stariji.dan;

	return stari;
}

/*finalno poredjenje starosne razlike*/
int uporedi_datume(struct Datum kandidat, struct Datum direktor,int dani)
{
	int stariji=0;
	if(dani>0) {
		stariji=poredjenje(kandidat,direktor);
		if(stariji>dani) return 1;
		return 0;

	}

	stariji=poredjenje(direktor,kandidat);
	if(stariji==0 || stariji<-dani) return 1;

	return 0;

}
/*izbacivanje clanova sa odredjenim karakteristikama*/
int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana)
{
	struct Uposlenik *pocetak=kandidati,*pomocni=kandidati,*kraj=kandidati+vel;
	while(pocetak<kraj) {
		if(uporedi_datume(pocetak->datum_rodjenja,direktor.datum_rodjenja,broj_dana)&& Uporedi_ime(pocetak->ime_prezime,direktor.ime_prezime)) {
			pomocni=pocetak;

			while(pomocni<kraj-1) {
				*pomocni=*(pomocni+1);
				pomocni++;
			}
			kraj--;
			vel--;
			pocetak--;




		}
		pocetak++;
	}



	return vel;
}


int main()
{

	return 0;
}
