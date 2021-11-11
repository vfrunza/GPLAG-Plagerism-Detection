#include <stdio.h>

double stepenovanje(int baza,int stepen)
{
    int i,rezultat=1;
    for(i =0; i < stepen; i++)
    {
        rezultat *= baza;
    }
    return rezultat;
}

int izbacicifru(int broj, int cifra)
{
    int broj_cifara=0,temp,rez=0,a;
    if(broj >= 0) temp = broj;
    else if(broj < 0) temp =-1*broj;
    while(temp != 0)
    {
            a = temp % 10;
            if(a != cifra)
            {
                rez += (temp % 10) * stepenovanje(10,broj_cifara);
                broj_cifara++;
            }
            temp /= 10;
    }
    if(broj < 0) rez*=-1;
    
    return rez;
}

int izbaci_cifre(int niz[], int velicina1, int niz_cifara[], int velicina2)
{
    int i,j;
    for(i =0; i < velicina2; i++)
    {
        if((niz_cifara[i] < 0) || (niz_cifara[i] > 9)) return 0;
    }
    for(i =0; i < velicina2; i++)
    {
        for(j = 0; j < velicina2; j++)
        {
            if(niz_cifara[i] == niz_cifara[j] && i != j) return 0;
        }
    }
    
    for(i = 0; i < velicina1; i++)
    {
        for(j =0; j < velicina2; j++)
        {
            niz[i] = izbacicifru(niz[i],niz_cifara[j]);
        }
    }
   return 1;
}


int main()
{
    int a,i,niz[5]={134,2235,567,45678,12},cifre[3]={1,2,3};
    izbaci_cifre(niz,5,cifre,3);
    for(i =0; i < 5; i++)
    {
        printf("%d ",niz[i]);
    }
    
    return 0;
}
