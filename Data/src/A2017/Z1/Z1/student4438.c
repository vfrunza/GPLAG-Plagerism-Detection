#include <stdio.h>
#define HAMBURGER_RESTORAN 3.30
#define PIZZA_RESTORAN 6.80
#define CEVAPI_RESTORAN 5.00
#define HAMBURGER_FAST 3.00
#define PIZZA_FAST 8.00
#define CEVAPI_FAST 3.90
#define HAMBURGER_BISTRO 5.00
#define PIZZA_BISTRO 5.30
#define CEVAPI_BISTRO 6.00
int main()
{
    char tarik,bojan,mirza,novi_red;
    float cijena,restoran,fast,bistro,prvi,drugi,treci,prvi1,drugi1,treci1,prvi2,drugi2,treci2;
    printf("Unesite jelo za Tarika: ");
    scanf("%c",&tarik);
    scanf("%c",&novi_red);
    printf("Unesite jelo za Bojana: ");
    scanf("%c",&bojan);
    scanf("%c",&novi_red);
    printf("Unesite jelo za Mirzu: ");
    scanf("%c",&mirza);
    scanf("%c",&novi_red);
    
    switch(tarik)
    {
        case 'H':
        prvi=HAMBURGER_RESTORAN;
        drugi=HAMBURGER_FAST;
        treci=HAMBURGER_BISTRO;
        break;
        
        case 'P':
        prvi=PIZZA_RESTORAN;
        drugi=PIZZA_FAST;
        treci=PIZZA_BISTRO;
        break;
        
        case 'C':
        prvi=CEVAPI_RESTORAN;
        drugi=CEVAPI_FAST;
        treci=CEVAPI_BISTRO;
        break;
        default:
        printf("Greska.");
    }
    
    switch(bojan)
    {
        case 'H':
        prvi1=HAMBURGER_RESTORAN;
        drugi1=HAMBURGER_FAST;
        treci1=HAMBURGER_BISTRO;
        break;
        
        case 'P':
        prvi1=PIZZA_RESTORAN;
        drugi1=PIZZA_FAST;
        treci1=PIZZA_BISTRO;
        break;
        
        case'C':
        prvi1=CEVAPI_RESTORAN;
        drugi1=CEVAPI_FAST;
        treci1=CEVAPI_BISTRO;
        break;
        default:
        printf("Greska");
        
    }
    
    switch(mirza)
    {
        case 'H':
        prvi2=HAMBURGER_RESTORAN;
        drugi2=HAMBURGER_FAST;
        treci2=HAMBURGER_BISTRO;
        break;
        
        case 'P':
        prvi2=PIZZA_RESTORAN;
        drugi2=PIZZA_FAST;
        treci2=PIZZA_BISTRO;
        break;
        
        case 'C':
        prvi2=CEVAPI_RESTORAN;
        drugi2=CEVAPI_FAST;
        treci2=CEVAPI_BISTRO;
        break;
        default:
        printf("Greska");
    }
    
    restoran=(prvi+prvi1+prvi2);
    fast=(drugi+drugi1+drugi2);
    bistro=(treci+treci1+treci2);
    
    if((restoran<fast) && (restoran<bistro))
    {
        printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",restoran);
    }
    if((fast<restoran) && (fast<bistro))
    {
        printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",fast);
        if((prvi==prvi1) && (prvi1==prvi2))
        {
            cijena=restoran-restoran*0.1;
            if(cijena<fast)
            {
                printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",cijena);
            }
        }
        if((prvi>prvi1) && (prvi>prvi2))
        {
            cijena=(prvi-prvi*0.1)+prvi1+prvi2;
            if(cijena<fast)
            {
                printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",cijena);
            }
        }
        if((prvi2>prvi) && (prvi2>prvi1))
        {
            cijena=prvi+prvi1+(prvi2-prvi2*0.1);
            if(cijena<fast)
            {
                printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",cijena);
            }
        }
        if((prvi==prvi1)&& (prvi1!=prvi2))
        {
            cijena=(prvi-prvi*0.1)+(prvi1-prvi1*0.1)+prvi2;
            if(cijena<fast)
            {
                printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",cijena);
            }
        }
        
    }
    if((bistro<restoran) && (bistro<fast))
    {
        printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",bistro);
        if((prvi==prvi1) && (prvi1==prvi2))
        {
            cijena=restoran-restoran*0.1;
            if(cijena<bistro)
            {
                printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",cijena);
            }
        }
        if((prvi>prvi1) && (prvi>prvi2))
        {
            cijena=(prvi-prvi*0.1)+prvi1+prvi2;
            if(cijena<bistro)
            {
                printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",cijena);
            }
        }
        if((prvi2>prvi) && (prvi2>prvi1))
        {
            cijena=prvi+prvi1+(prvi2-prvi2*0.1);
            if(cijena<bistro)
            {
                printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",cijena);
            }
        }
        if((prvi==prvi1) && (prvi1!=prvi2))
        {
            cijena=(prvi-prvi*0.1)+(prvi2-prvi2*0.1)+prvi;
            if(cijena<bistro)
            {
                printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",cijena);
            }
        }
        if((prvi1==prvi2) && (prvi!=prvi2))
        {
            cijena=(prvi1-prvi1*0.1)+(prvi2-prvi2*0.1)+prvi;
            if(cijena<bistro)
            {
                printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",cijena);
            }
        }
    };
   return 0; 
    
}