#include <stdio.h>
int main ( )
{
    float a1, a2, b1, b2, A, B;
    printf ("Unesite a1,b1,a2,b2: ");
    scanf ("%f,%f,%f,%f", &a1, &b1, &a2, &b2);

    if (a1==a2 && b1==b2) {
        printf ("Poklapaju se \n");
        return 0;
    }
    if (a1==a2 && b1!=b2) {
        printf ("Paralelne su \n");
        return 0;
    }
    A=((b2-b1)/(a1-a2));
    B=a2*A+b2;
    printf ("Prave se sijeku u tacci (%.1f,%.1f)", A, B);
    return 0;
}