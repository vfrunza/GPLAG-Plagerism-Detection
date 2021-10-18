#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#define eps 0.0001

 int main() {
 	double TIp,TIIp,Tp,Tz,Tzi,BIp,BIIp,Bp,Bz,Bzi,MIp,MIIp,Mp,Mz,Mzi,UbB,UbM,UbT;
 	int Ot,Ob,Om;
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &TIp);
	    if(TIp<0 || TIp>20){
	        printf("Neispravan broj bodova \n"); return 0;}
	        
        
    printf("II parcijalni ispit: ");
    scanf("%lf", &TIIp);
        if(TIIp<0 || TIIp>20){
            printf("Nesipravan broj bodova"); return 0; }

    printf("Prisustvo: ");
    scanf("%lf", &Tp);
        if(Tp<0 || Tp>10){
            printf("Neispravan broj bodova"); return 0; }
    
    printf("Zadace: ");
    scanf("%lf", &Tz);
        if(Tz<0 || Tz>10){
            printf("Neispravan broj bodova"); return 0; }
    
    printf("Zavrsni ispit: ");
    scanf("%lf", &Tzi);
        if(Tzi<0|| Tzi>40){
            printf("Neispravan broj bodova"); return 0; }
    
    UbT=(TIp+TIIp+Tp+Tz+Tzi);
    
        if(UbT>=0 && UbT<50.00){
          Ot=5;}
        else if(UbT>=55.00 && UbT<65.00){
          Ot=6;}
        else if(UbT>=65.00 && UbT<75.00){
          Ot=7;}
        else if(UbT>=75.00 && UbT<85.00){
          Ot=8;}
        else if(UbT>=85.00 && UbT<92.00){
          Ot=9;}
        else if(UbT>=92.00 && UbT<=100.00){
          Ot=10;}
    
    printf("Unesite bodove za Bojana: \n");
    printf("I parcijalni ispit: ");
    scanf("%lf",&BIp);
        if(BIp<0 || BIp>20){
            printf("Neispravan broj bodova"); return 0;}
    printf("II parcijalni ispit: ");
    scanf("%lf",&BIIp);
        if(BIIp<0 || BIIp>20){
            printf("Neispravan broj bodova"); return 0;}
    printf("Prisustvo: ");
    scanf("%lf", &Bp);
        if(Bp<0 || Bp>10){
            printf("Neispravan broj bodova"); return 0;}
    printf("Zadace: ");
    scanf("%lf", &Bz);
        if(Bz<0 || Bz>10){
            printf("Neispravan broj bodova");return 0;}
    printf("Zavrsni ispit: ");
    scanf("%lf", &Bzi);
        if(Bzi<0 || Bzi>40){
            printf("Neispravan broj bodova"); return 0;}
    
    UbB=BIp+BIIp+Bp+Bz+Bzi;
        if(UbB>=0 && UbB<55.00){
            Ob=5;}
        else if(UbB>=55.00 && UbB<65.00){
            Ob=6;}
        else if(UbB>=65.00 && UbB<75.00){
            Ob=7;}
        else if(UbB>=75.00 && UbB<85.00){
            Ob=8;}
        if(UbB>=85.00 &&  UbB<92.00){
            Ob=9;}
        if(UbB>=92.00 && UbB<=100.00){
            Ob=10;}
    
    printf("Unesite bodove za Mirzu:\n");
    printf("I parcijalni ispit: ");
    scanf("%lf", &MIp);
        if(MIp<0 || MIp>20){
            printf("Neispravan broj bodova"); return 0; }
    printf("II parcijalni ispit: ");
    scanf("%lf", &MIIp);
        if(MIIp<0 || MIIp>20){
            printf("Neispravan broj bodova"); return 0;}
    printf("Prisustvo: ");
    scanf("%lf", &Mp);
        if(Mp<0 || Mp>10){
            printf("Neispravan broj bodova"); return 0;}
    printf("Zadace: ");
    scanf("%lf" ,&Mz);
        if(Mz<0 || Mz>10){
            printf("Neispravan broj bodova"); return 0;}
    printf("Zavrsni ispit: ");
    scanf("%lf", &Mzi);
        if(Mzi<0 || Mzi>40){
            printf("Neispravan broj bodova"); return 0;}
    
    UbM=MIp+MIIp+Mp+Mz+Mzi;
        
        if(UbM>=0 && UbM<55.00){
            Om=5;}
        if(UbM>=55.00 && UbM<65.00){
            Om=6;}
        if(UbM>=65.00 && UbM<75.00){
            Om=7;}
        if(UbM>=75.00 && UbM<85.00){
            Om=8;}
        if(UbM>=85.00 && UbM<92.00){
            Om=9;}
        if(UbM>=92.00 && UbM<=100.00){
            Om=10;}
                       
 
    if((UbT<55 && UbB<55 && UbM<55)){
        printf("Nijedan student nije polozio. ");return 0;}
    else if((Ot>5 && Ob==5 && Om==5) || (Ob>5 && Ot==5 && Om==5) || (Om>5 && Ot==5 && Ob==5)){
        printf("Jedan student je polozio. \n"); return 0;}
    else if((Ot==5 && Om>5 && Ob==5)||(Ob==5 && Om>5 && Ot>5)||(Om==5 && Ot>5 && Ob>5)){
        printf("Dva studenta su polozila. ");return 0;}
    else if ((Ot!=5 && Om!=5 && Ob!=5) || (Om!=5 && Ot!=5 && Ob!=5) || (Ob!=5 && Ot!=5 && Om!=5)){
        printf("Sva tri studenta su polozila. \n");}

    if((Ot!=5 && Om!=5 && Ob!=5) && (fabs(Ot-Om)<eps && fabs(Om-Ob)<eps && fabs(Ot-Ob)<eps))
    {
            printf("Sva tri studenta imaju istu ocjenu. "); return 0;
        
    }
     else if((( fabs(Ot-Om)<eps && fabs(Ob-Om)>eps) && fabs(Ob-Ot)>eps)||((fabs(Ot-Ob)<eps && fabs(Om-Ob)>eps && fabs(Om-Ot)>0)||((fabs(Ob-Om)<eps && fabs(Ot-Om)>eps) && fabs(Ot-Ob)>eps)))
     {
            printf("Dva od tri studenta imaju istu ocjenu. ");return 0;
         
     }
       else if(fabs(Ot-Om)>eps && fabs(Om-Ob)>eps && fabs(Ot-Ob)>eps){
            printf("Svaki student ima razlicitu ocjenu. "); return 0;}
            
return 0;
     
 }