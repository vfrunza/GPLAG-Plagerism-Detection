#include <stdio.h>
int main ()
{
    double parc1_tarik, parc2_tarik, prisustvo_tarik, zadace_tarik, zispit_tarik;
    double parc1_bojan, parc2_bojan, prisustvo_bojan, zadace_bojan, zispit_bojan;
    double parc1_mirza, parc2_mirza, prisustvo_mirza, zadace_mirza, zispit_mirza;
    double bodovi_tarik, bodovi_bojan, bodovi_mirza;
    int ocjena_tarik, ocjena_bojan, ocjena_mirza;
    int brojac=0, brojac_ocjena=0;
    
    /*ULAZ - Tarik*/
    scanf("%lf", &parc1_tarik);
    if(parc1_tarik<0 || parc1_tarik>20)
    {
        printf("Unesite bodove za Tarika:\n");
        printf("I parcijalni ispit: Neispravan broj bodova\n");
        return 0;
    }
    scanf("%lf", &parc2_tarik);
    if(parc2_tarik<0 || parc2_tarik>20)
    {
        printf("Unesite bodove za Tarika:\n");
        printf("I parcijalni ispit: II parcijalni ispit: Neispravan broj bodova\n");
        return 0;
    }
    scanf("%lf", &prisustvo_tarik);
    if(prisustvo_tarik<0 || prisustvo_tarik>10)
    {
        printf("Unesite bodove za Tarika: \n");
        printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Neispravan broj bodova\n");
        return 0;
    }
    scanf("%lf", &zadace_tarik);
    if(zadace_tarik<0 || zadace_tarik>10)
    {
        printf("Unesite bodove za Tarika:\n");
        printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Neispravan broj bodova\n");
        return 0;
    }
    scanf("%lf", &zispit_tarik);
    if(zispit_tarik<0 || zispit_tarik>40)
    {
        printf("Unesite bodove za Tarika: \n");
        printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Neispravan broj bodova\n");
        return 0;
    }
    /*ULAZ - Bojan*/
    scanf("%lf", &parc1_bojan);
    if(parc1_bojan<0 || parc1_bojan>20)
    {
        printf("Unesite bodove za Tarika:\n");
        printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Bojana:\n");
        printf("I parcijalni ispit: Neispravan broj bodova\n");
        return 0;
    }
    scanf("%lf", &parc2_bojan);
    if(parc2_bojan<0 || parc2_bojan>20)
    {
        printf("Unesite bodove za Tarika:\n");
        printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Bojana:\n");
        printf("I parcijalni ispit: II parcijalni ispit: Neispravan broj bodova\n");
        return 0;
    }
    scanf("%lf", &prisustvo_bojan);
    if(prisustvo_bojan<0 || prisustvo_bojan>10)
    {
        printf("Unesite bodove za Tarika: \n");
        printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Bojana:\n");
        printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Neispravan broj bodova\n");
        return 0;
    }
    scanf("%lf", &zadace_bojan);
    if(zadace_bojan<0 || zadace_bojan>10)
    {
        printf("Unesite bodove za Tarika:\n");
        printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Bojana:\n");
        printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Neispravan broj bodova\n");
        return 0;
    }
    scanf("%lf", &zispit_bojan);
    if(zispit_bojan<0 || zispit_bojan>40)
    {
        printf("Unesite bodove za Tarika: \n");
        printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Bojana:\n");
        printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Neispravan broj bodova\n");
        return 0;
    }
    /*ULAZ - Mirza*/
    scanf("%lf", &parc1_mirza);
    if(parc1_mirza<0 || parc1_mirza>20)
    {
        printf("Unesite bodove za Tarika: \n");
        printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Bojana:\n");
        printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Mirzu:\n");
        printf("I parcijalni ispit: Neispravan broj bodova\n");
        return 0;
    }
    scanf("%lf", &parc2_mirza);
    if(parc2_mirza<0 || parc2_mirza>20)
    {
        printf("Unesite bodove za Tarika:\n");
        printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Bojana:\n");
        printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Mirzu:\n");
        printf("I parcijalni ispit: II parcijalni ispit: Neispravan broj bodova\n");
        return 0;
    }
    scanf("%lf", &prisustvo_mirza);
    if(prisustvo_mirza<0 || prisustvo_mirza>10)
    {
        printf("Unesite bodove za Tarika:\n");
        printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Bojana:\n");
        printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Mirzu:\n");
        printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Neispravan broj bodova\n");
        return 0;
    }
    scanf("%lf", &zadace_mirza);
    if(zadace_mirza<0 || zadace_mirza>10)
    {
        printf("Unesite bodove za Tarika:\n");
        printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Bojana:\n");
        printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Mirzu:\n");
        printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Neispravan broj bodova\n");
        return 0;
    }
    scanf("%lf", &zispit_mirza);
    if(zispit_mirza<0 || zispit_mirza>40)
    {
        printf("Unesite bodove za Tarika:\n");
        printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Bojana:\n");
        printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Mirzu: \n");
        printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Neispravan broj bodova\n");
        return 0;
    }
    /*BODOVI*/
    bodovi_tarik=parc1_tarik+parc2_tarik+prisustvo_tarik+zadace_tarik+zispit_tarik;
    bodovi_bojan=parc1_bojan+parc2_bojan+prisustvo_bojan+zadace_bojan+zispit_bojan;
    bodovi_mirza=parc1_mirza+parc2_mirza+prisustvo_mirza+zadace_mirza+zispit_mirza;
    /*OCJENA - Tarik*/
    if(bodovi_tarik>=55 && bodovi_tarik<65)
    {
        ocjena_tarik=6;
        brojac++;
    }
    if(bodovi_tarik>= 65 && bodovi_tarik<75)
    {
        ocjena_tarik=7;
        brojac++;
    }
    if(bodovi_tarik>=75 && bodovi_tarik<85)
    {
        ocjena_tarik=8;
        brojac++;
    }
    if(bodovi_tarik>=85 && bodovi_tarik<92)
    {
        ocjena_tarik=9;
        brojac++;
    }
    if(bodovi_tarik>=92 && bodovi_tarik<=100)
    {
        ocjena_tarik=10;
        brojac++;
    }
    /*OCJENA - Bojan*/
    if(bodovi_bojan>=55 && bodovi_bojan<65)
    {
        ocjena_bojan=6;
        brojac++;
    }
    if(bodovi_bojan>=65 && bodovi_bojan<75)
    {
        ocjena_bojan=7;
        brojac++;
    }
    if(bodovi_bojan>=75 && bodovi_bojan<85)
    {
        ocjena_bojan=8; 
        brojac++;
    }
    if(bodovi_bojan>=85 && bodovi_bojan<92)
    {
        ocjena_bojan=9;
        brojac++;
    }
    if(bodovi_bojan>=92 && bodovi_bojan<=100)
    {
        ocjena_bojan=10; 
        brojac++;
    }
    /*OCJENA - Mirza*/
    if(bodovi_mirza>=55 && bodovi_mirza<65)
    {
        ocjena_mirza=6;
        brojac++;
    }
    if(bodovi_mirza>=65 && bodovi_mirza<75)
    {
        ocjena_mirza=7;
        brojac++;
    }
    if(bodovi_mirza>=75 && bodovi_mirza<85)
    {
        ocjena_mirza=8; 
        brojac++;
    }
    if(bodovi_mirza>=85 && bodovi_mirza<92)
    {
        ocjena_mirza=9;
        brojac++;
    }
    if(bodovi_mirza>=92 && bodovi_mirza<=100)
    {
        ocjena_mirza=10;
        brojac++;
    }
    if(brojac==0)
    {
        printf("Unesite bodove za Tarika:\n");
        printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Bojana:\n");
        printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Mirzu:\n");
        printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Nijedan student nije polozio.\n");
        return 0;
    }
    if(brojac==1)
    {
        printf("Unesite bodove za Tarika:\n");
        printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Bojana: \n"),
        printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Mirzu: \n");
        printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Jedan student je polozio.\n");
        return 0;
    }
    if(brojac==2)
    {
        printf("Unesite bodove za Tarika:\n");
        printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Bojana: \n");
        printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Mirzu: \n");
        printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Dva studenta su polozila.\n");
        return 0;
    }
    if(brojac==3)
    {
        if(ocjena_mirza!=ocjena_bojan) brojac_ocjena++;
        if(ocjena_mirza!=ocjena_tarik) brojac_ocjena++;
        if(ocjena_tarik!=ocjena_bojan) brojac_ocjena++;
        if(brojac_ocjena==0)
        {
            printf("Sva tri studenta su polozila.\n");
            printf("Sva tri studenta imaju istu ocjenu.\n");
            return 0;
        }
        if(brojac_ocjena==2)
        {
            printf("Unesite bodove za Tarika: \n");
            printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Bojana: \n");
            printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Mirzu: \n");
            printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Sva tri studenta su polozila.\n");
            printf("Dva od tri studenta imaju istu ocjenu.\n");
            return 0;
        }
        if(brojac_ocjena==3)
        {
            printf("Unesite bodove za Tarika: \n");
            printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Bojana: \n");
            printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Mirzu: \n");
            printf("I parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Sva tri studenta su polozila.\n");
            printf("Svaki student ima razlicitu ocjenu.\n");
            return 0;
        }
    }
    
    return 0;
}