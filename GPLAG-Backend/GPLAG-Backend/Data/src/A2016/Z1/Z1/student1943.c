#include <stdio.h>

int main() {
      float parc11,parc12,prisustvo1,zadace1,zavrsni1;
      float parc21,parc22,prisustvo2,zadace2,zavrsni2;
      float parc31,parc32,prisustvo3,zadace3,zavrsni3;
      float bodovi1=0,bodovi2=0,bodovi3=0;
      int br=0;
      int ocjena1=0,ocjena2=0,ocjena3;
      printf("Unesite bodove za Tarika: \n");
      printf("I parcijalni ispit: ");
      scanf("%f",&parc11);
       if(parc11<0 || parc11>20) { printf("Neispravan broj bodova"); return 0; }
      printf("II parcijalni ispit: ");
      scanf("%f",&parc12);
      if(parc12<0 || parc12>20) { printf("Neispravan broj bodova"); return 0; }
      printf("Prisustvo: ");
      scanf("%f",&prisustvo1);
       if(prisustvo1<0 || prisustvo1>10) { printf("Neispravan broj bodova"); return 0; }
      printf("Zadace: ");
      scanf("%f",&zadace1);
      if(zadace1<0 || zadace1>10) { printf("Neispravan broj bodova"); return 0; }
      printf("Zavrsni ispit: ");
      scanf("%f",&zavrsni1);
      if(zavrsni1<0 || zavrsni1>40) {printf("Neispravan broj bodova"); return 0; }
      
      
      printf("Unesite bodove za Bojana: \n");
      printf("I parcijalni ispit: ");
      scanf("%f",&parc21);
        if(parc21<0 || parc21>20) { printf("Neispravan broj bodova"); return 0; }
      printf("II parcijalni ispit: ");
      scanf("%f",&parc22);
        if(parc22<0 || parc22>20) {  printf("Neispravan broj bodova"); return 0; }
      printf("Prisustvo: ");
      scanf("%f",&prisustvo2);
       if(prisustvo2<0 || prisustvo2>10) { printf("Neispravan broj bodova"); return 0; }
     
      printf("Zadace: ");
      scanf("%f",&zadace2);
       if(zadace2<0 || zadace2>10) { printf("Neispravan broj bodova"); return 0; }
      printf("Zavrsni ispit: ");
     scanf("%f",&zavrsni2);
       if(zavrsni2<0 || zavrsni1>40) {printf("Neispravan broj bodova"); return 0; }
       
       
    
      printf("Unesite bodove za Mirzu: \n");
      printf("I parcijalni ispit: ");
      scanf("%f",&parc31);
       if(parc31<0 || parc31>20) { printf("Neispravan broj bodova"); return 0; }
      printf("II parcijalni ispit: ");
      scanf("%f",&parc32);
      if(parc32<0 || parc32>20) { printf("Neispravan broj bodova"); return 0; }
      printf("Prisustvo: ");
      scanf("%f",&prisustvo3);
       if(prisustvo3<0 || prisustvo3>10) { printf("Neispravan broj bodova"); return 0; }
      printf("Zadace: ");
      scanf("%f",&zadace3);
      if(zadace3<0 || zadace3>10) { printf("Neispravan broj bodova"); return 0; }
      printf("Zavrsni ispit: ");
      scanf("%f",&zavrsni3);
       if(zavrsni3<0 || zavrsni3>40) {printf("Neispravan broj bodova"); return 0; }
       
      
      
      
      bodovi1=parc11+parc12+prisustvo1+zadace1+zavrsni1;
       bodovi1=(int)(bodovi1*100+0.5)/100;
      if(bodovi1>=55 && bodovi1<65) ocjena1=6;
      else if(bodovi1>=65 && bodovi1<75) ocjena1=7;
      else if(bodovi1>=75 && bodovi1<85) ocjena1=8;
      else if(bodovi1>=85 && bodovi1<92) ocjena1=9;
      else if(bodovi1>=92 && bodovi1<=100) ocjena1=10;
      else ocjena1=5;
      
       bodovi2=parc21+parc22+prisustvo2+zadace2+zavrsni2;
       bodovi2=(int) (bodovi2*100+0.5)/100;
      if(bodovi2>=55 && bodovi2<65) ocjena2=6;
      else if(bodovi2>=65 && bodovi2<75) ocjena2=7;
      else if(bodovi2>=75 && bodovi2<85) ocjena2=8;
      else if(bodovi2>=85 && bodovi2<92) ocjena2=9;
      else if(bodovi2>=92 && bodovi2<=100) ocjena2=10;
      else ocjena2=5;
      
      bodovi3=parc31+parc32+prisustvo3+zadace3+zavrsni3;
      bodovi3=(int) (bodovi3*100+0.5)/100;
      if(bodovi3>=55 && bodovi3<65) ocjena3=6;
      else if(bodovi3>=65 && bodovi3<75) ocjena3=7;
      else if(bodovi3>=75 && bodovi3<85) ocjena3=8;
      else if(bodovi3>=85 && bodovi3<92) ocjena3=9;
      else if(bodovi3>=92 && bodovi3<=100) ocjena3=10;
      else ocjena3=5;
      
       if(bodovi1>=55) br++;
      if(bodovi2>=55) br++;
      if(bodovi3>=55) br++;
      
      if(br==1) printf("Jedan student je polozio.");
      else if(br==2) printf("Dva studenta su polozila.");
      else if(br==3) { 
      	               printf("Sva tri studenta su polozila.");
      	               if(ocjena1==ocjena2 && ocjena1==ocjena3) printf("\nSva tri studenta imaju istu ocjenu.");
      	               else if((ocjena1==ocjena2 && ocjena1!=ocjena3) || (ocjena1==ocjena3 && ocjena1!=ocjena2) || (ocjena2==ocjena3 &&ocjena2!=ocjena1)) printf("\nDva od tri studenta imaju istu ocjenu.");
      	               else printf("\nSvaki student ima razlicitu ocjenu.");
      }
      
     else printf("Nijedan student nije polozio.");
      
      return 0;
      }
