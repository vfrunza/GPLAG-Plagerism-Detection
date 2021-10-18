#include <stdio.h>

char *kodiraj(char *s, char *q)
{
    char *p,*r;
    int i,j,pom;
    char pom2;
    char slova[95];
    char brojaci[95]; /*Smjestamo zadane vrijednosti u niz*/
    for(i=0; i<95; i++) {
        slova[i]=32+i;
        brojaci[i]=0;

    }
    p=s;
    while(*p!='\0') {
        if(*p>=32 && *p<=126) {
            brojaci[*p-32]++;
        }
        p++;
    }
    for(i=0; i<95; i++) {
        for(j=i; j<95; j++) {
            if(brojaci[j]>brojaci[i] || (brojaci[j]==brojaci[i] && slova[j]<slova[i])) {
                pom=brojaci[i];
                brojaci[i]=brojaci[j];
                brojaci[j]=pom;
                pom2=slova[i];
                slova[i]=slova[j];
                slova[j]=pom2;
            }
        }
    }
    i=0;
    r=q; /*Smjestamo ascii vrijednosti u sifru ovisno o frekvenciji pa sifriramo tekst*/
    for(i=0;i<95;i++){
        r[i]=slova[i];
    }
    r[i]='\0';
    p=s;
    while(*p!='\0') {
        for(i=0; i<95; i++) {
            if(*p==slova[i]) break;

        }
        *p=126-i;
        p++;
    }
    return s;
}

char *dekodiraj(char*s, char *q) /*Dekodiramo tekst tako sto vrsimo postupak suprotan sifriranju*/
{
    char*p=s;
    int i;
    int duzina=0;
    while(*p!='\0') {
        duzina++;
        p++;

    }
    p=s;
    for(i=0; i<duzina; i++) {
        p[i]=q[126-p[i]];
    }
    return s;
}

int main()
{
    return 0;
}
