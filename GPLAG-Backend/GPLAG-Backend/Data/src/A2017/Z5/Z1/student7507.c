#include <stdio.h>
#include <stdlib.h>
 
struct Datum {
	int dan, mjesec, godina;
};

struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

void unesi (char niz[], int velicina)
{
	int i=0;
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	while(i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

int prestupna (int godina)
{
	if((godina%4==0 && godina%100!=0) || godina%400==0) return 1;
	return 0;
}

int razlika (struct Datum kandidat, struct Datum direktor)
{
	int broj_dana[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
	int dani=0, i, god_tmp, mj_tmp;


	if(kandidat.mjesec==direktor.mjesec && kandidat.dan<direktor.dan) {
		dani+=direktor.dan-kandidat.dan;
	}

	else if(kandidat.godina==direktor.godina && kandidat.mjesec<direktor.mjesec) {
		for(i=kandidat.mjesec; i<direktor.mjesec-1; i++) {
			dani+=broj_dana[i];
		}
		dani+=direktor.dan;
		dani+=broj_dana[kandidat.mjesec-1]-kandidat.dan;
		if(prestupna(direktor.godina) && direktor.mjesec>=2) dani++;
	}

	else if(direktor.godina > kandidat.godina) {
		mj_tmp=kandidat.mjesec;

		for(i=mj_tmp; i<12; i++) {
			dani+=broj_dana[i];
		}

		dani+=(broj_dana[kandidat.mjesec-1]-kandidat.dan);

		if(prestupna(kandidat.godina) && kandidat.mjesec>=2) dani++;

		god_tmp=kandidat.godina+1;
		while(god_tmp<direktor.godina) {
			if(!prestupna(god_tmp)) dani+=365;
			else dani+=366;
			god_tmp++;
		}

		for(i=0; i<direktor.mjesec-1; i++) {
			dani+=broj_dana[i];
		}
		dani+=direktor.dan;

		if(prestupna(direktor.godina) && direktor.mjesec>=2) dani++;
	}

	return dani;
}

int jednako_prezime(const char *kandidat, const char* direktor)
{
	int  razmak_d=0, crta_d=0, jednako=0, postavljeno=0, dvaprez=0;
	const char *d_start=direktor, *d_end=direktor, *k=kandidat, *d=direktor, *p,*q;


	while(*d!='\0') {
		if(*d==' ') razmak_d++;
		if(*d=='-') crta_d++;
		d++;
	}


	d=direktor;
	if(razmak_d==1 && crta_d==0) {
		while (*d!='\0') {
			if(*d==' ') {
				d_start=d+1;
				d_end=d+1;
				while(*d_end++!='\0');
				d_end--;
				break;
			}
			d++;
		}

	}

	else if(razmak_d==2 && crta_d==0) {
		d=direktor;
		razmak_d=0;
		while (*d!='\0') {
			if(*d==' ') razmak_d++;
			if(razmak_d==2 && postavljeno==0) {
				d_start=d+1;
				postavljeno=1;
			} else d_end=d;
			d++;
		}
	}

	else if(razmak_d==1 && crta_d==1) {
		d=direktor;
		while (*d!='\0') {
			if(*d==' ')
				d_start=d+1;
			if(*d=='-')
				d_end=d-1;
			d++;
		}
		dvaprez=1;
	}

	else if(razmak_d==2 && crta_d==1) {
		d=direktor;
		razmak_d=0;
		while (*d!='\0') {
			if(*d==' ') razmak_d++;
			if(razmak_d==2 && postavljeno==0) {
				d_start=d+1;
				postavljeno=1;
			}
			if(*d=='-') d_end=d-1;
			d++;
		}
		dvaprez=1;
	}

	k=kandidat;
	while(*k!='\0') {
		p=k;
		q=d_start;
		while(*p++==*q++)
			if(*q==*d_end && (*p=='\0' || *p=='-')) {
				jednako=1;
				break;
			}
		if(jednako) return 1;
		k++;
	}


	if(dvaprez) {
		k=kandidat;
		d_start=d_end+2;
		while(*k!='\0') {
			p=k;
			q=d_start;
			while(*p++==*q++)
				if(*q=='\0') {
					jednako=1;
					break;
				}
			if(jednako) return 1;
			k++;
		}
	}


	return 0;
}



int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana)
{
	int i, j;

	for (i=0; i<vel; i++) {
		if(!jednako_prezime(kandidati[i].ime_prezime, direktor.ime_prezime) && razlika(kandidati[i].datum_rodjenja, direktor.datum_rodjenja)>abs(broj_dana)) {
			for(j=i; j<vel-1; j++) {
				kandidati[j]=kandidati[j+1];
			}
			i--;
			vel--;
		}
	}

	return vel;
}

int main()
{
	return 0;
}
