#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, rezultat=0, brojacCifara=0,zadnjaCifra, predzadnjaCifra, razlikaCifara, i;
    
       printf("Unesite broj: ");
       scanf ("%d", &n);
       
       n = abs(n);
       
       if((n / 10)==0) {
           rezultat = 0;
            }
            else {
           while(n !=0) {
           zadnjaCifra = n%10;
           predzadnjaCifra = (n / 10) % 10;
           if ((n/10)!=0) {
               razlikaCifara = abs(predzadnjaCifra - zadnjaCifra);
               for (i=0; i < brojacCifara; i++) 
                   razlikaCifara *= 10;
                   rezultat = razlikaCifara + rezultat;
           }
               
               n = n / 10;
               brojacCifara++;
                
                }
            }
    printf("%d\n", rezultat);
    return 0;
}