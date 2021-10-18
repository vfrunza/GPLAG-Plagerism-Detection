#include <stdio.h>
#include <math.h>
#define eps 0.001
int main() {double X1,X2,x1,x2,a,b,c,D;
printf("Unesite koeficijente a, b i c: ");
scanf("%lf %lf %lf",&a,&b,&c);
X1=((-b)+(sqrt((pow(b,2))-(4*a*c))))/2*a;
X2=((-b)-(sqrt((pow(b,2))-(4*a*c))))/2*a;
D=(pow(b,2))-(4*a*c);

if(D<0){printf("Rjesenja su imaginarni brojevi.");}
else{ 
do{
    printf("Unesite rjesenje x1: ");
    scanf("%lf",&x1);
    if(fabs(x1-X1)<eps){printf("Tacno\n");}
    
    else if((x1<X1) && (fabs(x1-X1)>=0.1)){printf("Manje\n");}
    
    else if((x1>X1) && (fabs(x1-X1)>=0.1)){printf("Vece\n");}
   
    else if((x1>X1) && (fabs(x1-X1)<0.1)){printf("Priblizno vece\n");}
   
    else if((x1<X1) && (fabs(x1-X1)<0.1)){printf("Priblizno manje\n");}
   
    else return 0;    
} while(fabs(x1-X1)>=eps);
do{
    printf("Unesite rjesenje x2: ");
    scanf("%lf",&x2);
    if(fabs(x2-X2)<eps){printf("Tacno\n");}
    
    else if((x2<X2) && (fabs(x2-X2)>=0.1)){printf("Manje\n");}
    
    else if((x2>X2) && (fabs(x2-X2)>=0.1)){printf("Vece\n");}
    
    else if((x2>X2) && (fabs(x2-X2)<0.1)){printf("Priblizno vece\n");}
   
    else if((x2<X2) && (fabs(x2-X2)<0.1)){printf("Priblizno manje\n");}

    else return 0;
} while(fabs(x2-X2)>=eps);}
return 0;
   
	
}
