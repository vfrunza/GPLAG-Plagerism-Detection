#include <stdio.h>
#include <stdlib.h>

int ProstBroj (int x)
{
    int i=2;
    while (i<x){
    if (x%i==0) 
        return 0;
    
    i++;
    }
    return 1;
}

int daj_prost ()
{
    int static y=2;
    while (1){
        if (ProstBroj(y)) {
            return y++;
        }
        else {
            y++;
        }
    }
}

int main() {
    int A, B, suma=0, c;
    printf ("Unesite brojeve A i B: ");
    scanf ("%d %d", &A, &B);
    while (A<=0 || A>=B) {
        if (A<=0) {
        printf ("A nije prirodan broj.\n");
        printf ("Unesite brojeve A i B: ");
        scanf ("%d %d", &A, &B); 
        }
        if (A>=B) {
        printf ("A nije manje od B.\n");
        printf ("Unesite brojeve A i B: ");
        scanf ("%d %d", &A, &B);
        }
    }
    c=daj_prost();
    while (c<=A) {
        c=daj_prost();
    }
    while (c<B) {;
        suma+=c;
        c=daj_prost();
    }
    printf ("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
    return 0;
}






