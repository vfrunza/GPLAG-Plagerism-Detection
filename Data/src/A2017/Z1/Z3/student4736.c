#include <stdio.h>
#include <math.h>
#define e 0.001

int main() {
	
	double a,b,c,izracunato_x1,izracunato_x2,korisnicko_x1,korisnicko_x2,D,temp;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	
	D = b*b - 4*a*c;
	
	if (fabs(D)<e || D>0) {
		izracunato_x1 =  (-b - sqrt(D))/(2*a);
		izracunato_x2 =  (-b + sqrt(D))/(2*a);
		if(izracunato_x1>izracunato_x2){
			temp=izracunato_x1;
			izracunato_x1=izracunato_x2;
			izracunato_x2=temp;
		}
		
		do{
			printf("Unesite rjesenje x1: ");
			scanf("%lf",&korisnicko_x1);
			if(fabs(korisnicko_x1-izracunato_x1)<e){
				printf("Tacno\n");
				break;
			}
			else if(fabs(korisnicko_x1-izracunato_x1)<0.1){
				if(korisnicko_x1>izracunato_x1){
					printf("Priblizno vece\n");
				}	
				else{
					printf("Priblizno manje\n");
				}
			}
			else{
				if(korisnicko_x1>izracunato_x1){
					printf("Vece\n");
				}	
				else{
					printf("Manje\n");
				}	
			}
		}while(1==1);
		
		do{
			printf("Unesite rjesenje x2: ");
			scanf("%lf",&korisnicko_x2);
			if(fabs(korisnicko_x2-izracunato_x2)<=e){
				printf("Tacno\n");
				break;
			}
			else if(fabs(korisnicko_x2-izracunato_x2)<0.1){
				if(korisnicko_x2>izracunato_x2){
					printf("Priblizno vece\n");
				}	
				else{
					printf("Priblizno manje\n");
				}
			}
			else{
				if(korisnicko_x2>izracunato_x2){
					printf("Vece\n");
				}	
				else{
					printf("Manje\n");
				}	
			}
		}while(1==1);
		
		
	}
	else{
		printf("Rjesenja su imaginarni brojevi.");
	}
	
	
	return 0;
}
