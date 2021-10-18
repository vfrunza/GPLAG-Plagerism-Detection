#include <stdio.h>

struct Datum { int dan, mjesec, godina; };
struct Uposlenik {
		char ime_prezime[50];
		struct Datum datum_rodjenja;
};

int prestupna(int god)
{
	if(god%400==0 || (god%4==0 && god%100!=0)) return 1;
    return 0;
}

int brojdana(struct Datum d)
{
	int rez=0;
    int i;
    for(i=1; i < d.godina; i++) {
        if(prestupna(i)==1)
            rez+=366;
        else
            rez+=365;
    }
    for(i=1; i<d.mjesec; i++) {
        if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12) rez+=31;
        else if(i==2 && prestupna(d.godina)==1) rez+=29;
        else if(i==2 && prestupna(d.godina)==0) rez+=28;
        else rez+=30;
    }
    rez+=d.dan;
    return rez;
}

void dodijeli(char *s1, char *s2)
{
	char *p1=s1, *p2=s2;
	while(*p2!='\0') {*p1++=*p2++;}
	*p1='\0';
}

int uporedi(char *s1, char *s2)
{
	int ima1=0, ima2=0;
	char *p1=s1,*p2=s2, *pc1=s1, *pc2=s2;
	while(*p1!='\0') { if(*p1=='-') { ima1=1; pc1=p1;} p1++;}
	while(*p2!='\0') { if(*p2=='-') {ima2=1; pc2=p2;} p2++;}
	
	if(ima1==0 && ima2==0)
	{
		if((p1-s1)!=(p2-s2)) return 0;
		while(*s1!='\0') if(*s1++!=*s2++) return 0;
		return 1;
	}
	else if(ima1==1 && ima2==0)
	{
		int ima=0;
		//printf("DASDADAS");
		char *pom=s2;
		while(*s1!='-') if(*s1++!=*s2++) ima=1;
		if(ima==0) return 1;
		return(uporedi(pc1+1, pom));
	}
	else if(ima1==0 && ima2==1)
	{
		int ima=0;
		char *pom=s1;
		while(*s2!='-') if(*s1++!=*s2++) ima=1;
		if(ima==0) return 1;
		return(uporedi(pom, pc2+1));
	}
}

int istoprezime(char *s1, char *s2)
{
	char *p1=s1, *p11=s1, *p12=s1;
	char *p2=s2, *p21=s2, *p22=s2;
	
	while(*p1!='\0')
	{
		if(*p1==' ') p11=p1; p1++;
	}
	p11++;
	p12=p1;
	
	while(*p2!='\0')
	{
		if(*p2==' ') p21=p2; p2++;
	}
	p21++;
	p22=p2;
	return uporedi(p11,p21);
}

int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana)
{
	int brdd=brojdana(direktor.datum_rodjenja);
	int i, j;
	for(i=0; i<vel; i++)
	{
		if(brdd-brojdana(kandidati[i].datum_rodjenja)>broj_dana && istoprezime(direktor.ime_prezime, kandidati[i].ime_prezime)==0)
		{
			for(j=i; j<vel-1; j++)
			{
				dodijeli(kandidati[j].ime_prezime,kandidati[j+1].ime_prezime);
				kandidati[j].datum_rodjenja.dan=kandidati[j+1].datum_rodjenja.dan;
				kandidati[j].datum_rodjenja.mjesec=kandidati[j+1].datum_rodjenja.mjesec;
				kandidati[j].datum_rodjenja.godina=kandidati[j+1].datum_rodjenja.godina;
			}
			vel--;
			i--;
		}
	}
	return vel;
}

int main() {
	struct Uposlenik direktor = {"Mujo Mujic-Peric", {3, 3, 1992} };
struct Uposlenik kandidati[7] = {
    { "Meho Mehic", { 31, 1, 1990 } },
    { "Pero Peric", { 1, 2, 1990 } },
    { "Sara Sarac", { 2, 2, 1990 } },
    { "Fata Mujic", { 1, 2, 1986 } },
    { "Jozo Jozic", { 1, 10, 1990 } },
    { "Mijo Mijic", { 4, 3, 1989 } },
    { "Suljo Suljic", { 31, 12, 1991 } },
};

int novi_br = suzi_listu(kandidati, 7, direktor, 3);
int i;
printf("Nakon suzenja liste:\n");
for (i=0; i<novi_br; i++)
    printf("%s\n", kandidati[i].ime_prezime);
    return 0;
}
