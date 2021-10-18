#include <stdio.h>
#include <string.h>

struct Datum { int dan,mjesec,godina };

struct Uposlenik
{
 char ime_prezime[50];
 struct Datum datum_rodjenja;
};

int IstoPrezime(char *s1, char *s2)
{
 int duzina1=strlen(s1);
 int duzina2=strlen(s2);
 while(*s1!=' ')
 {
  s1++;
 }
 s1++;
 while(*s2!=' ')
 {
  s2++;
 }
 s2++;
 while(*s1!='\0' || *s2!='\0')
 {
  if(*s1!=*s2) return 0;
 }
 return 1;
}

int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana)
{
 int i=0,n=0,j=0;
 n=broj_dana+direktor.datum_rodjenja.dan;
 if(direktor.datum_rodjenja.mjesec==1 || direktor.datum_rodjenja.mjesec==3 || direktor.datum_rodjenja.mjesec==5 || direktor.datum_rodjenja.mjesec==7 || direktor.datum_rodjenja.mjesec==8 || direktor.datum_rodjenja.mjesec==10 || direktor.datum_rodjenja.mjesec==12)
 {
  direktor.datum_rodjenja.dan=n;
  if(direktor.datum_rodjenja.dan>31)
  {
   direktor.datum_rodjenja.dan=1;
   direktor.datum_rodjenja.mjesec++;
   if(direktor.datum_rodjenja.mjesec>12)
   {
    direktor.datum_rodjenja.mjesec=1;
    direktor.datum_rodjenja.godina++;
   }
  }
 }
 else if(direktor.datum_rodjenja.mjesec==2)
 {
  direktor.datum_rodjenja.dan=n;
  if(direktor.datum_rodjenja.godina%4==0)
  {
   if(direktor.datum_rodjenja.godina%100!=0 && direktor.datum_rodjenja.godina%400==0)
   {
    if(direktor.datum_rodjenja.dan>29)
    {
     direktor.datum_rodjenja.dan=1;
     direktor.datum_rodjenja.mjesec++;
     if(direktor.datum_rodjenja.mjesec>12)
     {
      direktor.datum_rodjenja.mjesec=1;
      direktor.datum_rodjenja.godina++;
     }
    }
   }
  }
  else
  {
   if(direktor.datum_rodjenja.dan>28)
   {
    direktor.datum_rodjenja.dan=1;
    direktor.datum_rodjenja.mjesec++;
    if(direktor.datum_rodjenja.mjesec>12)
    {
     direktor.datum_rodjenja.mjesec=1;
     direktor.datum_rodjenja.godina++;
    }
   }
  }
 }
 else
 {
  if(direktor.datum_rodjenja.dan>30)
  {
   direktor.datum_rodjenja.dan=1;
   direktor.datum_rodjenja.mjesec++;
   if(direktor.datum_rodjenja.mjesec>12)
   {
    direktor.datum_rodjenja.mjesec=1;
    direktor.datum_rodjenja.godina++;
   }
  }
 }
 for(i=0;i<vel;i++)
 {
  if(kandidati[i].datum_rodjenja.dan==direktor.datum_rodjenja.dan && kandidati[i].datum_rodjenja.mjesec==direktor.datum_rodjenja.mjesec && kandidati[i].datum_rodjenja.godina==direktor.datum_rodjenja.godina)
  {
   /*if(IstoPrezime(kandidati[i].ime_prezime,direktor.ime_prezime)==0)*/
   {
    for(j=i;j<vel-1;j++)
    {
     kandidati[j]=kandidati[j+1];
    }
    vel--;
    i--;
   }
  }
 }
 return --vel;
}

int main() {
	printf("Zadaća 5, Zadatak 1");
	return 0;
}
