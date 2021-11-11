#include <stdio.h>
#include <math.h>
#include <stdlib.h>

  void zaokruzi1 (float *niz, int vel){
    int i;
    for (i=0; i<vel; i++){
      *niz = round(*niz*10)/10;
      niz++;
    }
  }
  
  int zbir_cifara (int n){
     int broj=n, suma = 0;
     while (broj!=0){
       suma += (broj % 10);
       broj /= 10;
     }
    return suma;
  }
  
  void preslozi (float *p, int vel, int k){
     zaokruzi1(p,vel);
     int i;
     int niz01[50000]; /* u ovaj niz cemo upisivati 1 ako clan sa tim indeksom je veci ili jednak od k,
     a u suprotnom je 0 */
     for (i=0; i<vel; i++){
        float br = (*(p+i)*10);
        int broj = br;
        if (zbir_cifara(abs(broj)) >= k)
           niz01[i] = 1;
        else
           niz01[i] = 0;
     }
     
     /* sada treba sortirati niz, tako da clanove ciji je index niza01 = 1 budu naprijed */
     float *pok = p;
     int j;
     float br;
     for (i=0; i<vel; i++){
         pok = p;
         j = i;
         while (niz01[j]==0 && (pok<p+vel-i)){
             j++;
             pok++;
             if (j==vel)
                break;
         }
         if (pok == p+vel-i){
             pok++;
             continue;
         }
         br = *pok;
         
         while (pok != p) {
             *pok = *(pok-1);
             pok--;
         }
         *p = br;
         niz01[j]=0;
         niz01[i]=1;
         p++;
         
    }
  }
  
int main() {
    
	
	return 0;
}