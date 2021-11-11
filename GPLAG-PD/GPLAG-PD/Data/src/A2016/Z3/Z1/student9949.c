#include <stdio.h>
int main (){
 int A,B,i,S=0,prost=0;
 int daj_prost();
  
  do {
   printf("Unesite brojeve A i B: ");
   scanf("%d %d", &A, &B);
   if(A==0 || A<0) printf("A nije prirodan broj.\n");
   else if(A>=B)  printf("A nije manje od B.\n");
 } while (A>=B || A<=0);

 for(i=0; i<B; i++) {
  prost=daj_prost();
  if(prost>A && prost<B)
  S+=prost;
  else if(prost>=B)
  break; }
  printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, S);
  return 0; }
  
 int daj_prost () {
  static int broj=2;
  int i=2, prost=0;
  
  while(i<=broj){
   if(broj%i==0 && broj==i){
    prost=broj;
    break;
   }
   else if(broj%i==0 && broj!=0){
    broj++;
    i=2;
   }
   i++;
  }
  broj++;
  return prost;
 }