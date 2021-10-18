#include <stdio.h>

void najduzi_bp(char *s1, char s2[])
{
    int max=0;
    int i,j,m=0,k=0,duzina=0,brojac=0;
    char znak=*s1;
    char rijec[100];
    char temp[100];
    while(*s1!='\0') {
        /*preskace elemente koji po definiciji ne mogu pripadati rijeci*/
        for(i=0; i<80; i++) {
            if((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z')) break;
            if(*s1=='\0') break;
            s1++;
        }
        /*sljedeci niz char-ova predstavlja rijec*/
        for(i=0; i<80; i++) {
            if(*s1<'A' || (*s1>'Z' && *s1<'a') || *s1>'z') break;
            rijec[i]=*s1;
            s1++;
        }
        rijec[i]='\0';
        duzina=i; /*duzina rijeci*/
        m=0;
        /*analiziranje posmatrane rijeci*/
        while(duzina>0) {
            brojac=0;
            for(k=0; k<duzina; k++) {
                int br=0;
                znak=rijec[k+m];/*izdvojimo jedno slovo rijeci i poredimo s prethodnim slovima*/
                brojac++;
                if(znak>='A' && znak<='Z') {
                    for(i=0; i<brojac-1; i++) {
                        if(rijec[i+m]!=znak && rijec[i+m]!=(znak+32)) br++;
                    }
                }
                if(znak>='a' && znak<='z') {
                    for(i=0; i<brojac-1; i++) {
                        if(rijec[i+m]!=znak && rijec[i+m]!=(znak-32)) br++;
                    }
                }
                /*ukoliko je posmatrano slovo razlicito od svih prethodnika, dodajemo ga u trenutni string*/
                if(br==brojac-1) {
                    temp[k]=znak;
                } else break;
            }
            /*poredimo duzinu pronadjenog podstringa i duzinu najduzeg dosadasnjeg podstringa*/
            if(k>max) {
                max=k;
                /*najduzi podstring je sada prethodni trenutni string, jer mu je duzina veca nego kod dosadasnjeg najduzeg podstringa*/
                for(j=0; j<max; j++) {
                    s2[j]=temp[j];
                }
                /*obiljezavamo kraj najduzeg podstringa*/
                s2[j]='\0';
            }
            m++;
            duzina--; /*smanjivanje duzine rijeci, da bi mogli posmatrati neki dio rijeci*/
        }
    }
}
int main(void)
{
    return 0;
}