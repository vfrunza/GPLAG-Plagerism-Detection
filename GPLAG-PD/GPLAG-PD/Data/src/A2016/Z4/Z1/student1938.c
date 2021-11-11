#include <stdio.h>

char toupper1(char a);
int koliko_pon(char *rijec, char *tekst);
int jel_jedanka(char *rijec1, char *rijec2);
int jel_dobra(char s) {
    return ((s>='a' && s<='z' ) || (s <= 'Z' && s >='A'));

}
char *previous_word (char *s, char *poc) {
    char *pocetni =s;
    if(poc == pocetni)return poc;
    else if(jel_dobra(*pocetni)) {
        while(jel_dobra(*pocetni)) {
            if(pocetni==poc)break;
            pocetni--;
        }
        while(!jel_dobra(*pocetni)) {
            if(pocetni==poc)break;
            pocetni--;
        }
        while(jel_dobra(*pocetni)) {
            if(pocetni==poc)break;
            pocetni--;
        }
        if(!(pocetni==poc))pocetni++;
    } else {
        while(!jel_dobra(*pocetni)) {
            if(pocetni==poc)break;
            pocetni--;
        }
        while(jel_dobra(*pocetni)) {
            if(pocetni==poc)break;
            pocetni--;
        }
        if(!(pocetni==poc))pocetni++;
    }
    return pocetni;
}
char *izbaci_najcescu(char* s) {
    int l=0;
    char *poc=s;
    int max_pon = 0;
    int t_pon;
    char *zizbacit = s, *zizbacit_poc;
    while(*s!='\0') {
        while(!jel_dobra(*s)) {
            if(*s=='\0')break;
            s++;
        }
        t_pon = koliko_pon(s,poc);
        if(t_pon>max_pon) {
            zizbacit_poc=s;
            max_pon=t_pon;
            l=0;
        }
        if(l==0)
            while(jel_dobra(*s)) {
                zizbacit=s;
                s++;
                l++;
            }
        else while(jel_dobra(*s))s++;
    }
    while(max_pon--) {
        while(!jel_dobra(*s)) {
            if(s==poc)break;
            s--;
        }
        while(jel_dobra(*s)) {
            if(s==poc)break;
            s--;
        }
        s++;
        while(!jel_jedanka(s,zizbacit_poc)) {
            s=previous_word(s,poc);
            if(s==poc)break;

        }
        if(s==poc){while(!jel_dobra(*s))s++;}
        while(jel_dobra(*s))s++;
        while(*s!='\0') {
            if(!((s-l)<poc))
            *(s-l) = *s;
            if(*s=='\0')break;
            s++;
        }
        *(s-l)='\0';
    }
    return poc;
}

int main() {

    char t[]="1PsT1 psT2 3Pst pstpst pst";
    printf("'%s'", izbaci_najcescu(t));
    return 0;
}

char toupper1(char a) {

    if(a<='z' && a>='a')return a-32;
    return a;
}
int koliko_pon(char *rijec, char *tekst) {
    int br=0;
    while(*tekst!='\0') {
        if(jel_dobra(*tekst)) {
            if(jel_jedanka(rijec,tekst))br++;
            while(jel_dobra(*tekst)) {
                tekst++;
                if(*tekst=='\0')break;
            }

        }
        if(*tekst=='\0')break;
        tekst++;

    }
    return br;
}
int jel_jedanka(char *rijec1, char *rijec2) {
    int duzina1=0,duzina2=0,jes=1;
    char *poc1=rijec1;
    char *poc2=rijec2;
    char a,b;
    while(jel_dobra(*rijec1)) {
        duzina1++;
        if(rijec1=='\0')break;
        rijec1++;
    }
    rijec1=poc1;
    while(jel_dobra(*rijec2)) {
        duzina2++;
        if(rijec2=='\0')break;
        rijec2++;
    }
    rijec2=poc2;
    if(duzina1==duzina2) {
        while(--duzina1) {
            a=toupper1(*rijec1);
            b=toupper1(*rijec2);
            if(a!=b) {
                jes=0;
                break;
            }
            rijec1++;
            rijec2++;
        }
    } else jes = 0;
    return jes;
}