#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int ipt1 = 0, n = 0, br = 0, c = 0, otp = 0, pv, ipt, ost, a, b;
    printf ("Unesite broj: ");
    scanf ("%d", &ipt);
    ipt = abs(ipt);
    pv = ipt;
    while (pv != 0) { 
        pv = pv / 10;
        c++;
    }
    pv = 0;
    if (ipt < 10 && ipt > -10) {
        otp = 0;}
        else { 
            while (ipt != 0 && c > 1) {
                b = ipt % 10;
                ipt = ipt / 10;
                a = ipt % 10;
                pv = b - a;
                if ( pv < 0){ 
                    pv = -pv;}
                    otp = pv * pow(10, n) + otp;
                    c--; 
                    n++;
            }
        }
        printf ("%d", otp);
        return 0;
}
            

		
