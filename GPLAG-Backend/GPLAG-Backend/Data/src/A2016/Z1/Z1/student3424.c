#include <stdio.h> 

int main()
{
    float T1, T2, TP, TZ, TU, B1, B2, BP, BZ, BU, M1, M2, MP, MZ, MU, TB, BB, MB;
    int TO=0, BO=0, MO=0;                           /*TO-Tarikova ocjena, BO-Bojanova ocjena, MO-Mirzina ocjena*/
    
    printf("Unesite bodove za Tarika: \n");   /*T1-prva parc, T2-druga parc, TP-prisustvo, TZ-zadace, TU-zavrsni-usmeni*/
    printf("I parcijalni ispit: ");
    scanf("%f", &T1);
    if (T1<0.0f || T1>20.0f)
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("II parcijalni ispit: ");
    scanf("%f", &T2);
    if (T2<0.0f || T2>20.0f)
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Prisustvo: ");
    scanf("%f", &TP);
    if (TP<0.0f || TP>10.0f)
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Zadace: ");
    scanf("%f", &TZ);
    if (TZ<0.0f || TZ>10.0f)
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Zavrsni ispit: ");
    scanf("%f", &TU);
    if (TU<0.0f || TU>40.0f)
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    
    printf("Unesite bodove za Bojana: \n");   /*B1-prva parc, B2-druga parc, BP-prisustvo, BZ-zadace, BU-zavrsni-usmeni*/
    printf("I parcijalni ispit: ");
    scanf("%f", &B1);
    if (B1<0.0f || B1>20.0f)
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("II parcijalni ispit: ");
    scanf("%f", &B2);
    if (B2<0.0f || B2>20.0f)
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Prisustvo: ");
    scanf("%f", &BP);
    if (BP<0.0f || BP>10.0f)
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Zadace: ");
    scanf("%f", &BZ);
    if (BZ<0.0f || BZ>10.0f)
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Zavrsni ispit: ");
    scanf("%f", &BU);
    if (BU<0.0f || BU>40.0f)
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    
    printf("Unesite bodove za Mirzu: \n");   /*M1-prva parc, M2-druga parc, MP-prisustvo, MZ-zadace, MU-zavrsni-usmeni*/
    printf("I parcijalni ispit: ");
    scanf("%f", &M1);
    if (M1<0.0f || M1>20.0f)
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("II parcijalni ispit: ");
    scanf("%f", &M2);
    if (M2<0.0f || M2>20.0f)
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Prisustvo: ");
    scanf("%f", &MP);
    if (MP<0.0f || MP>10.0f)
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Zadace: ");
    scanf("%f", &MZ);
    if (MZ<0.0f || MZ>10.0f)
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Zavrsni ispit: ");
    scanf("%f", &MU);
    if (MU<0.0f || MU>40.0f)
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    
    TB=T1+T2+TP+TZ+TU;
    BB=B1+B2+BP+BZ+BU;
    MB=M1+M2+MP+MZ+MU;
    
    if (TB<50.0f && BB<50.0f && MB<50.0f)
    {
        printf("Nijedan student nije polozio.");
    }
    else if ((TB>=50.0f && BB<55.0f && MB<55.0f) || (TB<50.0f && BB>=55.0f && MB<55.0f) || (TB<50.0f && BB<55.0f && MB>=55.0f))
    {
        printf("Jedan student je polozio.");
    }
    else if ((TB>=55.0f && BB>=55.0f && MB<55.0f) || (TB>=55.0f && BB<55.0f && MB>=55.0f) || (TB<55.0f && BB>=55.0f && MB>=55.0f))
    {
       printf("Dva studenta su polozila."); 
    }
    else if(TB>=50.0f && BB>=55.0f && MB>=55.0f)
    {
        printf("Sva tri studenta su polozila.\n");
        
        if(TB>=50.0f && TB<65.0f)
        {
            TO=6;
        }
        else if (TB>=65.0f && TB<75.0f)
        {
            TO=7;
        }
        else if (TB>=75.0f && TB<85.0f)
        {
            TO=8;
        }
        else if (TB>=85.0f && TB<92.0f)
        {
            TO=9;
        }
        else if (TB>=92.0f && TB<=100.0f)
        {
            TO=10;
        }
        
        if(BB>=55.0f && BB<65.0f)
        {
            BO=6;
        }
        else if (BB>=65.0f && BB<75.0f)
        {
            BO=7;
        }
        else if (BB>=75.0f && BB<85.0f)
        {
            TO=8;
        }
        else if (BB>=85.0f && BB<92.0f)
        {
            BO=9;
        }
        else if (BB>=92.0f && BB<=100.0f)
        {
            BO=10;
        }
        
        if(MB>=55.0f && MB<65.0f)
        {
            MO=6;
        }
        else if (MB>=65.0f && MB<75.0f)
        {
            MO=7;
        }
        else if (MB>=75.0f && MB<85.0f)
        {
            MO=8;
        }
        else if (MB>=85.0f && MB<92.0f)
        {
            MO=9;
        }
        else if (MB>=92.0f && MB<=100.0f)
        {
            MO=10;
        }
        
        if (TO==BO && TO==MO && BO==MO)
        {
            printf("Sva tri studenta imaju istu ocjenu.");
        }
        else if ((TO==BO && BO!=MO) || (TO==MO && TO!=BO) || (BO==MO && TO!=BO))
        {
            printf("Dva od tri studenta imaju istu ocjenu.");
        }
        else if (TO!=BO && TO!=MO && BO!=MO)
        {
            printf("Svaki student ima razlicitu ocjenu.");
        }
        
        
    }
    
    
    return 0;
}