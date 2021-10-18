#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Datum {
	int dan, mjesec, godina;
};

struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

int prijestupne(struct Datum d) //Racuna broj prijestupnih godina
{
	int god=d.godina;
	if(d.mjesec<=2) //Trenutna godina se ne uzima u obzir ako je uslov ispunjen
		god--;
		
	return god/4 - god/100 + god/400;
}

int razlika_dana(struct Datum d1,struct Datum d2)
{
	int broj_dana[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int i;
	
	long int br1=d1.godina*365 + d1.dan; //Ukupan broj dana u godinama i dati dani
	
	for(i=0; i<d1.mjesec-1;i++) //Dani po mjesecima
		br1+=broj_dana[i];
		
	br1+=prijestupne(d1);
	
	long int br2=d2.godina*365+d2.dan;
	
	for(i=0; i<d2.mjesec-1;i++)
		br2+=broj_dana[i];
	
	br2+=prijestupne(d2);
	
	return br1-br2;
}

char* samo_prezime(char*s) //Nalazi prezime u stringu
{
	char*p=s;
	int razmak=1;
	while(*s!='\0')
	{
		if(*s==' ') razmak=1;
		else if(razmak==1)
		{
			razmak=0;
			p=s;
		}
	s++;
	}
	return p;
}

int duploprez(char*p) //Trazi dupla prezimena
{
	while(*p!='\0')
	{
		if(*p=='-') return 1;
		p++;
	}
	return 0;
}

int poredi_prezime(char*s1,char*s2) //Poredi sve moguce kombinacije prezimena direktora i uposlenika
{
	char*pom1=s1,*pom2=s2;
	if(duploprez(s1)==1 && duploprez(s2)==1)
	{
		char p1[1000],p2[1000],q1[1000],q2[1000];
		char*prez1=p1,*prez2=p2,*qrez1=q1,*qrez2=q2,*pocdrugog,*pocprvog;
		pocprvog=prez1;
		while(*pom1!='-')
		{
			*prez1=*pom1;
			pom1++;
			prez1++;
		}
		*prez1='\0';
		prez1=pocprvog;
		pom1++;
		pocdrugog=pom1;
		while(*pom1!='\0')
		{
			*prez2=*pom1;
			pom1++;
			prez2++;
		}
		*prez2='\0';
		prez2=pocdrugog;
		
		pocprvog=qrez1;
		while(*pom2!='-')
		{
			*qrez1=*pom2;
			pom2++;
			qrez1++;
		}
		*qrez1='\0';
		qrez1=pocprvog;
		pom2++;
		pocdrugog=pom2;
		while(*pom2!='\0')
		{
			*qrez2=*pom2;
			pom2++;
			qrez2++;
		}
		*qrez2='\0';
		qrez2=pocdrugog;
		
		if(strcmp(prez1,qrez1)!=0 && strcmp(prez1,qrez2)!=0 && strcmp(prez2,qrez1)!=0 && strcmp(prez2,qrez2)!=0)
			return 0;
		else return 1;
	}
	if(duploprez(s1)==1 && duploprez(s2)==0)
	{
		char p1[1000],p2[1000];
		char *prez1=p1,*prez2=p2,*pocprvog,*pocdrugog;
		pocprvog=prez1;
		while(*pom1!='-')
		{
			*prez1=*pom1;
			pom1++;
			prez1++;
		}
		*prez1='\0';
		prez1=pocprvog;
		pom1++;
		pocdrugog=pom1;
		while(*pom1!='\0')
		{
			*prez2=*pom1;
			pom1++;
			prez2++;
		}
		*prez2='\0';
		prez2=pocdrugog;
		if(strcmp(prez1,s2)!=0 && strcmp(prez2,s2)!=0) return 0;
		else return 1;
	}
	
	if(duploprez(s1)==0 && duploprez(s2)==1)
	{
		char p1[1000],p2[1000];
		char *prez1=p1,*prez2=p2,*pocprvog,*pocdrugog;
		pocprvog=prez1;
		while(*pom2!='-')
		{
			*prez1=*pom2;
			pom2++;
			prez1++;
		}
		*prez1='\0';
		prez1=pocprvog;
		pom2++;
		pocdrugog=pom2;
		while(*pom2!='\0')
		{
			*prez2=*pom2;
			pom2++;
			prez2++;
		}
		*prez2='\0';
		prez2=pocdrugog;
		if(strcmp(prez1,s1)!=0 && strcmp(prez2,s1)!=0) return 0;
		else return 1;
	}
	
	if(duploprez(s1)==0 && duploprez(s2)==0)
	{
		if(strcmp(s1,s2)!=0) return 0;
		else return 1;
	}
	
	return 0;
}

int suzi_listu(struct Uposlenik *kandidati, int vel, struct Uposlenik direktor, int broj_dana)
{
	int i,j;
	char*p1,*p2;
	p1=samo_prezime(direktor.ime_prezime);
	for(i=0;i<vel;i++)
	{
		p2=samo_prezime(kandidati[i].ime_prezime);
		int razlika;
		razlika=razlika_dana(direktor.datum_rodjenja,kandidati[i].datum_rodjenja);
		if(poredi_prezime(p1,p2)==0)
		{

			if(razlika>broj_dana)
			{
				for(j=i;j<vel-1;j++)
					kandidati[j]=kandidati[j+1];
				vel--;
				i--;
			}
		}
	}
	
	return vel;
}

int main() {
	
struct Uposlenik direktor = {"Mujo Mujic", {1, 3, 1980} };
struct Uposlenik kandidati[7] = {
    { "Meho Mehic", { 31, 1, 1980 } },
    { "Pero Peric", { 1, 2, 1980 } },
    { "Sara Sarac", { 2, 2, 1980 } },
    { "Fata Mujic", { 1, 2, 1976 } },
    { "Jozo Jozic", { 1, 10, 1980 } },
    { "Mijo Mijic", { 4, 3, 1979 } },
    { "Suljo Suljic", { 15, 1, 1982 } },
};

int novi_br = suzi_listu(kandidati, 7, direktor, 28);
int i;
printf("Nakon suzenja liste:\n");
for (i=0; i<novi_br; i++)
    printf("%s\n", kandidati[i].ime_prezime);

	return 0;
}
