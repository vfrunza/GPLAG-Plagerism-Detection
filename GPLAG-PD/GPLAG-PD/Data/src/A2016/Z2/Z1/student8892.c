#include <stdio.h>
#include <stdlib.h>


int main() {
    
    int a, b, c, d=0, e=0, n=1, f=0, g=0, i;
    
    printf ("Unesite broj: ");
    scanf ("%d", &a);
    
    
    
    if (a<0){
        a = -a;
        
    }
    
     if (a<10){
        printf ("0");
        return 0;
    }
    
    b= a%10;
    a/=10;
    while (a){
        c=a%10;
        a/=10;
        d= abs( c- b);
        
        if (d!=0) n=0;
        if (d==0 && n==1) e++;
        f= f*10 + d;
        b=c;
    }
    while (f){
        c=f%10;
        f/=10;
        g=g*10 + c;
    }
   
   
    
    if(g==0) {
        printf("0\n");
        return 0;
    }
        printf ("%d", g);
        for (i=0; i<e; i++){
            printf("0");
        }
        printf ("\n");
    
return 0;
}
   
    