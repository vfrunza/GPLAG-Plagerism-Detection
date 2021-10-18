#include <stdio.h>
#define eps 0.0001
int main() {
float Tp1,Tp2,Tpr,Tza,Tzav;
float Bp1,Bp2,Bpr,Bza,Bzav;
float Mp1,Mp2,Mpr,Mza,Mzav;
float st=0,sb=0,sm=0;
int o1,o2,o3;
printf("Unesite bodove za Tarika:\n");
printf("I parcijalni ispit: ");
scanf("%f",&Tp1);
if(Tp1>20||Tp1<0){
 printf("Neispravan broj bodova");
 return 0;}

printf("II parcijalni ispit: ");
scanf("%f",&Tp2);
if(Tp2>20||Tp2<0){
    printf("Neispravan broj bodova");
    return 0;}
printf("Prisustvo: ");
scanf("%f",&Tpr);
if(Tpr>10||Tpr<0)
{
    printf("Neispravan broj bodova");
    return 0;
}
printf("Zadace: ");
scanf("%f",&Tza);
if(Tza>10||Tza<0){printf("Neispravan broj bodova");
return 0;}
printf("Zavrsni ispit: ");
scanf("%f",&Tzav);
if(Tzav>40||Tzav<0){
    printf("Neispravan broj bodova");
    return 0;
}
st=Tp1+Tp2+Tpr+Tza+Tzav;


printf("Unesite bodove za Bojana:\n");
printf("I parcijalni ispit: ");
scanf("%f",&Bp1);
if(Bp1>20||Bp1<0){
 printf("Neispravan broj bodova");
 return 0;}

printf("II parcijalni ispit: ");
scanf("%f",&Bp2);
if(Bp2>20||Bp2<0){
    printf("Neispravan broj bodova");
    return 0;}
printf("Prisustvo: ");
scanf("%f",&Bpr);
if(Bpr>10||Bpr<0)
{
    printf("Neispravan broj bodova");
    return 0;
}
printf("Zadace: ");
scanf("%f",&Bza);
if(Bza>10||Bza<0){printf("Neispravan broj bodova");
return 0;}
printf("Zavrsni ispit: ");
scanf("%f",&Bzav);
if(Bzav>40||Bzav<0){
    printf("Neispravan broj bodova");
    return 0;
}
sb=Bp1+Bp2+Bpr+Bza+Bzav;
printf("Unesite bodove za Mirzu:\n");
printf("I parcijalni ispit: ");
scanf("%f",&Mp1);
if(Mp1>20||Mp1<0){
 printf("Neispravan broj bodova");
 return 0;}

printf("II parcijalni ispit: ");
scanf("%f",&Mp2);
if(Mp2>20||Mp2<0){
    printf("Neispravan broj bodova");
    return 0;}
printf("Prisustvo: ");
scanf("%f",&Mpr);
if(Mpr>10||Mpr<0)
{
    printf("Neispravan broj bodova");
    return 0;
}
printf("Zadace: ");
scanf("%f",&Mza);
if(Mza>10||Mza<0){printf("Neispravan broj bodova");
return 0;}
printf("Zavrsni ispit: ");
scanf("%f",&Mzav);
if(Mzav>40||Mzav<0){
    printf("Neispravan broj bodova");
    return 0;
}
sm=Mp1+Mp2+Mpr+Mza+Mzav;


o1=5;
if(st+eps>=55&&st<65){
    o1=6;
}
else if(st+eps>=65&&st<75){
    o1=7;
}
else if(st+eps>=75&&st<85){
    o1=8;
}
else if(st+eps>=85&&st<92){
    o1=9;
}
else if(st+eps>=92&&st<=100){
    o1=10;
}
o2=5;
if(sb+eps>=55&&sb<65){
    o2=6;
}
else if(sb+eps>=65&&sb<75){
    o2=7;
}
else if(sb+eps>=75&&sb<85){
    o2=8;
}
else if(sb+eps>=85&&sb<92){
    o2=9;
}
else if(sb+eps>=92&&sb<=100){
    o2=10;
}
o3=5;
if(sm+eps>=55&&sm<65){
    o3=6;
}
else if(sm+eps>=65&&sm<75){
    o3=7;
}
else if(sm+eps>=75&&sm<85){
    o3=8;
}
else if(sm+eps>=85&&sm<92){
    o3=9;
}
else if(sm+eps>=92&&sm<=100){
    o3=10;
}

if(o1<6&&o2<6&&o3<6){
    printf("Nijedan student nije polozio.");
    
}else if(o1+o2+o3>=18&&o1>=6&&o2>=6&&o3>=6){
    printf("Sva tri studenta su polozila.");
}
if(o1>=6&&o2>=6&&o3<6){
    printf("Dva studenta su polozila.");
}
else if(o1<6&&o2>=6&&o3>=6){
    printf("Dva studenta su polozila.");
}
else if(o1>=6&&o2<6&&o2>=6){
    printf("Dva studenta su polozila.");
}
else if(o1<6&&o2<6&&o3>=6){
    printf("Jedan student je polozio.");
}
else if(o1<6&&o2>=6&&o3<6){
    printf("Jedan student  je polozio.");
}
else if (o1>=6&&o2<6&&o3<6) {
    printf("Jedan student je polozio.");
    
}
printf("\n");
if(o1==o3 &&o1==o2&&o2==o1&&o2==o3&&o3==o1&&o3==o2&&o1>=6&&o2>=6&&o3>=6){
    printf("Sva tri studenta imaju istu ocjenu.");
}
else if(o1==o2&&o3!=o1&&o3!=o1&&o1>=6&&o2>=6){
    printf("Dva od tri studenta imaju istu ocjenu.");
}
else if(o2==o3&&o1!=o2&&o1!=o3&&o2>=6&&o3>=6){
    printf("Dva od tri studenta imaju istu ocjenu.");
}
else if(o1==o3&&o2!=o1&&o2!=o3&&o1>=6&&o3>=6){
    printf("Dva od tri studenta imaju istu ocjenu.");
    
}
else if(o1!=o3 &&o1!=o2&&o2!=o1&&o2!=o3&&o3!=o1&&o3!=o2&&o1>=6&&o2>=6&&o3>=6)
{ printf("Svaki student ima razlicitu ocjenu.");
}





	return 0;
}
