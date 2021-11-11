#include <stdio.h>

void izbacivanje (char* recenica, int n)
{
    int neslovo=1, broj_rijeci=0;
    char* s=recenica;
    char* pocetak;
    char* kraj;
    while (*s!='\0')
    {
        if (!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))) neslovo=1;
        else if (neslovo==1)
        {
            neslovo=0;
            broj_rijeci++;
            if (broj_rijeci==n) pocetak=s;
            if (broj_rijeci==n+1)
            {
                kraj=s;
                while ((*kraj>='A' && *kraj<='Z')|| (*kraj>='a' && *kraj<='z')) kraj--;
                while (*pocetak++=*kraj++);
                return;
            }
        }
        s++;
    }
    if (broj_rijeci==n) *pocetak='\0';
    
}

int zadnja_rijec (char* recenica, char* kraj_rijeci)
{
    char* p=recenica;
    char* g=kraj_rijeci;
    char* pok1, *pok2;
    int n=0;
    while (*p!='\0') p++;
    p--;
    while (p!=recenica)
    {
        while (*p>=32 && *p<=64) p--;
        pok1=p;
        pok2=g;
        while (*pok1==*pok2) 
        {
            pok1--;
            pok2--;
            if (*pok2>=32 && *pok2<=64) break;
        }
        if ((*pok2>=32 && *pok2<=64) && *pok1==*pok2) n++;
        p--;
    }
    return n;
}

int broj_ponavljanja (char* recenica, char* pocetak_rijeci)
{
    char* p=recenica;
    char* g=pocetak_rijeci;
    int n=0;
    char* pok1, *pok2;
    while (*p!='\0')
    {
        while (*p>=32 && *p<=64) p++;
        pok1=p;
        pok2=g;
        while (*pok1==*pok2)
        {
            pok1++;
            pok2++;
            if (*pok2>=32 && *pok2<=64) break;
        }
        if ((*pok2>=32 && *pok2<=64) && *pok1==*pok2) n++;
        p++;
    }
    return n;
}

char * izbaci_najcescu (char*s)
{
    int znak=1, broj_rijeci=0, n=0, i, j=0, max;
    char* nizp[100];
    char* nizk[100];
    int brojac[100]={0};
    int iste_rijeci[100]={0};
    char* p=s;
    char* g=s;
    char* q=s;
    char* r=s;
    int logic=0;
    char* pok1, *pok2;
    
    if (*q=='\0') return s;  /* slucaj da je poslan prazan string*/
    
    while (*r!='\0')         /* slucaj da se string sastoji iskljucivo od znakova*/
    {
        if ((*r>='A' && *r<='Z')|| (*r>='a' && *r<='z'))
        {
            logic++;
            break;
        }
        r++;
    }
    
    if (logic==0)
    {
        return s;
    }
    
    
       while (*p!='\0')         /* niz pokazivaca gdje ce svaki clan pokazivati na pocetak rijeci*/
        {
            if (*p>=32 && *p<=64)
            znak=1;
            else if (znak==1)
            {
                znak=0;
                *(nizp+n++)=p;
            }
            p++;
        }
    
        znak=1;
        broj_rijeci=n;
        *(nizk+(--n))=--p;
    
        while (n>=0)            /*niz pokazivaca gdje ce svaki clan pokazivati na kraj rijeci*/
        {
            if (*p>=32 && *p<=64)
            znak=1;
            else if (znak==1)
            {
                znak=0;
                *(nizk+n--)=p;
            }
            p--;
        }
    
        for (i=0; i<broj_rijeci-1; i++)     
        {
            brojac[i]=broj_ponavljanja(g, *(nizp+i));  /* odredjuje koliko puta se svaka rijec ponovila u stringu */
        }
    
        brojac[i]=zadnja_rijec(g, nizk[i]);             /* ispituje poseban slucaj za posljednju rijec u stringu */
    
        max=0;
        for (i=0; i<broj_rijeci; i++)                   /*odredjeje koje se to rijeci (po indeksima) najvise puta ponavljaju*/
        {
            if(brojac[i]>brojac[max])
        max=i;
        }
    
        iste_rijeci[j++]=max;
    
        for (i=max+1; i<broj_rijeci; i++)
        {
            if (brojac[max]==brojac[i])
            {
                pok1=nizp[max];
                pok2=nizp[i];
            
                while (*pok1==*pok2 )
                {
                    if (*pok2>=32 && *pok2<=64) break;
                    pok1++;
                    pok2++;
                }
            
                if ((*pok2>=32 && *pok2<=64) || *pok2=='\0') 
                    iste_rijeci[j++]=i;
                }
            }
        for (i=0; i<brojac[max]; i++)           /*izbacivanje rijeci prema njihovom polozaju u stringu*/
        {
            izbacivanje(g, iste_rijeci[i]-i+1);
        }
        return s;
        
}

int main() {
    
	/*char t[]="Ovo je neki bezvezni tekst";
    printf("'%s'", izbaci_najcescu(t));*/
    /*char t[]=" Koristio sam auto-stop da dodjem do znaka stop ali prije stopa sam otvorio dekstop kompjutera stop";
    printf("'%s'", izbaci_najcescu(t));*/
    char t[]="12345 ./,4 !@#%^ ";
    printf("'%s'", izbaci_najcescu(t));
	return 0;
}
