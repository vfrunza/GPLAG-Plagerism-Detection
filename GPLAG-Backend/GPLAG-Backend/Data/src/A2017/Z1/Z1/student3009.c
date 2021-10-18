#include<stdio.h>
#define PR 6.80
#define PF 8.00
#define PB 5.30
#define HR 3.30
#define HF 3.00
#define HB 5.00
#define CR 5.00
#define CF 3.90
#define CB 6.00
int main()
{
    char tarik,t1,bojan,b1,mirza,m1;
    float sumaR,sumaF,sumaB,sumaR1,pizza,cevapi,hamburger;
    printf("Unesite jelo za Tarika: ");
    scanf("%c",&tarik);
    scanf("%c",&t1);
    printf("Unesite jelo za Bojana: ");
    scanf("%c",&bojan);
    scanf("%c",&b1);
    printf("Unesite jelo za Mirzu: ");
    scanf("%c",&mirza);
    scanf("%c",&m1);
    sumaR=0;
    sumaF=0;
    sumaB=0;
    sumaR1=0;
    if (tarik=='P') {
        sumaR=PR;
        sumaF=PF;
        sumaB=PB;
    } else if(tarik=='H') {
        sumaR=HR;
        sumaF=HF;
        sumaB=HB;
    } else if (tarik=='C') {
        sumaR=CR;
        sumaF=CF;
        sumaB=CB;
    }

    if (bojan=='P') {
        sumaR+=PR;
        sumaF+=PF;
        sumaB+=PB;
    } else if(bojan=='H') {
        sumaR+=HR;
        sumaF+=HF;
        sumaB+=HB;
    } else if (bojan=='C') {
        sumaR+=CR;
        sumaF+=CF;
        sumaB+=CB;
    }

    if (mirza=='P') {
        sumaR+=PR;
        sumaF+=PF;
        sumaB+=PB;
    } else if(mirza=='H') {
        sumaR+=HR;
        sumaF+=HF;
        sumaB+=HB;
    } else if (mirza=='C') {
        sumaR+=CR;
        sumaF+=CF;
        sumaB+=CB;
    }

    if (tarik=='P' || mirza=='P' || bojan=='P') {
        pizza=PR-0.1*PR;
        if (tarik=='P') {
            sumaR1=pizza;
        } else if(tarik=='H') {
            sumaR1=HR;
        } else if (tarik=='C') {
            sumaR1=CR;
        }

        if (bojan=='P') {
            sumaR1+=pizza;
        } else if(bojan=='H') {
            sumaR1+=HR;
        } else if (bojan=='C') {
            sumaR1+=CR;
        }

        if (mirza=='P') {
            sumaR1+=pizza;
        } else if(mirza=='H') {
            sumaR1+=HR;
        } else if (mirza=='C') {
            sumaR1+=CR;
        }

    } else if (tarik=='C' || mirza=='C' || bojan=='C') {
        cevapi=CR-0.1*CR;
        if (tarik=='P') {
            sumaR1=PR;
        } else if(tarik=='H') {
            sumaR1=HR;
        } else if (tarik=='C') {
            sumaR1=cevapi;
        }

        if (bojan=='P') {
            sumaR1+=PR;
        } else if(bojan=='H') {
            sumaR1+=HR;
        } else if (bojan=='C') {
            sumaR1+=cevapi;
        }

        if (mirza=='P') {
            sumaR1+=PR;
        } else if(mirza=='H') {
            sumaR1+=HR;
        } else if (mirza=='C') {
            sumaR1+=cevapi;
        }

    } else {
        hamburger=HR-0.1*HR;
        if (tarik=='P') {
            sumaR1=PR;
        } else if(tarik=='H') {
            sumaR1=hamburger;
        } else if (tarik=='C') {
            sumaR1=CR;
        }

        if (bojan=='P') {
            sumaR1+=PR;
        } else if(bojan=='H') {
            sumaR1+=hamburger;
        } else if (bojan=='C') {
            sumaR1+=CR;
        }

        if (mirza=='P') {
            sumaR1+=PR;
        } else if(mirza=='H') {
            sumaR1+=hamburger;
        } else if (mirza=='C') {
            sumaR1+=CR;
        }

    }


    if (sumaR<sumaF && sumaR<sumaB) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",sumaR);
    else if (sumaF<sumaR && sumaF<sumaB) {
        printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",sumaF);
        if (sumaR1<sumaF)
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",sumaR1);

    } else if (sumaB<sumaR && sumaB<sumaF) {
        printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",sumaB);
        if (sumaR1<sumaB)
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",sumaR1);
    }

    return 0;
}


 