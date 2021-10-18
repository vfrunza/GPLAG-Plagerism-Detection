#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float p,d,r,z,i,p1,d1,r1,z1,i1,p2,d2,r2,z2,i2,bod,bod1,bod2;
    printf ("Unesite bodove za Tarika:\n");
    printf ("I parcijalni ispit: ");
    scanf ("%f", &p);
    if (p>20 || p<0)
    {
        printf ("Neispravan broj bodova");
        return 0;
    }
    printf ("II parcijalni ispit: ");
    scanf ("%f", &d);
    if (d>20 || d<0)
    {
        printf ("Neispravan broj bodova");
        return 0;
    }
    printf ("Prisustvo: ");
    scanf ("%f", &r);
    if (r>10 || r<0)
    {
        printf ("Neispravan broj bodova");
        return 0;
    }
    printf ("Zadace: ");
    scanf ("%f", &z);
    if (z>10 || z<0)
    {
        printf ("Neispravan broj bodova");
    }
    printf ("Zavrsni ispit: ");
    scanf ("%f", &i);
    if (i>40 || i<0)
    {
        printf ("Neispravan broj bodova");
        return 0;
    }

    printf ("Unesite bodove za Bojana:\n");
    printf ("I parcijalni ispit: ");
    scanf ("%f", &p1);
    if (p1>20 || p1<0)
    {
        printf ("Neispravan broj bodova");
        return 0;
    }
    printf ("II parcijalni ispit: ");
    scanf ("%f", &d1);
    if (d1>20 || d1<0)
    {
        printf ("Neispravan broj bodova");
        return 0;
    }
    printf ("Prisustvo: ");
    scanf ("%f", &r1);
    if (r1>10 || r1<0)
    {
        printf ("Neispravan broj bodova");
        return 0;
    }
    printf ("Zadace: ");
    scanf ("%f", &z1);
    if (z1>10 || z1<0)
    {
        printf ("Neispravan broj bodova");
        return 0;
    }
    printf ("Zavrsni ispit: ");
    scanf ("%f", &i1);
    if (i1>40 || i1<0)
    {
        printf ("Neispravan broj bodova");
        return 0;
    }


    printf ("Unesite bodove za Mirzu:\n");
    printf ("I parcijalni ispit: ");
    scanf ("%f", &p2);
    if (p2>20 || p2<0)
    {
        printf ("Neispravan broj bodova");
        return 0;
    }
    printf ("II parcijalni ispit: ");
    scanf ("%f", &d2);
    if (d2>20 || d2<0)
    {
        printf ("Neispravan broj bodova");
        return 0;
    }
    printf ("Prisustvo: ");
    scanf ("%f", &r2);
    if (r2>10 || r2<0)
    {
        printf ("Neispravan broj bodova");
        return 0;
    }
    printf ("Zadace: ");
    scanf ("%f", &z2);
    if (z2>10 || z2<0)
    {
        printf ("Neispravan broj bodova");
        return 0;
    }
    printf ("Zavrsni ispit: ");
    scanf ("%f", &i2);
    if (i2>40 || i2<0)
    {
        printf ("Neispravan broj bodova");
        return 0;
    }



    bod = p + d + r + z + i;
    bod1 = p1 + d2 + r1 + z1 + i1;
    bod2 = p2 + d2 + r2 + z2 + i2;

     if (bod < 55 && bod1 < 55 && bod2 < 55)
    {
        printf ("Nijedan student nije polozio.");
    }

     if (bod >= 55 && bod1 >=55 && bod2 >= 55)
        printf ("Sva tri studenta su polozila.");

     if ((bod >= 55 && bod1 < 55 && bod2 < 55) || (bod < 55 && bod1 >= 55 && bod2 < 55) || (bod < 55 && bod1 < 55 && bod2 >= 55))
    {
        printf ("Jedan student je polozio.");
    }
    if ((bod >= 55 && bod1 >= 55 && bod2 < 55) || (bod >= 55 && bod1 < 55 && bod2 >= 55)
        || (bod < 55 && bod1 >= 55 && bod2 >= 55))
    {

        printf ("Dva studenta su polozila.");
    }

    if ((bod >=55 && bod < 65) && (bod1>= 55 && bod < 65) && (bod2 >=55 && bod2 < 65))
    {
        printf ("\nSva tri studenta imaju istu ocjenu.");
    }
    if ((bod >=55 && bod < 65) && (bod1>= 55 && bod < 65) && (bod2 >=55 && bod2 > 65) ||
        (bod >=55 && bod > 65) && (bod1>= 55 && bod < 65) && (bod2 >=55 && bod2 < 65) ||
        (bod >=55 && bod < 65) && (bod1>= 55 && bod > 65) && (bod2 >=55 && bod2 < 65))
    {
        printf ("\nDva od tri studenta imaju istu ocjenu.");
    }


    if ((bod >=65 && bod < 75) && (bod1>= 65 && bod < 75) && (bod2 >=65 && bod2 < 75))
    {
        printf ("\nSva tri studenta imaju istu ocjenu.");
    }
    if ((bod >=65 && bod < 75) && (bod1>= 65 && bod < 75) && (bod2 <=65 && bod2 > 75) ||
        (bod >=65 && bod > 75) && (bod1 <= 65 && bod < 75) && (bod2 >=65 && bod2 < 75) ||
        (bod <=65 && bod < 75) && (bod1>= 65 && bod > 75) && (bod2 >=65 && bod2 < 75))
    {
        printf ("\nDva od tri studenta imaju istu ocjenu.");
    }
    if ((bod >=75 && bod < 85) && (bod1>= 75 && bod < 85) && (bod2 >=75 && bod2 < 85))
    {
        printf ("\nSva tri studenta imaju istu ocjenu.");
    }
    if ((bod >=75 && bod < 85) && (bod1>= 75 && bod < 85) && (bod2 <=75 && bod2 > 85) ||
        (bod >=75 && bod > 85) && (bod1 <= 75 && bod < 85) && (bod2 >=75 && bod2 < 85) ||
        (bod <=75 && bod < 85) && (bod1>= 75 && bod > 85) && (bod2 >=75 && bod2 < 85))
    {
        printf ("\nDva od tri studenta imaju istu ocjenu.");
    }
    if ((bod >=85 && bod < 92) && (bod1>= 85 && bod < 92) && (bod2 >=85 && bod2 < 92))
    {
        printf ("\nSva tri studenta imaju istu ocjenu.");
    }
    if ((bod >=85 && bod < 92) && (bod1>= 85 && bod < 92) && (bod2 <=85 && bod2 > 92) ||
        (bod >=85 && bod > 92) && (bod1<= 85 && bod < 92) && (bod2 >=85 && bod2 < 92) ||
        (bod <=85 && bod < 92) && (bod1>= 85 && bod > 92) && (bod2 >=85 && bod2 < 92))
    {
        printf ("\nDva od tri studenta imaju istu ocjenu.");
    }

    if ((bod >=92 && bod < 100) && (bod1>= 92 && bod < 100) && (bod2 >=92 && bod2 < 100))
    {
        printf ("\nSva tri studenta imaju istu ocjenu.");
    }
    if ((bod >=92 && bod < 100) && (bod1>= 92 && bod < 100) && (bod2 <=92 ) ||
        (bod >=92 && bod > 100) && (bod1<= 92) && (bod2 >=92 && bod2 < 100) ||
        (bod <=92) && (bod1>= 92 && bod > 100) && (bod2 >=92 || bod2 < 100))
    {
        printf ("\nDva od tri studenta imaju istu ocjenu.");
    }



    return 0;


}

