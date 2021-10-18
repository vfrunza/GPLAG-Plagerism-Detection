#include <stdio.h>

char* dekodiraj(char* s, char* tablica)
{
    char *p=s;
    int i, pomjer;
    while(*p!='\0')
    {
        for(i=0;i<127;i++)
        {
            // Trazimo karakter u tablici jednak nasem karakteru
            if(*p==126-i) pomjer=i;
        }
        *p=(*(tablica+pomjer));
        p++;
    }
    return s;
}

char* kodiraj(char* s, char* tablica)
{
    char *p, *t;
    int brojputa[128]={0}, vecbilo[128]={0}, i, dodanoclanova=0, brmax=0, maxindeks, pozicija;
    p=s;
    t=tablica;
    
    //Prvo izbrojimo koliko se koji karakter puta pojavljuje u stringu
    
    while(*p!='\0')
    {
        brojputa[*p]++;
        p++;
    }
    
    //Pravljenje tablice
    
    while(dodanoclanova<95)
    {
        brmax=0;
        i=32;
        while(i<127 && vecbilo[i]) i++;
        brmax=brojputa[i];
        maxindeks=i;
        for(i=32;i<127;i++)
        {
            if(brojputa[i]>brmax && !vecbilo[i])
            {
                brmax=brojputa[i];
                maxindeks=i;
            }
            if(brojputa[i]==brmax && !vecbilo[i])
            {
                // Ako je broj puta ponavljanja jednak za dva karaktera, poredimo njihove ASCII vrijednosti
                
                if(i<maxindeks)
                {
                    brmax=brojputa[i];
                    maxindeks=i;
                }
            }
        }
        *t=maxindeks;
        t++;
        vecbilo[maxindeks]=1;
        dodanoclanova++;
    }
    *t='\0';
    
    // Kodiranje
    
    p=s;
    while(*p!='\0')
    {
        t=tablica;
        pozicija=0;
        while(*t!='\0')
        {
            pozicija++;
            if(*p==*t) 
            {
                *p=127-pozicija;
                break;
            }
            t++;
        }
        p++;
    }

    return s;
}

int main() 
{
    char t[100], s[100]="Ovo je neki testni tekst";
	printf("%s\n", kodiraj(s, t));
	printf("%s\n", t);
	printf("%s\n", dekodiraj(s, t));
	return 0;
}
