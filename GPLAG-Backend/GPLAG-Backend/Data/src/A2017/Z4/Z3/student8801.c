#include <stdio.h>
void najduzi_bp(char* s1, char* s2)
{

while(*s1!='\0')
{

    if(!((*s1>='A'&& *s1<='Z') || (*s1>='A'&& *s1<='Z')) {
    while(!((*s1>='A'&& *s1<='Z') || (*s1>='A'&& *s1<='Z')) && *s1!='\0')
                s1++;
                
    }

else {

    int duzina_max=0;
    char* pretraga=s1+1;
    char* kraj=s1+1;
    char temp=*s1;
    if(*s1>='A' && *s1<='Z')
            temp=temp+('a'-'A');
        while(*kraj!=temp && *kraj!=' ' && *kraj!='\0')
            kraj++;
        int duzina=kraj-s1;
        if(duzina>duzina_max)
            *s2++=*s1;
        while(*pretraga!=temp && *pretraga!=' ' && *pretraga!='\0' && duzina>duzina_max)
            *s2++=*pretraga++;
        if(duzina>duzina_max)
           { duzina_max=duzina;
        s2=s2-duzina_max;
               
           }
s1++;
    
}





}




