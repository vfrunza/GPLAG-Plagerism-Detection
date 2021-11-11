#include <stdio.h>

void unesi(char niz[], int velicina) {
    char znak = getchar();
        int i = 0;
    if (znak == '\n') znak = getchar();
    while (i<velicina-1 && znak != '\n'){
        niz[i]=znak;
        i++;
        znak=getchar();
    }
    niz[i]='\0';
}

char veliko(char slovo)
{
    if(slovo >= 'A' && slovo <= 'Z')
        return slovo;
    else
        return slovo-32;
}

int indeks_najveceg(int niz[], int vel)
{
    int i=0;
    int indeks=0;
    int najveci=niz[0];
    for(i=0; i<vel; i++)
    {
        if(niz[i]>najveci)
        {
            najveci=niz[i];
            indeks=i;
        }
    }
    return indeks;
}

char* izbaci_najcescu(char* s)
{
    char rijeci[50][50], rijec[50], slovo1, slovo2;
    int brojaci[50], i=0, j=0, broj_rijeci=0, najcesca;
    int ima=0, ista=1, brisati=1; /*bool varijable*/
    char* poc, *pocetak=s, *prva;
    
    for(i=0; i<50; i++)
    brojaci[i]=0;
    
    while(*s != '\0')
    {
        if((*s>64 && *s<91)||(*s>96 && *s<123))
        {
            ima = 0;
            j = 0;
            while((*s>64 && *s<91)||(*s>96 && *s<123))
        rijec[j++]=*s++;
        rijec[j]='\0';
        
        if(broj_rijeci != 0)
        {
            for(i=0; i<broj_rijeci; i++)
            {
                j=0;
                ista=1;
                while(rijeci[i][j] != '\0' && rijec[j] != '\0')
                {
                    slovo1=rijeci[i][j];
                    slovo2=rijec[j];
                    if(veliko(slovo1) != veliko(slovo2))
                    {
                        ista=0;
                        break;
                    }
                    j++;
                }
                if(ista)
                {
                    ima=1;
                    brojaci[i]++;
                    break;
                }
            }
            if(!ima)
            {
                j=0;
                while(rijec[j] != '\0')
                {
                    rijeci[broj_rijeci][j]=rijec[j];
                    j++;
                }
                rijeci[broj_rijeci][j]='\0';
                brojaci[broj_rijeci]++;
                broj_rijeci++;
            }
        }
        else
        {
            j=0;
            while(rijec[j] != '\0')
            {
                rijeci[0][j]=rijec[j];
                j++;
            }
            rijeci[0][j]='\0';
            brojaci[broj_rijeci]++;
            broj_rijeci++;
        }
    }
    else s++;
}

najcesca = indeks_najveceg(brojaci, broj_rijeci);

s=pocetak;

while(*s != '\0')
{
    if((*s>64 && *s<91) || (*s>96 && *s<123))
    {
        brisati=1;
        poc=s;
        prva = s;
        j=0;
        while((*s>64 && *s<91) || (*s>96 && *s<123))
        {
            rijec[j++]=*s++;
        }
        rijec[j]='\0';
        j=0;
        while(rijeci[najcesca][j] != '\0' && rijec[j] != '\0')
        {
            slovo1 = rijeci[najcesca][j];
            slovo2 = rijec[j];
            if(veliko(slovo1) != veliko(slovo2))
            {
                brisati = 0;
                break;
            }
            j++;
        }
        if(brisati && rijeci[najcesca][j] == '\0' && rijec[j] == '\0')
        {
            while(*s != '\0')
            {
                *poc++ = *s++;
            }
            *poc='\0';
            s=prva;
        }
        if(*s == '\0')
            break;
        s++;
    }
    else 
    {
        if(*s == '\0')
            break;
        s++;
    }
}
s=pocetak;
return s;
}

int main () {
    char str[1000];
    int i;
    
    unesi(str, 1000);
    /*i=0;
    while(str[i] != '\0') {
        printf("%c", str[i]);
        i++; }*/
        izbaci_najcescu(str);
        
        i=0;
        while(str[i] != '\0')
        {
            printf("%c", str[i]);
            i++;
        }
        return 0;
    }