#include <stdio.h>
#include <stdlib.h>

int obrnut (int n)
{

    int obr = 0, pom;
    while (n!=0) {
        pom = n%10;
        n/=10;
        obr+=pom;
        obr*=10;
    }
    return obr/10;
}

int duzina (int a)
{

    int povratna = 0;
    while (a) {
        a/=10;
        povratna++;
    }
    return povratna;
}

int rijec(char c)
{
    if ((c >= 'a' && c <= 'z') || (c>='A' && c <='Z')) return 1;
    return 0;
}



char* ubaci_broj (char* s1, int a)
{
    int razmak = 1,broj_rijeci=0;
    char * pocetak, * kraj;
    char* povratna = s1;
    int pomak = duzina(a)+1;
    if (a<0) pomak++;


    char* zadnja = s1;

    int razmak2=1,broj_rijeci2=0;
    while (*zadnja !='\0') {
        if (*zadnja ==' ') razmak2 = 1;
        else if (razmak2==1) {
            broj_rijeci2++;
            razmak2=0;
        }
        zadnja++;
    }


    while (*s1 != '\0') {
        if (*s1==' ') razmak=1;
        else if(razmak==1) {
            razmak = 0;
            broj_rijeci++;
        }

        if (broj_rijeci==broj_rijeci2) break;
        if (*(s1+1)=='\0') break;
        if (*s1 == ' ' && s1!=povratna && rijec(*(s1-1)) && broj_rijeci!=broj_rijeci2) {
            pocetak = s1;
            kraj = s1;
            while (*kraj != '\0') kraj++;
            int opala=0;
            char* razmaci = s1;
            while (*razmaci == ' ') {
                razmaci++;
                opala++;
            }
            
            if (opala>=pomak) pomak = 0;
         
         
            
            
                
            while (kraj > pocetak) {
                *(kraj+pomak)=*kraj;

                kraj--;
            }


            s1++;
            int temp;
            if (a<0) {
                temp = obrnut(a);
                *s1++='-';
                temp*=-1;
            } else  temp = obrnut(a);


            while (temp != 0) {
                *s1++ = temp % 10 + '0';
                temp /= 10;
            }

            if (pomak !=0)*s1++=' ';
            while (*s1==' ') s1++;

        }






        s1++;
    }



    return povratna;
}



int main()
{
    char s[100] = "a sada i primjer koji se zavrsava razmacima       ";
    ubaci_broj(s,321);



    printf ("%s",s);


    return 0;
}
