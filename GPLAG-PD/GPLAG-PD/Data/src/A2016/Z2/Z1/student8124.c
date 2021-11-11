#include <stdio.h>
#include <stdlib.h>

int main() {

    long novi_broj = 0, shift = 1;
    int  broj, cifra1, cifra2;

    printf("Unesite broj: ");
    scanf("%i", &broj);
    
    if (broj < 0) 
      broj = abs(broj);

    while (broj > 9) {
       cifra1 = broj % 10;
       broj = broj / 10;
       cifra2 = broj % 10;
       novi_broj += shift * abs(cifra2-cifra1);
       shift *= 10;
    };

    printf("%i", novi_broj);

    return 0;
}