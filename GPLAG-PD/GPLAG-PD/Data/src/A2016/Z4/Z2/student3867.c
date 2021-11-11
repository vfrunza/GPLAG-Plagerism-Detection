#include <stdio.h>

/*standard kopirana funkcija za unos stringa*/
void unesi(char niz[], int velicina)
{
    int i=0;
    char znak=getchar();
    if (znak=='\n')
        znak=getchar();
    while(i<velicina-1 && znak!='\n')
    {
        niz[i]=znak;
        i++;
        znak=getchar();
    }
    niz[i]='\0';
}

char* kodiraj(char* s, char* c)
{
    int hist[96]={0},i,j,max=0,count=0;
    char pom[150]={0};
/*formiranje ascii stringa*/
    for(i=0;i<95;i++)
        *(c+i)=i+32;
    *(c+i)='\0';
/**/

/*provjera ucestalosti charova uz pomoc ascii stringa*/
/*te zapisivanje u histogram broj ponavljanja*/
    for(i=0;;i++)
    {
        for(j=0;j<95;j++)
        {
            if(*(s+i)==*(c+j))
            {
                hist[j]++;
                break;
            }
        }
        if(*(s+i+1)=='\0')
            break;
    }
/**/

/*pronalazenje najveceg elementa iz histograma*/
    for(i=0;i<95;i++)
    {
        if(hist[i]>max)
            max=hist[i];
    }
/**/

/*stvaranje pomocnog kljuc stringa*/
/*redoslijedom od najucestalijeg char-a do onih koji se ne pojavljuju*/
    do
    {
        for(i=0;i<95;i++)
        {
            for(j=0;;j++)
            {
                count=0;
                if(hist[j]==max)
                {
                    pom[i]=*(c+j);
                    if(max>0)
                    {
                        if(count==0)
                            i++;
                    }
                    else if(max==0)
                        i++;
                    count++;
                }
                if(*(c+j)=='\0')
                    break;
            }
            if(count==0)
                i--;
            max--;
        }
    }while(max>0);
/**/

/*pretvaranje ascii stringa u kljuc*/
    for(i=0;;i++)
    {
        *(c+i)=pom[i];
        if(pom[i]=='\0')
            break;
    }
/**/

/*sifriranje unesenog stringa uz pomoc kljuca*/
    for(i=0;;i++)
    {
        if(*(s+i)=='\0')
        {
            *(s+i)='\0';
            break;
        }
        for(j=0;;j++)
        {
            if(*(c+j)=='\0')
                break;
            if(*(s+i)==*(c+j))
            {
                *(s+i)=126-j;
                break;
            }
        }
    }
/**/
    return s;
}

/*koristimo reverse metod da desifrujemo sifrirani string uz pomoc kljuca*/
char* dekodiraj(char* s, char* c)
{
    int i,j;
    for(i=0;*(s+i)!='\0';i++)
    {
        for(j=0;j<95;j++)
        {
            if(*(s+i)==126-j)
            {
                *(s+i)=*(c+j);
                break;
            }
        }
    }
    return s;
}

int main()
{
	char str[1000],crypt[150];
	unesi(str,1000);
    printf("%s\n",kodiraj(str,crypt));
    printf("%s",dekodiraj(str,crypt));
    return 0;
}