#include <stdio.h>

 int dva_od_tri (int niz1[], int vel1, int niz2[], int vel2, int niz3[], int vel3){
     
     int i,j,k,z; 
     int brojac = 0;
     int ponavlja_se = 0; /* varijabla sa kojom ispitujemo da li se ponavlja broj */
     int postoji;
     
     for (i=0; i<vel1; i++){ /* ispitujemo za prvi niz, da li sadrzi iste elem. kao drugi i treci */
        ponavlja_se = 0;
        for (z=0; z<i; z++){
           if (niz1[z] == niz1[i]){
             ponavlja_se = 1;
             break;
           }
        }
        if (ponavlja_se) 
           continue;
        postoji = 0;
        for (j=0; j<vel2; j++){
           ponavlja_se = 0;
           for (z=0; z<j; z++){
              if (niz2[z] == niz2[j]){
                ponavlja_se = 1;
                break;
              }
           }    
           if (ponavlja_se)
             continue;
             
           postoji = 0;
           if (niz1[i] == niz2[j]){
              postoji = 1;
              for (k=0; k<vel3; k++){
                 ponavlja_se = 0;
                 for (z=0; z<k; z++){
                     if (niz3[z] == niz3[k]){
                       ponavlja_se = 1;
                       break;
                     }
                 }
                 if (ponavlja_se)
                    continue;
                 if (niz2[j] == niz3[k]){
                    postoji = 0;
                    break;
                 }
              }
           }
           if (postoji)
             brojac++;
        }
        
        
        
        
        for (k=0; k<vel3; k++){
           ponavlja_se = 0;
           for (z=0; z<k; z++){
              if (niz3[z] == niz3[k]){
                  ponavlja_se = 1;
                  break;
              }
           }
           if (ponavlja_se)
              continue;
           postoji = 0;
           if (niz1[i] == niz3[k]){
              postoji = 1;
                 for (j=0; j<vel2; j++){
                     if (niz1[i] == niz2[j])
                         postoji = 0;
                 }
           }
        
           if (postoji)
              brojac++;
       
        }
      
     }
 
     for (j=0; j<vel2; j++){ /* ispitujemo da li drugi i treci niz imaju iste elemente */
        ponavlja_se = 0;
        for (z=0; z<j; z++){
           if (niz2[z] == niz2[j]){
               ponavlja_se = 1;
               break;
           }
        }
        if (ponavlja_se)
          continue;
        postoji = 0;
        for (k=0; k<vel3; k++){
           ponavlja_se = 0;
           for (z=0; z<k; z++){
                if (niz3[z] == niz3[k]){
                    ponavlja_se = 1;
                    break;
                }
            }
           if (ponavlja_se)
              continue;
           if (niz2[j] == niz3[k]){
               postoji = 1;
               for (i=0; i<vel1; i++){
                   ponavlja_se = 0;
                   for (z=0; z<i; z++){
                       if (niz1[i] == niz1[z]){
                           ponavlja_se = 1;
                           break;
                       }
                   }
                   if (ponavlja_se)
                      continue;
                   if (niz2[j] == niz1[i]){
                       postoji = 0;
                       break;
                    }
                }
                break;
            }
        }
        if (postoji)
          brojac ++;
     }
     
     return brojac;
  }
  
int main (){
    
       
return 0;
}