#include <stdio.h>

int Funkcija(int niz1[], int vel1, int niz2[], int vel2, int niz3[], int vel3){
     int i, j, k, l, istiunizu=0, ima12=0, ima13=0, brojac=0;
   for(i=0; i<vel1;  i++){
       istiunizu=0;
       for(j=i+1; j<vel1; j++){
           if(niz1[i]==niz1[j]){
               istiunizu=1;
               break;
           }
       }
       if(istiunizu==1) continue;
       for(k=0; k<vel2; k++){
           ima12=0;
           if(niz1[i]==niz2[k]){
               ima12=1; 
               break;
           }
       }
       for(l=0; l<vel3; l++){
           ima13=0;
           if(niz1[i]==niz3[l]){
               ima13=1;
               break;
           }
       }
       if(ima12==1 && ima13==0) brojac++;
       else if(ima12==0 && ima13==1) brojac++;
   }   
   return brojac;
}
int dva_od_tri(int niz1[], int vel1, int niz2[], int vel2, int niz3[], int vel3){
    int brojac=0;
    brojac+=Funkcija(niz1,vel1,niz2,vel2,niz3,vel3);
    brojac+=Funkcija(niz2,vel2,niz3,vel3,niz1,vel1);
    brojac+=Funkcija(niz3,vel3,niz2,vel2,niz1,vel1);
    

   return brojac/2;
}
int main(){
    return 0;
}