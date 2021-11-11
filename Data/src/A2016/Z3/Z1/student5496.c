#include <stdio.h>
/* funkcija daje prost */
int daj_prost()  {
  static int n=1;
  int i, prost=1;
  for( ; ; ) {
   n++;
   if(n==2) 
   return n;
   for(i=2;i<n;i++) {
    if(n%i==0) {
     prost=0; break;
    }
   }
  if(prost) return n;
  prost=1;
 }
}
/* funkcija za sumu prostih brojeva */
int suma (int A, int B) {  
  int suma=0,i,broj=0;
  for(i=0;i<B;i++){
    broj=daj_prost();
    if(broj>A&&broj<B) {
     suma+=broj;
     }
   }
  return suma;
}

int main() {
	int A,B;
    do 
    {
	  printf("Unesite brojeve A i B: ");
	  scanf("%d %d", &A, &B);
      if(A<1) {
        printf("A nije prirodan broj.\n");
      } 
	 else if(A>=B) { 
	    printf("A nije manje od B.\n");
	 } 
    } while(A<1 || A>=B);
     printf ("Suma prostih brojeva izmedju %d i %d je %d.", A, B,suma(A,B));
	return 0;
}
