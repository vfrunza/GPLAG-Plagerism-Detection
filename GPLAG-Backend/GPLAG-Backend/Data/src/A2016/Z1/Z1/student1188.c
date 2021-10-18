#include <stdio.h>

int main() {
  int a=0;
 	double tp1=0,tp2=0,tz,tdr,tp,bp1,bp2,bz,bp,bdr,mp1,mp2,mp,mz,mdr,zbirt=0,zbirb=0,zbirm=0,oct,ocb,ocm;
 	printf("Unesite bodove za Tarika: \n");
 	printf("I parcijalni ispit: ");
 	    scanf("%lf",&tp1);
 	    if(tp1<0||tp1>20)
 	    {printf("Neispravan broj bodova");
 	      return 0;
 	    }
 	    else {
 	printf("II parcijalni ispit: ");
 	    scanf("%lf",&tp2);
 	    if(tp2<0||tp2>20)
 	    {printf("Neispravan broj bodova");
 	      return 0;
 	    }
 	    else{
 	printf("Prisustvo: ");
 	    scanf("%lf",&tp);
 	    if(tp<0||tp>10)
 	    {printf("Neispravan broj bodova");
 	      return 0;
 	    }
 	    else{
 	printf("Zadace: ");
 	    scanf("%lf",&tdr);
 	    if(tdr<0||tdr>10)
 	    {printf("Neispravan broj bodova");
 	      return 0;
 	    }
 	    else{
 	printf("Zavrsni ispit: ");
 	    scanf("%lf",&tz);
 	    if(tz<0||tz>40)
 	    {printf("Neispravan broj bodova");
 	      return 0;
 	    }
 	    else{
 	    
 	    printf("Unesite bodove za Bojana: \n");
 	printf("I parcijalni ispit: ");
 	    scanf("%lf",&bp1);		
 	    if(bp1<0||bp1>20)
 	    {printf("Neispravan broj bodova");
 	      return 0;
 	    }
 	    else{
 	printf("II parcijalni ispit: ");
 	    scanf("%lf",&bp2);
 	    if(bp2<0||bp2>20)
 	    {printf("Neispravan broj bodova");
 	      return 0;
 	    }
 	    else{
 	printf("Prisustvo: ");
 	    scanf("%lf",&bp);
 	    if(bp<0||bp>10)
 	    {printf("Neispravan broj bodova");
 	      return 0;
 	    }
 	    else{
 	printf("Zadace: ");
 	    scanf("%lf",&bdr);
 	     if(bdr<0||bdr>10)
 	    {printf("Neispravan broj bodova");
 	      return 0;
 	    }
 	    else{
 	printf("Zavrsni ispit: ");
 	    scanf("%lf",&bz);
 	     if(bz<0||bz>40)
 	    {printf("Neispravan broj bodova");
 	      return 0;
 	    }
 	    else{
 	    
 	    printf("Unesite bodove za Mirzu: \n");
 	printf("I parcijalni ispit: ");
 	    scanf("%lf",&mp1);
 	     if(mp1<0||mp1>20)
 	    {printf("Neispravan broj bodova");
 	      return 0;
 	    }
 	    else{
 	printf("II parcijalni ispit: ");
 	    scanf("%lf",&mp2);
 	     if(mp2<0||mp2>20)
 	    {printf("Neispravan broj bodova");
 	      return 0;
 	    }
 	    else{
 	printf("Prisustvo: ");
 	    scanf("%lf",&mp);
 	     if(mp<0||mp>10)
 	    {printf("Neispravan broj bodova");
 	      return 0;
 	    }
 	    else{
 	printf("Zadace: ");
 	    scanf("%lf",&mdr);
 	     if(mdr<0||mdr>10)
 	    {printf("Neispravan broj bodova");
 	      return 0;
 	    }
 	    else{
 	printf("Zavrsni ispit: ");
 	    scanf("%lf",&mz);
 	     if(mz<0||mz>40)
 	    {printf("Neispravan broj bodova");
 	      return 0;
 	    }}}}}}}}}}}}}}}
 
 
     zbirt=(tp1+tp2+tp+tz+tdr);
     zbirb=(bp1+bp2+bp+bz+bdr);
     zbirm=(mp1+mp2+mp+mz+mdr);
               if(zbirt<55){
                oct=5;
               }
               if((zbirt>=55)&&(zbirt<65)){
                 oct=6;
               }
               if((zbirt>=65)&&(zbirt<75)){
                 oct=7;
               }
               if((zbirt>=75)&&(zbirt<85)){
                 oct=8;
               }
               if((zbirt>=85)&&(zbirt<92)){
                 oct=9;
               }
               if((zbirt>=92)&&(zbirt<=100)){
                 oct=10;
               }
               
               
               if(zbirb<55){
                ocb=5;
               }
               if((zbirb>=55)&&(zbirb<65)){
                 ocb=6;
               }
               if((zbirb>=65)&&(zbirb<75)){
                 ocb=7;
               }
               if((zbirb>=75)&&(zbirb<85)){
                 ocb=8;
               }
               if((zbirb>=85)&&(zbirb<92)){
                 ocb=9;
               }
               if((zbirb>=92)&&(zbirb<=100)){
                 ocb=10;
               }
               
               
               if(zbirm<55){
                ocm=5;
               }
               if((zbirm>=55)&&(zbirm<65)){
                 ocm=6;
               }
               if((zbirm>=65)&&(zbirm<75)){
                 ocm=7;
               }
               if((zbirm>=75)&&(zbirm<85)){
                 ocm=8;
               }
               if((zbirm>=85)&&(zbirm<92)){
                 ocm=9;
               }
               if((zbirm>=92)&&(zbirm<=100)){
                 ocm=10;
               }
               
               
               if((oct==5)&&(ocb==5)&&(ocm==5)){
                 printf("Nijedan student nije polozio.\n");
               }
               if(oct>5){
                 a++;
               }
               if(ocb>5){
                 a++;
               }
               if(ocm>5){
                a++;
               }
               
               if(a==1){
                 printf("Jedan student je polozio.\n");
               }
               if(a==2){
                 printf("Dva studenta su polozila.\n");
               }
               if(a==3){
                 printf("Sva tri studenta su polozila.\n");
                 if((oct==ocb)&&(ocb==ocm)){
                   printf("Sva tri studenta imaju istu ocjenu.\n");
                 }
                 else if((oct==ocb)||(oct==ocm)||(ocm==ocb)){
                   printf("Dva od tri studenta imaju istu ocjenu.\n");
                 }
                 else {
                   printf("Svaki student ima razlicitu ocjenu.\n");
                 }
               }
 
               return 0;
 	     
 	    }