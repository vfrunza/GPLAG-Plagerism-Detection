#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void restartuj(int niz[])
{
    int i=0;
    for(i=0;i<100;i++)
        niz[i]=0;
}

void najduzi_bp(char* s1, char* s2)
{
    int brojac=0;
    int najduza=0;
    char *pok=s1;
    char *pr;
    char *kr;
    char *prn;
    int slova[100];
    restartuj(slova);

    while(*pok!='\0') // prebacimo sve u velika slova
    {
        if(*pok>='a' && *pok<='z') *pok+='A'-'a';
        pok++;
    }

    pok=s1;

    while(*pok!='\0')
    {
        if(pok==s1 && *pok>='A' && *pok<='Z' || *pok>='A' && *pok<='Z' && *(pok-1)<'A' || *(pok-1)>'Z') pr=pok;
        if(*pok>='A' && *pok<='Z' && slova[*pok]==0)
        {
            slova[*pok]++;
            brojac++;
        }
        else if(*pok>='A' && *pok<='Z' && slova[*pok]!=0 || *pok<'A' || *pok>'Z')
        {
            if(najduza<brojac) {najduza=brojac; kr=pok; pok=pr; prn=pr;}
            if(*(pok+1)>='A' && *(pok+1)<='Z') pr++;
            restartuj(slova);
            brojac=0;
        }
        if(*pok=='\0') break;
        pok++;
    }

    int i=0;
    while(i<najduza)
    {
        *s2=*prn;

        prn++;
        s2++;
        i++;
    }

    *s2='\0';





}


int main()
{
    char string1[50]="   Ovo    je    neki    primjer teksta   ";
    char string2[50]="";

    najduzi_bp(string1,string2);

    char *pok = string1;

    printf("\n");
    while(*pok!='\0')
    {
        printf("%c", *pok);
        pok++;
    }

    pok = string2;

    printf("\n");
    while(*pok!='\0')
    {
        printf("%c", *pok);
        pok++;
    }

    return 0;
}