#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926

int main () {
    
double niz [500];
double step,min,sec,x;
int i,j,n;

printf ("Unesite broj uglova: ");
scanf ("%d", &n);

for (i=0; i<n; i++) {
    scanf ("%lf", &niz[i]); 
    }

for (i=0; i<n; i++) {

x = fabs ((niz[i])*(180/PI));
min = ((x-(int)x)*60);
sec = (round ((min-(int)min)*60)); 
if(sec==60) { sec=0; min++;}

if (sec>30) {
    
for (j=i; j<n-1; j++) {
        niz [j]=niz [j+1]; 
    
    }
        n--;
        i--;
    } }


printf ("Uglovi su:\n");
for (i=0; i<n; i++) {
    
    x= (niz[i]*(180/PI));
    min = fabs((x-(int)x)*60);
    sec = ((min-(int)min)*60);

    step=(int)x;
    min=(int) min;
    sec=round (sec);
    
if (step>=0) {
    if (sec==60){sec=0; min++;} 
    if (min==60){min=0; step++;}}
    
if (step<0) {
    if (sec==60){sec=0; min++;}
    if (min==60){min=0; step--;}}
    
printf("%.f stepeni %.f minuta %.f sekundi\n", step, min, sec);    
    
}

return 0;

}


    


