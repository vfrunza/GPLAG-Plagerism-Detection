#include <stdio.h>
#define e 0.001
#include <math.h>

int main() {
	
	double a,b,c,D,x1,x2,xp,xd,provjera;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a,&b,&c);
	
	D=((b*b)-4*a*c);
	xp=((-b-sqrt(D))/(2*a));
	xd=((-b+sqrt(D))/(2*a));
	
	if(xp>xd) //provjerava koje je rjesenje vece/manje
	{
		provjera=xd;
		xd=xp;
		xp=provjera;
	}
	
	if(D<0) printf("Rjesenja su imaginarni brojevi.");
 	else{
 		
 		do{
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &x1);
		if ((fabs(x1-xp))<e) printf("Tacno\n");  
		else if(((fabs(x1-xp))<0.1) && (x1>xp)) printf("Priblizno vece\n");
		else if (((fabs(x1-xp))<0.1) && (x1<xp)) printf("Priblizno manje\n");
		else if (x1>xp) printf("Vece\n");
		else if (x1<xp) printf("Manje\n");
		
		}while((fabs(x1-xp))>=e);
 
 		do{
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &x2);
		if (fabs(x2-xd)<e) printf("Tacno"); 
		else if (((fabs(x2-xd))<0.1) && (x2>xd)) printf("Priblizno vece\n");
		else if (((fabs(x2-xd))<0.1) && (x2<xd)) printf("Priblizno manje\n");
		else if (x2>xd) printf("Vece\n");
		else if (x2<xd) printf("Manje\n");
		}while((fabs(x2-xd))>=e);
 		
 		
 	}
		

	
	
	return 0;
}
