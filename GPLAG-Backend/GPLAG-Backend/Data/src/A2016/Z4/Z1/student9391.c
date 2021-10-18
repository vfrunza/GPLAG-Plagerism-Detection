#include <stdio.h>
#include <ctype.h>

int dajBrojPonavljanjaRijeci (char* s, char* r) {
    int brojac=0, daLiPokazujeNaKraj=0;
    while (*s!='0') {
        char* p1=r;
        while(!isalpha(*s)) {
            if(*s=='\0') return brojac;
            s++;
        }
         while (isalpha(*p1) && (*p1==*s || *p1==*s+32 || *p1==*s-32)) {
             p1++;
             s++;
             if(*s=='\0') {
                 daLiPokazujeNaKraj=1;
                 break;
             }
         }
         if(!isalpha(*p1) && !isalpha(*s)) {
             brojac++;
             if(*s=='\0') return brojac;
         }
         else while(isalpha(*s)) {
             s++;
             if(*s=='\0') daLiPokazujeNaKraj=1;
         }
         if(!daLiPokazujeNaKraj)
            s++;
        else continue;
    }
    return brojac;
}

char* dajNajcescuRijec (char* s) {
    int maxi=0, br_ponavljanja;
    char* najcesca, *p=s, *trenutna;
    while(!isalpha(*s))
        s++;
    while(*s!='\0') {
        while(!isalpha(*s) && *s!='\0')
            s++;
        if(*s!='\0') {
            trenutna=s;
            br_ponavljanja=dajBrojPonavljanjaRijeci(p,trenutna);
            if(maxi<br_ponavljanja) {
                najcesca=trenutna;
                maxi=br_ponavljanja;
            }
            s++;
        }
        else return najcesca;
    }
    return najcesca;
}

int imaLiRijeci (char* s) {
    for(;*s;s++) if(isalpha(*s)) return 1;
    return 0;
}

char* izbaci_najcescu(char* s) {
    char *pocRijeci, *p, *krajRijeci, *pom, *pompr, *adr;
    if(!imaLiRijeci(s)) return s;
    p=s;
    pocRijeci=dajNajcescuRijec(s);
    pom=pocRijeci;
    while(isalpha(*pom))
        pom++;
    krajRijeci=pom;
    s=krajRijeci;
    while(*s!='\0') {
        pompr=pocRijeci;
        while(!isalpha(*s)) {
            if(*s=='\0') break;
            s++;
        }
        if(*s=='\0') break;
        pom=s;
        while(isalpha(*s) && (*pompr==*s || *pompr==*s+32 || *pompr==*s-32)) {
            pompr++;
            s++;
        }
        if(!isalpha(*pompr) && isalpha(*s)) {
            while(isalpha(*s))
                s++;
            continue;
        } 
        else if (isalpha(*pompr) && isalpha(*s)) {
            while (isalpha(*s))
                s++;
            continue;
        }
        else if (isalpha(*pompr) && !isalpha(*s))
            continue;
        else {
            adr=pom;
            while(*s!='\0') {
                *adr=*s;
                adr++;
                s++;
            }
            while(*adr!='\0')
                *adr++='\0';
            adr='\0';
            s=pom;
        }
    }
    if(*krajRijeci=='\0')
        while(*pocRijeci!='\0')
        *pocRijeci++='\0';
    else {
        while (*krajRijeci!='\0') {
            *pocRijeci=*krajRijeci;
            pocRijeci++;
            krajRijeci++;
        }
        *krajRijeci='\0';
        while(*pocRijeci!='\0')
            *pocRijeci++='\0';
    }
    return p;
}

int main() {
	//printf("Zadaća 4, Zadatak 1");
	return 0;
}
