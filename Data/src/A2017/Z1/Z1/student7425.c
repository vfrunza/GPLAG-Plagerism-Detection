#include <stdio.h>
#define pizzafast 8.00
#define pizzabistro 5.30
#define cevapifast 3.90
#define cevapibistro 6.00
#define ukupnorest 15.10
#define ukupnofast 14.90
#define ukupnobistro 16.30
int main()
{
   char tarik,bojan,mirza,novi_red;
   double hamburgerrest=3.30, hamburgerbistro=5.00,hamburgerfast=3.00,pizzarest=6.80,cevapirest=5.00;
    printf("Unesite jelo za Tarika: ");
    scanf("%c", &tarik);
    scanf("%c", &novi_red);
     printf("Unesite jelo za Bojana: ");
    scanf("%c", &bojan);
    scanf("%c", &novi_red);
     printf("Unesite jelo za Mirzu: ");
    scanf("%c", &mirza);
    scanf("%c", &novi_red);
    if (tarik=='H' && bojan=='H' && mirza=='H') {
     float suma1;
    float suma2;
    float suma3;
    
    suma1=3*hamburgerrest;
    suma2=3*hamburgerbistro;
    suma3=3*hamburgerfast;
    
    if(suma1<suma2 && suma1<suma3) {
     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",suma1);
    }
     if(suma2<suma1 && suma2<suma3) {
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",suma2);
    }
    if(suma3<suma1 && suma3<suma2){
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM). \n",suma3);
    }
    
    
    hamburgerrest*=0.9;
    suma1=3*hamburgerrest;
    if(suma2>suma1 && suma3>suma1) {
     
     printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma1);
    
    }
    
    }
  if (tarik=='P' && bojan=='H' && mirza=='H') {
      float suma1;
    float suma2;
    float suma3;
    suma1=pizzarest+(2*hamburgerrest);
    suma2=pizzabistro+(2*hamburgerbistro);
    suma3=pizzafast+(2*hamburgerfast);
    if(suma1<suma2 && suma1<suma3) {
     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",suma1);
    }
    if(suma2<suma1 && suma2<suma3) {
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",suma2);
    }
    if(suma3<suma1 && suma3<suma2){
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",suma3);
    }
    if(suma1>suma2 && suma1>suma3) {
    pizzarest*=0.9;
    suma1=pizzarest;
    if (suma2>suma1 && suma3>suma1)
    { 
     printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma1);
    }
    }
  }
    if (tarik=='C' && bojan=='H' && mirza=='H') {
     float suma1;
    float suma2;
    float suma3;
    suma1=cevapirest+(2*hamburgerrest);
    suma2=cevapibistro+(2*hamburgerbistro);
    suma3=cevapifast+(2*hamburgerfast);
    if(suma1<suma2 && suma1<suma3) {
     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",suma1);
    }
    if(suma2<suma1 && suma2<suma3) {
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",suma2);
    }
    if(suma3<suma1 && suma3<suma2){
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",suma3);
    }
    if(suma1>suma2 && suma1>suma3) {
    cevapirest*=0.9;
    suma1=cevapirest;
    if (suma2>suma1 && suma3>suma1)
    { 
     printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma1);
    }
    }
    }
