#include <stdio.h>
#include <math.h>
#define eps 0.001
int main() {
	double a,b,c,x1,x2;
	double x1_stvarno=0,x2_stvarno=0;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	if((b*b-4*a*c)<0){
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	printf("Unesite rjesenje x1: ");
	scanf("%lf",&x1);
	x1_stvarno=(-b+sqrt(b*b-4*a*c))/(2*a);
	if(x1>x1_stvarno  && (fabs(x1-x1_stvarno))>=0.1 ){
		printf("Vece\n");
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&x1);
		if(fabs(x1-x1_stvarno)<eps){
			printf("Tacno\n");
		}
	}else if(x1<x1_stvarno && (fabs(x1-x1_stvarno))>=0.1){
		printf("Manje\n");
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&x1);
		if(fabs(x1-x1_stvarno)<eps){
			printf("Tacno\n");
		}
	}else if((fabs(x1-x1_stvarno))<=0.1 && x1<x1_stvarno && fabs(x1-x1_stvarno)>eps){
		printf("Priblizno manje\n");
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&x1);
		if(fabs(x1-x1_stvarno)<eps){
			printf("Tacno\n");
		}
	}else if ((fabs(x1-x1_stvarno))<=0.1 && x1>x1_stvarno && fabs(x1-x1_stvarno)>eps){
		printf("Priblizno vece\n");
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&x1);
		if(fabs(x1-x1_stvarno)<eps){
			printf("Tacno\n");
		}
	}else if((fabs(x1-x1_stvarno))<eps){
		printf("Tacno\n");
	}
	if(fabs(x1-x1_stvarno)>=eps){
	do{
		
		if(x1>x1_stvarno && (fabs(x1-x1_stvarno))>=0.1){
			printf("Vece\n");
			printf("Unesite rjesenje x1: ");
			scanf("%lf",&x1);
			if(fabs(x1-x1_stvarno)<eps){
				printf("Tacno\n");
				break;
			}
		}else if(x1<x1_stvarno && (fabs(x1-x1_stvarno))>=0.1){
			printf("Manje\n");
			printf("Unesite rjesenje x1: ");
			scanf("%lf",&x1);
			if(fabs(x1-x1_stvarno)<eps){
				printf("Tacno\n");
				break;
			}
		}else if((fabs(x1-x1_stvarno))<=0.1 && x1<x1_stvarno && fabs(x1-x1_stvarno)>eps ){
			printf("Priblizno manje\n");
			printf("Unesite rjesenje x1: ");
			scanf("%lf",&x1);
			if(fabs(x1-x1_stvarno)<eps){
				printf("Tacno\n");
				break;
			}
		}else if((x1-x1_stvarno)<=0.1 && x1>x1_stvarno && fabs(x1-x1_stvarno)>=eps){
			printf("Priblizno vece\n");
			printf("Unesite rjesenje x1: ");
			scanf("%lf",&x1);
			if(fabs(x1-x1_stvarno)<eps){
				printf("Tacno\n");
			    break;
			}
		}else if ((fabs(x1-x1_stvarno))<eps){
			 printf("Tacno\n");
		}
		
	}while(fabs(x1-x1_stvarno)>=eps);
	}
	printf("Unesite rjesenje x2: ");
	scanf("%lf",&x2);
	x2_stvarno=(-b-sqrt(b*b-4*a*c))/(2*a);
	if(x2>x2_stvarno && (fabs(x2-x2_stvarno))>=0.1){
		printf("Vece\n");
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&x2);
		if(fabs(x2-x2_stvarno)<eps){
			printf("Tacno");
			
		}
	}else if(x2<x2_stvarno && (fabs(x2-x2_stvarno))>=0.1){
		printf("Manje\n");
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&x2);
		if(fabs(x2-x2_stvarno)<eps){
			printf("Tacno");
			
		}
	}else if((fabs(x2-x2_stvarno))<=0.1 && x2<x2_stvarno && fabs(x2-x2_stvarno)>eps ){
		printf("Priblizno manje\n");
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&x2);
		if(fabs(x2-x2_stvarno)<eps){
			printf("Tacno");
		
		}
	}else if((fabs(x2-x2_stvarno))>=0.1 && x2>x2_stvarno && fabs(x2-x2_stvarno)>eps ){
		printf("Priblizno vece\n");
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&x2);
		if(fabs(x2-x2_stvarno)<eps){
			printf("Tacno");
		
		}
	}else if((fabs(x2-x2_stvarno))<eps){
		printf("Tacno");
	}
	if(fabs(x2-x2_stvarno)>eps)
	do{
		
			if(x2>x2_stvarno && (fabs(x2-x2_stvarno))>=0.1){
				printf("Vece\n");
				printf("Unesite rjesenje x2: ");
				scanf("%lf",&x2);
				if(fabs(x2-x2_stvarno)<eps){
					printf("Tacno");
					break;
				}
			}else if(x2<x2_stvarno && (fabs(x2-x2_stvarno))>=0.1){
				printf("Manje\n");
				printf("Unesite rjesenje x2: ");
				scanf("%lf",&x2);
				if(fabs(x2-x2_stvarno)<eps){
					printf("Tacno");
					break;
				}
			}else if((fabs(x2-x2_stvarno))<=0.1 && x2<x2_stvarno && fabs(x2-x2_stvarno)>eps){
				printf("Priblizno manje\n");
				printf("Unesite rjesenje x2: ");
				scanf("%lf",&x2);
				if(fabs(x2-x2_stvarno)<eps){
					printf("Tacno");
					break;
				}
			}else if((fabs(x2-x2_stvarno))<=0.1 && x2>x2_stvarno && fabs(x2-x2_stvarno)>eps){
				printf("Priblizno vece\n");
				printf("Unesite rjesenje x2: ");
				scanf("%lf",&x2);
				if(fabs(x2-x2_stvarno)<eps){
					printf("Tacno");
					break;
				}
			}else if((fabs(x2-x2_stvarno))<eps){
				printf("Tacno");
			}
		
	}while(fabs(x2-x2_stvarno)>=eps*(fabs(x2)+fabs(x2_stvarno)));
	return 0;
}
