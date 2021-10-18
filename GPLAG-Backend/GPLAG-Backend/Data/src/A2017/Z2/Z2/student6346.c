#include <stdio.h>
#include <math.h>
#define A 100
#define B 1000
int main()
{
    int niz[A],niz1[100],niz2[1000],i,c;
    int n,brojac;
    do {
        printf("Unesite velicinu niza: ");
        scanf("%d", &n);

    } while (n<0 || n>100);

    printf("Unesite clanove niza: ");

    for(i=0; i<n; i++) {
        brojac=0;
        scanf("%d", &niz[i]) ;
            while(niz[i]!=0){
        c=niz[i]%10;
        niz[i]=niz[i]/10;
        brojac++;
        niz1[i]=c;
        
      }
      
      
      for(i=brojac; i>0; i--){
        niz2[i]=niz1[i];
      }
        }
        
      printf("Finalni niz glasi:\n");
        


    

    
    
        
   

    
    return 0;
}