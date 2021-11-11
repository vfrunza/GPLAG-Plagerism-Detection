#include <stdio.h>
#include <math.h>
#define BROJ_EL 500
#define PI 3.1415926
int main () {
    
    double  niz[BROJ_EL], stepeni=0, minute=0, sekunde=0, radijani=0, ukupno_minuta=0, ukupno_sekundi=0;
    int broj_uglova=0, j=0, i=0;
    
    printf ("Unesite broj uglova: ");
    
    do {
        scanf ("%d", &broj_uglova);
    } while (broj_uglova<1 || broj_uglova>=500);
    
    do {
        scanf ("%lf", &niz[i]);
        i++;
    } while (i<broj_uglova);
    
    printf ("Uglovi su: ");
    for (i=0; i<broj_uglova; i++) {
        
        radijani=fabs(niz[i]);
        stepeni= (int) ((radijani*180)/PI); /*sve u stepene*/
        ukupno_sekundi=radijani*180/PI; /*sve u sekunde*/
        minute= (int) ((ukupno_sekundi-stepeni)*60);
        ukupno_minuta=((ukupno_sekundi-stepeni)*60);
        sekunde= round((ukupno_minuta-minute)*60);
        
        if (sekunde>=60) {
            sekunde-=60;
            minute++;
        }
      
        if (minute>=60) {
            minute-=60;
            stepeni++;        
        }
        if (sekunde>30) {
            for (j=i; j<broj_uglova-1; j++) {
                niz[j]=niz[j+1];
            }
        broj_uglova--;
        i--;
        }
        
        else {
        if (niz[i]<0) {
            printf ("\n-%.lf stepeni %.lf minuta %.lf sekundi", stepeni, minute, sekunde);
        }
        else {
            printf ("\n%.lf stepeni %0.lf minuta %.lf sekundi", stepeni, minute, sekunde);
        }
        
        }
    }
    return 0;
}