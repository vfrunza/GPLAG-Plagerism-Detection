#include <stdio.h>
#include <stdlib.h>

void Funkcija(char *s)
{
    int br = 0;
    int b = 0;
    int max = 0;
    char *p = s;
    char *pr, *kr, *pi, *ki;
    char *ci;
    while(*s != '\0')
    {
        if((tolower (*p) >= 'a' && tolower (*p) <= 'z') && (p == s) || *(p - 1) == ' ')
            pr = p;
        while(tolower(*p) >= 'a' && tolower (*p) <= 'z')
            p++;
        if(*p == ' ' || *p == '\0')
        {
            kr = p;
            if(max < (kr - pr))
            {
                max = kr - pr;
                pi = pr;
                ki = kr;
            }
        }
        else p++;
    }
    ci = pi;
    while(ci != ki)
    {
        printf("%c", *ci);
        ci++;
    }

}
int main()
{
    char s[100] = {"Otorinolaringologija je garant najduza."};
    Funkcija(s);
    return 0;
}
