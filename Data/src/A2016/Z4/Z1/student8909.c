/*Zadaca 4. zadatak 1. */

#include <stdio.h>
#include <stdlib.h>

int prebroj_rijeci(char *s)
{
    int brojrijeci = 0;
    
    while(*s != '\0')
    {
        if((*(s+1) < 'A' || *(s+1) > 'z') && (*s >= 'A' && *s <= 'z'))
        brojrijeci ++;
        
        s++;
    }
    return brojrijeci;
}

int jesu_li_jednake(char* prva, char* druga)
{
    while(*prva != '\0')
    {
        char a = *prva;
        char b = *druga;
        
        if(a > 'Z')
        {
            a = a - ('a' - 'A');
        }
        if(b > 'Z')
        {
            b = b - ('a' - 'A');
        }
        if(a != b)
            return 0;
            
        prva ++;
        druga ++;
        
        if(*prva == '\0' && *druga != '\0')
            return 0;
    }
    return 1;
}

int nijeSlovo(char* s)
{
    if(*s >= 'A' && *s <= 'Z')
        return 0;
        
    if(*s >= 'a' && *s <= 'z')
        return 0;
        
    return 1;    
}

char* izbaci_najcescu(char* s)
{
 
    int broj_rijeci = prebroj_rijeci(s);
    int i, j, w = 0;
    char *t = s;
    char rijeci_bez_ponavljanja[50][50];
    char sve_rijeci[50][50];
    int broj_rijeci_bez_ponavljanja = 0;
    
    for(i=0; i<broj_rijeci; i++)
    {
        while(nijeSlovo(t))
        {
            if(*t == '\0')
                break;
                
            *t++;    
        }
        
        char rijec[50];
        char *p;
        p = t;
        j=0;
        
        while(*p >= 'A' && *p <= 'z')
        {
            sve_rijeci[i][j] = *p;
            rijec[j++] = *p++;
        }
        
        rijec[j] = '\0';
        sve_rijeci[i][j] = '\0';
        
        int duplikat = 0;
        int k;
        
        if(i>0)
        {
            for(k=0; k<i; k++)
                if(jesu_li_jednake(rijec, &rijeci_bez_ponavljanja[k][0]) == 1)
                {
                    duplikat = 1;
                    break;
                }
        }
        j=0;
        
        if(duplikat == 1)
        {
            t=p;
            continue;
        }
        else
        {
            while(!nijeSlovo(t))
            rijeci_bez_ponavljanja[w][j++] = *t++;
            
            broj_rijeci_bez_ponavljanja++;
            rijeci_bez_ponavljanja[w][j] = '\0';
        }
        w++;
    }
    
    
    /* Niz brojaca pojavljivanja svake rijeci */
    
    int ponavljanja[50];
    for(i=0; i<broj_rijeci_bez_ponavljanja; i++)
    ponavljanja[i] = 0;
    
    
    /*Brojim koliko se koja rijec puta pojavila */
    
    for(i=0; i<broj_rijeci_bez_ponavljanja; i++)
    {
        for(j=0; j<broj_rijeci; j++)
        {
            if(jesu_li_jednake(&rijeci_bez_ponavljanja[i][0], &sve_rijeci[j][0]) == 1)
            ponavljanja[i] = ponavljanja[i]+1;
        }
    }
    
    int indeks_najcesce = 0;
    
    /*Nalazimo indeks rijeci koja se najcesce pojavljuje. */
    
    for(i=0; i<broj_rijeci_bez_ponavljanja; i++)
    if(ponavljanja[i] > ponavljanja[indeks_najcesce])
        indeks_najcesce = i;
        
    char najcesca[50];
    j=0;
    t = &rijeci_bez_ponavljanja[indeks_najcesce][0];
    
    while(*t != '\0')
        najcesca[j++] = *t++;
        
        najcesca[j] = '\0';
        
    t = s;
    char *p;
    p = t;
    
    while(ponavljanja[indeks_najcesce] > 0)
    {
        if(*t == '\0')
            break;
        while(nijeSlovo(t))
        {
            t++;
            p++;
        }
        
        while(*p >= 'A' && *p <= 'z')
            p++;
            
            int jednake_su = 1;
            
            char *skener_teksta = t;
            char *skener_rijeci = &najcesca;
            
            while(*skener_teksta != *p)
            {
                char slovo_iz_teksta = *skener_teksta++, slovo_iz_rijeci = *skener_rijeci++;
                
                if(slovo_iz_teksta > 'Z')
                slovo_iz_teksta -= ('a' - 'A');
                
                if(slovo_iz_rijeci > 'Z')
                slovo_iz_rijeci -= ('a' - 'A');
                
                if(slovo_iz_teksta != slovo_iz_rijeci++)
                {
                    jednake_su = 0;
                    break;
                }
            }
            if(jednake_su)
            {
                while(*p != '\0')
                *t++ = *p++;
                
                *t=*p;
                ponavljanja[indeks_najcesce]--;
                t=p=s;
            }
            else t=p;

    }
    return s;
        
}

int main()
{
    char t[] = "12345 ./,4 !@#%^ ";
    printf("'%s'", izbaci_najcescu(t));
    
    return 0;
}