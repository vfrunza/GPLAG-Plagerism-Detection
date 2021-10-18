#include <stdio.h>
#include <stdlib.h>

struct Najduzi
{
    char* ind;
    int duzina;
};

void najduzi_bp(char* s1, char* s2)
{
    char pomocna[100];
    int vel = 0;
    int i;
    int daLiSePonavlja=0;
    struct Najduzi temp;
    temp.duzina=0;

    while(*s1 != '\0')
    {
        while(*s1 == ' ') s1++;
        while(*s1 >= 'a' && *s1 <= 'z' || *s1 >= 'A' && *s1 <= 'Z')
        {
            for(i=0; i<vel; i++)
                if(pomocna[i] == *s1 || pomocna[i] == (*s1 - ('a'-'A')))
                    daLiSePonavlja = 1;

            if(daLiSePonavlja == 0)
            {
                if(*s1>='a')
                    pomocna[vel] = *s1;
                else
                    pomocna[vel] = *s1 + 'a' - 'A';
                vel++;
            }
            if(daLiSePonavlja == 1 || *(s1+1)<'A' || *(s1+1)>'z' || (*(s1+1)>'Z' && *(s1+1)<'a'))
            {
                if(vel>temp.duzina)
                {
                    temp.duzina=vel;
                    temp.ind = s1-vel;
                }
                vel=0;
                daLiSePonavlja=0;
            }
            s1++;
        }
    }

    for(i=0; i<temp.duzina; i++)
    {
        *s2=*(temp.ind);
        s2++; temp.ind++;
    }
    *s2='\0';
}

int main()
{
    char* s1 ;
    char s2[7];
    najduzi_bp(s1,s2);
    printf("%s", s2);
    return 0;
}