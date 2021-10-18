#include <stdio.h>
#include <stdlib.h>

double daj_zaokruzen(double broj)
{
    double vrati;
    double ostatak;
    int int_broja;
    int int_ostatka;
    int cifra_2;
    int cifra_1;
    if(broj < 0){
        broj = -broj;
        int_broja = (int)broj;

        ostatak = (broj - int_broja)*100;
        int_ostatka = (int)ostatak;
        cifra_2 = int_ostatka%10;
        cifra_1 = (int)int_ostatka/10;
        if(cifra_2 >= 5 && cifra_1 < 9)
            cifra_1++;
        if(cifra_1 == 9){
            int_broja++;
            return -int_broja;
        }
        vrati = int_broja + cifra_1/10.0;

        vrati = -vrati;
        return vrati;
    }
    int_broja = (int)broj;

    ostatak = (broj - int_broja)*100;
    int_ostatka = (int)ostatak;
    cifra_2 = int_ostatka%10;
    cifra_1 = (int)int_ostatka/10;
    if(cifra_2 >= 5 && cifra_1 < 9)
        cifra_1++;
    if(cifra_1 == 9){
            int_broja++;
            return int_broja;
        }
    vrati = int_broja + cifra_1/10.0;

    return vrati;
}


void zaokruzi1(float *niz, int velicina){
    unsigned int i=0;
    float *pointer = niz;
    for(i=0; i<velicina; i++){
        *pointer = daj_zaokruzen(*pointer);
        pointer++;
    }
}

int daj_sumu_cifara(double broj)
{
    int suma = 0;
    int cifra = 0;
    broj *= 10;
    int broj_1 = (int)broj;
    while(broj_1 > 0)
    {
        cifra = broj_1%10;
        suma += cifra;
        broj_1 /= 10;
    }

    return suma;
}

void preslozi(double* niz, int vel, int k)
{
    int i, m = 0, l = 0, suma;
    double niz_1[100], niz_2[100];

    //Zaokruzi cifre
    for(i=0; i<vel;i++){
        niz[i] = daj_zaokruzen(niz[i]);
    }

//    for(i=0; i<vel; i++){
//        printf("%.1f ", niz[i]);
//    }

//    printf("\n\n");


    for(i = 0; i < vel; i++){
        suma = daj_sumu_cifara(niz[i]);
        if(suma<k){
            niz_1[m++] = niz[i];
        }else niz_2[l++] = niz[i];
    }

    for(i=0; i<l;i++) niz[i] = niz_2[i];
    int br = 0;
    for(i=l; i<vel;i++){
        niz[i] = niz_1[br++];
    }

//    for(i=0; i<vel; i++){
//        printf("%.1f ", niz[i]);
//    }
}

int main()
{
    double niz[1000];
    int vel ;
    int i;
    

    printf("Unesite velicinu niza: ");
    scanf("%d", &vel);

    printf("Unesite clanove niza: ");
    for(i = 0; i < vel; i++)
        scanf("%lf", &niz[i]);
    

    preslozi(niz, vel, 14);

    return 0;
}
