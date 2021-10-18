#include <stdio.h>
#include <math.h>

int main() {
	float t1,t2,t3,t4,t5,b1,b2,b3,b4,b5,m1,m2,m3,m4,m5;
	int T,M,B,O1,O2,O3;
	
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%f", &t1);
	if(t1<0 || t1>20){
	printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%f",&t2);
	if(t2<0 || t2>20){
	printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%f",&t3);
	if(t3<0 || t3>10){
    printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%f",&t4);
	if(t4<0 || t4>10){
    printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%f", &t5);
	if(t5<0 || t5>40){
    printf("Neispravan broj bodova"); return 0;}
    
   O1= round(t1+t2+t3+t4+t5);
    if(O1<55)
    T=5;
    else if (O1>=55 && O1<65)
    T=6;
    else if (O1>=65 && O1<75)
    T=7;
    else if (O1>=76 && O1<85)
    T=8;
    else if (O1>=85 && O1<92)
    T=9;
    else if (O1>=92 && O1<=100)
    T=10;
 
    
    
    printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%f", &b1);
	if(b1<0 || b1>20){
    printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%f",&b2);
	if(b2<0 || b2>20){
    printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%f",&b3);
	if (b3<0 || b3>10){
    printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%f",&b4);
	if(b4<0 || b4>10){
    printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%f", &b5);
	if(b5<0 || b5>40){
    printf("Neispravan broj bodova"); return 0;}
    
	O2=round(b1+b2+b3+b4+b5);
	 if(O2<55)
    B=5;
    else if (O2>=55 && O2<65)
    B=6;
    else if (O2>=65 && O2<75)
    B=7;
    else if (O2>=76 && O2<85)
    B=8;
    else if (O2>=85 && O2<92)
    B=9;
    else if (O2>=92 && O2<=100)
    B=10;
    
    
    printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%f", &m1);
	if(m1<0 || m1>20){
	printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%f",&m2);
	if(m2<0 || m2>20){
    printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%f",&m3);
	if(m3<0 || m3>10){
    	printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
		scanf("%f",&m4);
	if(m4<0 || m4>10){
	printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%f", &m5);
	if(m5<0 || m5>40){
    printf("Neispravan broj bodova"); return 0;}
    

	O3=round(m1+m2+m3+m4+m5);
	 if(O3<55)
    M=5;
    else if (O3>=55 && O3<65)
    M=6;
    else if (O3>=65 && O3<75)
    M=7;
    else if (O3>=76 && O3<85)
    M=8;
    else if (O3>=85 && O3<92)
    M=9;
    else if (O3>=92 && O3<=100)
    M=10;
  
    
    if(T==5 && B==5 && M==5)
    printf("Nijedan student nije polozio.\n");
   else if((T>5 && B==5 && M==5) || (T==5 && B>5 && M==5) || (T==5 && B==5 && M>5))
   printf("Jedan student je polozio. \n");
    else if((T>5 && B>5 && M==5) || (T==5 && B>5 && M>5) || (T>5 && B==5 && M>5))
    printf("Dva studenta su polozila.\n");
    else if (T>5 && B>5 && M>5){
    printf("Sva tri studenta su polozila.\n");
    if(T==B && B==M)
    printf("Sva tri studenta imaju istu ocjenu.\n");
    else if ((T==B && B!=M) || (T!=B && B==M) || (T==M && M!=B))
    printf("Dva od tri studenta imaju istu ocjenu. \n");
    else if (T!=B && B!=M && T!=M)
    printf("Svaki student ima razlicitu ocjenu.\n");
    
    }
	return 0;
}
