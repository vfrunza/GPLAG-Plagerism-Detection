#include <stdio.h>
#include <ctype.h>
int broj_rijeci(char*string)
{
	int br=0;
	char* tmp=string;
	while(*tmp!='\0')
	{
		if(*tmp==' ' || *tmp=='-') br++;
		tmp++;
	}
	br++;
	return br;
}
char* izbaci_najcescu(char* string)
{
    char* pokusaj_slova=string;
    int brojac_slova=0;
    while(*pokusaj_slova)
    {
        if((*pokusaj_slova>='A' && *pokusaj_slova<='Z')||(*pokusaj_slova>='a' && *pokusaj_slova<='z')) {brojac_slova++; break;}
        pokusaj_slova++;
    }
    if(brojac_slova==0) return string;
    int max=0;
    char* pok_na_string=string;
    int brojRijeci;
    char* pokazivaci[100];
    int i=0,j=0;
    int nizBrojaca[100]={0};
    char prazni[1000];
    char* pok_na_prazni=prazni;
    brojRijeci=broj_rijeci(string);
    if(brojRijeci==1)
	{
		string[0]='\0';
		return string;
	}

    while(i<brojRijeci)
    {

        while(*string)
        {
         char*pocetak_rijeci;
         if(((*string>='A' && *string<='Z') || (*string>='a' && *string<='z')) && (string==pok_na_string || *(string-1)==' ' ||*(string-1)=='-'))
            {
                pocetak_rijeci=string;
                pokazivaci[i]=pocetak_rijeci;
                i++;
            }
            string++;
        }
    }
    string=pok_na_string;


    for(i=0; i<brojRijeci; i++)
    {
        for(j=0; j<brojRijeci; j++)
        {
            if((toupper(*pokazivaci[i])==toupper(*pokazivaci[j])) )//|| (toupper(*pokazivaci[i]+32==*pokazivaci[j]) || (*pokazivaci[i]-32==*pokazivaci[j]))
            {
                char* tmpi;
                char* tmpj;
                tmpi=pokazivaci[i];

                tmpj=pokazivaci[j];
                int ista=1;
                while((*tmpi!=' ' && *tmpi!='-' && *tmpj!=' ') && (*tmpj!='-' && *tmpi!='\0' && *tmpj!='\0'))
                {
                    if(*tmpi!=*tmpj)
                    {
                        ista=0;
                        break;
                    }
                    tmpi++;
                    tmpj++;
                }
                if(ista==1)
                {
                    if((*(tmpi)==' ' || *(tmpi)=='-' || *(tmpi)=='\0')||(*(tmpj)==' ' || *(tmpj)=='-' || *(tmpj)=='\0'))
                    {
                        nizBrojaca[i]++;
                    }
                }
            }
        }
    }

    //----------
    for(i=0;i<brojRijeci; i++)
    {
        if(nizBrojaca[i]>max) max=nizBrojaca[i];
    }

    string=pok_na_string;
    if(max!=1)
    {
    j=0;
    for(i=0; i<brojRijeci; i++)
    {
        if(nizBrojaca[i]==max)
        {
            if(i!=0)
                {
                    char* p=pokazivaci[i];
                    prazni[j]=*(p-1);
                    j++;
                }
            continue;
        }
        else{
            if(i!=0)
                {
                    char* p=pokazivaci[i];
                    prazni[j]=*(p-1);
                    j++;
                }
            char* pom=pokazivaci[i];
            if(i!=brojRijeci-1)
            {
                while(*pom!=*pokazivaci[i+1])
                {
                    prazni[j]=*pom;
                    pom++;
                    j++;
                }
            }
            else
            {
                while(*pom!='\0')
                    {
                        prazni[j]=*pom;
                        pom++;
                        j++;
                    }
            }
        }
    }
    prazni[j]='\0';

    string=pok_na_prazni;

    return pok_na_prazni;
    }
    else
    {
        char* krajPrve=pok_na_string;
        char* pocetakPrve=pok_na_string;
        while(*krajPrve!=' ' && *krajPrve!='-' && *krajPrve!='\0')
            krajPrve++;
        string=krajPrve;
    }
   return string;
}

int main()
{
	
	char t[]="";
	printf("%s", izbaci_najcescu(t));
	return 0;
}
