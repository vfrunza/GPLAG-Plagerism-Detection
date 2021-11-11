#include <stdio.h>
#define E 0.001
#include <math.h>
int main() {
	double a,b,c,z,w,x1,x2,m,n;
	int ispravno1=0, ispravno2=0;
	printf("Unesite koeficijente a, b i c: ");
	scanf ("%lf %lf %lf", &a,&b,&c);
	
	if ((b*b-4*a*c)<0){
		printf ("Rjesenja su imaginarni brojevi.");
		return 1;
	}
	z=(b*(-1)+sqrt(b*b-4*a*c))/(2*a);
	w=(b*(-1)-sqrt(b*b-4*a*c))/(2*a);
	if(z<=w){
	 x1=z;
	  x2=w;
}
	else { x1=w;
	       x2=z;}
	      
	       

 do  { printf ("Unesite rjesenje x1: ");
      scanf ("%lf", &n); 
      
    if (fabs(n-x1)<E)
     {printf ("Tacno\n");
     ispravno1++ ;
     }
     else if (fabs (n-x1)<0.1){
     	  if (n<x1)
     	  printf ("Priblizno manje\n");
     	  else if (n>x1)
     	  printf("Priblizno vece\n");
    }
     else if (n<x1){
         printf ("Manje\n");}
         else if (n>x1){
         printf ("Vece\n");}
     
     } while (ispravno1==0);
      
     
do { printf ("Unesite rjesenje x2: ");
      scanf ("%lf", &m); 
      
    if (fabs(m-x2)<E)
     {printf ("Tacno");
     ispravno2++;}
        else if 
     (fabs (m-x2)<0.1){
     	  if (m<x2)
     	  printf ("Priblizno manje\n");
     	  else if (m>x2)
     	  printf("Priblizno vece\n");

} 
     else if (m<x2){
         printf ("Manje\n"); }
        else if (m>x2){
        printf ("Vece\n"); }
  
}while (ispravno2==0);
return 0;
}
     
     
     
     
     