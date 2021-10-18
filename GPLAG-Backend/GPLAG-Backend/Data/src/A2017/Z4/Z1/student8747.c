#include <stdio.h>
#include <math.h>
#include <ctype.h>

int PrebrojRijeci(char* s)
{
    char Temp=' ';
    int BrojRijeci=0;
    while(*s) {
        if(isspace(Temp) && !isspace(*s)) {
            BrojRijeci++;
        }
        Temp=*s++;
    }
    return BrojRijeci;
}

void SrediRazmake(char* s)
{
    char* q=s;
    char* p=s;
    int Razmak=0;
    while(*q!=0) {
        if(*q!=' ') {
            break;
        }
        q++;
    }
    while(*q!='\0') {
        if(*q==' ' && *(q+1)==' ' && *(q+2)!=' ' ) {
            Razmak++;
            p=q+1;
            while(*(p+1)!='\0') {
                *p=*(p+1);
                p++;
            }
        }
        q++;
        if(*q=='\0' && Razmak==0) {
            return;
        }
    }
    q=s;
    while(*q!='\0') {
        q++;
    }
    if(*(q-Razmak+1)==*(q-Razmak) && *(q-Razmak)!=' ' && Razmak!=0) {
        *(q-Razmak)='\0';
    } else {
        *(q-Razmak+1)='\0';
    }
}

char* ubaci_broj (char* tekst, int broj)
{
    char* p=tekst;
    int SigurnosniBroj=0;
    int x=fabs(broj);
    int Clanovi=0;
    int BrojacClanova=1;
    int BrojRijeci;
    SrediRazmake(tekst);
    BrojRijeci=PrebrojRijeci(p);
    if (BrojRijeci==0) {
        return tekst;
    }
    Clanovi=fabs(broj);
    if(broj<0) {
        BrojacClanova=2;
    }
    while(Clanovi!=0 || Clanovi!=-0) {
        Clanovi=Clanovi/10;
        BrojacClanova++;
    }
    SigurnosniBroj=BrojacClanova;
    char* r=tekst;
    while(*r!='\0') {
        r++;
    }
    int Rbrojac=0;
    while(*r==' ') {
        r--;
        Rbrojac++;
    }
    r=r+Rbrojac;
    while(*p!='\0' && BrojRijeci-1!=0) {
        x=fabs(broj);
        char*q =tekst;
        BrojacClanova=SigurnosniBroj;
        if(*p!=' ' && *(p+1)==' ' && *p!=(x%10)+48 ) {
            while(*q!='\0') {
                q++;
            }
            while(q>p) {
                *(q+BrojacClanova)=*q;
                q--;
            }
            while((BrojacClanova)!=0) {
                if(BrojacClanova==1 && broj<0) {
                    *(p+BrojacClanova+1)='-';
                } else if(BrojacClanova!=SigurnosniBroj) {
                    if (broj<0) {
                        *(p+BrojacClanova+1)=(x%10)+48;
                    }
                    if(broj>0 ) {
                        *(p+BrojacClanova+1)=(x%10)+48;
                    }
                    x=x/10;
                }
                BrojacClanova--;
            }
            BrojRijeci--;

        }
        p++;
    }

    return tekst;
}

int main()
{
    char s[12] = "hello.world";
    char s2[4] = "Sajam glupih mornara ";
    printf("\"%s\"\n", ubaci_broj(s, 263745));
    printf("\"%s\"", ubaci_broj(s2, 2734));
    return 0;
}