if (tarik=='H' && bojan=='P' && mirza=='H') {
      float suma1;
    float suma2;
    float suma3;
    suma1=pizzarest+(2*hamburgerrest);
    suma2=pizzabistro+(2*hamburgerbistro);
    suma3=pizzafast+(2*hamburgerfast);
    if(suma1<suma2 && suma1<suma3) {
     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",suma1);
    }
    if(suma2<suma1 && suma2<suma3) {
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",suma2);
    }
    if(suma3<suma1 && suma3<suma2){
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",suma3);
    }
    if(suma1>suma2 && suma1>suma3) {
    pizzarest*=0.9;
    suma1=pizzarest;
    if (suma2>suma1 && suma3>suma1)
    { 
     printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma1);
    }
    }
}
     if (tarik=='H' && bojan=='C' && mirza=='H') {
     float suma1;
    float suma2;
    float suma3;
    suma1=cevapirest+(2*hamburgerrest);
    suma2=cevapibistro+(2*hamburgerbistro);
    suma3=cevapifast+(2*hamburgerfast);
    if(suma1<suma2 && suma1<suma3) {
     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",suma1);
    }
    if(suma2<suma1 && suma2<suma3) {
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",suma2);
    }
    if(suma3<suma1 && suma3<suma2){
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",suma3);
    }
    if(suma1>suma2 && suma1>suma3) {
    cevapirest*=0.9;
    suma1=cevapirest;
    if (suma2>suma1 && suma3>suma1)
    { 
     printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma1);
    }
    }
     }
 if (tarik=='H' && bojan=='H' && mirza=='P') {
      float suma1;
    float suma2;
    float suma3;
    suma1=pizzarest+(2*hamburgerrest);
    suma2=pizzabistro+(2*hamburgerbistro);
    suma3=pizzafast+(2*hamburgerfast);
    if(suma1<suma2 && suma1<suma3) {
     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",suma1);
    }
    if(suma2<suma1 && suma2<suma3) {
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",suma2);
    }
    if(suma3<suma1 && suma3<suma2){
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",suma3);
    }
    if(suma1>suma2 && suma1>suma3) {
    pizzarest*=0.9;
    suma1=pizzarest;
    if (suma2>suma1 && suma3>suma1)
    { 
     printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma1);
    }
    }
 }
 if (tarik=='H' && bojan=='H' && mirza=='C') {
     float suma1;
    float suma2;
    float suma3;
    suma1=cevapirest+(2*hamburgerrest);
    suma2=cevapibistro+(2*hamburgerbistro);
    suma3=cevapifast+(2*hamburgerfast);
    if(suma1<suma2 && suma1<suma3) {
     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",suma1);
    }
    if(suma2<suma1 && suma2<suma3) {
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",suma2);
    }
    if(suma3<suma1 && suma3<suma2){
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",suma3);
    }
    if(suma1>suma2 && suma1>suma3) {
    cevapirest*=0.9;
    suma1=cevapirest;
    if (suma2>suma1 && suma3>suma1)
    { 
     printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma1);
    }
    }
 }
    if (tarik=='P' && bojan=='P' && mirza=='P') {
      float suma1;
    float suma2;
    float suma3;
    suma1=3*pizzarest;
    suma2=3*pizzabistro;
    suma3=3*pizzafast;
    if(suma1<suma2 && suma1<suma3) {
     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",suma1);
    }
    if(suma2<suma1 && suma2<suma3) {
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",suma2);
    }
    if(suma3<suma1 && suma3<suma2){
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",suma3);
    }
    if(suma1>suma2 && suma1>suma3) {
    pizzarest*=0.9;
    suma1=3*pizzarest;
    if (suma2>suma1 && suma3>suma1)
    { 
     printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma1);
    }
    }
    }
    if (tarik=='H' && bojan=='P' && mirza=='P') {
     float suma1;
    float suma2;
    float suma3;
    suma1=hamburgerrest+(2*pizzarest);
    suma2=hamburgerbistro+(2*pizzabistro);
    suma3=hamburgerfast+(2*pizzafast);
    if(suma1<suma2 && suma1<suma3) {
     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",suma1);
    }
    if(suma2<suma1 && suma2<suma3) {
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM). \n",suma2);
    }
    if(suma3<suma1 && suma3<suma2){
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",suma3);
    }
   
    pizzarest*=0.9;
    suma1=2*pizzarest+hamburgerrest;
    if (suma2>suma1 && suma3>suma1)
    { 
     printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma1);
    }
    }
    
if (tarik=='C' && bojan=='P' && mirza=='P') {
      float suma1;
    float suma2;
    float suma3;
    suma1=cevapirest+(2*pizzarest);
    suma2=cevapibistro+(2*pizzabistro);
    suma3=cevapifast+(2*pizzafast);
    if(suma1<suma2 && suma1<suma3) {
     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",suma1);
    }
    if(suma2<suma1 && suma2<suma3) {
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",suma2);
    }
    if(suma3<suma1 && suma3<suma2){
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",suma3);
    }
    if(suma1>suma2 && suma1>suma3) {
   pizzarest*=0.9;
    suma1=2*pizzarest;
    if (suma2>suma1 && suma3>suma1)
    { 
     printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma1);
    }
    }
}
 if (tarik=='P' && bojan=='H' && mirza=='P') {
     float suma1;
    float suma2;
    float suma3;
    suma1=hamburgerrest+(2*pizzarest);
    suma2=hamburgerbistro+(2*pizzabistro);
    suma3=hamburgerfast+(2*pizzafast);
    if(suma1<suma2 && suma1<suma3) {
     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",suma1);
    }
    if(suma2<suma1 && suma2<suma3) {
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",suma2);
    }
    if(suma3<suma1 && suma3<suma2){
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",suma3);
    }
    if(suma1>suma2 && suma1>suma3) {
   pizzarest*=0.9;
    suma1=2*pizzarest;
    if (suma2>suma1 && suma3>suma1)
    { 
     printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma1);
    }
    }
 }
