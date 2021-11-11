#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    int x,y,n,broj_1=0,broj_2=1;
    printf ("Unesite broj: ");
    scanf ("%d", &n);
    
    n=abs(n);
    if (n<10) {
    	printf ("0");
    	return 0;
    }
    while (n>=10) {
    	x=n%10;
    	n=n/10;
    	y=n%10;
    	broj_1=broj_1+(abs(x-y))*broj_2;
    	broj_2=broj_2*10;
    }
    printf ("%d", broj_1);

	return 0;
}
