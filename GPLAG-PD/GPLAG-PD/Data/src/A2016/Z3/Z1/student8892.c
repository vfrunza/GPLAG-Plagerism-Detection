#include <stdio.h>

int daj_prost (){
    static int i=1;
    int j;
    i++;
    for (j = 2; j < i; j++){
        if (i % j == 0){
            j=2;        /* provjerava se da li je broj i prost i j se povercava sve dok se ne dogije prost broj, kad dolazi do promjene broja i, a j se vraca na pocetak */
            i++;
        }
    }
    return i;   
}

int main(){
    int A, B, suma=0, y, i;
    
    /* unos brojeva gdje B mora da bude veci od broja A, a brojevi moraju da budu prirodni */
    do{
        printf ("Unesite brojeve A i B: ");
        scanf ("%d %d", &A, &B);
        
        if(A <= 0 ){
        printf ("A nije prirodan broj.\n");
        }
        else if (A >=B){
            printf ("A nije manje od B.\n");
        }
    }while(A >=B || A <= 0);
    
    for (i=1; ; i++){
        y = daj_prost();        /* pozivanje funkcije, gdje se njena trenutna virjednost dodjeljuje broju y iz funkcije main */
        if (y >= B){
            break;
        }
        else if (y <= A){
            continue;
        }
        suma = suma + y;
    }
    printf ("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
    
    return 0;
}