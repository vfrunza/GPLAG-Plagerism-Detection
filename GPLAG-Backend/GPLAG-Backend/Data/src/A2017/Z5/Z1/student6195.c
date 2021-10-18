#include <stdio.h>
#include <math.h>

struct Datum {
	int dan, mjesec, godina;
};

struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

int prezime(char* k, char *d) {
	while(*k!='\0' || *d!='\0') {
		if(*k=='-' || *d=='-') break;
		if(*k!=*d) return 0;
		k++;
		d++;
	}
	if((*d=='\0' || *d=='-')&& (*k=='\0' || *k=='-')) return 1;
	return 0;
}

int prestupna_godina(int godina) {
	if((godina%100==0 && godina%400==0 && godina%4==0) || (godina%4==0 && godina%100!=0)) return 1;
	return 0;
}

int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana) {
	int razlika=0,mladji=-1;
	int i,izbaci=0,j,d,m,g;
	char *q, *p1, *p2, *s1, *s2;
	for(i=0; i<vel; i++) {
		izbaci=0;
		razlika=0;
		d=kandidati[i].datum_rodjenja.dan;
		m=kandidati[i].datum_rodjenja.mjesec;
		g=kandidati[i].datum_rodjenja.godina;

		if(g<direktor.datum_rodjenja.godina) mladji=0;
		else if(g>direktor.datum_rodjenja.godina) mladji=1;
		else {
			if(m<direktor.datum_rodjenja.mjesec) mladji=0;
			else if(m>direktor.datum_rodjenja.mjesec) mladji=1;
			else {
				if(d<direktor.datum_rodjenja.dan) mladji=0;
				else if(d>direktor.datum_rodjenja.dan) mladji=1;
			}
		}

		q=direktor.ime_prezime;
		p1=q;
		p2=q;
		while(*q!='\0') {
			if(*q==' ') {
				p1=q;
				p2=q;
			}
			if(*q=='-') p2=q;
			q++;
		}
		p1++;
		p2++;

		if (mladji==1 && broj_dana>0) izbaci=0;
		else if (mladji==0 && broj_dana<0) izbaci=1;
		else if (mladji==1) {
			do {
				d--;
				razlika++;
				if(razlika>fabs(broj_dana)) {
					izbaci=0;
					break;
				}
				if(d<1) {
					m--;
					if(m<1) {
						m=12;
						g--;
					}
					if(m==2 && prestupna_godina(g)==1) d=29;
					else if(m==2) d=28;
					else if(m==4 || m==6 || m==9 || m==11) d=30;
					else d=31;
				}
			} while(d!=direktor.datum_rodjenja.dan ||  m!=direktor.datum_rodjenja.mjesec || g!=direktor.datum_rodjenja.godina );
			if(razlika<fabs(broj_dana)) izbaci=1;
		} else if(mladji==0) {
			do {
				d++;
				razlika++;
				if(razlika>broj_dana) {
					izbaci=1;
					break;
				}
				if(m==2 && prestupna_godina(g)==1 && d==30) {
					d=1;
					m++;
				} else if((m==2 && prestupna_godina(g)==0) && d==29) {
					d=1;
					m++;
				} else if((m==4 || m==6 || m==9 || m==11)&& d==31) {
					d=1;
					m++;
				} else if((m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) && d==32) {
					d=1;
					m++;
				}
				if(m>12) {
					m=1;
					g++;
				}
			} while(d!=direktor.datum_rodjenja.dan || m!=direktor.datum_rodjenja.mjesec || g!=direktor.datum_rodjenja.godina);
		}

		q=kandidati[i].ime_prezime;
		s1=q;
		s2=q;
		while(*q!='\0') {
			if(*q==' ') {
				s1=q;
				s2=q;
			} else if (*q=='-') {
				s2=q;
			}
			q++;
		}
		s1++;
		s2++;

		if(prezime(s1,p1)) izbaci=0;
		else if(prezime(s2,p1)) izbaci=0;
		else if(prezime(s1,p2)) izbaci=0;
		else if(prezime(s2,p2)) izbaci=0;

		if(izbaci==1) {
			for(j=i; j<vel-1; j++) {
				kandidati[j]=kandidati[j+1];
			}
			vel--;
			i--;
		}
	}
	return vel;
}
int main(){
	return 0;
}