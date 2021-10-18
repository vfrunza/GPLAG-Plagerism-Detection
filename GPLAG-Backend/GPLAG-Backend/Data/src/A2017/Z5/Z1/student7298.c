#include <stdio.h>
 int main() {
 int c, samoglasnika=0;
 char niz[100];
 char *p=niz,a,*pok;
 FILE* ulaz = fopen("rad_sa_datotekom.txt", "r");
 if (ulaz == NULL) {
 printf("Otvaranje datoteke prva.txt nije uspjelo");
 return 1;
 }
  while (c != EOF)
  {
 c = fgetc(ulaz);
 a=(char)c;
 pok=&a;
 p=pok;
 niz=*p++;
  }
  printf("%s",*p);
 fclose(ulaz);
 return 0;
 }
