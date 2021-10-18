#include <stdio.h>
#include <math.h>

struct Datum {
	int dan, mjesec, godina;
};

struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

int razlika_u_danima(struct Datum datum1, struct Datum datum2)
{
	int razlika=0, i=0, p=0, k=0, d=0, s=0;
	if((datum1.godina%4==0 && datum1.godina%100!=0) || (datum1.godina%400==0)) {
		razlika+=1;
	}
	if(datum2.godina!=datum1.godina && ((datum2.godina%4==0 && datum2.godina%100!=0) || (datum2.godina%400==0))) {
		razlika+=1;
	}

	if((datum1.godina<=datum2.godina && datum1.mjesec<=datum2.mjesec) || (datum2.godina<=datum1.godina && datum2.mjesec<=datum1.mjesec)) {
		if(datum1.godina<=datum2.godina && datum1.mjesec<=datum2.mjesec) {
			razlika=razlika+(datum2.godina-datum1.godina)*365;
			p=datum1.mjesec;
			k=datum2.mjesec;
			d=datum2.dan;
			s=datum1.dan;
		} else if(datum2.godina<=datum1.godina && datum2.mjesec<=datum1.mjesec) {
			razlika=razlika+(datum1.godina-datum2.godina)*365;
			p=datum2.mjesec;
			k=datum1.mjesec;
			d=datum1.dan;
			s=datum2.dan;
		}

		for(i=p; i<=k; i++) {
			if(i==k) {
				razlika+=d;
				break;
			} else if(i==1) {
				razlika+=31;
			} else if(i==2) {
				razlika+=28;
			} else if(i==3) {
				razlika+=31;
			} else if(i==4) {
				razlika+=30;
			} else if(i==5) {
				razlika+=31;
			} else if(i==6) {
				razlika+=30;
			} else if(i==7) {
				razlika+=31;
			} else if(i==8) {
				razlika+=31;
			} else if(i==9) {
				razlika+=30;
			} else if(i==10) {
				razlika+=31;
			} else if(i==11) {
				razlika+=30;
			} else if(i==12) {
				razlika+=31;
			}
		}
		razlika=razlika-s;
	} else if((datum1.godina<=datum2.godina && datum2.mjesec<=datum1.mjesec) || (datum2.godina<=datum1.godina && datum1.mjesec<=datum2.mjesec)) {
		if(datum1.godina<=datum2.godina && datum2.mjesec<=datum1.mjesec) {
			razlika=razlika+(datum2.godina-datum1.godina-1)*365;
			p=datum1.mjesec;
			k=datum2.mjesec;
			d=datum2.dan;
			s=datum1.dan;
		} else if(datum2.godina<=datum1.godina && datum1.mjesec<=datum2.mjesec) {
			razlika=razlika+(datum1.godina-datum2.godina-1)*365;
			p=datum2.mjesec;
			k=datum1.mjesec;
			d=datum1.dan;
			s=datum2.dan;
		}
		for(i=p; i<=12; i++) {
			if(i==1) {
				razlika+=31;
			} else if(i==2) {
				razlika+=28;
			} else if(i==3) {
				razlika+=31;
			} else if(i==4) {
				razlika+=30;
			} else if(i==5) {
				razlika+=31;
			} else if(i==6) {
				razlika+=30;
			} else if(i==7) {
				razlika+=31;
			} else if(i==8) {
				razlika+=31;
			} else if(i==9) {
				razlika+=30;
			} else if(i==10) {
				razlika+=31;
			} else if(i==11) {
				razlika+=30;
			} else if(i==12) {
				razlika+=31;
				break;
			}
		}
		for(i=1; i<=k; i++) {
			if(i==k) {
				razlika+=d;
				break;
			} else if(i==1) {
				razlika+=31;
			} else if(i==2) {
				razlika+=28;
			} else if(i==3) {
				razlika+=31;
			} else if(i==4) {
				razlika+=30;
			} else if(i==5) {
				razlika+=31;
			} else if(i==6) {
				razlika+=30;
			} else if(i==7) {
				razlika+=31;
			} else if(i==8) {
				razlika+=31;
			} else if(i==9) {
				razlika+=30;
			} else if(i==10) {
				razlika+=31;
			} else if(i==11) {
				razlika+=30;
			} else if(i==12) {
				razlika+=31;
			}
		}
		razlika=razlika-s;
	}
	return razlika;
}

