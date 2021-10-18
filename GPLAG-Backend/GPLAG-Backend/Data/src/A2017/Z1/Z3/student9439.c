#include <stdio.h>
#include <math.h>
#define E 0.0001
#define e 0.1
int main() {
	double a,b,c,x1,x2,y,i,j;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a , &b , &c);
	if(a!=0){
	y=b*b-4*a*c;
	x1=(- b - sqrt (y))/2*a;
	x2=(-b + sqrt (y))/2*a;
	
	if(y<0){
	printf("Rjesenja su imaginarni brojevi.");
	}else if(y>=0){
	do{
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &i);
			if(fabs(i-x1)<=E){
				printf("Tacno\n");
				break;}else
		
		if((fabs(x1-i)<e)&&(x1-i)>0){
				printf("Priblizno manje\n");
				
				}else
				if((fabs(x1-i)<e)&&((x1-i)<0)){
				printf("Priblizno vece\n");}else

			if((i-x1)>e){
				printf("Vece\n");
			}else
				if((i-x1)<e){
				printf("Manje\n");}
				
						
					}
	
				while(i!=x1);
					
				
				
		
	do{
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &j);
		if(fabs(x2-j)<=E){
				printf("Tacno\n");
			break;
		}else
			if((fabs(x2-j)<e)&&(x2-j)<0){
				printf("Priblizno vece\n");
				
				}else
					if((fabs(x2-j)<e)&&(x2-j)>0){
				printf("Priblizno manje\n");}else

			if((j-x2)>e){
				printf("Vece\n");
			
			}else
				if((j-x2)<e){
				printf("Manje\n");
				
				}
					}while(j!=x2);
				
				
	
}else{return 0;}}
	
	return 0;
}
