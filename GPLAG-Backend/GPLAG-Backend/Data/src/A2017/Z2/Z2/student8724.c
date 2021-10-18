#include <stdio.h>

int main() {
    int niz1 [100], pomocni_niz [1000], niz2 [1000], i, vel_niza, brojac, cifra[10], j, k=0, l=0, element;
    /*unos velicine niza*/
    printf ("Unesite velicinu niza: ");
    while (1)
        {
            scanf ("%d", &vel_niza);
            if (vel_niza>0) break;
        }
    /*unos clanova niza*/
    printf ("Unesite clanove niza: ");
    for (i=0; i<vel_niza; i++)
         {
             scanf ("%d", &niz1[i]);
             if (niz1[i]<0)
                {
                    i--;
                    continue;
                }   
         
         /*rastavljanje niza na cifre*/
            brojac=0;
            element=niz1[i];
            do {
                cifra[brojac] = element%10;
                 brojac++;
                 element/=10;
                 }  while (element);
            for  (j=0; j<brojac; j++)
                 pomocni_niz [k+j]=cifra[brojac-j-1];
            k+=brojac;     
        }

        /*jednakost susjednih cifara*/
    for (i=0; i<k; i++)
        { 
            brojac=0;
           for (j=i; j<k; j++)
           {
               if (pomocni_niz[j]==pomocni_niz[i]) brojac++;
               else break;
           }
        
          /*kreiranje finalnog niza*/
          niz2[l]=pomocni_niz[i];
          l++;
          niz2[l]=brojac;
          l++;
          i+=brojac-1;
         
        }
      /*ispis niza*/
    printf ("Finalni niz glasi:\n");    
    for (i=0; i<l; i++)
       printf ("%d ", niz2[i]);
	return 0;
}
