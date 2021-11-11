#include <stdio.h>

char* obuhvat(char* tekst, double x1, double x2, double y1, double y2)
{
    char* pok_na_tekst=tekst;
    double a,b, tacka;
    int unutra=0;
    while(*tekst)
    {
        if(*tekst>='A' && *tekst<='Z')
        *tekst=*tekst+32;
        else if(*tekst>='a' && *tekst<='z')
        *tekst=*tekst-32;
        tekst++;
    }
    tekst=pok_na_tekst;
    while(*tekst)
    {
        if(*tekst>='0' && *tekst<='9' && *(tekst+1)=='.')
        {
            a=*tekst;
            b=*(tekst+1);
        }
        tekst++;
    }
    tacka=a+(b/10);
    
    if(unutra==1)
    {
        tekst=pok_na_tekst;
    }
    else
    {
        tekst=pok_na_tekst++;
    }
    
    return NULL;
}

int main() {
    return 0;
}