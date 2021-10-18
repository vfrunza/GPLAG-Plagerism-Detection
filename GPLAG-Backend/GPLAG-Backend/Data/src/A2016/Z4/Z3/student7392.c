#include <stdio.h>

/* PROVJERAVA DA LI SU RIJECI ISTE */

int iste(char *rijec1, char *rijec2, int duzina){
    int i;
    for(i=0;i<duzina;i++){
        if(rijec2[i]=='\0')return 0;
        if(rijec1[i]!=rijec2[i])return 0;
    }
    if(rijec2[i]=='\0')return 1;
    return 0;
}

/* PROVJERAVA RIJECI TE IH MIJENJA AKO JE POTREBNO I VRACA POINTER NA PRVI KARAKTER TESKTA */

char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci){
    char *pocetak=tekst;
    char *temp=tekst;
    char *p=tekst;
    int duzina=0;
    int i, j;
    int duzinaZamjene=0;
    char a[1999000];
    int pozicija=0;
    /* ITERACIJA KROZ TEKST I PROVJERA USLOVA */
    while(*tekst){
        if(*tekst==' '){
            if(duzina!=0){
                for(i=0;i<broj_rijeci;i++){
                    if(iste(temp, rijeci[i], duzina)){
                        
                        p=zamjene[i];
                        duzinaZamjene=0;
                        while(*p){
                            a[pozicija+duzinaZamjene]=*p;
                            p++;
                            duzinaZamjene++;
                        }
                        pozicija=pozicija+duzinaZamjene;
                        a[pozicija]=' ';
                        pozicija++;
                        break;
                    }
                }
                if(i==broj_rijeci){
                    for(j=0;j<duzina;j++){
                        a[pozicija+j]=temp[j];
                    }
                    pozicija=pozicija+duzina;
                    a[pozicija]=' ';
                    pozicija++;
                }
            } else {
                a[pozicija]=*tekst;
                pozicija++;
            }
            duzina=0;
        } else {
            if(duzina==0){
                temp=tekst;
                duzina=1;
            } else duzina++;
        }
        tekst++;
    }
    if(duzina!=0){
        for(i=0;i<broj_rijeci;i++){
            if(iste(temp, rijeci[i], duzina)){
                p=zamjene[i];
                duzinaZamjene=0;
                while(*p){
                    a[pozicija+duzinaZamjene]=*p;
                    p++;
                    duzinaZamjene++;
                }
                pozicija=pozicija+duzinaZamjene;
                a[pozicija]='\0';
                pozicija++;
                break;
            }
        }
        if(i==broj_rijeci){
            for(j=0;j<duzina;j++){
                a[pozicija+j]=temp[j];
            }
            pozicija=pozicija+duzina;
            a[pozicija]='\0';
            pozicija++;
        }
    } else {
        a[pozicija]=*tekst;
        pozicija++;
    }
    for(i=0;i<pozicija;i++){
        pocetak[i]=a[i];
    }
    return pocetak;
}

int main() {
    char* rijeci[2] = { "p", "1111" };
	char* zamjene[2] = { "aaaa", "e" };
	char tekst[6] = "p 1111";
    printf("'%s'", zamjena_rijeci(tekst, rijeci, zamjene, 2));
	return 0;
}
