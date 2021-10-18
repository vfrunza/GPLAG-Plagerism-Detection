#include <math.h>
#include <stdio.h>


void zaokruzi1(float niz[], int velicina){
    int i;

    for (i=0; i < velicina; i++){
        niz[i] = round ( niz[i] * 10 ) / 10;
    }
}


int suma_cifara(int broj) {
    int suma = 0;

    if(broj < 0) {
        broj *= -1;
    }

    while(broj > 0) {
        suma += broj % 10;
        broj = broj / 10;
    }

    return suma;
}

void preslozi(float ulazni_niz[], int velicina, int k){
    int i;
    int suma=0;
    
    zaokruzi1(ulazni_niz, velicina);

    float radni_niz[1000];

    for (i = 0; i < velicina; i++){
        radni_niz[i] = ulazni_niz[i];
    }

    int brojac = 0;

    for(i = 0; i < velicina; i++) {
        float broj = radni_niz[i];

        suma = suma_cifara(broj * 10);

        if(suma >= k){
            ulazni_niz[brojac] = broj;
            brojac += 1;
        }
    }
  
    for(i = 0; i < velicina; i++) {
        float broj = radni_niz[i];

        int suma = suma_cifara(broj * 10);

        if(suma < k){
            ulazni_niz[brojac] = broj;
            brojac += 1;
        }
    }
}

int main() {
    int k ;
    float niz[1000] ;
    int velicina;
    int i;
    
    printf("Unesite velicinu niza i k: ");
    scanf("%d %d", &velicina, &k);
    printf("Unesite niz: ");
    for(i=0; i<velicina; i++){
        scanf("%f", &niz[i]);
    }

    preslozi(niz, velicina, k);

    printf("Niz glasi: ");

    for (i = 0; i < velicina; i++) {
          printf("%.1f ", niz[i]);
    }

    return 0;
}
