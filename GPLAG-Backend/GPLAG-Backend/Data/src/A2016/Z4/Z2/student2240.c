#include <stdio.h>
#include <stdlib.h>

void unesi(char niz[], int velicina)
{
    char znak=getchar();
    int i=0;
    
    if(znak=='\n') znak=getchar();
    while(i<velicina-1 && znak!='\n')
    {
        niz[i]=znak;
        i++;
        znak=getchar();
    }
    niz[i]='\0';
}

char* kodiraj(char* text, char* tablica)
{
    int ucestalost[96];
    int i=0, j=0, tmp_int;
    char tmp_char, *pocetak=text;
    
    for(i=0; i<95; i++)
    {
        ucestalost[i]=0;
        tablica[i] = i+32;
    }
    tablica[95] = '\0';
    while(*text!='\0')
    {
        for(i=0; i<95; i++)
        {
            if(*text==tablica[i])
            {
                ucestalost[i]++;
                break;
            }
        }
        text++;
    }
    for(i=0; i<94; i++)
    {
        for(j=i; j<95; j++)
        {
            if(ucestalost[i]<ucestalost[j])
            {
                tmp_int=ucestalost[i];
                ucestalost[i]=ucestalost[j];
                ucestalost[j]=tmp_int;
                
                tmp_char=tablica[i];
                tablica[i]=tablica[j];
                tablica[j]=tmp_char;
            }
            else if(ucestalost[i]==ucestalost[j])
            {
                if(tablica[i]>tablica[j])
                {
                    tmp_char=tablica[i];
                    tablica[i]=tablica[j];
                    tablica[j]=tmp_char;
                }
            }
        }
    }
    text=pocetak;
    while(*text != '\0')
    {
        for(i=0; i<95; i++)
        if(tablica[i]==*text)
            tmp_int=i;
        
        *text=126-tmp_int;
        text++;
    }
    text=pocetak;
    return text;
}
char* dekodiraj(char* text, char* tablica)
{
    int tmp_int;
    char* pocetak=text;
    
    while(*text != '\0')
    {
        tmp_int=126-*text;
        *text=tablica[tmp_int];
        text++;
    }
    text=pocetak;
    return text;
}
int main ()
{
    char str[1000];
    char tablica[96];
    int i;
    
    unesi(str, 1000);
    
    kodiraj(str, tablica);
    
    i=0;
    while(str[i]!='\0')
    {
        printf("%c", str[i]);
        i++;
    }
    dekodiraj(str, tablica);
    printf("\n");
    i=0;
    while(str[i]!='\0')
    {
        printf("%c", str[i]);
        i++;
    }
    return 0;
}