#include <stdio.h>


int daj_prost () {
	static int a=1;
	int i, prost=0;
g:	a++;
    if(a==2) {
    	return 2;
    }
    else {
   	     for(i=2; i<a; i++) {
   	         if(a%i!=0){
   	            prost=1;
   	         }
   	     else goto g; /*Ako if uslov nije ispunjen, ne treba ništa drugo da radi, već samo da poveća "a" na sljedeći broj koji ispituje! */
         }
 } 
 
if(prost==1) {
	return a;
}
return 0;
}

int main() {

	int A, B;
	int i, prost_broj;
	static int suma=0;
	do{
		printf("Unesite brojeve A i B: ");
	    scanf("%d", &A);
	    scanf("%d", &B);
               if(A<=0) {
               	  printf("A nije prirodan broj.\n"); 
               }
	       else if(B<=0 && A>0) {
	               printf("A nije manje od B.\n"); 
	       }
	       else if(A>=B) {
	               printf("A nije manje od B.\n"); 
	       }
} while(A<=0 || B<=0 || A>=B);

for(i=0; i<B; i++) {
    prost_broj=daj_prost(); /*Poziv funkcije "daj_prost", te se vrijednost smješta u varijablu prost_broj.*/
    if(prost_broj>A && prost_broj<B) {
     	suma=suma+prost_broj;
     }
}
printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
return 0;
}