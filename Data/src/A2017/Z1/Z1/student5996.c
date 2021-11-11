#include <stdio.h>
int main ()
{
//*CIJENE RESTORAN*//
    float pizzaR=6.8, hambR=3.3, cevR=5;
//*CIJENE TROVAC*//
    float pizzaT=8, hambT=3, cevT=3.9;
//*CIJENE LORELEI*//
    float pizzaL=5.3, hambL=5, cevL=6;
//*IZBORI ZA MOMKE*//
    char izbor1, izbor2, izbor3;
//*SUME NA SVA TRI MJESTA*//
    float sumaR=0, sumaT=0, sumaL=0;
    float min; //NAJMANJA CIJENA
    float popust= 0;
    printf ("Unesite jelo za Tarika: ");
    do {
        scanf("%c", &izbor1);

    } while (izbor1!='P' && izbor1!='H' && izbor1!='C'); //do-while petlja da ogranicimo korisnika da ne smije unjeti nista osim predefinisanih vrijednosti
    if(izbor1 == 'H') {
        sumaR+=hambR;
        sumaL+=hambL;
        sumaT+=hambT;
    }
    if (izbor1=='P') {
        sumaR+=pizzaR;
        sumaL+=pizzaL;
        sumaT+=pizzaT;

    }
    if (izbor1 == 'C') {
        sumaR+=cevR;
        sumaL+=cevL;
        sumaT+=cevT;

    }
    printf("Unesite jelo za Bojana: ");
    do {
        scanf("%c", &izbor2);
        
    } while (izbor2!='P' && izbor2!='H' && izbor2!='C');
    if (izbor2 == 'H') {
        sumaR+=hambR;
        sumaL+=hambL;
        sumaT+=hambT;

    }
    if (izbor2 == 'P') {
        sumaR+=pizzaR;
        sumaL+=pizzaL;
        sumaT+=pizzaT;
    }
    if (izbor2 == 'C') {
        sumaR+=cevR;
        sumaL+=cevL;
        sumaT+=cevT;

    }
    printf("Unesite jelo za Mirzu: ");
    do {
        scanf("%c", &izbor3);

    } while (izbor3!='P' && izbor3!='H' && izbor3!='C');
    if (izbor3 == 'H') {
        sumaR+=hambR;
        sumaL+=hambL;
        sumaT+=hambT;
    }
    if (izbor3 == 'P') {
        sumaR+=pizzaR;
        sumaL+=pizzaL;
        sumaT+=pizzaT;

    }
    if (izbor3 == 'C') {
        sumaR+=cevR;
        sumaL+=cevL;
        sumaT+=cevT;

    }
    if(sumaT<sumaL && sumaT<sumaR) {
        printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", sumaT);
        min=sumaT;

    }
    if(sumaL<sumaT && sumaL<sumaR) {
        printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", sumaL);
        min=sumaL;

    }
    if(sumaR<sumaT && sumaR<sumaL) {
        printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", sumaR);
        min=sumaR;
    }
   
   if(min < sumaR)
   {
        if(izbor1 == izbor2 && izbor2 == izbor3)
        {
            popust= sumaR - 0.1* sumaR;
        }
        else if( (izbor1=='P' && izbor2=='C' && izbor3=='C') || (izbor1=='C' && izbor2=='P' && izbor3=='C') || (izbor1=='C' && izbor2=='C' && izbor3=='P'))
        {
            popust = pizzaR + 2* cevR - 2*cevR*0.1;
        }
          else if( (izbor1=='P' && izbor2=='H' && izbor3=='H') || (izbor1=='H' && izbor2=='P' && izbor3=='H') || (izbor1=='H' && izbor2=='H' && izbor3=='P'))
        {
            popust = pizzaR + 2* hambR - pizzaR*0.1;
        }    
        else if( (izbor1=='H' && izbor2=='C' && izbor3=='C') || (izbor1=='C' && izbor2=='H' && izbor3=='C') || (izbor1=='C' && izbor2=='C' && izbor3=='H'))
        {
            popust = hambR + 2* cevR - 2*cevR*0.1;
        }
        else if( (izbor1=='H' && izbor2=='P' && izbor3=='P') || (izbor1=='P' && izbor2=='H' && izbor3=='P') || (izbor1=='P' && izbor2=='P' && izbor3=='H'))
        {
            popust = hambR + 2* pizzaR - 2*pizzaR*0.1;
        }
        else if( (izbor1=='C' && izbor2=='P' && izbor3=='P') || (izbor1=='P' && izbor2=='C' && izbor3=='P') || (izbor1=='P' && izbor2=='P' && izbor3=='C'))
        {
            popust = cevR + 2* pizzaR - 2*pizzaR*0.1;
        }
        else if( (izbor1=='C' && izbor2=='H' && izbor3=='H') || (izbor1=='H' && izbor2=='C' && izbor3=='H') || (izbor1=='H' && izbor2=='H' && izbor3=='C'))
        {
            popust = cevR + 2* hambR - 2*hambR*0.1;
        } 
        else  {
            popust= hambR + cevR + pizzaR - pizzaR*0.1;
        }
        
        if(popust<min) { 
         printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);   
        }
        
   } 
   
  
    return 0;
}