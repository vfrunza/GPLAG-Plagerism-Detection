#include <stdio.h>

void unesi (char niz[], int velicina)
{
    char znak = getchar();
    if (znak == '\n') znak = getchar();
    int i = 0;
    while (i < velicina -1 && znak != '\n')
    {
        niz[i] = znak;
        znak = getchar();
        i++;
    }
    niz[i] = '\0';
}

int duzina (char *s)
{
    int brojac = 0;
    while (*s != '\0')
    {
        brojac++;
        s++;
    }
    return brojac;
}

int broj_rijeci (char *s)
{
    int brojac = 0;
    while (*s != '\0')
    {
        if ((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z')) 
        {
            while ((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z')) s++;
            brojac++;
            s--;
        }
        s++;
    }
    /*nt rijeci = 0, razmak = 1;
    while (*s != '\0')
    {
        if (*s == ' ') razmak = 1;
        else  if (razmak == 1)
        {
            razmak = 0;
            rijeci++;
        }
        s++;
    }
    return rijeci;*/
    return brojac;
}

//II nacin da se broje rijeci:
int broj_rijeci2(char *poc, char *kraj)
{
    int brojac = 0;
    while (poc < kraj)
    {
        brojac++;
        poc++;
    }
    return brojac;
}

int provjeri_duzine (char *s, int niz[], int broj)
{
    int broj2 = broj_rijeci(s), test = 1, brojac = 0, slova;
    char *p, *q;
    if (broj == broj2)
    {
        while (*s != '\0')
        {
            if ((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z')) 
            {
                p = s;
                while ((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z')) s++;
                q = s;
                
                s--;
                
                slova  = broj_rijeci2(p,q);
                if (niz[brojac] != slova) test = 0;
                
                brojac++;
            }
            s++;
        }
    }
    else test = 0;
    return test;
}

int main() 
{
    
	return 0;
}