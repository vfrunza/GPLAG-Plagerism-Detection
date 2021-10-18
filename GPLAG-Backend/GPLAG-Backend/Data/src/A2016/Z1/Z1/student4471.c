#include <stdio.h>
#include <math.h>
int main() {
	
	float p1,p2,zd,prs,zvr,sum1,sum2,sum3;
	int b=0,c=0,d=0,e=0,g=0;
	int brojac = 0;
	/*if((p1<0 || p1>20) || (p2<0 || p2>20) || (zd<0 || zd>10) || (prs<0 || prs>10) || (zvr<0 || zvr>40) )*/
	
		printf("Unesite bodove za Tarika: ");
		printf("\nI parcijalni ispit: ");
		scanf("%f",&p1);
		if((p1<0 || p1>20) ) {printf("Neispravan broj bodova"); return 0 ;}
		printf("II parcijalni ispit: ");
		scanf("%f",&p2);
		if((p2<0 || p2>20)) {printf("Neispravan broj bodova"); return 0 ;} 
		printf("Prisustvo: ");
		scanf("%f",&prs);
		if((prs<0 || prs>10)) {printf("Neispravan broj bodova"); return 0 ;} 
		printf("Zadace: ");
		scanf("%f",&zd);
		if((zd<0 || zd>10)) {printf("Neispravan broj bodova"); return 0 ;} 
		printf("Zavrsni ispit: ");
		scanf("%f",&zvr);
		if((zvr<0 || zvr>40)) {printf("Neispravan broj bodova"); return 0 ;} 
		
		sum1 = p1 + p2 + prs + zd + zvr ;
		if(sum1<55){
			
		}else if(sum1>=55 && sum1<65) {
			
			b++;
		}else if(sum1>=65 && sum1<75) {
			
			c++;
		}else if(sum1>=75 && sum1<85) {
			
			d++;
		}else if(sum1>=85 && sum1<92) {
			
			e++;
		}else{g++;}
		
		if((55-sum1<=0.01) || sum1>=55){brojac++;}
	
	
		printf("Unesite bodove za Bojana: ");
		printf("\nI parcijalni ispit: ");
		scanf("%f",&p1);
		if((p1<0 || p1>20) ) {printf("Neispravan broj bodova"); return 0 ;}
		printf("II parcijalni ispit: ");
		scanf("%f",&p2);
		if((p2<0 || p2>20)) {printf("Neispravan broj bodova"); return 0 ;} 
		printf("Prisustvo: ");
		scanf("%f",&prs);
		if((prs<0 || prs>10)) {printf("Neispravan broj bodova"); return 0 ;} 
		printf("Zadace: ");
		scanf("%f",&zd);
		if((zd<0 || zd>10)) {printf("Neispravan broj bodova"); return 0 ;} 
		printf("Zavrsni ispit: ");
		scanf("%f",&zvr);
		if((zvr<0 || zvr>40)) {printf("Neispravan broj bodova"); return 0 ;} 
		
		sum2 = p1 + p2 + prs + zd + zvr ;
		if(sum2<55){
			
		
		}else if(sum2>=55 && sum2<65) {
			
			b++;
		}else if(sum2>=65 && sum2<75) {
			
			c++;
		}else if(sum2>=75 && sum2<85) {
			
			d++;
		}else if(sum2>=85 && sum2<92) {
			
			e++;
		}else{g++;}
		
		if((55-sum2<=0.01) || sum2>=55){brojac++;}
		
		printf("Unesite bodove za Mirzu: ");
		printf("\nI parcijalni ispit: ");
		scanf("%f",&p1);
		if((p1<0 || p1>20) ) {printf("Neispravan broj bodova"); return 0 ;}
		printf("II parcijalni ispit: ");
		scanf("%f",&p2);
		if((p2<0 || p2>20)) {printf("Neispravan broj bodova"); return 0 ;} 
		printf("Prisustvo: ");
		scanf("%f",&prs);
		if((prs<0 || prs>10)) {printf("Neispravan broj bodova"); return 0 ;} 
		printf("Zadace: ");
		scanf("%f",&zd);
		if((zd<0 || zd>10)) {printf("Neispravan broj bodova"); return 0 ;} 
		printf("Zavrsni ispit: ");
		scanf("%f",&zvr);
		if((zvr<0 || zvr>40)) {printf("Neispravan broj bodova"); return 0 ;} 
		
		sum3 = p1 + p2 + prs + zd + zvr ;
		if(sum3<55){
		
		}else if(sum3>=55 && sum3<65) {
			
			b++;
		}else if(sum3>=65 && sum3<75) {
			
			c++;
		}else if(sum3>=75 && sum3<85) {
			
			d++;
		}else if(sum3>=85 && sum3<92) {
			
			e++;
		}else{g++;}                                     
		
		if((55-sum3<=0.01) || sum3>=55){brojac++;}
		
		if(brojac==0){
			printf("Nijedan student nije polozio.");
		}else if (brojac==1){
			printf("Jedan student je polozio.");
		}else if (brojac==2){
			printf("Dva studenta su polozila.");
		}else {printf("Sva tri studenta su polozila.");}
		
		if(brojac==3){
		if(b==3 || c==3 || d==3 || e==3 || g==3){
			printf("\nSva tri studenta imaju istu ocjenu.");
		}else if (b==2 || c==2 || d==2 || e==2 || g==2){
			printf("\nDva od tri studenta imaju istu ocjenu.");
		}else {printf("\nSvaki student ima razlicitu ocjenu.");}
		}else {return 0 ;}
		
		
	return 0;
}
