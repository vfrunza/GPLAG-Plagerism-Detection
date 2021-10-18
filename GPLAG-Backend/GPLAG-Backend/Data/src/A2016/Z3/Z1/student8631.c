#include <stdio.h>
/* Trazanje prostih brojeva */
int daj_prost() {
 static int br=2; 
 int prost; 
 int j;  
 for( ; ; br++) {
  prost=1; 
  for(j=2; j<br; j++) 
  	{if(br%j==0) prost= 0;}
  	 if(prost==1) {
  	 return br++; 
  }
 }
}
  	/* Funkcija za racunanje sume */
  	
 int fsum(int a, int b) {
  int k; 
  int suma=0; 
  static int brprost=2; 
  for(k=2; k<=a; k++)  {
    brprost=daj_prost(); 
     if(brprost>a) break;
  }
  for(k=(a+1); k<b; k++) {
   if(brprost>=b) break;
    if(brprost==a) {
    brprost=daj_prost(); continue; 
  }
 	suma=suma+brprost; 
 	brprost=daj_prost();
  }
 	return suma; 
 }
int main() { 
 int a,b; 
do {
 printf("\nUnesite brojeve A i B: "); 
 scanf("%d%d", &a,&b);
if(a>=b)
 printf("A nije manje od B.");
if(a<1)
 printf("A nije prirodan broj.");
}
 while (a<1 || a>=b);
 printf("Suma prostih brojeva izmedju %d i %d je %d.", a,b, fsum(a,b)); 
 return 0;
 	}