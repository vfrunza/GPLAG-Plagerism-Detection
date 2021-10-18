#include<stdio.h>
	#include<math.h>
	#define E 0.001
	int main()
	{
	    double x1,x11,x2,x22,D,a,b,c,m,v;
	    printf("Unesite koeficijente a, b i c: ");
	    scanf("%lf %lf %lf",&a,&b,&c);
	    D=b*b-4*a*c;
	    
	    if (D<0) printf("Rjesenja su imaginarni brojevi.");
	    else {
	        x1=(-b-sqrt(D))/(2*a);
	        x2=(-b+sqrt(D))/(2*a);
	        if (x1<x2) {
	            m=x1;
	            v=x2;
	        }
	        else
	        {
	            m=x2;
	            v=x1;
	        }
	        do {
	            printf("Unesite rjesenje x1: ");
	            scanf("%lf",&x11);
	            if(fabs(x11-m)<E) printf("Tacno\n");
	            else if(fabs(m-x11)<0.1) {
	                if ((x11-m)<0) printf("Priblizno manje\n");
	                else printf("Priblizno vece\n");
	            } else if ((x11-m)<0) printf("Manje\n");
	            else printf ("Vece\n");
	        } while (fabs(m-x11)>=E );
	
	
	        do {
	            printf("Unesite rjesenje x2: ");
	            scanf("%lf",&x22);
	            if(fabs(v-x22)<=E) printf("Tacno\n");
	            else if(fabs(v-x22)<0.1) {
	                if ((x22-v)<0) printf("Priblizno manje\n");
	                else printf("Priblizno vece\n");
	            } else if ((x22-v)<0) printf("Manje\n");
	            else printf ("Vece\n");
	        } while (fabs(v-x22)>=E);
	
	    }
	    return 0;
	}
	