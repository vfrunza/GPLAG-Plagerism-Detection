#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct Datum { 
 int dan, mjesec, godina;
 
};


	struct Uposlenik {
		char ime_prezime[50];
		struct Datum datum_rodjenja;
	};


int da_li_rodbina(char kandidati[], char direktor[]){
 
 char*p=kandidati;
 char*q=direktor;
 while (*q!='\0') {
  if(*q==' ') {
  q++;
  break;
  }
  q++;
  }
  
  while (*p!='\0') {
   if(*p==' ') {
    p++;
    break;
   }
   p++;
  }
 
 while(*p!='\0'){
  
  if(*p==*q){
   while(*p++==*q++){
    if(*q=='\0' && *p=='\0') 
    return 1;
   
  }
  }
  p++;
 }
 
 
 return 0;
}

int godina_prestupna(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int broj_dana(struct Datum d) {
 
    int rez = 0;
    int i;
    
 int dani_u_mjesecu[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    for(i=1; i < d.godina; i++) {
        if(godina_prestupna(i))
            rez += 366;
        else
            rez += 365;
    }

    for(i=1; i < d.mjesec; i++) {
        rez += dani_u_mjesecu[i];

        if(godina_prestupna(d.godina) && i == 2) rez++;
    }

    rez += d.dan;
    return rez;
}


int saberi_dane(struct Datum datum_rodjenja)
{

    return broj_dana(datum_rodjenja);
}

int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana) {
 
 int i=0;
 int direktorr=saberi_dane(direktor.datum_rodjenja);

 for(i=0; i<vel; i++) {
  
  int da_li_rodbine=da_li_rodbina(kandidati[i].ime_prezime,direktor.ime_prezime);

  
  if(da_li_rodbine==0 ) {
   
  
  int x=saberi_dane(kandidati[i].datum_rodjenja)+ broj_dana;

  
  if(x < direktorr ) {
   int j,k=i;
   for(j=k+1; j<vel; j++){
   struct Uposlenik temp=kandidati[k];
   kandidati[k]=kandidati[j];
   kandidati[j]=temp;
   k++;
  }
  i--;
  vel--;
 }
}
}
return vel ;
}

int main () {
struct Uposlenik direktor = {"Mujo Mujic", {1, 3, 1980} };
struct Uposlenik kandidati[7] = {
  { "Fata Mujic", { 1, 2, 1976 } },
    { "Meho Mehic", { 31, 1, 1980 } },
    { "Pero Peric", { 1, 2, 1980 } },
    { "Sara Sarac", { 2, 2, 1980 } },
   
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






