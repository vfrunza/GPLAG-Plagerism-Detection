#include <stdio.h>
#include <string.h>
#include <math.h>
#define eps 0.00000001


struct Student {
    char ime[20], prezime[20];
    int ocjene[50];
	int br_ocjena;
};

double f(int *niz, int vel){
    int suma = 0,i;
    double vrati;
    for(i = 0; i < vel; i++)suma += niz[i];
    vrati = suma;
    vrati /= vel;
    return vrati;
}

int genijalci(struct Student *S,int vel,double prosjek){
    double pr,a,b,c;
    int i,j,izbaci,suma,cs,pozicija_prvog = -1,pozicija_drugog = -1,pozicija_treceg = -1;
    for(i = 0; i < vel; i++){
        izbaci = 1;
        /*racunamo prosjek*/
        suma = 0;
        pr = 5.0;
        cs = 1;
        for(j = 0; j < S[i].br_ocjena; j++){
            if(S[i].ocjene[j]  == 5) {cs = 0; break;}
            suma += S[i].ocjene[j];
        }
      if (cs && S[i].br_ocjena != 0)pr = (double)suma / S[i].br_ocjena;
        if(pr * eps < prosjek * eps){
            for(j = i; j < vel - 1; j++) 
                S[j] = S[j + 1];
            vel--;
            i--;
        }
    }
  
    if(vel == 0)return 0;
    //prvi najveci
        pr = f(S[0].ocjene,S[0].br_ocjena);
            for(j = 0; j < vel; j++){
                if(f(S[j].ocjene,S[j].br_ocjena) * eps >= pr * eps){
                    pr = f(S[j].ocjene,S[j].br_ocjena);
                    pozicija_prvog = j;
                }
            }
            
if(pozicija_prvog != -1){
    for(i = 0; i < vel; i++){
        if(f(S[i].ocjene,S[i].br_ocjena) * eps == pr * eps){
            if( strcmp(S[i].prezime,S[pozicija_prvog].prezime) < 0 ) pozicija_prvog = i;
                if((strcmp(S[i].prezime,S[pozicija_prvog].prezime) == 0) &&
                    (strcmp(S[i].ime,S[pozicija_prvog].ime) < 0))pozicija_prvog = i;
        }
    }
}
   
    a = pr;
  //drugi najveci
  if(pozicija_prvog != -1){
    for(i = 0; i < vel; i++){
        pr = f(S[i].ocjene,S[i].br_ocjena);
    if(pr * eps <= a * eps && i != pozicija_prvog) {
            for(j = 0; j < vel; j++){
                if((f(S[j].ocjene,S[j].br_ocjena) * eps >= pr * eps ) &&
                (f(S[j].ocjene,S[j].br_ocjena)  * eps <= a * eps) &&
                j != pozicija_prvog){
                    pr = f(S[j].ocjene,S[j].br_ocjena);
                    b = pr;
                    pozicija_drugog = j;
                }
            }
        }
    }
  }
  
 if(pozicija_drugog != -1){   
    for(i = 0; i < vel; i++){
        if(f(S[i].ocjene,S[i].br_ocjena) * eps == b * eps && i != pozicija_prvog){
            if( strcmp(S[i].prezime,S[pozicija_drugog].prezime) < 0 ) pozicija_drugog = i;
                if((strcmp(S[i].prezime,S[pozicija_drugog].prezime) == 0) &&
                    (strcmp(S[i].ime,S[pozicija_drugog].ime) < 0))pozicija_drugog = i;
        }
    }
 }

    //treci najveci
  if(pozicija_drugog != -1){
    for(i = 0; i < vel; i++){
        pr = f(S[i].ocjene,S[i].br_ocjena);
    if(pr * eps <= b * eps && i != pozicija_prvog && i != pozicija_drugog) {
         pozicija_treceg = j;
            for(j = 0; j < vel; j++){
                if((f(S[j].ocjene,S[j].br_ocjena) * eps >= pr * eps ) && 
                (f(S[j].ocjene,S[j].br_ocjena)  * eps <= b * eps) &&
                 j != pozicija_prvog && j != pozicija_drugog){
                    pr = f(S[j].ocjene,S[j].br_ocjena);
                    c = pr;
                    pozicija_treceg = j;
                }
            }
        }
    }
    
  if(pozicija_treceg != -1){  
    for(i = 0; i < vel; i++){
        if(f(S[i].ocjene,S[i].br_ocjena) * eps == c * eps && i != pozicija_prvog && i != pozicija_drugog){
            if( strcmp(S[i].prezime,S[pozicija_treceg].prezime) < 0 ) pozicija_treceg = i;
                if((strcmp(S[i].prezime,S[pozicija_treceg].prezime) == 0) &&
                    (strcmp(S[i].ime,S[pozicija_treceg].ime) < 0))pozicija_treceg = i;
        }
    }
    }
  
      
  }
        if(pozicija_prvog != -1 && pozicija_drugog != -1 && pozicija_treceg != -1){
        printf("%s %s\n",S[pozicija_prvog].prezime,S[pozicija_prvog].ime);        
        printf("%s %s\n",S[pozicija_drugog].prezime,S[pozicija_drugog].ime);        
        printf("%s %s\n",S[pozicija_treceg].prezime,S[pozicija_treceg].ime);       
        }
        else  if(pozicija_prvog != -1 && pozicija_drugog != -1){
        printf("%s %s\n",S[pozicija_prvog].prezime,S[pozicija_prvog].ime);        
        printf("%s %s\n",S[pozicija_drugog].prezime,S[pozicija_drugog].ime);        
        }
        else if(pozicija_prvog != -1){
            printf("%s %s\n",S[pozicija_prvog].prezime,S[pozicija_prvog].ime);        
        }

    return vel;
}


int main(){
    struct Student studenti[4] ={
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Beba", "Bebic", { 6,6,6,6,6}, 5},
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Fata", "Fatic", { 7,7,7,7,8}, 5}, 
};
genijalci(studenti, 4, 6.5);
    return 0;
}