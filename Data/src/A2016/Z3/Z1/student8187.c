#include <stdio.h>

int daj_prost() {
    int m=0, n;
    /*ispitivanje da li je broj prost*/   
    do {
        m=0;
        static int p=2;
        for (n=2; n<p; n++)
        {
            if (p%n==0) 
            {
                m++;
            }
            
        }
            if (m==0)
            {
                p++;
                return p-1;
            }
           p++; 
            
        }
    
        while (m!=0);
}

int main() {
    int a,b,c=2,broj,d;
    /* osiguravanje pravilnog unosa brojeva a i b*/
    do {
        printf ("Unesite brojeve A i B: ");
        scanf ("%d%d", &a, &b);
        if (a>=b) 
        {
            printf ("A nije manje od B.\n");
        }
        else if (a<1)
        {
            printf ("A nije prirodan broj.\n");
        }
       
        else break;
    }
    while (c<3);
    
    
    d=0;
    broj=daj_prost();
    /*izracunavanje sume svih prostih brojeva vecih od a i manjih od b uz pomoc uslova i while petlje*/   
    while (broj<b)
    {
        if (a<broj && broj<b)
        d=d+broj;
        broj=daj_prost();
    }
    /*ispisivanje sume*/
    printf ("Suma prostih brojeva izmedju %d i %d je %d.", a,b,d);
	return 0;
}
