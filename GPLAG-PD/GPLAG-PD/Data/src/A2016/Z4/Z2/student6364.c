#include <stdio.h>
char *kodiraj (char *string, char *sifrarnik)
{
    char* p = string;
    char* q = string;
    char* kraj = string;
    char* pomocni = sifrarnik;
    int nizBrojac[150] = {0}, k = 0, i;
    int max = -1, x = 0;
    while (*p != '\0')
    {
        nizBrojac[*p++]++;              /* nizom brojača brojim koliko ima kojih znakova */
    }
  while ( k < 95)                       /* traženje najčešćeg */
  {
      for (i = 32; i < 127; i++)
      {
          if (nizBrojac[i] > max) 
          {
            max = nizBrojac[i];
            x = i;
          }
      }
      *sifrarnik = x;
      sifrarnik++; 
      nizBrojac[x] = -1;            /* kad ga nađemo postavljamo ga na -1 da nam se ne pojavljuje kao najčešći u idućem traženju */
      max = -1;
      k++;
  }
  *sifrarnik = '\0';
  while (*q != '\0')        /* kodiranje stringa */
  {
      for (i = 32; i < 127; i++)
      {
          if (*q == pomocni[i-32]) 
          {
              *q = 126 - (i-32);
              break;
          }
      }
      q++;
  } 
  return kraj;
}
char *dekodiraj (char *string, char *sifrarnik)
{
    char* q = string;
    int i;
    while (*string != '\0')
    {
       i = 126 - *string;
       *string = sifrarnik[i];
       string++;
    }
    return q;
}

int main() {
char tekst[] = "LLMLNLNMONM";
char sifrarnik[150] = "";
int i;
char* p = kodiraj(tekst, sifrarnik);
while (*p != '\0') 
    printf("%c", *p++);

	return 0;
}
