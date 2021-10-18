#include <stdio.h>
#include <math.h>

int main(){
	float Pp, Dp, Prisus, Zad, Isp, Bod;
	int Ocj1, Ocj2, Ocj3;
    
/*Tarik*/    
    printf("Unesite bodove za Tarika: \n");
    
    printf("I parcijalni ispit: ");
    scanf("%f", &Pp);
    	if (Pp>=0 && Pp<=20){    
    printf("II parcijalni ispit: ");
	scanf("%f", &Dp);
		if (Dp>=0 && Dp<=20){
	printf("Prisustvo: ");
	scanf("%f", &Prisus);
		if (Prisus>=0 && Prisus<=10) {
	printf("Zadace: ");
	scanf("%f", &Zad);
		if (Zad>=0 && Zad<=10){
	printf("Zavrsni ispit: ");
	scanf("%f", &Isp);
		if (Isp>=0 && Isp<=40){
    
    Bod=Pp+Dp+Prisus+Zad+Isp;
    Bod=(int)(Bod*1000+0.5)/1000;
    
    if (Bod<55){
	      	Ocj1=5;}
	else if (Bod>=55 && Bod<65){
	      	Ocj1=6;}
	else if (Bod>=65 && Bod<75){
            Ocj1=7;}
	else if (Bod>=75 && Bod<85){
	      	Ocj1=8;}
	else if (Bod>=85 && Bod<92){
	      	Ocj1=9;}
	else if (Bod>=92 && Bod<=100){
	      	Ocj1=10;}}
           else { printf("Neispravan broj bodova"); return 0;}
	    }
	       else { printf("Neispravan broj bodova"); return 0;}
	    }
	       else { printf("Neispravan broj bodova"); return 0;}
	    }
	       else { printf("Neispravan broj bodova"); return 0;} 
        }
        else { printf("Neispravan broj bodova"); return 0;}

/*Bojan*/
    printf("Unesite bodove za Bojana: \n");
   
    printf("I parcijalni ispit: ");
    scanf("%f", &Pp);
    	if (Pp>=0 && Pp<=20){    
    printf("II parcijalni ispit: ");
	scanf("%f", &Dp);
		if (Dp>=0 && Dp<=20){
	printf("Prisustvo: ");
	scanf("%f", &Prisus);
		if (Prisus>=0 && Prisus<=10) {
	printf("Zadace: ");
	scanf("%f", &Zad);
		if (Zad>=0 && Zad<=10){
	printf("Zavrsni ispit: ");
	scanf("%f", &Isp);
		if (Isp>=0 && Isp<=40)
        {
    Bod=Pp+Dp+Prisus+Zad+Isp;
    Bod=(int)(Bod*1000+0.5)/1000;
    
    if (Bod<55){
	      	Ocj2=5;}
	else if (Bod>=55 && Bod<65){
	      	Ocj2=6;}
	else if (Bod>=65 && Bod<75){
            Ocj2=7;}
	else if (Bod>=75 && Bod<85){
	      	Ocj2=8;}
	else if (Bod>=85 && Bod<92){
	      	Ocj2=9;}
	else if (Bod>=92 && Bod<=100){
	      	Ocj2=10;}
        }
           else { printf("Neispravan broj bodova"); return 0;}
	    }
	       else { printf("Neispravan broj bodova"); return 0;}
	    }
	       else { printf("Neispravan broj bodova"); return 0;}
	    }
	       else { printf("Neispravan broj bodova"); return 0;} 
        }
        else { printf("Neispravan broj bodova"); return 0;}

/*Mirza*/
    printf("Unesite bodove za Mirzu: \n");
    
    printf("I parcijalni ispit: ");
    scanf("%f", &Pp);
    	if (Pp>=0 && Pp<=20){    
    printf("II parcijalni ispit: ");
	scanf("%f", &Dp);
		if (Dp>=0 && Dp<=20){
	printf("Prisustvo: ");
	scanf("%f", &Prisus);
		if (Prisus>=0 && Prisus<=10) {
	printf("Zadace: ");
	scanf("%f", &Zad);
		if (Zad>=0 && Zad<=10){
	printf("Zavrsni ispit: ");
	scanf("%f", &Isp);
		if (Isp>=0 && Isp<=40){
   
    Bod=Pp+Dp+Prisus+Zad+Isp;
    Bod=(int)(Bod*1000+0.5)/1000;
    
    	if (Bod<55)
	      {
	      	Ocj3=5;}
	else if (Bod>=55 && Bod<65){
	      	Ocj3=6;}
	else if (Bod>=65 && Bod<75){
            Ocj3=7;}
	else if (Bod>=75 && Bod<85){
	      	Ocj3=8;}
	else if (Bod>=85 && Bod<92){
	      	Ocj3=9;}
	else if (Bod>=92 && Bod<=100){
	      	Ocj3=10;}
        }
           else { printf("Neispravan broj bodova"); return 0;}
	    }
	       else { printf("Neispravan broj bodova"); return 0;}
	    }
	       else { printf("Neispravan broj bodova"); return 0;}
	    }
	       else { printf("Neispravan broj bodova"); return 0;} 
        }
        else { printf("Neispravan broj bodova"); return 0;}

     if (Ocj1>5 && Ocj2>5 && Ocj3>5)
       { 
     printf("Sva tri studenta su polozila.\n"); 
     if (Ocj1!=Ocj2 && Ocj1!=Ocj3 && Ocj2!=Ocj3) { 
     	printf("Svaki student ima razlicitu ocjenu.");}
     
     if (Ocj1==Ocj2 && Ocj2==Ocj3) {	
     	printf("Sva tri studenta imaju istu ocjenu.\n"); }
     
     if (Ocj1==Ocj2) { printf("Dva od tri studenta imaju istu ocjenu."); }
     if (Ocj1==Ocj3) { printf("Dva od tri studenta imaju istu ocjenu."); }
     if (Ocj2==Ocj3) { printf("Dva od tri studenta imaju istu ocjenu."); }
       }
     if (Ocj1>5 && Ocj2>5 && Ocj3<6) { printf("Dva studenta su polozila.");}
     if (Ocj1>5 && Ocj2>6 && Ocj3<5) { printf("Dva studenta su polozila.");}
     if (Ocj1>6 && Ocj2>5 && Ocj3<5) { printf("Dva studenta su polozila.");}
     if (Ocj1<6 && Ocj2<6 && Ocj3>5) { printf("Jedan student je polozio.");}
     if (Ocj1<6 && Ocj2>5 && Ocj3<6) { printf("Jedan student je polozio.");}
     if (Ocj1>5 && Ocj2<6 && Ocj3<6) { printf("Jedan student je polozio.");}
     if (Ocj1<6 && Ocj2<6 && Ocj3<6) { printf("Nijedan student nije polozio.");}
     
     
return 0;
}