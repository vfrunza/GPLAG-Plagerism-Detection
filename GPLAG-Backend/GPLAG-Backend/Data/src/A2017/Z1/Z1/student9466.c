#include <stdio.h>

int main()
{
    char jeloZaTarika, jeloZaMirzu, jeloZaBojana, noviRed;

    printf("Unesite jelo za Tarika: ");
    scanf("%c", &jeloZaTarika);
    scanf("%c", &noviRed);
    printf("Unesite jelo za Bojana: ");
    scanf("%c", &jeloZaBojana);
    scanf("%c", &noviRed);
    printf("Unesite jelo za Mirzu: ");
    scanf("%c", &jeloZaMirzu);
    scanf("%c", &noviRed);

    float pizzaRestoran = 6.8, pizzaTrovac = 8.0, pizzaLorelei = 5.3;
    float hamburgerRestoran = 3.3, hamburgerTrovac = 3.0, hamburgerLorelei = 5.0;
    float cevapiRestoran = 5.0, cevapiTrovac = 3.9, cevapiLorelei = 6.0;

    float ukupnoRestoran = 0, ukupnoTrovac = 0, ukupnoLorelei = 0;
    
    float ukupnoHamburger = 0, ukupnoPizza = 0, ukupnoCevapi = 0;

    switch(jeloZaTarika) {
    case 'H' :
        ukupnoRestoran += hamburgerRestoran;
        ukupnoTrovac += hamburgerTrovac;
        ukupnoLorelei += hamburgerLorelei;
        ukupnoHamburger += hamburgerRestoran;
        break;
    case 'P':
        ukupnoRestoran += pizzaRestoran;
        ukupnoTrovac += pizzaTrovac;
        ukupnoLorelei += pizzaLorelei;
        ukupnoPizza += pizzaRestoran;
        break;
    case 'C':
        ukupnoRestoran += cevapiRestoran;
        ukupnoTrovac += cevapiTrovac;
        ukupnoLorelei += cevapiLorelei;
        ukupnoCevapi += cevapiRestoran;
        break;
    default:
        break;
    }

    switch(jeloZaBojana) {

    case 'H':
        ukupnoRestoran+=hamburgerRestoran;
        ukupnoTrovac+=hamburgerTrovac;
        ukupnoLorelei+=hamburgerLorelei;
        ukupnoHamburger += hamburgerRestoran;
        break;
    case 'P':
        ukupnoRestoran+=pizzaRestoran;
        ukupnoTrovac+=pizzaTrovac;
        ukupnoLorelei+=pizzaLorelei;
        ukupnoPizza += pizzaRestoran;
        break;
    case 'C':
        ukupnoRestoran+=cevapiRestoran;
        ukupnoTrovac+=cevapiTrovac;
        ukupnoLorelei+=cevapiLorelei;
        ukupnoCevapi += cevapiRestoran;
        break;
    default:
        break;
    }

    switch(jeloZaMirzu) {
    case 'H':
        ukupnoRestoran+=hamburgerRestoran;
        ukupnoTrovac+=hamburgerTrovac;
        ukupnoLorelei+=hamburgerLorelei;
        ukupnoHamburger += hamburgerRestoran;
        break;
    case 'P':
        ukupnoRestoran+=pizzaRestoran;
        ukupnoTrovac+=pizzaTrovac;
        ukupnoLorelei+=pizzaLorelei;
        ukupnoPizza += pizzaRestoran;
        break;
    case 'C':
        ukupnoRestoran+=cevapiRestoran;
        ukupnoTrovac+=cevapiTrovac;
        ukupnoLorelei+=cevapiLorelei;
        ukupnoCevapi += cevapiRestoran;
        break;
    default:
        break;
    }

    float min=1000;
    
    if(ukupnoRestoran < min) {
        min=ukupnoRestoran;
    }

    if(ukupnoTrovac < min) {
        min = ukupnoTrovac;
    }

    if(ukupnoLorelei < min) {
        min = ukupnoLorelei;
    }
    
    float max = 0;
    
    if(ukupnoHamburger > max){
        max = ukupnoHamburger;
    }
    
    if(ukupnoPizza > max){
        max = ukupnoPizza;
    }
    
    if(ukupnoCevapi > max){
        max = ukupnoCevapi;
    }
    
    float popust = max * 10/100;

    float restoranSaPopustom = 0;
    if(ukupnoRestoran != min) {
        restoranSaPopustom = ukupnoRestoran - popust;
    }

    if(min == ukupnoRestoran) {
        printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", ukupnoRestoran);

    }
    else if(min == ukupnoTrovac)
    {
        printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", ukupnoTrovac);
    } 
    else if(min == ukupnoLorelei)
    {
        printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", ukupnoLorelei);
    }
    
    if(restoranSaPopustom > 0 && restoranSaPopustom<min) {
        printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", restoranSaPopustom);
    }
    return 0;
}
