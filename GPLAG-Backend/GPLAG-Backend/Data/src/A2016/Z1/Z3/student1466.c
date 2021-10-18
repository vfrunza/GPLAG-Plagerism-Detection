#include<stdio.h>
#include<math.h>
#define EPSILON 0.0001
int main()
{
    char boja;
    int c=0,b=0,s=0,v=0,p=0,max;
    float procenat,suma=0;
    
                      printf ("Unesite vozila: ");
                      do {
                          
                                  scanf ("%c", &boja);
        
              if (boja == 'c' || boja== 'C') {
            c++;
            suma++;
        }
        
       else if (boja == 'b' || boja== 'B') {
            b++;
            suma++;
    }
     else if (boja == 's' || boja== 'S') {
            s++;
            suma++;
    }
    else if (boja == 'v'  || boja== 'V') {
            v++;
            suma++;
    }
    else if (boja == 'p' || boja== 'P') {
            p++;
            suma++;
    }
    
    if (boja != 'p' && boja != 'P' && boja != 'v' && boja != 'V' && boja != 's' && boja != 'S' && boja != 'b' && boja != 'B' && boja != 'c' && boja != 'C' && boja != 'k' && boja != 'K') {
        printf ("Neispravan unos\n");
    }
    
                      }
    while (boja != 'k' && boja != 'K');

max=c;

if (b>max) {
    max=b;
}
if (s>max) {
    max=s;
    }
    
    if (v>max) {
    max=v;
}

if (p>max) {
    max=p;
}

if (c>max) {
    max=c;
}

if ((fabs(suma-0)>EPSILON))

procenat=(max*100)/suma;

else if((fabs(suma-0)<EPSILON)) procenat=0;
printf ("Ukupno evidentirano %0.f vozila.\n", suma);

if (max==c) {
    printf ("Najpopularnija boja je crna (%.2f%%).", procenat);
    }
    
    else if (max==b) {
    printf ("Najpopularnija boja je bijela (%.2f%%).", procenat);
    }
    
   else  if (max==s) {

    printf ("Najpopularnija boja je siva (%.2f%%).", procenat);
    }
    
    else if (max==v) {
    printf ("Najpopularnija boja je crvena (%.2f%%).", procenat);
    }

    else if  (max==p) {
    printf ("Najpopularnija boja je plava (%.2f%%).", procenat);
    }
                     
    return 0;
}
    