#include <stdio.h>

int main()
{
    float bod, ta, bo, mi, prolaz, p;
    int ocjt, ocjb, ocjm;
    
    p=-0.0001;
    ta=bo=mi=prolaz=0;
    
    printf("Unesite bodove za Tarika:\nI parcijalni ispit: ");
    scanf("%f",&bod);
    if(bod<0 || bod>20)
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    ta+=bod;
    printf("II parcijalni ispit: ");
    scanf("%f",&bod);
    if(bod<0 || bod>20)
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    ta+=bod;
    printf("Prisustvo: ");
    scanf("%f",&bod);
    if(bod<0 || bod>10)
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    ta+=bod;
    printf("Zadace: ");
    scanf("%f",&bod);
    if(bod<0 || bod>10)
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    ta+=bod;
    printf("Zavrsni ispit: ");
    scanf("%f",&bod);
    if(bod<0 || bod>40)
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    ta+=bod;
    
    printf("Unesite bodove za Bojana:\nI parcijalni ispit: ");
    scanf("%f",&bod);
    if(bod<0 || bod>20)
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    bo+=bod;
    printf("II parcijalni ispit: ");
    scanf("%f",&bod);
    if(bod<0 || bod>20)
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    bo+=bod;
    printf("Prisustvo: ");
    scanf("%f",&bod);
    if(bod<0 || bod>10)
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    bo+=bod;
    printf("Zadace: ");
    scanf("%f",&bod);
    if(bod<0 || bod>10)
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    bo+=bod;
    printf("Zavrsni ispit: ");
    scanf("%f",&bod);
    if(bod<0 || bod>40)
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    bo+=bod;
    
    printf("Unesite bodove za Mirzu:\nI parcijalni ispit: ");
    scanf("%f",&bod);
    if(bod<0 || bod>20)
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    mi+=bod;
    printf("II parcijalni ispit: ");
    scanf("%f",&bod);
    if(bod<0 || bod>20)
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    mi+=bod;
    printf("Prisustvo: ");
    scanf("%f",&bod);
    if(bod<0 || bod>10)
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    mi+=bod;
    printf("Zadace: ");
    scanf("%f",&bod);
    if(bod<0 || bod>10)
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    mi+=bod;
    printf("Zavrsni ispit: ");
    scanf("%f",&bod);
    if(bod<0 || bod>40)
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    mi+=bod;
    
    /*OCJENA TARIK*/
    
    if(ta-55<p)
    {
        ocjt=0;
    }
    else if(ta<65)
    {
        ocjt=1;
    }
    else if(ta<75)
    {
        ocjt=3;
    }
    else if(ta<85)
    {
        ocjt=4;
    }
    else if(ta<92)
    {
        ocjt=5;
    }
    
    /*OCJENA BOJAN*/
    
    if(bo-55<p)
    {
        ocjb=0;
    }
    else if(bo<65)
    {
        ocjb=1;
    }
    else if(bo<75)
    {
        ocjb=3;
    }
    else if(bo<85)
    {
        ocjb=4;
    }
    else if(bo<92)
    {
        ocjb=5;
    }
    
    /*OCJENA MIRZA*/
    
    if(mi-55<p)
    {
        ocjm=0;
    }
    else if(mi<65)
    {
        ocjm=1;
    }
    else if(mi<75)
    {
        ocjm=3;
    }
    else if(mi<85)
    {
        ocjm=4;
    }
    else if(mi<92)
    {
        ocjm=5;
    }
    
    prolaz=0;
    if(ocjt>0)
    {
        prolaz+=1;
    }
    if(ocjb>0)
    {
        prolaz+=1;
    }
    if(ocjm>0)
    {
        prolaz+=1;
    }
    
    if(prolaz==0)
    {
        printf("Nijedan student nije polozio.\n");
    }
    if(prolaz==1)
    {
        printf("Jedan student je polozio.\n");
    }
    if(prolaz==2)
    {
        printf("Dva studenta su polozila.\n");
    }
    if(prolaz==3)
    {
        printf("Sva tri studenta su polozila.\n");
    }
    
    if(prolaz==3)
    {
        if(ocjt==ocjb)
        {
            if(ocjt==ocjm)
            {
            printf("Sva tri studenta imaju istu ocjenu.");
        }
        else
        {
            printf("Dva od tri studenta imaju istu ocjenu.");
        }
        }
        else if(ocjt==ocjm || ocjb==ocjm)
        {
            printf("Dva od tri studenta imaju istu ocjenu.");
        }
        else
        {
            printf("Svaki student ima razlicitu ocjenu.");
        }
    }
return 0;
}