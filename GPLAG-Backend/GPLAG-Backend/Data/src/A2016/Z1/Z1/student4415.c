#include <stdio.h>

int main() {
	
          double a1,b1,c1,d1,e1,a2,b2,c2,d2,e2,a3,b3,c3,d3,e3,S1,S2,S3;
          int brojac1,brojac2,G1=0,G2=0,G3=0;
          
          printf("Unesite bodove za Tarika:\n");
          printf("I parcijalni ispit: ");
          scanf("%lf",&a1);
          if(a1<0||a1>20){
          printf("Neispravan broj bodova");
          return 0;
          }
          printf("II parcijalni ispit: ");
          scanf("%lf",&b1);
           if(b1<0||b1>20){
          printf("Neispravan broj bodova");
          return 0;}
           printf("Prisustvo: ");
          scanf("%lf",&c1);
           if(c1<0||c1>10){
          printf("Neispravan broj bodova");
          return 0;}
           printf("Zadace: ");
          scanf("%lf",&d1);
          if(d1<0||d1>10){
          printf("Neispravan broj bodova");
          return 0;}
           printf("Zavrsni ispit: ");
          scanf("%lf",&e1);
          if(e1<0||e1>40){
          printf("Neispravan broj bodova");
          return 0;}
          if((a1<0||a1>20)||(b1<0||b1>20)||(c1<0||c1>10)||(d1<0||d1>10)||(e1<0||e1>40)){
                    printf("Neispravan broj bodova");
                    return 0;
          }
          
          printf("Unesite bodove za Bojana:\n");
          printf("I parcijalni ispit: ");
          scanf("%lf",&a2);
           if(a2<0||a2>20){
          printf("Neispravan broj bodova");
          return 0;}
          printf("II parcijalni ispit: ");
          scanf("%lf",&b2);
           if(b2<0||b2>20){
          printf("Neispravan broj bodova");
          return 0;}
           printf("Prisustvo: ");
          scanf("%lf",&c2);
          if(c2<0||c2>10){
          printf("Neispravan broj bodova");
          return 0;}
           printf("Zadace: ");
          scanf("%lf",&d2);
          if(d2<0||d2>10){
          printf("Neispravan broj bodova");
          return 0;}
           printf("Zavrsni ispit: ");
          scanf("%lf",&e2);
          if(e2<0||e2>40){
          printf("Neispravan broj bodova");
          return 0;}
          if((a2<0||a2>20)||(b2<0||b2>20)||(c2<0||c2>10)||(d2<0||d2>10)||(e2<0||e2>40)){
                    printf("Neispravan broj bodova");
                    return 0;
          }
          
          printf("Unesite bodove za Mirzu:\n");
          printf("I parcijalni ispit: ");
          scanf("%lf",&a3);
           if(a3<0||a3>20){
          printf("Neispravan broj bodova");
          return 0;}
          printf("II parcijalni ispit: ");
          scanf("%lf",&b3);
           if(b3<0||b3>20){
          printf("Neispravan broj bodova");
          return 0;}
           printf("Prisustvo: ");
          scanf("%lf",&c3);
          if(c3<0||c3>10){
          printf("Neispravan broj bodova");
          return 0;}
           printf("Zadace: ");
          scanf("%lf",&d3);
          if(d3<0||d3>10){
          printf("Neispravan broj bodova");
          return 0;}
           printf("Zavrsni ispit: ");
          scanf("%lf",&e3);
          if(e3<0||e3>40){
          printf("Neispravan broj bodova");
          return 0;}
          if((a3<0||a3>20)||(b3<0||b3>20)||(c3<0||c3>10)||(d3<0||d3>10)||(e3<0||e3>40)){
                    printf("Neispravan broj bodova");
                    return 0;
          }
          
          S1=a1+b1+c1+d1+e1;
          S2=a2+b2+c2+d2+e2;
          S3=a3+b3+c3+d3+e3;
          
          if(S1<55)
          G1=5;
          else if(S1>=55 && S1<65)
          G1=6;
          else if(S1>=65 && S1<75)
          G1=7;
          else if(S1>=75 && S1<85)
          G1=8;
          else if(S1>=85 && S1<92)
          G1=9;
          else if(S1>=92 && S1<=100)
          G1=10;
          
          if(S2<55)
          G2=5;
          else if(S2>=55 && S2<65)
          G2=6;
          else if(S2>=65 && S2<75)
          G2=7;
          else if(S2>=75 && S2<85)
          G2=8;
          else if(S2>=85 && S2<92)
          G2=9;
          else if(S2>=92 && S2<=100)
          G2=10;
          
          if(S3<55)
          G3=5;
          else if(S3>=55 && S3<65)
          G3=6;
          else if(S3>=65 && S3<75)
          G3=7;
          else if(S3>=75 && S3<85)
          G3=8;
          else if(S3>=85 && S3<92)
          G3=9;
          else if(S3>=92 && S3<=100)
          G3=10;
          
          brojac1=0;
          brojac2=0;
          
          if(G1!=5) brojac1++;
          if(G2!=5) brojac1++;
          if(G3!=5) brojac1++;
          
          if(G1==G2) brojac2++;
          if(G1==G3) brojac2++;
          if(G3==G2) brojac2++;
          
          if(brojac1==0)
          printf("Nijedan student nije polozio.");
          else if(brojac1==1)
          printf("Jedan student je polozio.");
          else if(brojac1==2)
          printf("Dva studenta su polozila.");
          else if(brojac1==3)
          printf("Sva tri studenta su polozila.");
          
          
          if(brojac1==3){
          if(brojac2==0)
          printf("\nSvaki student ima razlicitu ocjenu.");
          else if(brojac2==1)
          printf("\nDva od tri studenta imaju istu ocjenu.");
          else if(brojac2==2 || brojac2==3)
          printf("\nSva tri studenta imaju istu ocjenu.");}
         
         
	return 0;
}
