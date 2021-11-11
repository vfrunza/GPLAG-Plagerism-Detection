#include <stdio.h>
#include<math.h>
#include<stdlib.h>
void ubaci (int *niz, int DUPLO)
{
    int m,rastavi_cifru=0,zbir_cifara=0,elem;
                                                   /*pripremamo niz i prosirujemo ga*/
    for(m=DUPLO-1; m>=0; m--)
    {
        niz[2*m]=niz[m];                             /*NIz prosiren*/
    }
                                                /*U slucajuu da ne dode do greske*/
    for(m=0; m<2*DUPLO; m+=2)
    {
        elem=abs(niz[m]);
        if(elem<10)
        {
            zbir_cifara=elem;
        }
        else
        {
        
      do {
            rastavi_cifru=elem%10;      /*petlja racuna zbir cifara i novi elem koji unosi u petlju sve dok taj elem nije nula*/
           zbir_cifara=zbir_cifara+rastavi_cifru;
           elem=elem/10;
        } while(elem!=0);
        
         }                                                         /*ubacujem dobiveni zbir cifre izmedju dva elem i dodijelim mu dobiveni broj*/
         niz[m+1]=zbir_cifara;
             zbir_cifara=0;
         
    }
}
                                                       /*NOVA FUNKCIJA ZA IZBACIVANJE CLANOVA*/
                                                       
        
             
    int izbaci(int*niz, int DUPLO)                                /*funkcija izbacuje fibonacci brojeve iz niza*/
    {
            int i,j,prvi_broj=1,drugi_broj=1,zbir_brojeva=0;
            for(i=0; i<DUPLO; i++)
            {
                prvi_broj=1;
                drugi_broj=1;
                
                    for(j=i; j<1000; j++)
                    {
                        if(j==1)
                        {
                            zbir_brojeva=1;
                        }
                        else {
                            zbir_brojeva=prvi_broj+drugi_broj;
                            prvi_broj=drugi_broj;
                            drugi_broj=zbir_brojeva;
                        }
                        if(niz[i]==zbir_brojeva)
                        {
                            for(zbir_brojeva=i; zbir_brojeva<DUPLO-1; zbir_brojeva++)
                            {
                                niz[zbir_brojeva]=niz[zbir_brojeva+1];
                            }
                            DUPLO--;
                            i--;
                            break;
                        }
                    
                }
            }
            return DUPLO;
            
        
        
}
    
int main() {
  int niz[100],i,mojniz,duzina_niza=0;
  printf("Unesite niz od 10 brojeva: ");
  for(i=0; i<20; i++)
   {
       duzina_niza++;
       scanf("%d", &niz[i]);
   }
   ubaci(niz, duzina_niza);
   mojniz=(niz, duzina_niza);
   
    printf("Modificiran niz glasi: ");
    for(i=0; i<mojniz; i++)
    {
        if(i==mojniz-1)
        {
        printf("%d.", niz[i]);
        }
    
    else {
        printf("%d", niz[i]);
    }
    }
	return 0;
    }
