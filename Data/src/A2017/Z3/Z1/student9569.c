#include <stdio.h>

int dva_od_tri(int niz1[], int n1, int niz2[], int n2, int niz3[], int n3){
    int i=0,j=0,br,rj=0,broj;
    for(i=0; i<n1; i++){
        broj = niz1[i];
        br=1;
        if(i>0){                        //Provjeravamo da li se broj ponavljao samo ako pristupamo elemetima koji su iza prvog
            for(j=0; j<i; j++)
                if(niz1[j]==broj) break;        //ako smo broj vec jednom provjerili, nema potrebe opet. Cak bi rjesenje bilo pogresno jer bi se dato rj vise puta brojalo
            if(j<i) continue;
        }
        for(j=0; j<n2; j++){            //Provjeravamo ima li broj u nizu2 i povcamo brojac ako ima
            if(niz2[j]==broj){
                br++;
                break;
            }
        }
        for(j=0; j<n3; j++){        //Provjeravamo ima li broja u nizu 3 i povecavamo brojac ako ima
            if(niz3[j]==broj){
                br++;
                break;
            }
        }
        if(br==2) rj++;             //Ako brojac iznosi 2, onda broja ima u 2 od 3 niza i povecavamo brojac naseg rjesenja
    }
    for(i=0; i<n2; i++){
        int ponovo=0;
        for(j=0; j<n1; j++){
            if(niz1[j]==niz2[i]){
                ponovo=1;
                break;
            }
        }
        if(ponovo==1) continue;
        
        if(i>0){
            for(j=0; j<i; j++)
                if(niz2[j]==niz2[i]) break;        //ako smo broj vec jednom provjerili, nema potrebe opet. Cak bi rjesenje bilo pogresno jer bi se dato rj vise puta brojalo
            if(j<i) continue;
        }
        
        for(j=0; j<n3; j++){
            if(niz2[i]==niz3[j]){
                rj++;
                break;
            }
        }
    }
    return rj;
	
}


int main() {
/* AT1: Primjer iz zadatka */
int niz1[] = {1, 2, 3, 5};
int niz2[] = {1, 2, 4, 6, 7};
int niz3[] = {1, 3, 4, 8, 9, 10};
int rez = dva_od_tri(niz1, 4, niz2, 5, niz3, 6);
printf("%d", rez);
}
