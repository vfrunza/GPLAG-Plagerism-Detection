#include <stdio.h>
int provjeri(const char *tekst)
{
    char string[1000];
    const char *p=tekst;
    char *s=string,*p1=string,*p2=string,*poz1=string,*poz2=string;
    while(*p!='\0')
    {
        *s=*p;
        s++;
        p++;
    }
    *s=*p;
    s=string;
    while(*s!='\0')
    {
        while(*s!='<' && *s!='\0')  s++;
        if(*s=='\0')    return 1;
        poz1=s;
        s++;
        p1=s;
        while(*s!='>' && *s!=' ' && *s!='\0')   s++;
        if(*s=='\0')    return 0;
        p2=s;
        while(*s!='>' && *s!='\0')  s++;
        if(*s=='\0')    return 0;
        while(*s!='<' && *s!='\0')  s++;
        if(*s=='\0')    return 0;
        s++;
        if(*s=='/')
        {
            s++;
            while(p1!=p2)
            {
                if(*p1>='a' && *p1<='z')
                {
                    *p1=*p1-32;
                }
                if(*s>='a' && *s<='z')
                {
                    *s=*s-32;
                }
                if(*p1!=*s)     return 0;
                p1++;
                s++;
            }
            if(*s=='>') 
            {
                s++;
                poz2=s;
                while(poz1!=poz2)
                {
                    *poz1=' ';
                    poz1++;
                }
                s=string;
            }
            else    return 0;
        }
        else if((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))
        {
            s--;
            
        }
        else return 0;
        s++;
        s--;
    }
    return 1;
}
int main() {
    printf ("Provjera  9: %d\n", provjeri("<p   >i ovo je validno, razmaci NAKON p</p    >"));
	printf ("Provjera 10: %d\n", provjeri("<></>")); /* nije validno */
	return 0;
}
