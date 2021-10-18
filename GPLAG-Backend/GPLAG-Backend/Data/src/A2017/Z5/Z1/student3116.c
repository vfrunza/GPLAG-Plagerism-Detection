#include <stdio.h>

struct Datum { int dan, mjesec, godina; };
struct Uposlenik {
		char ime_prezime[50];
		struct Datum datum_rodjenja;
	};
	
int istopr(char *s1, char *s2)
{
	char *poc1=s1, *kr1=s1, *pom=s1;
	while(*pom!='\0')
	{
		if(*pom==' ') { poc1=pom+1;} pom++;
	}
	kr1=pom;
	char *poc2=s2, *kr2=s2;
	pom=s2;
	while(*pom!='\0')
	{
		if(*pom==' ') { poc2=pom+1;} pom++;
	}
	kr2=pom;
	char a='d';
	if((kr2-poc2)>=(kr1-poc1))
	{
		char *crta=&a;
		
		char *p=poc2;
		while(p!=kr2) { if(*p=='-') crta=p; p++;}
		if(crta!=&a)
		{
			int da=1;
			p=poc2;
			char *poc11=poc1;
			while(p!=crta) {if(*p!=*poc11) da=0; p++; poc11++;}
			if(da==1) return 1;
			else
			{
				p++; da=1;
				poc11=poc1;
				while(p!=kr2) {if(*p!=*poc11) da=0; p++; poc11++;}
				if(da==1) return 1;
				else return 0;
			}
		}
		while(poc2!=kr2) { if(*poc1!=*poc2) return 0; poc1++; poc2++;}
		//if(*poc1!='\0') return 0;	
		return 1;
	}
	else
	{
		char *crta=&a;
		char *p=poc1;
		while(p!=kr1) { if(*p=='-') crta=p; p++;}
		if(crta!=&a)
		{
			int da=1;
			p=poc1;
			char *poc11=poc2;
			while(p!=crta) {if(*p!=*poc11) da=0; p++; poc11++;}
			if(da==1) return 1;
			else
			{
				p++; da=1;
				poc11=poc2;
				while(p!=kr1) {if(*p!=*poc11) da=0; p++; poc11++;}
				if(da==1) return 1;
				else return 0;
			}
		}
		while(poc1!=kr1) { if(*poc1!=*poc2)return 0; poc1++; poc2++;}
		//if(*poc2!='\0') return 0;	
		return 1;
	}
}
	
int broj(struct Datum d)
{
	int br=d.dan;
    int i;
    for(i=1; i < d.godina; i++) {
        if(i%400==0 || (i%4==0 && i%100!=0)) br+=366;
        else br+=365;
    }
    for(i=1; i<d.mjesec; i++) {
        if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12) br+=31;
        else if(i==2)
        {
        	if(d.godina%400==0 || (d.godina%4==0 && d.godina%100!=0)) br+=29;
        	else br+=28;
        }
        else br+=30;
    }
    return br;
}
	
int razlikadana(struct Uposlenik d, struct Uposlenik u)
{
	//if(d.datum_rodjenja.godina==u.datum_rodjenja.godina && d.datum_rodjenja.mjesec==u.datum_rodjenja.mjesec)
	//	return u.datum_rodjenja.dan-d.datum_rodjenja.dan+2;
	return broj(d.datum_rodjenja)-broj(u.datum_rodjenja);
}

int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana)
{
	int i, j;
	char *p1,*p2;
	for(i=0; i<vel; i++)
	{
		if(razlikadana(direktor,kandidati[i])>broj_dana)
		{
			
			if(istopr(direktor.ime_prezime,kandidati[i].ime_prezime)==0)
			{
				//printf("ASSDDDD\n");
				for(j=i; j<vel-1; j++)
				{
					kandidati[j].datum_rodjenja.godina=kandidati[j+1].datum_rodjenja.godina;
					kandidati[j].datum_rodjenja.mjesec=kandidati[j+1].datum_rodjenja.mjesec;
					kandidati[j].datum_rodjenja.dan=kandidati[j+1].datum_rodjenja.dan;
					p1=kandidati[j].ime_prezime;
					p2=kandidati[j+1].ime_prezime;
					while(*p2!='\0') { *p1=*p2; p1++; p2++;}
					*p1='\0';
				}
				vel--;
				i--;
			}
		} //else printf("%d %d %d\n", broj(direktor.datum_rodjenja), broj(kandidati[i].datum_rodjenja),razlikadana(direktor,kandidati[i]));
	}
	return vel;
}

int main() {
	/* AT7: Negativna razlika dana, ne ostaje niko */
struct Uposlenik direktor = {"Mujo Mujic", {1, 1, 1892} };
struct Uposlenik kandidati[7] = {
    { "Meho Mehic", { 31, 1, 1990 } },
    { "Pero Peric", { 1, 2, 1990 } },
    { "Sara Sarac", { 2, 10, 1990 } },
    { "Fata Mujicic", { 1, 2, 1986 } },
    { "Jozo Jozic", { 1, 10, 1990 } },
    { "Mijo Mijic", { 4, 3, 1989 } },
    { "Suljo Suljc", { 15, 1, 1992 } },
};
//int novi_br = suzi_listu(kandidati, 7, direktor, -15);
//printf("Novi broj: %d\n", novi_br);
direktor.datum_rodjenja.godina = 1992;
int novi_br = suzi_listu(kandidati, 7, direktor, 15);
printf("Novi broj: %d\n", novi_br);
int i;
//for(i=0; i<novi_br; i++) printf("\n%s\n", kandidati[i].ime_prezime);
return 0;
}
