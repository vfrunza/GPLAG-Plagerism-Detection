#include <stdio.h>
#include <stdlib.h>

int main()
{
    char znak;
    int c = 0, b = 0, s = 0, v = 0, p = 0, boja = 0, prvaB;
    double procenat = 0;
    printf ("Unesite vozila: ");
    do
    {
        scanf ("%c", &znak);
        if (znak == 'c' || znak == 'C')
        {
            c++;
            if (boja == 0)
            {
                prvaB = 0;
                boja++;
            }
        }
        else if (znak == 'b' || znak == 'B')
        {
            b++;
            if (boja == 0)
            {
                prvaB = 1;
                boja++;
            }
        }
        else if (znak == 's' || znak == 'S')
        {
            s++;
            if (boja == 0)
            {
                prvaB = 2;
                boja++;
            }
        }
        else if (znak == 'v' || znak == 'V')
        {
            v++;
            if (boja == 0)
            {
                prvaB = 3;
                boja++;
            }
        }
        else if (znak == 'p' || znak == 'P')
        {
            p++;
            if (boja == 0)
            {
                prvaB = 4;
                boja++;
            }
        }
        else if (znak != 'K' && znak != 'k') printf ("Neispravan unos\n");
    } while (znak != 'K' && znak != 'k');
    boja = 0;
    printf ("Ukupno evidentirano %d vozila.\n", c+b+s+v+p);
    if ((float)c/(c+b+s+v+p) >= procenat)procenat = (float)c/(c+b+s+v+p)*100;
    if ((float)b/(c+b+s+v+p)*100 > procenat || ((float)b/(c+b+s+v+p)*100 == procenat && prvaB == 1))
    {
        procenat = (float)b/(c+b+s+v+p)*100;
        boja = 1;
    }
    if ((float)s/(c+b+s+v+p)*100 > procenat || ((float)s/(c+b+s+v+p)*100 == procenat && prvaB == 2))
    {
        procenat = (float)s/(c+b+s+v+p)*100;
        boja = 2;
    }
    if ((float)v/(c+b+s+v+p)*100 > procenat || ((float)v/(c+b+s+v+p)*100 == procenat && prvaB == 3))
    {
        procenat = (float)v/(c+b+s+v+p)*100;
        boja = 3;
    }
    if ((float)p/(c+b+s+v+p)*100 > procenat || ((float)p/(c+b+s+v+p)*100 == procenat && prvaB == 4))
    {
        procenat = (float)p/(c+b+s+v+p)*100;
        boja = 4;
    }
    if (boja == 0) printf ("Najpopularnija boja je crna (%.2f%c).", procenat, '%');
    if (boja == 1) printf ("Najpopularnija boja je bijela (%.2f%c).", procenat, '%');
    if (boja == 2) printf ("Najpopularnija boja je siva (%.2f%c).", procenat, '%');
    if (boja == 3) printf ("Najpopularnija boja je crvena (%.2f%c).", procenat, '%');
    if (boja == 4) printf ("Najpopularnija boja je plava (%.2f%c).", procenat, '%');
    return 0;
}
