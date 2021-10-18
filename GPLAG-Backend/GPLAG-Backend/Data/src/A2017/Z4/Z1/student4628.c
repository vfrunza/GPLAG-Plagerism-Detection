#include <stdio.h>
#include <string.h>
void unesi (char niz[], int velicina)
{
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}

char *ubaci_broj (char* tekst, int broj)
{
  char *temp=tekst;
  int duzina_broja,var1,var;
  
  while (broj>0)
  {
      var1=broj%10;
      broj=broj/10;
      duzina_broja++;
  }

  while (*tekst!='\0')
  {
      if (*tekst==' ')
      {
          char *kraj=tekst;
          while (*kraj!='\0')
          {
              kraj++;
          }
          while (kraj>tekst)
          {
              *(kraj+duzina_broja)=*kraj;
              kraj--;
          }
      }
      
      while (broj!=0)
      {
          var=broj%10+'0';
          *tekst=var;
          broj=broj/10;
      }
      
     tekst++; 
  }



return temp;	
}

int main() {
char tekst[100];
int broj;
printf ("Unesi neki broj: ");
scanf ("%d", &broj);
printf ("Unesi tekst: ");
unesi (tekst,100);
printf ("Funkcija: %s", ubaci_broj(tekst,broj));



	return 0;
}