int ima_li_crta(char *s)
{
	int ima=0;
	while(*s!='\0') {
		if(*s=='-') return 1;
		s++;
		if(*s=='\0') break;
	}
	return ima;
}

int provjeri_sa_crtom(char *s1, char *s2)
{
	int isti=0;
	char *p,*q;
	int ima1=0, ima2=0;
	ima1=ima_li_crta(s1);
	ima2=ima_li_crta(s2);
	while(*s1!='\0' && *s2!='\0') {
		if(*s1=='\0' || *s2=='\0') {
			break;
		}
		while(*s1!=' ') {
			s1++;
			if(*s1=='\0') break;
		}
		s1++;
		if(*s1=='\0') break;
		p=s1;
		while(*s2!=' ') {
			s2++;
			if(*s2=='\0') break;
		}
		s2++;
		if(*s2=='\0') break;
		q=s2;
		if(*s1==*s2) {
			while(*s1!='-' || *s2!='-') {
				if(*s1==*s2) {
					s1++;
					s2++;
				} else {
					break;
				}
				if(*s1=='-' || *s2=='-') {
					isti=1;
					return isti;
				}
				if(*s1=='\0') break;
				if(*s2=='\0') break;
			}
		} else {
			if(ima1==1) {
				while(*s1!='-') {
					s1++;
					if(*s1=='\0') break;
				}
				s1++;
				if(*s1=='\0') break;
				if(*s1==*q) {
					while(*s1!='\0' && *q!='\0') {
						if(*s1==*q) {
							s1++;
							q++;
						}
						if(*s1=='\0' && *q=='\0') {
							isti=1;
							return 1;
						}
					}
				} else {
					isti=0;
					return isti;
				}
			} else if(ima2==1) {
				while(*s2!='-') {
					s2++;
					if(*s2=='\0') break;
				}
				s2++;
				if(*s2=='\0') break;
				if(*s2==*p) {
					while(*s2!='\0' && *p!='\0') {
						if(*s2==*p) {
							s2++;
							p++;
						} else {
							break;
						}
						if(*s2=='\0' && *p=='\0') {
							isti=1;
							return isti;
						}
					}
				} else {
					isti=0;
					return isti;
				}
			}
		}
	}
	return isti;
}

int uporedi_prezimena(char *s1, char *s2)
{
	int isti=0;
	if(ima_li_crta(s1)==1 || ima_li_crta(s2)==1) {
		isti=provjeri_sa_crtom(s1,s2);
		return isti;
	}
	while(*s1!='\0' && *s2!='\0') {
		while(*s1!=' ') {
			s1++;
			if(*s1=='\0') break;
		}
		s1++;
		while(*s2!=' ') {
			s2++;
			if(*s2=='\0') break;
		}
		s2++;
		if(*s1==*s2) {
			while(*s1!='\0' && *s2!='\0') {
				if(*s1==*s2) {
					s1++;
					s2++;
					if(*s1=='\0' && *s2=='\0') {
						isti=1;
						return isti;
					}
				} else {
					isti=0;
					return isti;
				}
			}
		} else {
			isti=0;
			return isti;
		}
	}
	return isti;
}


int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana)
{

	int broj, k, i=0, j=0;
	struct Uposlenik temp;
	if(vel==0) return 0;
	for(i=0; i<vel; i++) {
		if(direktor.datum_rodjenja.godina>=kandidati[i].datum_rodjenja.godina) {
			k=razlika_u_danima(kandidati[i].datum_rodjenja,direktor.datum_rodjenja);
			if(k>broj_dana) {
				if(uporedi_prezimena(kandidati[i].ime_prezime,direktor.ime_prezime)==0) {
					temp=kandidati[i];
					for(j=i; j<vel; j++) {
						if(j==vel-1) break;
						kandidati[j]=kandidati[j+1];
					}
					kandidati[vel-1]=temp;
					vel--;
					i--;
					broj=vel;
				}
			}
		}
	}
	return broj;
}

int main()
{

	return 0;
}
