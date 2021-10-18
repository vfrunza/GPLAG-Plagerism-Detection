#include <stdio.h>
int prestupna(int godina)
{
	int jeste=0;
	if((godina%4==0 && godina%100!=0) || (godina%400==0)) jeste=1;
	return jeste;
}
int mjeseci(int mjesec, int godina)
{
	if(mjesec==4 || mjesec==6 || mjesec==9 || mjesec==11) return 30;
	if(mjesec==2) {
		if(prestupna(godina)) return 29;
		return 28;
	}
	return 31;
}
int jednaki(char* s1,char* s2)
{
	char *p1,*p2;
	p1=s1,p2=s2;
	while(*p1!='\0' && *p2!='\0') {
		if((*p1=='\0' && *p2!='\0') || (*p1!='\0' && *p2=='\0')) return 0;
		if(*p1!=*p2) return 0;
		p1++;
		p2++;
	}
	return 1;
}
struct Datum {
	int dan,mjesec,godina;
};
struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};
int suzi_listu(struct Uposlenik* kandidati,int vel,struct Uposlenik direktor,int broj_dana)
{
	struct Uposlenik* p=kandidati;
	int kandidat_2_prez=0,sef_2_prez=0,porodica=0,proteklo=0;
	char *s,*pok,*pok1,*pok2;
	s=direktor.ime_prezime,pok=direktor.ime_prezime,pok1=direktor.ime_prezime,pok2=direktor.ime_prezime;
	int godina1=0,mjesec1=0,dan1=0;
	int godina2=direktor.datum_rodjenja.godina,mjesec2=direktor.datum_rodjenja.mjesec,dan2=direktor.datum_rodjenja.dan;
	while(*s!='\0') {
		if(*s=='-') {
			sef_2_prez=1;
			break;
		}
		s++;
	}
	if(sef_2_prez) {
		pok2=direktor.ime_prezime;
		while(*pok2!='-') pok2++;
		pok2++;
		pok1=pok2;
		while(*pok1!=' ') pok1--;
		pok1++;
	} else {
		pok=direktor.ime_prezime;
		while(*pok!='\0') pok++;
		while(*pok!=' ') pok--;
		pok++;
	}
	while(p<vel+kandidati) {
		godina1=p->datum_rodjenja.godina;
		mjesec1=p->datum_rodjenja.mjesec;
		dan1=p->datum_rodjenja.dan;
		s=p->ime_prezime;
		char* pokk,*pokk1,*pokk2;
		pokk=p->ime_prezime;
		pokk1=p->ime_prezime;
		pokk2=p->ime_prezime;
		while(*s!='\0') {
			if(*s=='-') {
				kandidat_2_prez=1;
				break;
			}
			s++;
		}
		if(kandidat_2_prez) {
			pokk2=p->ime_prezime;
			while(*pokk2!='-') pokk2++;
			pokk2++;
			pokk1=pokk2;
			while(*pokk1!=' ') pokk1--;
			pokk1++;
		} else {
			pokk=p->ime_prezime;
			while(*pokk!='\0') pokk++;
			while(*pokk!=' ') pokk--;
			pokk++;
		}
		if(sef_2_prez) {
			if(kandidat_2_prez) {
				porodica=jednaki(pok1,pokk1);
				if(porodica!=1) porodica=jednaki(pok1,pokk2);
				if(porodica!=1) porodica=jednaki(pok2,pokk1);
				if(porodica!=1) porodica=jednaki(pok2,pokk2);
			} else {
				porodica=jednaki(pok1,pokk);
				if(porodica!=1) porodica=jednaki(pok2,pokk);
			}
		} else {
			if(kandidat_2_prez) {
				porodica=jednaki(pok,pokk1);
				if(porodica!=1) porodica=jednaki(pok,pokk2);
			} else porodica=jednaki(pok,pokk);
		}
		if(porodica!=1) {
			if(godina1==godina2) {
				proteklo=0;
				if(mjesec1<mjesec2) {
					proteklo+=(mjeseci(mjesec1,godina1)-dan1)+dan2;
					while(++mjesec1<mjesec2) proteklo+=mjeseci(mjesec1,godina1);
				} else if(mjesec1>mjesec2 && broj_dana<0) {
					int tmp=mjesec2;
					proteklo+=(mjeseci(tmp,godina1)-dan2)+dan1;
					while(++tmp<mjesec1) proteklo+=mjeseci(tmp,godina1);
				} else {
					if(dan1<dan2) {
						while(dan1++<dan2) proteklo++;
					} else {
						while(dan2++<dan1) proteklo++;
					}
				}
			} else if(godina1<godina2) {
				proteklo=0;
				int tmp=1;
				if(prestupna(godina1)) {
					proteklo+=366;
					while(++tmp<mjesec1) proteklo-=mjeseci(tmp,godina1);
					proteklo-=dan1;
					tmp=1;
					while(++tmp<mjesec2) proteklo+=mjeseci(tmp,godina2);
					proteklo+=dan2;
				} else {
					proteklo+=365;
					while(++tmp<mjesec1) proteklo-=mjeseci(tmp,godina1);
					proteklo-=dan1;
					tmp=1;
					while(++tmp<mjesec2) proteklo+=mjeseci(tmp,godina2);
					proteklo+=dan2;
				}
			} else if(godina1>godina2 && broj_dana<0) {
				proteklo=0;
				int tmp=1;
				if(prestupna(godina2)) {
					proteklo+=366;
					while(++tmp<mjesec2) proteklo-=mjeseci(tmp,godina2);
					proteklo-=dan2;
					tmp=1;
					while(++tmp<mjesec1) proteklo+=mjeseci(tmp,godina1);
					proteklo+=dan1;
				}
			}
			if(proteklo>broj_dana && broj_dana>0 || -proteklo<broj_dana && broj_dana<0) {
				proteklo=0;
				struct Uposlenik* tmp=p;
				while(tmp<kandidati+vel-1) {
					*tmp=*(tmp+1);
					tmp++;
				}
				vel--;
			} else p++;
		} else {
			p++;
			proteklo=0;
			porodica=0;
		}
	}
	return vel;
}

int main()
{
	return 0;
}
