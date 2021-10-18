#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define E 0.001

int main() {
	double a, b, c, D, x1, x2, Dprvo, provjera_prvog, provjera_drugog;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	Dprvo=b*b-4*a*c;
	if (Dprvo<0){
	    printf("Rjesenja su imaginarni brojevi.");
	    return 0;
	}
	D=sqrt(Dprvo);
	double nazivnik=2*a;
	x1=(-b-D)/nazivnik;
	    if(b==0)
	    x1=D/nazivnik;
	x2=(-b+D)/nazivnik;
	    if(b==0)
	    x2=-D/nazivnik;
	int k=0;
	do{
	    printf("Unesite rjesenje x1: ");
	    scanf("%lf", &provjera_prvog);
	    if((provjera_prvog>x1 && provjera_prvog-x1<E) || (x1>provjera_prvog && x1-provjera_prvog<E) || (provjera_prvog==x1))
	    {
	        printf("Tacno\n");
	        k=1;
	    }
	    if(provjera_prvog>x1 && provjera_prvog-x1<0.1 && provjera_prvog-x1>=E)
	    printf("Priblizno vece\n");
	    if(x1>provjera_prvog && x1-provjera_prvog<0.1 && x1-provjera_prvog>=E)
	    printf("Priblizno manje\n");
	    if(provjera_prvog>x1 && provjera_prvog-x1>=0.1)
	    printf("Vece\n");
	    if(x1>provjera_prvog && x1-provjera_prvog>=0.1)
	    printf("Manje\n");
	    }while(k!=1);
	    int t=0;
	    do{
	        printf("Unesite rjesenje x2: ");
	        scanf("%lf", &provjera_drugog);
	        if((provjera_drugog>x2 && provjera_drugog-x2<E) || (x2>provjera_drugog && x2-provjera_drugog<E) || (provjera_drugog==x2))
	        {
	            printf("Tacno\n");
	            t=1;
	        }
	        if(provjera_drugog>x2 && provjera_drugog-x2<0.1 && provjera_drugog-x2>=E)
	        printf("Priblizno vece\n");
	        if(x2>provjera_drugog && x2-provjera_drugog<0.1 && x2-provjera_drugog>=E)
	        printf("Priblizno manje\n");
	        if(provjera_drugog>x2 && provjera_drugog-x2>=0.1)
	        printf("Vece\n");
	        if(x2>provjera_drugog && x2-provjera_drugog>=0.1)
	        printf("Manje\n");
	    }while(t!=1);
	
	return 0;
}
