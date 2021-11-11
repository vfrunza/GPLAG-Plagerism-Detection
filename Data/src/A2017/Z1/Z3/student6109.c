#include <stdio.h>
#include <math.h>
#define e 0.001

int main() {
	double a,b,c;
	double x1,x2;
	double D;
	double br1,br2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a, &b, &c);
	D=b*b-4*a*c;
	if(D<0){
		printf("Rjesenja su imaginarni brojevi.");
	 return 0; }
	x2=(-b-sqrt(D))/(2*a);
	x1=(-b+sqrt(D))/(2*a);
	
	
	do{
	printf("Unesite rjesenje x1: ");
	scanf("%lf\n", &br1); 
	if(fabs(br1-x1)<e){
		printf("Tacno\n");
	 break; }
	else if(br1<x1 && fabs(br1-x1)>=0.1){
		printf("Manje\n");
	} else if(br1>x1 && fabs(br1-x1)>=0.1){
		printf("Vece\n");
	}
	   else if((br1<x1) && (x1-br1)<0.1){
	  	printf("Priblizno manje\n");
	  } else if((br1>x1) && (br1-x1)<0.1){
	  	printf("Priblizno vece\n");
	  }
	} while(fabs(x1-br1)>=e);
	
	
	  do{
	  printf("Unesite rjesenje x2: ");
	  scanf("%lf\n", &br2);
	  if(fabs(br2-x2)<e){
	  	printf("Tacno\n");
	   return 0; }
	  else if(br2<x2 && fabs(br2-x2)>=0.1){
	  	printf("Manje\n");
	  } else if(br2>x2 && fabs(br2-x2)>0.1){
	  	printf("Vece\n");
	  }
	   else if((br2<x2) && (x2-br2)<0.1){
	    	printf("Priblizno manje\n");
	    } else if((br2>x1) && (br2-x2)<0.1){
	    	printf("Priblizno vece\n");
	    } 
	  } while(fabs(x2-br2)>=e);
	  return 0; }
	
