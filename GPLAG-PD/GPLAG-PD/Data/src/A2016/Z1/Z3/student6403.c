#include <stdio.h>

int main()
{
    int broj=0, crna=0, bijela=0, siva=0, plava=0, crvena=0, naj_broj=0 ;
    char  znak, naj_znak='\0';
    float postotak;
    printf("Unesite vozila: ");
    do {
        scanf("%c", &znak);
        if(znak!='K' && znak!='k') {

            if(znak=='c' || znak=='C') {
                crna++;
                broj++;
                if(crna>naj_broj) {
                    naj_broj=crna;
                    naj_znak=znak;

                }
            }

            else if(znak=='p' || znak=='P') {
                plava++;
                broj++;
                if(plava>naj_broj) {
                    naj_broj=plava;
                    naj_znak=znak;

                }
            }

            else if(znak=='V' || znak=='v') {
                crvena++;
                broj++;
                if(crvena>naj_broj) {
                    naj_broj=crvena;
                    naj_znak=znak;

                }
            }

            else if(znak=='b' || znak=='B') {
                bijela++;
                broj++;
                if(bijela>naj_broj) {
                    naj_broj=bijela;
                    naj_znak=znak;

                }

            }

            else if(znak=='S' || znak=='s') {
                siva++;
                broj++;
                if(siva>naj_broj) {
                    naj_broj=siva;
                    naj_znak=znak;

                }

            }

            else {
                printf("Neispravan unos\n");
                continue;
            }
        } else break;

    } while(znak!='K' && znak!='k');


    printf("Ukupno evidentirano %d vozila.\n", broj);
    if(broj==0) {
        printf("Najpopularnija boja je crna (0.00%%).");
    }
    if(broj!=0) {
        if(naj_znak=='c' || naj_znak=='C') {
            postotak=naj_broj*100/(float)broj;
            printf("Najpopularnija boja je crna (%.2f%%).",postotak);
        }
        if(naj_znak=='s' || naj_znak=='S') {
            postotak=naj_broj*100/(float)broj;
            printf("Najpopularnija boja je siva (%.2f%%).", postotak);
        }
        if(naj_znak=='V' || naj_znak=='v') {
            postotak=naj_broj*100/(float)broj;
            printf("Najpopularnija boja je crvena (%.2f%%).", postotak);
        }
        if(naj_znak=='b' || naj_znak=='B') {
            postotak=naj_broj*100/(float)broj;
            printf("Najpopularnija boja je bijela (%.2f%%).", postotak);
        }
        if(naj_znak=='P' || naj_znak=='p') {
            postotak=naj_broj*100/(float)broj;
            printf("Najpopularnija boja je plava (%.2f%%).", postotak);
        }
    }
    return 0;
}