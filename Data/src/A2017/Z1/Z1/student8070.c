#include <stdio.h>
#include<math.h>

int main()
{
#define pizzaR 6.80
#define pizzaT 8.00
#define pizzaB 5.30
#define hamR 3.30
#define hamT 3.00
#define hamB 5.00
#define cevR 5.00
#define cevT 3.90
#define cevB 6.00
    char T,B,M,novired;
    float cijenaR=0,cijenaT=0,cijenaB=0,cijenaP,cijena1=0,cijena2=0,cijena3=0,najveca;


    printf("Unesite jelo za Tarika: ");
    scanf("%c",&T);
    scanf("%c",&novired);
    printf("Unesite jelo za Bojana: ");
    scanf("%c",&B);
    scanf("%c",&novired);
    printf("Unesite jelo za Mirzu: ");
    scanf("%c",&M);
    scanf("%c",&novired);
    switch(T) {
    case 'P':
        cijenaR+=pizzaR;
        cijenaT+=pizzaT;
        cijenaB+=pizzaB;
        cijena1=pizzaR;
        break;
    case 'H':
        cijenaR+=hamR;
        cijenaT+=hamT;
        cijenaB+=hamB;
        cijena1=hamR;
        break;
    case 'C':
        cijenaR+=cevR;
        cijenaT+=cevT;
        cijenaB+=cevB;
        cijena1=cevR;
        break;

    }
    switch(B) {
    case 'P':
        cijenaR+=pizzaR;
        cijenaT+=pizzaT;
        cijenaB+=pizzaB;
        cijena2=pizzaR;
        break;
    case 'H':
        cijenaR+=hamR;
        cijenaT+=hamT;
        cijenaB+=hamB;
        cijena2=hamR;
        break;
    case 'C':
        cijenaR+=cevR;
        cijenaT+=cevT;
        cijenaB+=cevB;
        cijena2=cevR;
        break;

    }
    switch(M) {
    case 'P':
        cijenaR+=pizzaR;
        cijenaT+=pizzaT;
        cijenaB+=pizzaB;
        cijena3=pizzaR;
        break;
    case 'H':
        cijenaR+=hamR;
        cijenaT+=hamT;
        cijenaB+=hamB;
        cijena3=hamR;
        break;
    case 'C':
        cijenaR+=cevR;
        cijenaT+=cevT;
        cijenaB+=cevB;
        cijena3=cevR;
        break;

    }
    if(cijena1>=cijena2) {
        if(cijena1>=cijena3) najveca=cijena1;
        else najveca=cijena3;
    } else {
        if(cijena2>=cijena3) najveca=cijena2;
        else najveca=cijena3;
    }
    if(fabs(najveca-cijena1)<0.00001) cijena1=cijena1-0.1*cijena1;
    if(fabs(najveca-cijena2)<0.00001) cijena2=cijena2-0.1*cijena2;
    if(fabs(najveca-cijena3)<0.00001) cijena3=cijena3-0.1*cijena3;
    cijenaP=cijena1+cijena2+cijena3;

    if(cijenaR<cijenaT && cijenaR<cijenaB) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",cijenaR);
    else {
        if(cijenaT<cijenaR && cijenaT<cijenaB) {
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",cijenaT);
            if(cijenaP<cijenaT) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",cijenaP);
        }
        if(cijenaB<cijenaT && cijenaB<cijenaR) {
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",cijenaB);
            if(cijenaP<cijenaB) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",cijenaP);
        }

    }

    return 0;
}