if (tarik=='P' && bojan=='C' && mirza=='P') {
     float suma1;
    float suma2;
    float suma3;
    suma1=cevapirest+(2*pizzarest);
    suma2=cevapibistro+(2*pizzabistro);
    suma3=cevapifast+(2*pizzafast);
    if(suma1<suma2 && suma1<suma3) {
     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",suma1);
    }
    if(suma2<suma1 && suma2<suma3) {
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",suma2);
    }
    if(suma3<suma1 && suma3<suma2){
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",suma3);
    }
    if(suma1>suma2 && suma1>suma3) {
    pizzarest*=0.9;
    suma1=2*pizzarest;
    if (suma2>suma1 && suma3>suma1)
    { 
     printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma1);
    }
    }
}
 if (tarik=='P' && bojan=='P' && mirza=='H') {
      float suma1;
    float suma2;
    float suma3;
    suma1=hamburgerrest+(2*pizzarest);
    suma2=hamburgerbistro+(2*pizzabistro);
    suma3=hamburgerfast+(2*pizzafast);
    if(suma1<suma2 && suma1<suma3) {
     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",suma1);
    }
    if(suma2<suma1 && suma2<suma3) {
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",suma2);
    }
    if(suma3<suma1 && suma3<suma2){
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",suma3);
    }
    if(suma1>suma2 && suma1>suma3) {
   pizzarest*=0.9;
    suma1=2*pizzarest;
    if (suma2>suma1 && suma3>suma1)
    { 
     printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma1);
    }
    }
 }
