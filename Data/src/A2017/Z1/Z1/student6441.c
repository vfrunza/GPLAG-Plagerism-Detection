#include <stdio.h>
#define PR 6.80
#define HR 3.30
#define CR 5.00
#define PF 8.00
#define HF 3.00
#define CF 3.90
#define PB 5.30
#define HB 5.00
#define CB 6.00
int main()
{
    char tarik, bojan, mirza, novi_red;
    float cb, cf, cr, cpopust;
    printf("Unesite jelo za Tarika: ");
    scanf("%c", &tarik);
    scanf("%c", &novi_red);
    printf("Unesite jelo za Bojana: ");
    scanf("%c", &bojan);
    scanf("%c", &novi_red);
    printf("Unesite jelo za Mirzu: ");
    scanf("%c", &mirza)
    scanf("%c", &novi_red);
if (tarik=)
    {
    case 1:
        cr=3*PR;
        cf=3*PF;
        cb=3*PB;
        cpopust=3*PR-3*((PR*10)/100);
        break;

    case 2:
        cr=2*PR+HR;
        cf=2*PF+HF;
        cb=2*PB+HB;
        cpopust=HR+2*PR-2*((PR*10)/100);
        break;

    case 3:
        cr=2*PR+CR;
        cf=2*PF+CF;
        cb=2*PB+CB;
        cpopust=CR+2*PR-2*((PR*10)/100);
        break;

    case 4:
        cr=PR+CR+HR;
        cf=PF+HF+CF;
        cb=PB+HB+CB;
        cpopust=PR+CR+HR-((PR*10)/100);
        break;

    case 5:
        cr=PR+2*HR;
        cf=PF+2*HF;
        cb=PB+2*HB;
        cpopust=2*HR+PR-((PR*10)/100);
        break;

    case 6:
        cr=PR+2*CR;
        cf=PF+2*CF;
        cb=PB+2*CB;
        cpopust=2*CR+PR-((PR*10)/100);
        break;

    case 7:
        cr=3*HR;
        cf=3*HF;
        cb=3*HB;
        cpopust=3*HR-3*((HR*10)/100);
        break;

    case 8:
        cr=2*HR+CR;
        cf=2*HF+CF;
        cb=2*HB+CB;
        cpopust=2*HR+CR-((CR*10)/100);
        break;

    case 9:
        cr=2*CR+HR;
        cf=2*CF+HF;
        cb=2*CB+HB;
        cpopust=2*CR+HR-2*((CR*10)/100);
        break;

    case 10:
        cr=3*CR;
        cf=3*CF;
        cb=3*CB;
        cpopust=3*CR-3*((CR*10)/100);
        break;

    }
    
    if(cr<cb && cr<cf){
        printf("Najjeftiniji je Restoran \"Kod Konja i Konjusara\" (%.2f KM).\n", cr);
    }
    if(cf<cr && cf<cb){
        printf("Najjeftiniji je ")
    }
    return 0;
}
