#include <stdio.h>

int main() {
	double prvi1, drugi1, zavrsni1, prisustvo1, zadaca1, prvi2, drugi2, zavrsni2, prisustvo2, zadaca2, prvi3, drugi3, zavrsni3, prisustvo3, zadaca3, ocjena1, ocjena2, ocjena3;
	printf("\nUnesite bodove za Tarika:");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &prvi1); if(prvi1<0 || prvi1>20){ printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf", &drugi1); if(drugi1<0 || drugi1>20){ printf("Neispravan broj bodova"); return 0;}
		printf("Prisustvo: "); 
	scanf("%lf", &prisustvo1); if(prisustvo1<0 || prisustvo1>10){ printf("Neispravan broj bodova"); return 0;}
		printf("Zadace: ");
	scanf("%lf", &zadaca1); if(zadaca1<0 || zadaca1>10){ printf("Neispravan broj bodova"); return 0;}
			printf("Zavrsni ispit: ");
	scanf("%lf", &zavrsni1); if(zavrsni1<0 || zavrsni1>40){ printf("Neispravan broj bodova"); return 0;}
		printf("Unesite bodove za Bojana: ");
			printf("\nI parcijalni ispit: ");
	scanf("%lf", &prvi2); if(prvi2<0 || prvi2>20){ printf("Neispravan broj bodova"); return 0;}
		printf("II parcijalni ispit: ");
	scanf("%lf", &drugi2); if(drugi2<0 || drugi2>20){ printf("Neispravan broj bodova"); return 0;}
			printf("Prisustvo: "); 
	scanf("%lf", &prisustvo2);if(prisustvo2<0 || prisustvo2>10){ printf("Neispravan broj bodova"); return 0;}
			printf("Zadace: "); 
	scanf("%lf", &zadaca2); if(zadaca2<0 || zadaca2>10){ printf("Neispravan broj bodova"); return 0;}
				printf("Zavrsni ispit: ");
	scanf("%lf", &zavrsni2); if(zavrsni2<0 || zavrsni2>40){ printf("Neispravan broj bodova"); return 0;}
			printf("Unesite bodove za Mirzu: ");
						printf("\nI parcijalni ispit: ");
	scanf("%lf", &prvi3); if(prvi3<0 || prvi3>20){ printf("Neispravan broj bodova"); return 0;}
			printf("II parcijalni ispit: ");
	scanf("%lf", &drugi3); if(drugi3<0 || drugi3>20){ printf("Neispravan broj bodova"); return 0;}
				printf("Prisustvo: ");
	scanf("%lf", &prisustvo3); if(prisustvo3<0 || prisustvo3>10){ printf("Neispravan broj bodova"); return 0;}
				printf("Zadace: ");
	scanf("%lf", &zadaca3); if(zadaca3<0 || zadaca3>10){ printf("Neispravan broj bodova"); return 0;}
				printf("Zavrsni ispit: ");
	scanf("%lf", &zavrsni3); if(zavrsni3<0 || zavrsni3>40){ printf("Neispravan broj bodova"); return 0;}
	if(prvi1<0 || prvi1>20 || prvi2<0 || prvi2>20 || prvi3<0 || prvi3>20 || drugi1<0 ||
	drugi2<0 || drugi3<0 || drugi1>20 || drugi2>20 || drugi3>20 || zadaca1<0 || zadaca1>10 || zadaca2<0 || zadaca2>10 || zadaca3<0 || zadaca3>10 ||
	prisustvo1<0 || prisustvo1>10 || prisustvo2>10 || prisustvo2<0 || prisustvo3<0 || prisustvo3>10 ||
	zavrsni1<0 || zavrsni2<0 || zavrsni3<0 || zavrsni1>40 || zavrsni2>40 || zavrsni3>40){ printf("Neispravan broj bodova"); return 0;}
	else{
		ocjena1=prvi1+drugi1+prisustvo1+zavrsni1+zadaca1;
		ocjena2=prvi2+drugi2+prisustvo2+zavrsni2+zadaca2;
		ocjena3=prvi3+drugi3+prisustvo3+zavrsni3+zadaca3;
		if(ocjena1<55 && ocjena2<55 && ocjena3<55){ printf("Nijedan student nije polozio.");}
			if(ocjena1>=55 && ocjena2<55 && ocjena3<55){ printf("Jedan student je polozio.");}
			if(ocjena1<55 && ocjena2>=55 && ocjena3<55){ printf("Jedan student je polozio.");}
			if(ocjena1<55 && ocjena2<55 && ocjena3>=55){ printf("Jedan student je polozio.");}
			
		if(ocjena1<55 && ocjena2>55 && ocjena3>55){ printf("Dva studenta su polozila.");}
     	if(ocjena1>55 && ocjena2<55 && ocjena3>55){ printf("Dva studenta su polozila.");}
     	if(ocjena1>55 && ocjena2>55 && ocjena3<55){ printf("Dva studenta su polozila.");}
     	
     	if(ocjena1>=55 && ocjena2>=55 && ocjena3>=55){ printf("Sva tri studenta su polozila.");
     		if(ocjena1>=55 && ocjena2>=55 && ocjena3>=55 && ocjena1<65 && ocjena2<65 && ocjena3<65) {printf("\nSva tri studenta imaju istu ocjenu.");}
     		if(ocjena1>=65 && ocjena2>=65 && ocjena3>=65 && ocjena1<75 && ocjena2<75 && ocjena3<75) {printf("\nSva tri studenta imaju istu ocjenu.");}
     		if(ocjena1>=75 && ocjena2>=75 && ocjena3>=75 && ocjena1<85 && ocjena2<85 && ocjena3<85) {printf("\nSva tri studenta imaju istu ocjenu.");}
     		if(ocjena1>=85 && ocjena2>=85 && ocjena3>=85 && ocjena1<92 && ocjena2<92 && ocjena3<92) {printf("\nSva tri studenta imaju istu ocjenu.");}
        	if(ocjena1>=92 && ocjena2>=92 && ocjena3>=92 && ocjena1<=100 && ocjena2<=100 && ocjena3<=100) {printf("\nSva tri studenta imaju istu ocjenu.");}
        	
        if(ocjena1>=55 && ocjena2>=55 && ocjena1<65 && ocjena2<65 && ocjena3>=65 && ocjena3<75) {printf("\nDva od tri studenta imaju istu ocjenu.");}	
        if(ocjena1>=55 && ocjena2>=55 && ocjena1<65 && ocjena2<65 && ocjena3>=75 && ocjena3<85) {printf("\nDva od tri studenta imaju istu ocjenu.");}
        if(ocjena1>=55 && ocjena2>=55 && ocjena1<65 && ocjena2<65 && ocjena3>=85 && ocjena3<92) {printf("\nDva od tri studenta imaju istu ocjenu.");}
        if(ocjena1>=55 && ocjena2>=55 && ocjena1<65 && ocjena2<65 && ocjena3>=92 && ocjena3<=100) {printf("\nDva od tri studenta imaju istu ocjenu.");}
        
         if(ocjena3>=55 && ocjena2>=55 && ocjena3<65 && ocjena2<65 && ocjena1>=65 && ocjena1<75) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         if(ocjena3>=55 && ocjena2>=55 && ocjena3<65 && ocjena2<65 && ocjena1>=75 && ocjena1<85) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         if(ocjena3>=55 && ocjena2>=55 && ocjena3<65 && ocjena2<65 && ocjena1>=85 && ocjena1<92) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         if(ocjena3>=55 && ocjena2>=55 && ocjena3<65 && ocjena2<65 && ocjena1>=92 && ocjena1<=100) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         
         if(ocjena3>=55 && ocjena1>=55 && ocjena3<65 && ocjena1<65 && ocjena2>=65 && ocjena2<75) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         if(ocjena3>=55 && ocjena1>=55 && ocjena3<65 && ocjena1<65 && ocjena2>=75 && ocjena2<85) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         if(ocjena3>=55 && ocjena1>=55 && ocjena3<65 && ocjena1<65 && ocjena2>=85 && ocjena2<92) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         if(ocjena3>=55 && ocjena1>=55 && ocjena3<65 && ocjena1<65 && ocjena2>=92 && ocjena2<=100) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         
        if(ocjena1>=65 && ocjena2>=65 && ocjena1<75 && ocjena2<75 && ocjena3>=55 && ocjena3<65) {printf("\nDva od tri studenta imaju istu ocjenu.");}	
        if(ocjena1>=65 && ocjena2>=65 && ocjena1<75 && ocjena2<75 && ocjena3>=75 && ocjena3<85) {printf("\nDva od tri studenta imaju istu ocjenu.");}
        if(ocjena1>=65 && ocjena2>=65 && ocjena1<75 && ocjena2<75 && ocjena3>=85 && ocjena3<92) {printf("\nDva od tri studenta imaju istu ocjenu.");}
        if(ocjena1>=65 && ocjena2>=65 && ocjena1<75 && ocjena2<75 && ocjena3>=92 && ocjena3<=100) {printf("\nDva od tri studenta imaju istu ocjenu.");}
        
         if(ocjena3>=65 && ocjena2>=65 && ocjena3<75 && ocjena2<75 && ocjena1>=55 && ocjena1<65) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         if(ocjena3>=65 && ocjena2>=65 && ocjena3<75 && ocjena2<75 && ocjena1>=75 && ocjena1<85) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         if(ocjena3>=65 && ocjena2>=65 && ocjena3<75 && ocjena2<75 && ocjena1>=85 && ocjena1<92) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         if(ocjena3>=65 && ocjena2>=65 && ocjena3<75 && ocjena2<75 && ocjena1>=92 && ocjena1<=100) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         
         if(ocjena3>=65 && ocjena1>=65 && ocjena3<75 && ocjena1<75 && ocjena2>=55 && ocjena2<65) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         if(ocjena3>=65 && ocjena1>=65 && ocjena3<75 && ocjena1<75 && ocjena2>=75 && ocjena2<85) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         if(ocjena3>=65 && ocjena1>=65 && ocjena3<75 && ocjena1<75 && ocjena2>=85 && ocjena2<92) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         if(ocjena3>=65 && ocjena1>=65 && ocjena3<75 && ocjena1<75 && ocjena2>=92 && ocjena2<=100) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         
          if(ocjena1>=75 && ocjena2>=75 && ocjena1<85 && ocjena2<85 && ocjena3>=55 && ocjena3<65) {printf("\nDva od tri studenta imaju istu ocjenu.");}	
        if(ocjena1>=75 && ocjena2>=75 && ocjena1<85 && ocjena2<85 && ocjena3>=65 && ocjena3<75) {printf("\nDva od tri studenta imaju istu ocjenu.");}
        if(ocjena1>=75 && ocjena2>=75 && ocjena1<85 && ocjena2<85 && ocjena3>=85 && ocjena3<92) {printf("\nDva od tri studenta imaju istu ocjenu.");}
        if(ocjena1>=75 && ocjena2>=75 && ocjena1<85 && ocjena2<85 && ocjena3>=92 && ocjena3<=100) {printf("\nDva od tri studenta imaju istu ocjenu.");}
        
         if(ocjena3>=75 && ocjena2>=75 && ocjena3<85 && ocjena2<85 && ocjena1>=55 && ocjena1<65) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         if(ocjena3>=75 && ocjena2>=75 && ocjena3<85 && ocjena2<85 && ocjena1>=65 && ocjena1<75) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         if(ocjena3>=75 && ocjena2>=75 && ocjena3<85 && ocjena2<85 && ocjena1>=85 && ocjena1<92) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         if(ocjena3>=75 && ocjena2>=75 && ocjena3<85 && ocjena2<85 && ocjena1>=92 && ocjena1<=100) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         
         if(ocjena3>=75 && ocjena1>=75 && ocjena3<85 && ocjena1<85 && ocjena2>=55 && ocjena2<65) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         if(ocjena3>=75 && ocjena1>=75 && ocjena3<85 && ocjena1<85 && ocjena2>=65 && ocjena2<75) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         if(ocjena3>=75 && ocjena1>=75 && ocjena3<85 && ocjena1<85 && ocjena2>=85 && ocjena2<92) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         if(ocjena3>=75 && ocjena1>=75 && ocjena3<85 && ocjena1<85 && ocjena2>=92 && ocjena2<=100) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         
         if(ocjena1>=85 && ocjena2>=85 && ocjena1<92 && ocjena2<92 && ocjena3>=55 && ocjena3<65) {printf("\nDva od tri studenta imaju istu ocjenu.");}	
        if(ocjena1>=85 && ocjena2>=85 && ocjena1<92 && ocjena2<92 && ocjena3>=65 && ocjena3<75) {printf("\nDva od tri studenta imaju istu ocjenu.");}
        if(ocjena1>=85 && ocjena2>=85 && ocjena1<92 && ocjena2<92 && ocjena3>=75 && ocjena3<85) {printf("\nDva od tri studenta imaju istu ocjenu.");}
        if(ocjena1>=85 && ocjena2>=85 && ocjena1<92 && ocjena2<92 && ocjena3>=92 && ocjena3<=100) {printf("\nDva od tri studenta imaju istu ocjenu.");}
        
         if(ocjena3>=85 && ocjena2>=85 && ocjena3<92 && ocjena2<92 && ocjena1>=55 && ocjena1<65) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         if(ocjena3>=85 && ocjena2>=85 && ocjena3<92 && ocjena2<92 && ocjena1>=65 && ocjena1<75) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         if(ocjena3>=85 && ocjena2>=85 && ocjena3<92 && ocjena2<92 && ocjena1>=75 && ocjena1<85) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         if(ocjena3>=85 && ocjena2>=85 && ocjena3<92 && ocjena2<92 && ocjena1>=92 && ocjena1<=100) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         
         if(ocjena3>=85 && ocjena1>=85 && ocjena3<92 && ocjena1<92 && ocjena2>=55 && ocjena2<65) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         if(ocjena3>=85 && ocjena1>=85 && ocjena3<92 && ocjena1<92 && ocjena2>=65 && ocjena2<75) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         if(ocjena3>=85 && ocjena1>=85 && ocjena3<92 && ocjena1<92 && ocjena2>=75 && ocjena2<85) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         if(ocjena3>=85 && ocjena1>=85 && ocjena3<92 && ocjena1<92 && ocjena2>=92 && ocjena2<=100) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         
        if(ocjena1>=92 && ocjena2>=92 && ocjena1<=100 && ocjena2<=100 && ocjena3>=55 && ocjena3<65) {printf("\nDva od tri studenta imaju istu ocjenu.");}	
        if(ocjena1>=92 && ocjena2>=92 && ocjena1<=100 && ocjena2<=100 && ocjena3>=65 && ocjena3<75) {printf("\nDva od tri studenta imaju istu ocjenu.");}
        if(ocjena1>=92 && ocjena2>=92 && ocjena1<=100 && ocjena2<=100 && ocjena3>=75 && ocjena3<85) {printf("\nDva od tri studenta imaju istu ocjenu.");}
        if(ocjena1>=92 && ocjena2>=92 && ocjena1<=100 && ocjena2<=100 && ocjena3>=85 && ocjena3<92) {printf("\nDva od tri studenta imaju istu ocjenu.");}
        
         if(ocjena3>=92 && ocjena2>=92 && ocjena3<=100 && ocjena2<=100 && ocjena1>=55 && ocjena1<65) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         if(ocjena3>=92 && ocjena2>=92 && ocjena3<=100 && ocjena2<=100 && ocjena1>=65 && ocjena1<75) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         if(ocjena3>=92 && ocjena2>=92 && ocjena3<=100 && ocjena2<=100 && ocjena1>=75 && ocjena1<85) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         if(ocjena3>=92 && ocjena2>=92 && ocjena3<=100 && ocjena2<=100 && ocjena1>=85 && ocjena1<92) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         
         if(ocjena3>=92&& ocjena1>=92 && ocjena3<=100 && ocjena1<=100 && ocjena2>=55 && ocjena2<65) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         if(ocjena3>=92 && ocjena1>=92 && ocjena3<=100 && ocjena1<=100 && ocjena2>=65 && ocjena2<75) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         if(ocjena3>=92 && ocjena1>=92 && ocjena3<=100 && ocjena1<=100 && ocjena2>=75 && ocjena2<85) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         if(ocjena3>=92 && ocjena1>=92 && ocjena3<=100 && ocjena1<=100 && ocjena2>=85 && ocjena2<92) {printf("\nDva od tri studenta imaju istu ocjenu.");}
         
         if(ocjena1>=55 && ocjena1<65 && ocjena2>=65 && ocjena2<75 && ocjena3>=75 && ocjena3<85) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=55 && ocjena1<65 && ocjena2>=65 && ocjena2<75 && ocjena3>=85 && ocjena3<92) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=55 && ocjena1<65 && ocjena2>=65 && ocjena2<75 && ocjena3>=92 && ocjena3<=100) {printf("\nSvaki student ima razlicitu ocjenu.");}
         
         if(ocjena1>=55 && ocjena1<65 && ocjena2>=75 && ocjena2<85 && ocjena3>=65 && ocjena3<75) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=55 && ocjena1<65 && ocjena2>=75 && ocjena2<85 && ocjena3>=85 && ocjena3<92) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=55 && ocjena1<65 && ocjena2>=75 && ocjena2<85 && ocjena3>=92 && ocjena3<=100) {printf("\nSvaki student ima razlicitu ocjenu.");}
         
         if(ocjena1>=55 && ocjena1<65 && ocjena2>=85 && ocjena2<92 && ocjena3>=65 && ocjena3<75) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=55 && ocjena1<65 && ocjena2>=85 && ocjena2<92 && ocjena3>=75 && ocjena3<85) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=55 && ocjena1<65 && ocjena2>=85 && ocjena2<92 && ocjena3>=92 && ocjena3<=100) {printf("\nSvaki student ima razlicitu ocjenu.");}
         
         if(ocjena1>=55 && ocjena1<65 && ocjena2>=92 && ocjena2<=100 && ocjena3>=65 && ocjena3<75) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=55 && ocjena1<65 && ocjena2>=92 && ocjena2<=100 && ocjena3>=75 && ocjena3<85) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=55 && ocjena1<65 && ocjena2>=92 && ocjena2<=100 && ocjena3>=85 && ocjena3<92) {printf("\nSvaki student ima razlicitu ocjenu.");}
         
       if(ocjena1>=65 && ocjena1<75 && ocjena2>=55 && ocjena2<65 && ocjena3>=75 && ocjena3<85) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=65 && ocjena1<75 && ocjena2>=55 && ocjena2<65 && ocjena3>=85 && ocjena3<92) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=65 && ocjena1<75 && ocjena2>=55 && ocjena2<65 && ocjena3>=92 && ocjena3<=100) {printf("\nSvaki student ima razlicitu ocjenu.");}
         
         if(ocjena1>=65 && ocjena1<75 && ocjena2>=75 && ocjena2<85 && ocjena3>=55 && ocjena3<65) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=65 && ocjena1<75 && ocjena2>=75 && ocjena2<85 && ocjena3>=85 && ocjena3<92) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=65 && ocjena1<75 && ocjena2>=75 && ocjena2<85 && ocjena3>=92 && ocjena3<=100) {printf("\nSvaki student ima razlicitu ocjenu.");}
         
         if(ocjena1>=65 && ocjena1<75 && ocjena2>=85 && ocjena2<92 && ocjena3>=55 && ocjena3<65) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=65 && ocjena1<75 && ocjena2>=85 && ocjena2<92 && ocjena3>=75 && ocjena3<85) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=65 && ocjena1<75 && ocjena2>=85 && ocjena2<92 && ocjena3>=92 && ocjena3<=100) {printf("\nSvaki student ima razlicitu ocjenu.");}
         
         if(ocjena1>=65 && ocjena1<75 && ocjena2>=92 && ocjena2<=100 && ocjena3>=55 && ocjena3<65) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=65 && ocjena1<75 && ocjena2>=92 && ocjena2<=100 && ocjena3>=75 && ocjena3<85) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=65 && ocjena1<75 && ocjena2>=92 && ocjena2<=100 && ocjena3>=85 && ocjena3<92) {printf("\nSvaki student ima razlicitu ocjenu.");}
         
         if(ocjena1>=75 && ocjena1<85 && ocjena2>=55 && ocjena2<65 && ocjena3>=65 && ocjena3<75) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=75 && ocjena1<85 && ocjena2>=55 && ocjena2<65 && ocjena3>=85 && ocjena3<92) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=75 && ocjena1<85 && ocjena2>=55 && ocjena2<65 && ocjena3>=92 && ocjena3<=100) {printf("\nSvaki student ima razlicitu ocjenu.");}
         
         if(ocjena1>=75 && ocjena1<85 && ocjena2>=65 && ocjena2<75 && ocjena3>=55 && ocjena3<65) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=75 && ocjena1<85 && ocjena2>=65 && ocjena2<75 && ocjena3>=85 && ocjena3<92) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=75 && ocjena1<85 && ocjena2>=65 && ocjena2<75 && ocjena3>=92 && ocjena3<=100) {printf("\nSvaki student ima razlicitu ocjenu.");}
         
         if(ocjena1>=75 && ocjena1<85 && ocjena2>=85 && ocjena2<92 && ocjena3>=55 && ocjena3<65) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=75 && ocjena1<85 && ocjena2>=85 && ocjena2<92 && ocjena3>=65 && ocjena3<75) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=75 && ocjena1<85 && ocjena2>=85 && ocjena2<92 && ocjena3>=92 && ocjena3<=100) {printf("\nSvaki student ima razlicitu ocjenu.");}
         
         if(ocjena1>=75 && ocjena1<85 && ocjena2>=92 && ocjena2<=100 && ocjena3>=55 && ocjena3<65) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=75 && ocjena1<85 && ocjena2>=92 && ocjena2<=100 && ocjena3>=65 && ocjena3<75) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=75 && ocjena1<85 && ocjena2>=92 && ocjena2<=100 && ocjena3>=85 && ocjena3<92) {printf("\nSvaki student ima razlicitu ocjenu.");}  
         
          if(ocjena1>=85 && ocjena1<92 && ocjena2>=55 && ocjena2<65 && ocjena3>=65 && ocjena3<75) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=85 && ocjena1<92 && ocjena2>=55 && ocjena2<65 && ocjena3>=75 && ocjena3<85) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=85 && ocjena1<92 && ocjena2>=55 && ocjena2<65 && ocjena3>=92 && ocjena3<=100) {printf("\nSvaki student ima razlicitu ocjenu.");}
         
         if(ocjena1>=85 && ocjena1<92 && ocjena2>=65 && ocjena2<75 && ocjena3>=55 && ocjena3<65) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=85 && ocjena1<92 && ocjena2>=65 && ocjena2<75 && ocjena3>=75 && ocjena3<85) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=85 && ocjena1<92 && ocjena2>=65 && ocjena2<75 && ocjena3>=92 && ocjena3<=100) {printf("\nSvaki student ima razlicitu ocjenu.");}
         
         if(ocjena1>=85 && ocjena1<92 && ocjena2>=75 && ocjena2<85 && ocjena3>=55 && ocjena3<65) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=85 && ocjena1<92 && ocjena2>=75 && ocjena2<85 && ocjena3>=65 && ocjena3<75) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=85 && ocjena1<92 && ocjena2>=75 && ocjena2<85 && ocjena3>=92 && ocjena3<=100) {printf("\nSvaki student ima razlicitu ocjenu.");}
         
         if(ocjena1>=85 && ocjena1<92 && ocjena2>=92 && ocjena2<=100 && ocjena3>=55 && ocjena3<65) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=85 && ocjena1<92 && ocjena2>=92 && ocjena2<=100 && ocjena3>=65 && ocjena3<75) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=85 && ocjena1<92 && ocjena2>=92 && ocjena2<=100 && ocjena3>=75 && ocjena3<85) {printf("\nSvaki student ima razlicitu ocjenu.");} 
         
            if(ocjena1>=92 && ocjena1<=100 && ocjena2>=55 && ocjena2<65 && ocjena3>=65 && ocjena3<75) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=92 && ocjena1<=100 && ocjena2>=55 && ocjena2<65 && ocjena3>=75 && ocjena3<85) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=92 && ocjena1<=100 && ocjena2>=55 && ocjena2<65 && ocjena3>=85 && ocjena3<92) {printf("\nSvaki student ima razlicitu ocjenu.");}
         
         if(ocjena1>=92 && ocjena1<=100 && ocjena2>=65 && ocjena2<75 && ocjena3>=55 && ocjena3<65) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=92 && ocjena1<=100 && ocjena2>=65 && ocjena2<75 && ocjena3>=75 && ocjena3<85) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=92 && ocjena1<=100 && ocjena2>=65 && ocjena2<75 && ocjena3>=85 && ocjena3<92) {printf("\nSvaki student ima razlicitu ocjenu.");}
         
         if(ocjena1>=92 && ocjena1<=100 && ocjena2>=75 && ocjena2<85 && ocjena3>=55 && ocjena3<65) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=92 && ocjena1<=100 && ocjena2>=75 && ocjena2<85 && ocjena3>=65 && ocjena3<75) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=92 && ocjena1<=100 && ocjena2>=75 && ocjena2<85 && ocjena3>=85 && ocjena3<92) {printf("\nSvaki student ima razlicitu ocjenu.");}
         
         if(ocjena1>=92 && ocjena1<=100 && ocjena2>=85 && ocjena2<92 && ocjena3>=55 && ocjena3<65) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=92 && ocjena1<=100 && ocjena2>=85 && ocjena2<92 && ocjena3>=65 && ocjena3<75) {printf("\nSvaki student ima razlicitu ocjenu.");}
         if(ocjena1>=92 && ocjena1<=100 && ocjena2>=85 && ocjena2<92 && ocjena3>=75 && ocjena3<85) {printf("\nSvaki student ima razlicitu ocjenu.");}    
     	}
     	
	}
	return 0;
}
