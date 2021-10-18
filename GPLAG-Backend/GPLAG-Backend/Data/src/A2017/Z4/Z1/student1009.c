#include <stdio.h>

char* ubaci_broj(char* tekst, int broj)
{
    int minus,jedan_razmak,p;
    int broj_razmaka=0;
    int temp=broj,duzina_broja=0,temp2,pocetak=0,temp3,duzina_obrnut=0,razlika;
    int obrnut=0;
    char* poc=tekst;
    char* kraj=tekst;
    if(temp<0) temp=-temp;
    do {
        int cifra;
        cifra=temp%10;
        obrnut=obrnut*10+cifra;
        duzina_broja++;
        temp/=10;
    } while(temp>0);
    temp3=obrnut;
    do {
        duzina_obrnut++;
        temp3/=10;
    } while(temp3>0);

    while(*tekst!='\0') {
        if(*tekst!=' ') pocetak=1;
        razlika=duzina_broja-duzina_obrnut;
        temp2=obrnut;
        broj_razmaka=0;
        if(*tekst==' ' && pocetak==1) {
            char* p=tekst;
            minus=0,jedan_razmak=0;
            if(broj<0) minus=1;
            while(*kraj!='\0') kraj++;
            while(*p!='\0') {
                if(*p==' ') {
                    broj_razmaka++;
                    if(*(p+1)=='\0') return poc;
                } else break;
                p++;
            }
            if(broj_razmaka==1) jedan_razmak=1;
            tekst++;
            while(kraj>=tekst) {
                *(kraj+duzina_broja+minus+jedan_razmak)=*kraj;
                kraj--;

            }

            if(minus==1) *tekst++='-';
            do {
                int cifra=temp2%10;
                temp2/=10;
                *tekst++=cifra+'0';
            } while(temp2>0);
            while(razlika>0) {
                *tekst++='0';
                razlika--;
            }
            if(jedan_razmak==1) *tekst++=' ';
            tekst=p+duzina_broja+minus+jedan_razmak;
        }
        tekst++;
    }
    return poc;
}
int main()
{
    return 0;
}