if (tarik=='P' && bojan=='P' && mirza=='C') {
     float suma1;
    float suma2;
    float suma3;
    suma1=cevapirest+(2*pizzarest);
    suma2=cevapibistro+(2*pizzabistro);
    suma3=cevapifast+(2*pizzafast);
    if(suma1<suma2 && suma1<suma3) {
     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",suma1);
    }
    if(suma2<suma1 && suma2<suma3) {
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",suma2);
    }
    if(suma3<suma1 && suma3<suma2){
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",suma3);
    }
    if(suma1>suma2 && suma1>suma3) {
    pizzarest*=0.9;
    suma1=2*pizzarest;
    if (suma2>suma1 && suma3>suma1)
    { 
     printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma1);
    }
    }
}
if (tarik=='C' && bojan=='C' && mirza=='C') {
      float suma1;
    float suma2;
    float suma3;
    suma1=3*cevapirest;
    suma2=3*cevapibistro;
    suma3=3*cevapifast;
    if(suma1<suma2 && suma1<suma3) {
     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",suma1);
    }
    if(suma2<suma1 && suma2<suma3) {
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",suma2);
    }
    if(suma3<suma1 && suma3<suma2){
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",suma3);
    }
    if(suma1>suma2 && suma1>suma3) {
    cevapirest*=0.9;
    suma1=3*cevapirest;
    if (suma2>suma1 && suma3>suma1)
    { 
     printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma1);
    }
    }
}
if (tarik=='H' && bojan=='C' && mirza=='C') {
     float suma1;
    float suma2;
    float suma3;
    suma1=hamburgerrest+(2*cevapirest);
    suma2=hamburgerbistro+(2*cevapibistro);
    suma3=hamburgerfast+(2*cevapifast);
    if(suma1<suma2 && suma1<suma3) {
     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",suma1);
    }
    if(suma2<suma1 && suma2<suma3) {
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",suma2);
    }
    if(suma3<suma1 && suma3<suma2){
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",suma3);
    }
    if(suma1>suma2 && suma1>suma3) {
    cevapirest*=0.9;
    suma1=2*cevapirest;
    if (suma2>suma1 && suma3>suma1)
    { 
     printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma1);
    }
    }
}
if (tarik=='P' && bojan=='C' && mirza=='C') {
     float suma1;
    float suma2;
    float suma3;
    suma1=pizzarest+(2*cevapirest);
    suma2=pizzabistro+(2*cevapibistro);
    suma3=hamburgerfast+(2*cevapifast);
    if(suma1<suma2 && suma1<suma3) {
     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",suma1);
    }
    if(suma2<suma1 && suma2<suma3) {
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",suma2);
    }
    if(suma3<suma1 && suma3<suma2){
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",suma3);
    }
    if(suma1>suma2 && suma1>suma3) {
    pizzarest*=0.9;
    suma1=pizzarest;
    if (suma2>suma1 && suma3>suma1)
    { 
     printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma1);
    }
    }
}
if (tarik=='C' && bojan=='H' && mirza=='C') {
     float suma1;
    float suma2;
    float suma3;
    suma1=hamburgerrest+(2*cevapirest);
    suma2=hamburgerbistro+(2*cevapibistro);
    suma3=hamburgerfast+(2*cevapifast);
    if(suma1<suma2 && suma1<suma3) {
     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",suma1);
    }
    if(suma2<suma1 && suma2<suma3) {
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",suma2);
    }
    if(suma3<suma1 && suma3<suma2){
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",suma3);
    }
    if(suma1>suma2 && suma1>suma3) {
   cevapirest*=0.9;
    suma1=2*cevapirest;
    if (suma2>suma1 && suma3>suma1)
    { 
     printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma1);
    }
    }
}
if (tarik=='C' && bojan=='P' && mirza=='C') {
     float suma1;
    float suma2;
    float suma3;
    suma1=pizzarest+(2*cevapirest);
    suma2=pizzabistro+(2*cevapibistro);
    suma3=pizzafast+(2*cevapifast);
    if(suma1<suma2 && suma1<suma3) {
     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",suma1);
    }
    if(suma2<suma1 && suma2<suma3) {
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",suma2);
    }
    if(suma3<suma1 && suma3<suma2){
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",suma3);
    }
    if(suma1>suma2 && suma1>suma3) {
    pizzarest*=0.9;
    suma1=pizzarest;
    if (suma2>suma1 && suma3>suma1)
    { 
     printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma1);
    }
    }
}
if (tarik=='C' && bojan=='C' && mirza=='H') {
      float suma1;
    float suma2;
    float suma3;
    suma1=hamburgerrest+(2*cevapirest);
    suma2=hamburgerbistro+(2*cevapibistro);
    suma3=hamburgerfast+(2*cevapifast);
    if(suma1<suma2 && suma1<suma3) {
     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",suma1);
    }
    if(suma2<suma1 && suma2<suma3) {
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",suma2);
    }
    if(suma3<suma1 && suma3<suma2){
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",suma3);
    }
    if(suma1>suma2 && suma1>suma3) {
     cevapirest*=0.9;
    suma1=2*cevapirest;
    if (suma2>suma1 && suma3>suma1)
    { 
     printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma1);
    }
    }
}
if (tarik=='C' && bojan=='C' && mirza=='P') {
      float suma1;
    float suma2;
    float suma3;
    suma1=pizzarest+(2*cevapirest);
    suma2=pizzabistro+(2*cevapibistro);
    suma3=hamburgerfast+(2*cevapifast);
    if(suma1<suma2 && suma1<suma3) {
     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",suma1);
    }
    if(suma2<suma1 && suma2<suma3) {
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",suma2);
    }
    if(suma3<suma1 && suma3<suma2){
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",suma3);
    }
    if(suma1>suma2 && suma1>suma3) {
     pizzarest*=0.9;
    suma1=pizzarest;
    if (suma2>suma1 && suma3>suma1)
    { 
     printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma1);
    }
    }
}
if (tarik=='H' && bojan=='P' && mirza=='C') {
     float suma1;
    float suma2;
    float suma3;
    suma1=hamburgerrest+pizzarest+cevapirest;
    suma2=pizzabistro+hamburgerbistro+cevapibistro;
    suma3=hamburgerfast+pizzafast+cevapifast;
    if(suma1<suma2 && suma1<suma3) {
     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",suma1);
    }
    if(suma2<suma1 && suma2<suma3) {
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",suma2);
    }
    if(suma3<suma1 && suma3<suma2){
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",suma3);
    }
    if(suma1>suma2 && suma1>suma3) {
     pizzarest*=0.9;
    suma1=pizzarest;
    if (suma2>suma1 && suma3>suma1)
    { 
     printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma1);
    }
    }
}
if (tarik=='P' && bojan=='H' && mirza=='C') {
     float suma1;
    float suma2;
    float suma3;
    suma1=hamburgerrest+pizzarest+cevapirest;
    suma2=pizzabistro+hamburgerbistro+cevapibistro;
    suma3=hamburgerfast+pizzafast+cevapifast;
    if(suma1<suma2 && suma1<suma3) {
     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",suma1);
    }
    if(suma2<suma1 && suma2<suma3) {
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",suma2);
    }
    if(suma3<suma1 && suma3<suma2){
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",suma3);
    }
    if(suma1>suma2 && suma1>suma3) {
   pizzarest*=0.9;
    suma1=pizzarest;
    if (suma2>suma1 && suma3>suma1)
    { 
     printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma1);
    }
    }
}
    if (tarik=='C' && bojan=='P' && mirza=='H') {
      float suma1;
    float suma2;
    float suma3;
    suma1=hamburgerrest+pizzarest+cevapirest;
    suma2=pizzabistro+hamburgerbistro+cevapibistro;
    suma3=hamburgerfast+pizzafast+cevapifast;
    if(suma1<suma2 && suma1<suma3) {
     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",suma1);
    }
    if(suma2<suma1 && suma2<suma3) {
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",suma2);
    }
    if(suma3<suma1 && suma3<suma2){
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",suma3);
    }
    if(suma1>suma2 && suma1>suma3) {
   pizzarest*=0.9;
    suma1=pizzarest;
    if (suma2>suma1 && suma3>suma1)
    { 
     printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma1);
    }
    }
    }
    if (tarik=='H' && bojan=='C' && mirza=='P') {
     float suma1;
    float suma2;
    float suma3;
    suma1=hamburgerrest+pizzarest+cevapirest;
    suma2=pizzabistro+hamburgerbistro+cevapibistro;
    suma3=hamburgerfast+pizzafast+cevapifast;
    if(suma1<suma2 && suma1<suma3) {
     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",suma1);
    }
    if(suma2<suma1 && suma2<suma3) {
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",suma2);
    }
    if(suma3<suma1 && suma3<suma2){
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",suma3);
    }
    if(suma1>suma2 && suma1>suma3) {
    pizzarest*=0.9;
    suma1=pizzarest;
    if (suma2>suma1 && suma3>suma1)
    { 
     printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma1);
    }
    }
    }
    if (tarik=='P' && bojan=='C' && mirza=='H') {
     float suma1;
    float suma2;
    float suma3;
    suma1=hamburgerrest+pizzarest+cevapirest;
    suma2=pizzabistro+hamburgerbistro+cevapibistro;
    suma3=hamburgerfast+pizzafast+cevapifast;
    if(suma1<suma2 && suma1<suma3) {
     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",suma1);
    }
    if(suma2<suma1 && suma2<suma3) {
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",suma2 );
    }
    if(suma3<suma1 && suma3<suma2){
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",suma3);
    }
    if(suma1>suma2 && suma1>suma3) {
    pizzarest*=0.9;
    suma1=pizzarest;
    if (suma2>suma1 && suma3>suma1)
    { 
     printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma1);
    }
    }
    }
     if (tarik=='C' && bojan=='H' && mirza=='P') {
     float suma1;
    float suma2;
    float suma3;
    suma1=hamburgerrest+pizzarest+cevapirest;
    suma2=pizzabistro+hamburgerbistro+cevapibistro;
    suma3=hamburgerfast+pizzafast+cevapifast;
    if(suma1<suma2 && suma1<suma3) {
     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",suma1);
    }
    if(suma2<suma1 && suma2<suma3) {
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",suma2 );
    }
    if(suma3<suma1 && suma3<suma2){
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM). \n",suma3);
    }
    
    pizzarest*=0.9;
    suma1=pizzarest+hamburgerrest+cevapirest;
    if (suma2>suma1 && suma3>suma1)
    { 
     printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma1);
    }
    }
     
     
    
    
	return 0;
}
