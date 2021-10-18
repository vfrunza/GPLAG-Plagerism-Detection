#include <stdio.h>

int main()
{ 
    float  Iparc, IIparc, pr, dz, zavrsni, suma1, suma2, suma3;
    
    printf("\nUnesite bodove za Tarika: ");
    printf("\nI parc. ispit, II parc. ispit, prisustvo, zadace, zavrsni ispit: ");
    scanf("%f, %f, %f, %f, %f", &Iparc, &IIparc, &pr, &dz, &zavrsni);
    if ((Iparc<0 || Iparc>20) || (IIparc<0 || IIparc>20) || (pr<0 || pr>10) || (dz<0 || dz>10) || (zavrsni<0 || zavrsni>40))
    {
        printf("Neispravan broj bodova!");
        return 0;
    }
    suma1 = Iparc + IIparc + pr + dz + zavrsni;
    if (suma1 < 55)
    printf("Student pao = 5!");
    else if (suma1 >= 55 && suma1 < 65)
    printf("Ocjena 6!");
    else if (suma1 >= 65 && suma1 < 75)
    printf("Ocjena 7!");
    else if (suma1 >= 75 && suma1 < 85)
    printf("Ocjena 8!");
    else if (suma1 >= 85 && suma1 < 92)
    printf("Ocjena 9!");
    else if (suma1 >= 92 && suma1 <= 100)
    printf("Ocjena 10!");
    
    printf("\nUnesite bodove za Bojana: ");
    printf("\nI parc. ispit, II parc. ispit, prisustvo, zadace, zavrsni ipit: ");
    scanf("%f, %f, %f, %f, %f", &Iparc, &IIparc, &pr, &dz, &zavrsni);
    if ((Iparc<0 || Iparc>20) || (IIparc<0 || IIparc>20) || (pr<0 || pr>10) || (dz<0 || dz>10) || (zavrsni<0 || zavrsni>40))
    {
        printf("Neispravan broj bodova!");
        return 0;
    }
    suma2 = Iparc + IIparc + pr + dz + zavrsni;
    if (suma2 < 55)
    printf("Student pao = 5!");
    else if (suma2 >= 55 && suma2 < 65)
    printf("Ocjena 6!");
    else if (suma2 >= 65 && suma2 < 75)
    printf("Ocjena 7!");
    else if (suma2 >= 75 && suma2 < 85)
    printf("Ocjena 8!");
    else if (suma2 >=85 && suma2 < 92)
    printf("Ocjena 9!");
    else if (suma2 >= 92 && suma2 <= 100)
    printf("Ocjena 10!");
    
    printf("\nUnesite bodove za Mirzu: ");
    printf("\nI parc. ispit, II parc. ispit, prisustvo, zadace, zavrsni ispit: ");
    scanf("%f, %f, %f, %f, %f", &Iparc, &IIparc, &pr, &dz, &zavrsni);
    if ((Iparc<0 || Iparc>20) || (IIparc<0 || IIparc>20) || (pr<0 || pr>10) || (dz<0 || dz>10) || (zavrsni<0 || zavrsni>40)) 
    {
        printf("Neispravan broj bodova!");
        return 0;
        
    }
    suma3 = Iparc + IIparc + pr + dz + zavrsni;
    if (suma3 < 55)
    printf("Student pao = 5!");
    else if (suma3 >= 55 && suma3 < 65)
    printf("Ocjena 6!");
    else if (suma3 >= 65 && suma3 < 75)
    printf("Ocjena 7!");
    else if (suma3 >= 75 && suma3 < 85)
    printf("Ocjena 8!");
    else if (suma3 >= 85 && suma3 < 92)
    printf("Ocjena 9!");
    else if (suma3 >= 92 && suma3 <=100)
    printf("Ocjena 10!");
   
    if (suma1==5 && suma2==5 && suma3==5)
    printf("Nijedan student nije polozio!");
    if ((suma1!=5 && suma2==5 && suma3==5) || (suma1==5 && suma2!=5 && suma3==5) || (suma1==5 && suma2==5 && suma3!=5))
    printf("Jedan student je polozio!");
    if ((suma1!=5 && suma2!=5 && suma3==5) || (suma1!=5 && suma2==5 && suma3!=5) || (suma1==5 && suma2!=5 && suma3!=5))
    printf("Dva studenta su polozila!");
    if (suma1!=5 && suma2!=5 && suma3!=5)
    printf("Sva tri studenta su polozila!");
    
    if ((suma1==suma2) && (suma1==suma3) && (suma2==suma3))
    printf("Sva tri studenta imaju istu ocjenu!");
    if ((suma1!=suma2) && (suma1!=suma3) && (suma2!=suma3))
    printf("Svaki student ima razlicitu ocjenu!");
    if((suma1==suma2 && suma1!=suma3) || (suma2==suma3 && suma2!=suma1) || (suma1==suma3 && suma1!=suma2))
    printf("Dva od tri studenta imaju istu ocjenu!");
    
    return 0;
}