#include <stdio.h>

int provjeri_duzine(char* recenica,int niz[], int velicina)
{
    int brojac_slova=0,i=0,broj_rijeci=0,brojac_za_vracanje_recenice=0;
    while(*recenica!='\0')
    {
     if((*recenica>='A'&&*recenica<='Z')||(*recenica>='a'&&*recenica<='z'))
     {
         if(*(recenica+1)=='\0') broj_rijeci++;
          recenica++;
     }
     else
     {
        if((*(recenica-1)>='A'&&*(recenica-1)<='Z')||(*(recenica-1)>='a'&&*(recenica-1)<='z'))
        broj_rijeci++;
        recenica++;
     }
     brojac_za_vracanje_recenice++;
    }
    recenica-=brojac_za_vracanje_recenice;
    if(broj_rijeci!=velicina) return 0;
    while(i<velicina){
    while(*recenica!='\0')
    {
        brojac_slova=0;
        while((*recenica>='A'&&*recenica<='Z')||(*recenica>='a'&&*recenica<='z'))
        {
            brojac_slova++;
            recenica++;
        }
        if (brojac_slova!=niz[i]) return 0;
        else return 1;
        recenica++;
    }
    i++;
    }
   
}
int main(){

	return 0;
}
