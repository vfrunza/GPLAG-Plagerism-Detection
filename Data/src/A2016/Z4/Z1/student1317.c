#include <stdio.h>

/* Vraca ukupan broj rijeci u stringu s, popunjava adrese rijeci
i broj slova svake rijeci */
int histogram(char* s, char** adr_rij, int* br_slo)
{
    int nije_slovo=1, broj_rij=0, i=0;

    while(*s!='\0')
    {
        if(!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')))
        {
            nije_slovo=1;
            br_slo[broj_rij]=0;
        }
        else if(nije_slovo==1)
        {
            nije_slovo=0;
            if(broj_rij==0)
            {
                (*adr_rij)=s;
                adr_rij++;
            }
            if(broj_rij>0) 
            {
                br_slo[broj_rij-1]=i;
                i=0;
                (*adr_rij)=s;
                adr_rij++;
            }
            broj_rij++;
        }
        if((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) i++;
        s++;
        if(*s=='\0')
        {
            br_slo[broj_rij-1]=i;
            i=0;
        }
    }
    return broj_rij;
}
/* Vraca broj pojavljivanja rijeci oznacene pokazivacem s2 u stringu na koji pokazuje s1 */
int broji_rijeci(char* s1, char* s2)
{
    int br_poj_r=0, pocetak=1;
    char* p=s1;
    char* q=s2;
    while(*s1!='\0')
    {
        while(!((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z'))) 
        {
            s1++;
            pocetak=0;
        }
        p=s1;
        q=s2;
        while(*p==*q || *p==*q+32 || *p+32==*q)
        {
            p++;
            q++;
            if(pocetak==1 && *q=='\0' && (!((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')) || *p=='\0'))
            {
                br_poj_r++;
                break;
            }
            if(pocetak==0 && *q=='\0' && (!((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')) || *p=='\0') && !((*(s1-1)>='A' && *(s1-1)<='Z') || (*(s1-1)>='a' && *(s1-1)<='z')))  
            {
                br_poj_r++;
                break;
            }
        }
        s1=p;
        if(*s1!='\0') 
        {
            s1++;
            pocetak=0;
        }
    }
    return br_poj_r;
}

void izbaci_rijec(char* s1, char* s2)
{
    while((*s1++=*s2++));
}
/* Funkcija trazi rijec na koju pokazuje pokazivac s2 u stringu na koji pokazuje s1,
vraca adresu sljedeceg znaka iza rijeci koju je nasao, ili NULL ako ne nadje rijec */
char* trazi_rijec(char* s1, char* s2)
{
    int pocetak=1;
    char* p=s1;
    char* q=s2;
   
    while(*s1!='\0')
    {
        while(!((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z'))) 
        {
            s1++;
            pocetak=0;
        }
        p=s1;
        q=s2;
        while(*p==*q || *p==*q+32 || *p+32==*q)
        {
            p++;
            q++;
            if(pocetak==0 && *q=='\0' && (!((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')) || *p=='\0') && !((*(s1-1)>='A' && *(s1-1)<='Z') || (*(s1-1)>='a' && *(s1-1)<='z')))  return p;
            if(pocetak==1 && *q=='\0' && (!((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')) || *p=='\0')) return p;
        }   
        s1++;
        pocetak=0;
    }
    return NULL;
}
/* Izbacuje svako pojavljivanje rijeci koja ima najveci broj pojavljivanja */
char* izbaci_najcescu(char* s)
{
    char* pok=s, *pom_pok=s, *pok_max=s;
    int uk_rijeci=0, i=0, j=0, maxim=0, brslov_max=0;
    int br_poj_rij[10000]={0};
    int br_slova[10000]={0};
    char* adr_rijec[10000]={NULL};
    char rijec[1000]="";
    char rij_max[1000]="";
    
    uk_rijeci=histogram(s, adr_rijec, br_slova);
    
    if(uk_rijeci==0) return pok;
    
    for(i=0; i<uk_rijeci; i++)
    {
        pom_pok=adr_rijec[i];
        for(j=0; j<br_slova[i]; j++)
        {
            rijec[j]=*pom_pok;
            pom_pok++;
        }
        rijec[j]='\0';
        br_poj_rij[i]=broji_rijeci(s, rijec);
    }
    /* Odredjivanje rijeci koja se najcesce pojavljuje */
    pok_max=adr_rijec[0];
    maxim=br_poj_rij[0];
    brslov_max=br_slova[0];
    for(i=1; i<uk_rijeci; i++)
    {
        if(br_poj_rij[i]>maxim)
        {
            pok_max=adr_rijec[i];
            maxim=br_poj_rij[i];
            brslov_max=br_slova[i];
        }
    }
    
    pom_pok=pok_max;
    for(j=0; j<brslov_max; j++)
    {
        rij_max[j]=*pom_pok;
        pom_pok++;
    }
    rij_max[j]='\0';
    
    izbaci_rijec(pok_max, pok_max+brslov_max);
    if(maxim>1)
    {
        for(i=1; i<maxim; i++)
        {
            pok_max=trazi_rijec(s, rij_max);
            if(pok_max!=NULL) izbaci_rijec(pok_max-brslov_max, pok_max);
        }
    }
    return pok;
}

int main() 
{
	char s[]="";
	printf("%s", izbaci_najcescu(s));
	return 0;
}
