#include <stdio.h>
#include <math.h>

#define e 0.001

int main() {
	double a,b,c,x1,x2,k,x1u,x2u;
/*--------------------UNOS-----------------------------------------------------*/	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);

	k=pow(b,2)-(4*a*c); /*provjerit da li je pozitivno*/
	if(k<0){
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
/*---------------------RACUN RJESENJA-------------------------------------------*/	
	x1=((b*-1)+sqrt(k))/(2*a);
	x2=((b*-1)-sqrt(k))/(2*a);

	
/*---------------------UNOS I KOMPARACIJA RJESENJA------------------------------*/
	do{
	printf("Unesite rjesenje x1: ");/*-------------------------------------------X1*/
	scanf("%lf",&x1u);	
	
	 if(fabs(x1-x1u)<e){
         printf("Tacno\n");
         break;
     }
	
	if(x1-x1u<0.1&&x1-x1u>0){
        printf("Priblizno manje\n");
        continue;
     }
     	if(x1-x1u<0&&x1-x1u>-0.1){
        printf("Priblizno vece\n");
        continue;
     }
    	
	if(x1u<x1){
		printf("Manje\n");
	}
	else if(x1u>x1){
		printf("Vece\n");
	}
	
	}while(fabs(x1-x1u)>=e);
	

	
	do{
		printf("Unesite rjesenje x2: ");/*---------------------------------------X2*/
		scanf("%lf",&x2u);
		
		if(fabs(x2-x2u)<e){
         printf("Tacno\n");
         break;
     }
	
	if(x2-x2u<0.1&&x2-x2u>0){
        printf("Priblizno manje\n");
        continue;
     }
     	if(x2-x2u<0&&x2-x2u>-0.1){
        printf("Priblizno vece\n");
        continue;
     }
		
		if(x2u<x2){
		printf("Manje\n");
	}
			else if(x2u>x2){
		printf("Vece\n");
	}
		

    }while(fabs(x2-x2u)>=e);
	

	return 0;
}
