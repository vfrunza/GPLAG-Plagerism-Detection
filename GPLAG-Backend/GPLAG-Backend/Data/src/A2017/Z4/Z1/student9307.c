#include <stdio.h>

void unesi(char niz[],int velicina)
{
    char znak = getchar();
    if (znak =='\n')
        znak=getchar();
    int i=0;
    while (i<velicina-1 && znak!='\n') {
        niz[i]=znak;
        i++;
        znak=getchar();
    }
    niz[i]='\0';
}

char *ubaci_broj(char *tekst, int broj)
{
    char *temp=tekst;
    int cifre=0,razmaci=0,niz[20],niz2[20],i=0,j=0,negativnost=0,brojac_testni=0,tester=0;
    if (broj<0) {
        broj=-broj;
        negativnost=1;
    }
    while (broj>0) {
        niz[i]=broj%10;
        broj=broj/10;
        cifre++;
        i++;
    }
    for (i=cifre-1; i>=0; i--) {
        niz2[j]=niz[i];
        j++;
    }
    if (*tekst==' ') {
        while(*tekst==' ')
            tekst++;
    } 


    while (*tekst!='\0') {

        if (*tekst==' ') {

            char*brojac_raz=tekst;
            while (*brojac_raz==' ' || *brojac_raz=='\0') {
                if (*brojac_raz=='\0'){
                tester=1;
                break;}
                razmaci++;
                brojac_raz++;
            }
            if(tester)
            break;
            char*kraj=tekst;
            while (*kraj!='\0')
                kraj++;
            while (kraj>tekst) {
                if(razmaci==1) {
                    if(negativnost)
                        *(kraj+cifre+2)=*kraj;
                    else
                        *(kraj+cifre+1)=*kraj;
                } else {
                    if(negativnost)
                        *(kraj+cifre+1)=*kraj;
                    else
                        *(kraj+cifre)=*kraj;
                }
                kraj--;
            }
            char*trenutno=tekst;
            tekst=tekst+1;
            j=0;
            if (negativnost) {
                *tekst='-';
                tekst=tekst+1;
                while((tekst)<=trenutno+cifre+1) {
                    *(tekst)='0'+ niz2[j];
                    tekst++;
                    j++;
                }
            } else {
                while((tekst)<=trenutno+cifre) {
                    *(tekst)='0'+ niz2[j];
                    tekst++;
                    j++;
                }
            }
            char*trenutno2=tekst;
            if(razmaci==1) {
                while(tekst<(trenutno2+razmaci)) {
                    *tekst=' ';
                    tekst++;
                }
            } else {
                while(tekst<(trenutno2+razmaci-1)) {
                    *tekst=' ';
                    tekst++;
                }
            }
        }
        tekst++;
        razmaci=0;
        brojac_testni=0;
    }
    return temp;
}

int main()
{
    char niz[100];
    int n;
    printf ("Unesi recenicu: ");
    unesi(niz,100);
    printf ("Unesi broj: \n");
    scanf ("%d", &n);
    printf ("Nova recenica glasi: %s", ubaci_broj(niz,n));

    return 0;
}
