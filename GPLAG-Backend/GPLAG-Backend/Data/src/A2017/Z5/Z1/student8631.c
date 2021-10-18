#include <stdio.h>
NE RADI

struct Datum {
    int dan, mjesec, godina;
};

struct Uposlenik {
    char ime_prezime[50];
    struct Datum datum_rodjenja;
};

int postavi_datum(int dan, int mjesec, int godina)
{

    int broj_dana[12]= {31, 28, 31, 30,31,30,31,31,30, 31, 30, 31};
    if(godina%4==0 && godina%100!=0 || godina%400==0)
        broj_dana[1]++;
    int dani=0;
    dani+=dan;
    int i=0;
    for(i=0; i<mjesec; i++)  dani+=broj_dana[i];
    for(i=1; i<godina; i++)
        if(i %4==0 && i%100!=0 || i%400==0) dani+=366;
        else dani+=365;
    return dani;
    /*while(broj_dana[mjesec-1]<dan ) {mjesec++;
     dan=dan-broj_dana[mjesec-2];
     if(mjesec > 12  ) {godina++;  mjesec-=12;
     if(broj_dana[1]==29) broj_dana[1]--;
     if(godina%4==0 && godina%100!=0 || godina%400==0)
     broj_dana[1]++;
     }
     }
     if(godina<1 || mjesec<1 || mjesec>12 ||dan<1 || dan>broj_dana[mjesec-1])
     d.dan=dan;
     d.mjesec=mjesec;
     d.godina=godina;
     return d;*/
}

int uporedi_prezimena(char *prez1, char *prez2)
{
    char *pom1=prez1;
    char *pom2=prez2;
    char *p, *q;
    while (*pom1) {
        if(*pom1==' ') p=pom1;
        pom1++;
    }
    while (*pom2) {
        if(*pom2==' ') q=pom2;
        pom2++;
    }
    int prvo_isto=1;
    p++;
    q++;
    char *prvo_slovo=p;
    char *prvo_slovo_drugog=q;
    while (*p!='\0' && *p!='-') {
        if(*q!=*p) prvo_isto=0;
        p++;
        q++;
        if(*q=='\0' || *q=='-') break;
    }
    if(prvo_isto==1 && (*q=='-' || *q=='\0') && (*p=='-' || *p=='\0'))
        return 1;
    if(*q=='-') {
        q++;
        prvo_isto=1;
        p=prvo_slovo;
        while (*p!='\0' && *p!='-') {
            if(*q!=*p) prvo_isto=0;
            p++;
            q++;
            if(*q=='\0') break;
        }
        if(prvo_isto==1 && (*q=='\0') &&(*p=='-' || *p=='\0'))
            return 1;
    }
    if(*p=='\0') return 0;// ako nemma drugog prezimena
    p++;
    prvo_slovo=p;  //prvo slovo drugog prezimena
    q=prvo_slovo_drugog;
    prvo_isto=1;
    while (*p!='\0') {
        if(*q!=*p) prvo_isto=0;
        p++;
        q++;
        if(*q=='\0' || *q=='-') break;
    }
    if(prvo_isto==1 && (*q=='-' || *q=='\0') && (*p=='\0'))
        return 1;
    if(*q=='-') {
        q++;
        prvo_isto=1;
        p=prvo_slovo;
        while (*p!='\0') {
            if(*q!=*p) prvo_isto=0;
            p++;
            q++;
            if(*q=='\0') break;
        }
        if(prvo_isto==1 && *q=='\0' && *p=='\0')
            return 1;
    }
    return 0;
}

/*
int pret=1;
while (*p!='\0') {
     if((*p>='A' && *p<='Z') || (*p>='a' && *p<='z'))
      pt=p;
while ((*p>='A' && *p<='Z') || (*p>='a' && *p<='z'))
p++;
if(*p==' ' || *p=='\0'){
    kt=p;
}
if(*kt+1=='-') pm=pt; km=kt;
kt++;
while (*kt!='\0') { kt++; }
pt=kt+2;
}
// ako se pojavljaje prezime direkora izmedju pokazivaa pt i kt ili pm i km
while (kt>pt) {
 if(*pt++!=*pom++) pret=0;
}
pomocni=pom;
while (km>pm) {
 if(*pm++!=*pomocni++) pret=0;
}

if(pret) return 1;
return 0;
*/


int suzi_listu(struct Uposlenik * kandidati, int vel, struct Uposlenik direktor, int broj_dana)
{
    int i, j, pret;
    int dir, uposl;
    struct Datum d;
    if(broj_dana<0) broj_dana*=-1;
    for(i=0; i<vel; i++) {
        dir=postavi_datum(direktor.datum_rodjenja.dan, direktor.datum_rodjenja.mjesec, direktor.datum_rodjenja.godina);
        uposl=postavi_datum(kandidati[i].datum_rodjenja.dan, kandidati[i].datum_rodjenja.mjesec, kandidati[i].datum_rodjenja.godina);
        pret=0;
        if(uporedi_prezimena(kandidati[i].ime_prezime, direktor.ime_prezime) && (uposl-dir)<broj_dana)
            pret=1;
        if(pret==0) {
            for(j=i; j<vel-1; j++)
                kandidati[j]=kandidati[j+1];
            i--;
            vel--;
        }
    }
    if(pret==1) return vel;
//if(pret) return 1;
    return vel;
}

int main()
{
    //struct Datum d={32, 12, 1980};
    // struct Datum d1=Postavi_datum(d.dan, d.mjesec, d.godina);
    //printf(" %d, %d, %d", d1.dan, d1.mjesec,  d1.godina);
    printf("Zadaća 5, Zadatak 1");
    return 0;
}
