#include <stdio.h>

int provjeristring(char *s)
{
    // provjeravamo string onako kako je zadan u postavci, ako ne zadovoljava jedan od uslova vracamo 0

    while(*s!='\0') {
        if(*s++!='(') return 0;

        // u ovom dijelu provjerava koordinate 'x' tacke
        if(*s=='-') s++;
        if(*s>=48 && *s<=57) { // gleda da li se nalazi broj ispred .32 npr
            while(*s>=48 && *s<=57) s++; // sve dok su brojevi povecaj vrijednost
        } else return 0; // ako nije broj return 0;
        if(*s=='.') { // ako ima tacku, poslije tacke povecava sve dok su brojevi
            s++;
            while(*s>=48 && *s<=57) s++;
        }

        if(*s++!=',') return 0;

        // u ovom dijelu provjerava koordinate 'y' tacke
        if(*s=='-') s++;
        if(*s>=48 && *s<=57) { // gleda da li se nalazi broj ispred .32 npr
            while(*s>=48 && *s<=57) s++; // sve dok su brojevi povecaj vrijednost
        } else return 0; // ako nije broj return 0;
        if(*s=='.') { // ako ima tacku, poslije tacke povecava sve dok su brojevi
            s++;
            while(*s>=48 && *s<=57) s++;
        }

        if(*s++!=')') return 0;

        if(*s!=',') {
            if(*s!='\0') return 0; // ukoliko se nalazi nešto poslije , da nije zagrada
            else break; // ukoliko je '\0' samo breakamo i zavrsili smo sa pretragom
        }
        ++s;
        if(*s=='\0') return 0; // dodatni uslov ukoliko imamo poslije zagrade , a poslije '\0'
    }

    return 1; // u protivnom vracamo 1
}


void izbaci(char *s, char *poc)
{
    char *pomocni=s+2; // dodajemo +2 da bi preskocio ')' i ',' i pokazuje na narednu par x i y
    while(*pomocni!='\0') { // citavu koordinatu prekopiramo i terminiramo na kraju
        *poc=*pomocni;
        poc++;
        pomocni++;
    }
    *poc='\0';
}

int nijeslovo(char s)
{
    if(!(s>=48 && s<=57)) return 1;
    else return 0;

}

int pretvoriubroj(char s)
{
    return s-48;
}



char *obuhvat(char *tekst, double x1, double y1, double x2, double y2)
{
    if(provjeristring(tekst)==0) return 0;

    char *s = tekst;
    double x=0, y=0, dec;
    while(*s!='\0') {
        int imadec=0, predznak=1;

        char *poc = tekst;
        if(*s!='(') s++; // povecavamo string sve do '('
        if(*s=='(') poc = s; // kad dodjemo do '(' zapamtimo to mjesto i povecavamo za 1
        s++;

        x=0;
        dec=0.1;
        imadec=0;
        predznak=1;

        while(*s!=',') { // trazimo x koordinatu
            int  nijesl=0;

            if(nijeslovo(*s)) { // gledamo da li trenutni karakter nije broj

                nijesl=1;
                if(*s=='-') predznak=-1;
                if(*s=='.') imadec=1;

            }
            if(nijesl==1) s++;
            if(*s==',') break; // ukoliko dodje do , da break-a petlju (spec 2. primjer)


            int cifra = pretvoriubroj(*s);

            if(imadec==0) {

                x=x*10 + cifra;
            }
            if(imadec==1) {

                x=x+cifra*dec;
                dec/=10;
            }
            s++;
        }

        x*=predznak;
        s++; //preskace zarez

        y=0;
        imadec=0;
        predznak=1;
        dec=0.1;

        while(*s!=')') {
            int  nijes=0;

            if(nijeslovo(*s)) {

                nijes=1;
                if(*s=='-') predznak=-1;
                if(*s=='.') imadec=1;

            }
            if(nijes==1) s++;
            if(*s==')') break; // ako se s poveca i pokazuje na ')' moramo breakat (spec. 2. primjer)

            int cifra = pretvoriubroj(*s);

            if(imadec==0) {

                y=y*10 + cifra;
            }
            if(imadec==1) {

                y=y+cifra*dec;
                dec/=10;
            }
            s++;

        }
        y*=predznak;

        char *a = poc; // pokazuje na '('
        int izbaci1=0;
        if(y>y2 || y<y1 || x<x1 || x>x2) { // gleda da li se nalazi u kvadratu
            izbaci1=1;
            if(poc==tekst && *(s+1)=='\0') { // specijalno ukoliko je pocetak teksta tj. '(' i *(s+1)=='\0' tj. ako trebamo izbaciti jednu koordinatu
                *tekst='\0';
                return tekst;
            }

            if(*(s+1)=='\0') { // specijalno opet ako se treba zadnja koordinata izbaciti stavljamo pokazivac na poc-1 i tu terminiramo
                *(poc-1)='\0';
                return tekst;
            } else {
                izbaci(s, poc); // u protivnom normalno izbacivanje
            }

        }

        if(izbaci1==1) {
            s=a; // ukoliko se desi izbacivanje moramo gledati tu rijec koja se kopirala na mjesto bivse
            // i onda gledati da li se ona nalazi u kvadratu
        } else s++;
    }

    return tekst;
}


int main()
{
    char s[]="(2.,2),(100,100),(100,100)";
    printf("tekst - %s\n", s);
    char *rez = obuhvat(s,-3,-3,3,3);
    printf("novi - %s", rez);
    return 0;
}
