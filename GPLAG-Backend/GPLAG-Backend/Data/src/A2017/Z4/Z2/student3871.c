#include <stdio.h>
int provjeri_duzine(char *s,int niz[],int x)
{
 int brojac=0;
 int broj_rijeci=1; /*broj rijeci postavljam na 1*/
 if(!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))) broj_rijeci=0; /*kada ne pocinje sa slovom broj rijeci je 0*/
 while(*s!='\0')
 { 
  if(!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) && ((*(s+1)>='A' && *(s+1) <= 'Z') || (*(s+1)>='a' && *(s+1)<='z'))) broj_rijeci++; /*koliko ima rijeci u recenici*/
  s++;
  brojac++; /*pamtim koliko se pokazivac pomjerio*/
 }
 s-=brojac; /*vracam pokazivac na pocetak recenice*/
 if(broj_rijeci!=x) return 0; /*broj rijeci se mora poklapati sa velicinom niza*/
 else 
 {
  int broj_slova=0;
  int i=0;
  while(*s!='\0')
  {
   if((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))
   {
    broj_slova=0; /*stalno broj slova vracam na nulu*/
    while(((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) && *s!='\0')
    {
     broj_slova++;
     s++;
    }
    if(broj_slova!=niz[i]) return 0; /*poredim clan niza za brojem slova rijeci*/
    i++;
    if(*s=='\0') break; /*kad pokazivac dodje na kraj recenice breakam petlju da ne dodje do memorijske greske*/
   }
   s++;
  }
  return 1;
 }
}
int main() {
	return 0;
}
