#include <stdio.h>
#include <math.h>

void unesi (char niz[], int velicina) {
    char znak= getchar();
    if (znak == '\n') znak = getchar ();
    int i = 0;
    while (i < velicina - 1  && znak != '\n') {
        niz[i]=znak;
        i++;
        znak = getchar ();
    }
    niz[i] = '\0';
}


char* ubaci_broj (char* tekst, int broj) {
    char*p=tekst, *p2=tekst, *zamjena=p, *p3=p;
    int predznak=1, temp=broj, brcfr=1+(int)log10(fabs(broj)), dokle=0, ima_razmak=0, umetni_broj=0;
    if (broj < 0 ) predznak = -1;
    
    while (*p != '\0') {
        if (((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')) &&  *(p+1)==' ' && *(p+1)!='\0') {
            p2=p;
           umetni_broj=0;  
            ima_razmak=0;
            if (umetni_broj==0) { 
            while (*p2!='\0') {
                if ((*p2>='A' && *p2<='Z') || (*p2>='a' && *p2<='z'))   { umetni_broj=1; p2++; } }
            dokle=brcfr;
            while (dokle>0) {
                p2++;
                dokle--;
            }
            if (predznak==-1) p2++;
            zamjena=p;
            while ((*zamjena>='A' && *zamjena<='Z') || (*zamjena>='a' && *zamjena<='z')) zamjena++;
            zamjena++;
            if ((*zamjena>='A' && *zamjena<='Z') || (*zamjena>='a' && *zamjena<='z')) {
                p2++;
                ima_razmak=1;
            }
            while (*zamjena!='\0') zamjena++;
            while (zamjena!=p) {
                *p2=*zamjena;
                p2--;
                zamjena--;
            }
            zamjena=p;
            zamjena++;
            *zamjena=' ';
         /*   zamjena++;  */
            if (predznak==-1) {zamjena++;  *zamjena='-'; } 
            zamjena+=brcfr;
            if (ima_razmak) {
                zamjena++;
                *zamjena=' ';
                zamjena--;
            }
            temp=broj*predznak;
            while (temp!=0) {
                *zamjena='0' + temp%10;
                zamjena--;
                temp/=10;
            }
        }
        p++;
    }
    return tekst;
} }

int main () {
    char recenica[1000];
    int broj;
    
    printf ("Unesite recenicu: ");
    unesi (recenica,1000);
    printf ("Unesite neki broj: ");
    scanf ("%d", &broj);
    ubaci_broj (recenica, broj);
    printf ("%s", recenica);
    return 0;
}