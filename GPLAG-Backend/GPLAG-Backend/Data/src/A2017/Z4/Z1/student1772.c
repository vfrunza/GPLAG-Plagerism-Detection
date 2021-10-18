#include <stdio.h>
#include <math.h>
int prebroji  (int broj)
{
    int duzina=0;
    if (broj<0)
    {
        duzina=1;
        broj=fabs(broj);
    }
    do
    {
        broj=broj/10;
        duzina++;
    }
    while(broj!=0);
    return duzina;
}
char* ubaci_broj (char* tekst, int broj)
{
    char *pocetak=tekst+1;
    
    int duzina=prebroji(broj)+1;
    if(broj<0) duzina--;
    while((*pocetak)!='\0' && (*(pocetak+1))!='\0')                           
    {
        if(*pocetak==' ' && *(pocetak-1)!=' ' && *(pocetak+1)!=' ')
        {
            char *kraj=tekst;
            while(*kraj!='\0') kraj++;
            while(kraj!=pocetak)
            {
                if(broj>=0) *(kraj+duzina)=*kraj;
                else *(kraj+duzina+1)=*kraj;
                kraj--;
            }
            int i;
            *pocetak=' ';
            pocetak++;
            if(broj<0) *pocetak++='-';
            
            int tempbr=fabs(broj);
            int novibr=0;
            while(tempbr!=0)
            {
                novibr+=tempbr%10;
                novibr*=10;
                tempbr/=10;
            }
            novibr/=10;
            
            for(i=0; i<duzina;i++)
            {
                *(pocetak+i)=novibr%10+'0';
                novibr/=10;
            }
            pocetak+=duzina;
            *(pocetak-1)=' ';
        }
        pocetak++;
    }
    return tekst;
    /*
    char *pocetak=tekst;
    char *p_pocet=tekst;
    char *p;
    int a=0;
    char *pok_na_broj;
    int i=0,duzina=0,ostatak=0;
    char*zadnji=tekst;
    int negativan=0;
    duzina=prebroji(broj);
    char niz[10]="";
    while((*pocetak)!='\0')
    {
        while (*pocetak==' ' || *pocetak=='\t') pocetak++;
        a=0;
        while (*zadnji!='\0') zadnji++;
        while (*pocetak!=' ' && *pocetak!='\t' && *pocetak!='\0')
        {
            pocetak++;
        }
        p=zadnji;
        zadnji=zadnji+duzina+1;
        while (p!=pocetak)
        {
            *zadnji=*p;
            p--;
            zadnji--;
        }
        (*zadnji)=' ';
        // ovdje treba da se broj pretvori u string
        if (broj<0)
        {
           * negativan=1;
            broj=fabs(broj);
        }
        if (negativan)
        {
            do
            {
                ostatak=broj%10;
                niz[i]=ostatak+'0';
                broj=broj/10;
                i++;
            }
            while (i<duzina-1);
        }
        else
        {
            do
            {
                ostatak=broj%10;
                niz[i]=ostatak+'0';
                broj=broj/10;
                i++;
            }
            while (i<duzina);
        }
        if (negativan) pok_na_broj=&niz[duzina-2];
        else
        {
            pok_na_broj=&niz[duzina-1];
        }
        if (negativan)
        {
            pocetak++;
            *pocetak='-';
            pocetak++;
        }
        else
        {
            pocetak++;
            *pocetak=' ';
        }
        if (negativan)
        {
            while(a!=duzina-1)
            {
                *pocetak=*pok_na_broj;
                pok_na_broj--;
                pocetak++;
                a++;
            }
        }
        else
        {
            while(a!=duzina)
            {
                *pocetak=*pok_na_broj;
                pok_na_broj--;
                pocetak++;
                a++;
            }
        }
        while (*pocetak==' ' || *pocetak=='\t' ) pocetak++;
        pok_na_broj=pok_na_broj+duzina-1;
    }
    return p_pocet;*/
    
}
int main()
{
    /* AT4: Vise razmaka izmedju rijeci */
char s[77] = "Ovdje  izmedju    rijeci ima      po nekoliko   razmaka";
printf("\"%s\"", ubaci_broj(s, 320));
    return 0;
}