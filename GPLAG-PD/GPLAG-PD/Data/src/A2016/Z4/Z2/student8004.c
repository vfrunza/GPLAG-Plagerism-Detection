#include <stdio.h>

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

char* kodiraj(char* s, char* t)
{
    int brojac[96]={0},i,j;
    int maxi=0,broj_brojaca=0;
    char ascii[200]={0};
/*formiranje ascii stringa*/
    for(i=0;i<96;i++)
    {
    	if(i==95)
    		*(t+i)='\0';
    	else *(t+i)=i+32;
    }
/*ucestalosti charova*/
    for(i=0;;i++)
    {
    	j=0;
        while(j<95)
        {
            if(*(s+i)==*(t+j))
            {
                brojac[j]++;
                break;
            }
            j++;
        }
        if(*(s+i+1)=='\0')
            break;
    }
/*pronalazenje najucestalijeg*/
	i=0;
    while(i<95)
    {
        if(brojac[i]>maxi)
            maxi=brojac[i];
        i++;
    }
/**/
/*redoslijedom od najucestalijeg*/
    do
    {
        for(i=0;i<95;i++)
        {
            for(j=0;;j++)
            {
                broj_brojaca=0;
                if(brojac[j]==maxi)
                {
                    ascii[i]=*(t+j);
                    if(maxi>0)
                    {
                        if(broj_brojaca==0)
                            i++;
                    }
                    if(maxi==0)
                        i++;
                    broj_brojaca++;
                }
                if(*(t+j)=='\0')
                    break;
            }
            if(broj_brojaca==0)
                i--;
            maxi--;
        }
    }while(maxi>0);
/*pretvaranje u kod*/
    for(i=0;;i++)
    {
        *(t+i)=ascii[i];
        if(ascii[i]=='\0')
            break;
    }
/*sifriranje*/
    for(i=0;;i++)
    {
    	if(*(s+i)=='\0')
        {
            *(s+i)='\0';
            break;
        }
        for(j=0;;j++)
        {
        	if(*(t+j)=='\0')
                break;
            if(*(s+i)==*(t+j))
            {
                *(s+i)=126-j;
                break;
            }
        }
    }
	return s;
}

char* dekodiraj(char* s, char* t)
{
    int i,j;
    for(i=0;*(s+i)!='\0';i++)
    {
        for(j=0;j<95;j++)
        {
            if(*(s+i)==126-j)
            {
                *(s+i)=*(t+j);
                break;
            }
        }
    }
    return s;
}

int main()
{
	char s[1000],kod[150];
	unesi(s,1000);
    printf("%s",kodiraj(s,kod));
    printf("\n%s",dekodiraj(s,kod));
    return 0;
}