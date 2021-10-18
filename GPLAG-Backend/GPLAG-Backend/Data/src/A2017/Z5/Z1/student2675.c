#include <stdio.h>
#include <string.h>

struct Datum {
	int dan, mjesec, godina;
};

struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

int razlika(struct Datum d1, struct Datum d2)
{
	int br_dana=0;
	int veca;

	if (d1.godina>d2.godina)
		veca=1;
	if (d2.godina>d1.godina)
		veca=2;
	if (d1.godina==d2.godina)
		veca=0;
	if (!veca) {
		if (d1.mjesec>d2.mjesec)
			veca=1;
		if (d2.mjesec>d1.mjesec)
			veca=2;
		if (d1.mjesec==d2.mjesec)
			veca=0;
		if (!veca) {
			if (d1.dan>d2.dan)
				veca=1;
			else if (d2.dan>d1.dan)
				veca=2;
			else
				return 0;
		}
	}

	while (d1.godina!=d2.godina || d1.mjesec!=d2.mjesec || d1.dan!=d2.dan) {

		if (veca==1) {
			d1.dan--;
			if (d1.dan==0) {
				d1.mjesec--;
				if (d1.mjesec==0) {
					d1.dan=31;
					d1.mjesec=12;
					d1.godina--;
				} else if (d1.mjesec==2) {
					if (((d1.godina%4==0)&&(d1.godina%100!=0))||(d1.godina%400==0))
						d1.dan=29;
					else
						d1.dan=28;
				} else if (d1.mjesec==1 || d1.mjesec==3 ||d1.mjesec==5 ||d1.mjesec==7 ||d1.mjesec==8 ||d1.mjesec==10)
					d1.dan=31;
				else
					d1.dan=30;
			}
			br_dana++;
		}

		if (veca==2) {
			d2.dan--;
			if (d2.dan==0) {
				d2.mjesec--;
				if (d2.mjesec==0) {
					d2.dan=31;
					d2.mjesec=12;
					d2.godina--;
				} else if (d2.mjesec==2) {
					if (((d2.godina%4==0)&&(d2.godina%100!=0))||(d2.godina%400==0))
						d2.dan=29;
					else
						d2.dan=28;
				} else if (d2.mjesec==1 || d2.mjesec==3 ||d2.mjesec==5 ||d2.mjesec==7 ||d2.mjesec==8 ||d2.mjesec==10)
					d2.dan=31;
				else
					d2.dan=30;
			}
			br_dana++;
		}
	}

	if (veca==2)
		return br_dana;
	else
		return -br_dana;
}

int uporedi(char *s1, char *s2)
{
	char *pom;
	char *pom_2;
	while (*s2!='\0') {
		s2++;
	}
	while (*s2!=' ') {
		s2--;
	}
	while (*s1!='\0') {
		s1++;
	}
	while (*s1!=' ') {
		s1--;
	}

	pom=s2;
	while (*s1!='\0' && *pom!='\0') {
		if (*s1!=*pom) {
			break;
		}
		s1++;
		pom++;
	}
	if ((*s1=='\0' && *pom=='\0') || (*s1=='\0' && *pom=='-') || (*s1=='-' && *pom=='\0'))
		return 1;

	pom=s2;
	pom_2=s1;

	while (*s1!='\0') {
		if (*s1=='-')
			break;
		s1++;
	}

	if (*s1=='-') {
		s1++;
		pom++;
		while (*s1!='\0' && *pom!='\0') {
			if (*s1!=*pom) {
				break;
			}
			pom++;
			s1++;
		}
		if ((*s1=='\0' && *pom=='\0')||(*s1=='\0' && *pom=='-'))
			return 1;
	}

	s1=pom_2;
	while (*s2!='\0') {
		if (*s2=='-')
			break;
		s2++;
	}

	pom=s2;
	if (*s2=='-') {
		s2++;
		pom++;
		while (*s1!='\0' && *pom!='\0') {
			if (*s1!=*pom) {
				break;
			}
			pom++;
			s1++;
		}
		if ((*s1=='\0' && *pom=='\0')||(*s1=='-' && *pom=='\0'))
			return 1;


		while (*s1!='\0') {
			if (*s1=='-')
				break;
			s1++;
		}

		pom=s2;
		if (*s1=='-') {
			s1++;
			pom++;
			while (*s1!='\0' && *pom!='\0') {
				if (*s1!=*pom) {
					break;
				}
				pom++;
				s1++;
			}
			if (*s1=='\0' && *pom=='\0')
				return 1;
		} else
			return 0;
	}
	return 0;
}


int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana)
{
	int br_dana;
	int i, j;
	if (broj_dana==0)
		return vel;

	for (i = 0; i < vel; i++) {
		br_dana=razlika(kandidati[i].datum_rodjenja, direktor.datum_rodjenja);
		if ((broj_dana>0 && br_dana>0 && br_dana>broj_dana)||(br_dana>=0 && broj_dana<0)||(broj_dana<0 && br_dana<0 && br_dana>broj_dana)) {
			if (!uporedi(kandidati[i].ime_prezime, direktor.ime_prezime)) {
				for (j = i; j < vel-1; j++) {
					strcpy(kandidati[j].ime_prezime, kandidati[j+1].ime_prezime);
					kandidati[j].datum_rodjenja=kandidati[j+1].datum_rodjenja;
				}
				vel--;
				i--;
			}
		}
	}
	return vel;
}

int main()
{
	/* AT6: Negativna razlika dana */
	struct Uposlenik direktor = {"Mujo Mujic", {1, 9, 1980} };
	struct Uposlenik kandidati[7] = {
		{ "Meho Mehic", { 31, 1, 1980 } },
		{ "Pero Peric", { 1, 2, 1980 } },
		{ "Sara Sarac", { 3, 10, 1980 } },
		{ "Fata Mujic", { 1, 2, 1976 } },
		{ "Jozo Jozic", { 2, 10, 1980 } },
		{ "Mijo Mijic", { 4, 3, 1979 } },
		{ "Suljo Suljc", { 15, 1, 1982 } },
	};

	int novi_br = suzi_listu(kandidati, 7, direktor, -31);
	int i;
	printf("Nakon suzenja liste:\n");
	for (i=0; i<novi_br; i++)
		printf("%s\n", kandidati[i].ime_prezime);
	return 0;
}
