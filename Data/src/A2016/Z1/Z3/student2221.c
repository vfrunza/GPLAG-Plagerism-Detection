#include <stdio.h>

int main ()
{
    int c=0, b=0, s=0, v=0, p=0, najveciBroj=0;    
    char m = ' ', znakPrve = ' ', znakDruge = ' ', znakTrece = ' ', znakCetvrte = ' ', znakPete = ' ';
    printf ("Unesite vozila: ");
    
    for (;;)
    {
        scanf ("%c", &m);
        if (m == 'C' || m == 'c')
        {
            c = c + 1;
            if (znakPrve == ' ')
                znakPrve = 'c';
            else if (znakDruge == ' ' && znakPrve != 'c')
                znakDruge = 'c';
            else if (znakTrece == ' ' && znakDruge != 'c' && znakPrve != 'c')
                znakTrece = 'c';
            else if (znakCetvrte == ' ' && znakTrece != 'c' && znakDruge != 'c' && znakPrve != 'c')
                znakCetvrte = 'c';
            else if (znakPete == ' ' && znakCetvrte != 'c' && znakTrece != 'c' && znakDruge != 'c' && znakPrve != 'c')
                znakPete = 'c';
            
            if (c > najveciBroj)
                najveciBroj = c;
            
        }
        else if (m == 'B' || m == 'b')
        {
            b = b + 1;
            if (znakPrve == ' ')
                znakPrve = 'b';
            else if (znakDruge == ' ' && znakPrve != 'b')
                znakDruge = 'b';
            else if (znakTrece == ' ' && znakDruge != 'b' && znakPrve != 'b')
                znakTrece = 'b';
            else if (znakCetvrte == ' ' && znakTrece != 'b' && znakDruge != 'b' && znakPrve != 'b')
                znakCetvrte = 'b';
            else if (znakPete == ' ' && znakCetvrte != 'b' && znakTrece != 'b' && znakDruge != 'b' && znakPrve != 'b')
                znakPete = 'b';
            
            if (b > najveciBroj)
                najveciBroj = b;
            
        }
        else if (m == 'S' || m == 's')
        {
            s = s + 1;
            if (znakPrve == ' ')
                znakPrve = 's';
            else if (znakDruge == ' ' && znakPrve != 's')
                znakDruge = 's';
            else if (znakTrece == ' ' && znakDruge != 's' && znakPrve != 's')
                znakTrece = 's'; 
            else if (znakCetvrte == ' ' && znakTrece != 's' && znakDruge != 's' && znakPrve != 's')
                znakCetvrte = 's';
            else if (znakPete == ' ' && znakCetvrte != 's' && znakTrece != 's' && znakDruge != 's' && znakPrve != 's')
                znakPete = 's';
            
            if (s > najveciBroj)
                najveciBroj = s;
            
        }
        else if (m == 'V' || m == 'v')
        {
            v = v + 1;
            if (znakPrve == ' ')
                znakPrve = 'v';
            else if (znakDruge == ' ' && znakPrve != 'v')
                znakDruge = 'v'; 
            else if (znakTrece == ' ' && znakDruge != 'v' && znakPrve != 'v')
                znakTrece = 'v';
            else if (znakCetvrte == ' '  && znakTrece != 'v' && znakDruge != 'v' && znakPrve != 'v')
                znakCetvrte = 'v';
            else if (znakPete == ' ' && znakCetvrte != 'v' && znakTrece != 'v' && znakDruge != 'v' && znakPrve != 'v')
                znakPete = 'v';
            
            if (v > najveciBroj)
                najveciBroj = v;
            
        }
        else if (m == 'P' || m == 'p')
        {
            p = p + 1;
            if (znakPrve == ' ')
                znakPrve = 'p';
            else if (znakDruge == ' ' && znakPrve != 'p')
                znakDruge = 'p';
            else if (znakTrece == ' ' && znakDruge != 'p' && znakPrve != 'p')
                znakTrece = 'p';
            else if (znakCetvrte == ' ' && znakTrece != 'p' && znakDruge != 'p' && znakPrve != 'p')
                znakCetvrte = 'p';
            else if (znakPete == ' ' && znakCetvrte != 'p' && znakTrece != 'p' && znakDruge != 'p' && znakPrve != 'p')
                znakPete = 'p';
            
            if (p > najveciBroj)
                najveciBroj = p;
            
            
        }
        else if (m == 'K' || m == 'k')
        {
            break;
        }
        else {
            printf ("Neispravan unos\n");
        }
    }

    int ukupno = c + b + s + v + p;
    char postotak = '%';
    printf ("Ukupno evidentirano %i vozila.\n", ukupno);
    printf ("Najpopularnija boja je " );
    if(ukupno == 0){
        printf("crna (0.00%c).", postotak);
        return 0;
    }
    
    if (znakPrve == 'c' && c == najveciBroj)
    {
        float k = (float)c/ukupno;
        k = k * 100;
        printf ("crna (%.2f%c).\n", k, postotak);
    }
    else if  (znakPrve == 'b' && b == najveciBroj)
    {
        float k = (float)b/ukupno;
        k = k * 100;
        printf ("bijela (%.2f%c).\n", k, postotak);
    }
    else if (znakPrve == 's' && s == najveciBroj)
    {
        float k = (float)s/ukupno;
        k = k * 100;
        printf ("siva (%.2f%c).\n", k, postotak);
    }
    else if (znakPrve == 'v' && v == najveciBroj)
    {
        float k = (float)v/ukupno;
        k = k * 100;
        printf ("crvena (%.2f%c).\n", k, postotak);
    }
    else if (znakPrve == 'p' && p == najveciBroj)
    {
        float k = (float)p/ukupno;
        k = k * 100;
        printf ("plava (%.2f%c).\n", k, postotak);
    }
    else if (znakDruge == 'c' && c == najveciBroj)
    {
        float k = (float)c/ukupno;
        k = k * 100;
        printf ("crna (%.2f%c).\n", k, postotak);
    }
    else if (znakDruge == 'b' && b == najveciBroj)
    {
        float k = (float)b/ukupno;
        k = k * 100;
        printf ("bijela (%.2f%c).\n", k, postotak);
    }
    else if (znakDruge == 's' && s == najveciBroj)
    {
        float k = (float)s/ukupno;
        k = k * 100;
    printf ("siva (%.2f%c).\n", k, postotak);
    }
    else if (znakDruge == 'v' && v == najveciBroj)
    {
        float k = (float)v/ukupno;
        k = k * 100;
        printf ("crvena (%.2f%c).\n", k, postotak);
    }
    else if (znakDruge == 'p' && p == najveciBroj)
    {
        float k = (float)p/ukupno;
        k = k * 100;
        printf ("plava (%.2f%c).\n", k, postotak);
    }
    else if (znakTrece == 'c' && c == najveciBroj)
    {
        float k = (float)c/ukupno;
        k = k * 100;
        printf ("crna (%.2f%c).\n", k, postotak);
    }
    else if (znakTrece == 'b' && b == najveciBroj)
    {
        float k = (float)b/ukupno;
        k = k * 100;
        printf ("bijela (%.2f%c).\n", k, postotak);
    }
    else if (znakTrece == 's' && s == najveciBroj)
    {
        float k = (float)s/ukupno;
        k = k * 100;
        printf ("siva (%.2f%c).\n", k, postotak);
    }
    else if (znakTrece == 'v' && v == najveciBroj)
    {
        float k = (float)v/ukupno;
        k = k * 100;
        printf ("crvena (%.2f%c).\n", k, postotak);
    }
    else if (znakTrece == 'p' && p == najveciBroj)
    {
        float k = (float)p/ukupno;
        k = k * 100;
        printf ("plava (%.2f%c).\n", k, postotak);
    }
    else if (znakCetvrte == 'c' && c == najveciBroj)
    {
        float k = (float)c/ukupno;
        k = k * 100;
        printf ("crna (%.2f%c).\n", k, postotak);
    }
    else if (znakCetvrte == 'b' && b == najveciBroj)
    {
        float k = (float)b/ukupno;
        k = k * 100;
        printf ("bijela (%.2f%c).\n", k, postotak);
    }
    else if (znakCetvrte == 's' && s == najveciBroj)
    {
        float k = (float)s/ukupno;
        k = k * 100;
        printf ("siva (%.2f%c).\n", k, postotak);
    }
    else if (znakCetvrte == 'v' && v == najveciBroj)
    {
        float k = (float)v/ukupno;
        k = k * 100;
        printf ("crvena (%.2f%c).\n", k, postotak);
    }
    else if (znakCetvrte == 'p' && p == najveciBroj)
    {
        float k = (float)p/ukupno;
        k = k * 100;
        printf ("plava (%.2f%c).\n", k, postotak);
    }
    else if (znakPete == 'c' && c == najveciBroj)
    {
        float k = (float)c/ukupno;
        k = k * 100;
        printf ("crna (%.2f%c).\n", k, postotak);
    }
    else if (znakPete == 'b' && b == najveciBroj)
    {
        float k = (float)b/ukupno;
        k = k * 100;
        printf ("bijela (%.2f%c).\n", k, postotak);
    }
    else if (znakPete == 's' && s == najveciBroj)
    {
        float k = (float)s/ukupno;
        k = k * 100;
        printf ("siva (%.2f%c).\n", k, postotak);
    }
    else if (znakPete == 'v' && v == najveciBroj)
    {
        float k = (float)v/ukupno;
        k = k * 100;
        printf ("crvena (%.2f%c).\n", k, postotak);
    }
    else if (znakPete == 'p' && p == najveciBroj)
    {
        float k = (float)p/ukupno;
        k = k * 100;
        printf ("plava (%.2f%c).\n", k, postotak);
    }
    
    return 0;
}