/*Napisati funkciju provjeri_duzine koja prima neki string koji predstavlja rečenicu i niz cijelih brojeva. Funkcija
treba provjeriti da li niz predstavlja niz dužina riječi u rečenici, te vraća 1 ako je uslov ispunjen a 0 ako nije.
Riječ se definiše kao neprekinut niz velikih i malih slova tako da se npr. string "Auto-Stop" smatra za dvije riječi.

Primjer: ako string glasi:
Ovo je neki primjer teksta

Onda bi niz brojeva morao glasiti: 3, 2, 4, 7, 6 jer su to dužine riječi u ovoj rečenici.

U programu je zabranjeno koristiti funkcije iz biblioteka string.h i stdlib.h, te funkcije sprintf i sscanf iz biblioteke
stdio.h. Također je strogo zabranjeno kreirati pomoćni niz/string u funkciji!
*/

#include <stdio.h>
#define maxBrojRijeci 1000

int slovo(char znak)
{
    if((znak>= 'a' && znak <= 'z') || (znak>='A' && znak<='Z')) return 1;
    return 0;
}

int broj (char znak)
{
    if (znak>='0' && znak<='9') return 1;
    return 0;
}

int delimiter (char  znak)
{
    if (slovo(znak)==0 && broj(znak)==0) return 1;
    return 0;
}

int brojrijeci(char *s){
    
    int istina=0;
    int rijeci=0;
    
    while (*s!='\0'){
        if (*s==' ' || *s=='\n' || *s=='\t'){
        if (istina==0)
        rijeci++;
        istina=1;
        }
        if (*s!=' ' && *s!='\n' && *s!='\t'){
            istina=0;
        }
        s++;
    }
   
    if(istina==0)           /*Ispitujemo zadnju rijec*/
    rijeci++;
    
    
    return rijeci;
}

int provjeri_duzine( char *s, int niz[], int vel)
{
    int i;
    int brojRijeci;
    int pocetak=0;

    if(vel<1) return 0;
    if (vel>maxBrojRijeci) return -1;

    brojRijeci=brojrijeci(s);

    if(vel !=brojRijeci) return 0;
    s=s-pocetak; /*vracamo se na pocetak*/

    i=0;

    while (*s!='\0') {
        int duzina=0;
        while (broj(*s)==0 || slovo(*s)==0 || *s!='\0') {
            if (delimiter(*s)) break;
            s++;
            duzina++;
        }
        if (duzina!=niz[i++]) return 0;
        s++;
        if (i==vel) break;

    }


    return 1;
}




int main()
{

    return 0;
}