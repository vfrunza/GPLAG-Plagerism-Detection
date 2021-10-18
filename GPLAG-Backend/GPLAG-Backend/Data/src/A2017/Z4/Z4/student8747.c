#include <stdio.h>
#include <string.h>

char* Skrati(char* PocetakStringa, char* Pocetak, char* Kraj)
{
    char* p=Pocetak;
    char* q=Kraj;
    while(*q!='\0') {
        *p=*q;
        q++;
        p++;
    }
    *p=*q;
    return PocetakStringa;
}
int provjeri(char* tekst)
{
    char* Prebaci=tekst;
    char s[10000];
    char* Prebaci2=s;
    int Prebacivanje=0;
    while(*Prebaci!='\0') {
        if(*Prebaci==' ' && *(Prebaci+1)!='<' && *(Prebaci+1)!='>' && *(Prebaci-1)!='<' && *(Prebaci-1)!='>') {
            *Prebaci2='>';
            Prebaci2++;
            while(*Prebaci!='<') {
                if(*Prebaci=='\0') {
                    break;
                }
                Prebaci++;
            }
        }
        *Prebaci2=*Prebaci;
        Prebaci2++;
        Prebaci++;
    }
    *Prebaci2='\0';
    char*q =s;
    int Vise=0;
    int Manje=0;
    while(*q!='\0') {
        if(*q=='<') {
            Manje++;
        }
        if(*q=='>') {
            Vise++;
        }
        q++;
    }
    q=s;
    if(Manje%2!=0) {
        return 0;
    }
    int Ponavljanje=Manje/2;
    while(Ponavljanje!=0) {
        char Tag[200];
        char Tag2[200];
        char *k=Tag2;
        char *r=Tag;
        while(*q!='\0') {
            if(*q=='<') {
                while(*q!='>') {
                    if(*q==' ') {
                        *r=='>';
                        break;
                    }
                    *r=*q;
                    r++;
                    q++;
                }
                *r='>';
                r++;
            }
            *r='\0';
            q++;
        }
        q=s;
        char*t=s;
        char*j=Tag;
        while(*j!='\0' && Prebacivanje==0 ) {
            *t=*j;
            j++;
            t++;
        }
        Prebacivanje++;
        int Duzina=0;
        while(*q!='\0') {
            if(*q=='<' && *(q+1)==47) {
                while(*q!='>') {
                    *k=*q;
                    k++;
                    q++;
                    Duzina++;
                }
                *k='>';
                k++;
                break;
            }
            q++;
            *k='\0';

        }
        char Varijabla[50];
        char* Ubacivanje=Varijabla;
        char* Skratioc=q+1;
        char* PocetakKracenja=q-Duzina-Duzina;
        Ubacivanje=Ubacivanje+Duzina;
        *Ubacivanje='\0';
        Ubacivanje--;
        while(q>Skratioc-Duzina) {
            if(*q==47) {
                q--;
            }
            *Ubacivanje=*q;
            q--;
            Ubacivanje--;
        }
        Ubacivanje++;

        int rezultat=0;
        q=q-Duzina+1;

        while(*q!='<') {
            q--;
        }
        if(*q!='\0') {
            q++;
        }
        if(Duzina>2) {
            Duzina=Duzina-2;
        } else Duzina=1;
        while(Duzina!=0 ) {
            if(*q==*Ubacivanje  || *q==*(Ubacivanje)+32 || *q==*(Ubacivanje)-32) {
                rezultat=1;
            } else {
                rezultat=0;
                break;
            }
            q++;
            Ubacivanje++;
            Duzina--;
        }
        if(rezultat==0) {
            return 0;
        } else {
            if(Ponavljanje==0 && rezultat==1) {
                break;
            }
            Ponavljanje--;
            Skrati(s,PocetakKracenja,Skratioc);
        }
    }
    return 1;
}

int main()
{
    char etfunsaba[] = "<center>"
                       "<a href=\"http://icat.etf.unsa.ba/\">"
                       "<p class=\"tekst\">"
                       "<span class=\"linkovi\">"
                       "XXVI International Conference on Information,"
                       "<br></br>"
                       "Communication and Automation Technologies"
                       "<br></br>"
                       "<br></br>"
                       "<strong>ICAT 2017</strong><br></br>"
                       "<br></br>"
                       "Sarajevo, Bosnia and Herzegovina<br></br>"

                       "</span>"
                       "</p>"
                       "</a>"
                       "</center>";
    printf ("Provjera 1: %d\n", provjeri (etfunsaba));
    etfunsaba[1] = 'z';
    printf ("Provjera 2: %d\n", provjeri (etfunsaba));
    return 0;
}
