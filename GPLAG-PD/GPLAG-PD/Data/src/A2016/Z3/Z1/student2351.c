#include <stdio.h>

int da_li_je_broj_prost (int n) {
	int i;
	for (i=2; i<n; i++) {
	    if (n%i==0)  return 0; }
	    return 1; 
}
int daj_prost () {
    static int broj=2;
    while (1) {
        if (da_li_je_broj_prost(broj)==1) {
            broj++;
            return broj-1; 
        }   
        broj++;
    }
}
int main() {
int X,Y,suma=0,broj;
broj=daj_prost ();

do {
printf("Unesite brojeve A i B: ");
    scanf("%d %d", &X,&Y);
    if (X<=0) printf("A nije prirodan broj.\n"); 
    if (Y<X) printf("A nije manje od B.\n"); 
    if (X==Y) printf("A nije manje od B.\n");
} while (X>Y || X<=0 || X==Y);
 while (broj<=X) broj=daj_prost();
 while (broj<Y)
 {
     suma+=broj; 
     broj=daj_prost();
 }
printf("Suma prostih brojeva izmedju %d i %d je %d. ", X,Y,suma);
return 0;

}