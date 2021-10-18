#include <stdio.h>

int main() {
	printf("Zadaća 5, Zadatak 4");
	return 0;
}

//Npr. ako niz glasi: 15, 30, 29, 1, 8342, 999 funkcija treba vratiti broj 2 jer članovi 999 i 1 zadovoljavaju uslov zadatka, a ostali ne.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define duzina 50
int funkcija (int* p, int velicina)
{
 int privremenaCifra;
 int isteCifre = 0;
 int i;
 int flag;
 /*Petlja kojom prolazimo kroz elemente niza*/
 for (i = 0; i < velicina; i++)
 {
flag = 0; /*pretpostavljamo da su kod
naseg elementa niza sve cifre jednake*/
 int temp = *(p+i); /*Privremena varijabla
koja uzima vrijednosti brojeva iz niza, i njome
manipulišemo*/
 if(temp < 0)
temp = -temp; /*Provjeravamo je li
nas broj negativan, ako jeste mijenjamo ga
u pozitivan da manipulisemo sa njim*/
privremenaCifra = temp % 10; /*Privre
mena cifra je prva cifra slijeva, s njom
poredimo*/
temp/=10;
 /*Petlja kojom prolazimo kroz cifre
svakog elementa*/
 while (temp > 0)
 {
 if (privremenaCifra != temp%10) /*Ako
se bilo koja od sljedecih cifara razlikuje od
privremene, stavi flag na 1!*/
 {
flag = 1;
 break;
 }
temp/=10;
 }
 /*Na kraju ispitujemo vrijednost flag, i
ako se ona nije promijenila, broj ima iste
cifre*/
 if (flag == 0)
isteCifre++;
 }
 return isteCifre;
}
int main ()
{
 /*Otvaranje datoteke*/
FILE* ulaz = fopen("mjerenja.txt", "r");
 int niz[duzina];
 char c;
 /*Provjera otvaranja*/
 if (ulaz == NULL)
 {
 printf("Datoteka ne može biti učitana.");
 exit(1);
 }
 /*Pohranjivanje elemenata datoteke u niz
intova*/
 int i = 0;
 do
 {
 fscanf(ulaz,"%i", &niz[i++]);
 } while ((c=fgetc(ulaz))!=EOF && i < duzina);
 fclose(ulaz);
 /*Otvaranje datoteke za ispis*/
FILE* izlaz = fopen("statistika.txt", "w");
 /*Poziv funkcije koja ispituje elemente cije
su cifre u opadajucem redoslijedu*/
 int rezultat = funkcija(niz,i);
 /*Ispis rezultata u datoteku statistika.txt*/
 fprintf(izlaz, "%i", rezultat);
 fclose(izlaz);
 return 0;
}

 int temp = *(p+i); /*Privremena varijabla
koja uzima vrijednosti brojeva iz niza, i njome
manipulišemo*/
 if(temp < 0) /*Provjeravamo je li nas
broj negativan, ako jeste mijenjamo ga u
pozitivan da manipulisemo sa njim*/
temp = -temp;
prethodnaCifra = temp % 10; /*Uzmemo
posljednju cifru broja*/
temp/=10;
 /*Petlja kojom prolazimo kroz cifre
svakog elementa*/
 while (temp > 0)
 {
 /*Posto uporedjujem cifre od zadnje
prema prvoj,
redoslijed mora biti opadajuci. prvu
cifru stavimo na prethodnu,
pa ispitujemo za svaku sljedecu jel
manja! */
 if (prethodnaCifra > temp%10)
 {
prethodnaCifra = temp %10;
temp/=10;
 }
 else /*Prvi put kad naidjemo da nije
zadovoljen uslov iznad, postavilo flag na 1 i
izlazimo iz petlje*/
 {
flag = 1;
 break;
 }
 }
 /*Ako nismo prosli nijednom kroz else,
znaci da su cifre broja u rastucem redoslijedu*/
 if (flag == 0)
brojRastucih++;
 }
 return brojRastuc