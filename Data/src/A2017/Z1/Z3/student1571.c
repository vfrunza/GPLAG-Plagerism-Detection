#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
	/*printf("Zadaća 1, Zadatak 3");*/
	double a,b,c,D,t,x1,x2,x1_u,x2_u;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	
	D=b*b-4.0*a*c;
	
	
	if(D<0){
		printf("Rjesenja su imaginarni brojevi.");
	}
	
	else{
		t=sqrt(D);
		x1=(-b-t)/(2*a);
		x2=(-b+t)/(2*a);
		
		do{
			printf("Unesite rjesenje x1: ");
		    scanf("%lf",&x1_u);
		    
		    if(fabs(x1-x1_u)<EPSILON){
			     printf("Tacno\n");
			     break;
		    }
		    
		    else if(x1>0){
		    	if(x1_u>0){
		    		if(x1_u>x1){
		    			if(x1_u-x1<0.1) printf("Priblizno vece\n");
		    			else printf("Vece\n");
		    		}
		    		
		    		else if(x1_u<x1){
		    			if(x1-x1_u<0.1) printf("Priblizno manje\n");
		    			else printf("Manje\n");
		    		}
		    		
		    	    
		    	}
		    	
		    	else if(x1_u<0){
		    		if(fabs((-1*x1_u)-x1)<EPSILON) printf("Manje\n");
		    		else printf("Manje\n");
		    	}
		    	else if(fabs(x1_u-0)<EPSILON){
		    		if(fabs(x1-x1_u)<0.1) printf("Priblizno manje\n");
		    		else printf("Manje\n");
		    	}
		    	
		    	
		    }
		    
		   else if(x1<0){
		    	if(x1_u>0){
		    		if(fabs(-1*x1-x1_u)<EPSILON) printf("Vece\n");
		    		else printf("Vece\n");
		    	}
		    	else if(x1_u<0){
		    		if(x1_u>x1){
		    			if(fabs(x1)-fabs(x1_u)<0.1) printf("Priblizno vece\n");
		    			else printf("Vece\n");
		    		}
		    	    else if(x1_u<x1){
		    	    	if(fabs(x1_u)-fabs(x1)<0.1) printf("Priblizno manje\n");
		    	    	else printf("Manje\n");
		    	    }	
		    	
		    	}
		    	else if(fabs(x1_u-0)<EPSILON){
		    		if(fabs(x1-x1_u)<0.1) printf("Priblizno vece\n");
		    		else printf("Vece\n");
		    	}
		    }
		    
		   /* else if(x1<0 && x1_u>0) printf("Vece\n");
		    else if(x1<0 && x1_u<0){
		    	if(x1_u>x1){
		    		if(fabs(x1)-fabs(x1_u)<0.1) printf("Priblizno vece\n");
		    		else printf("Vece\n");
		    	}
		    	else if(x1_u<x1){
		    		if(fabs(x1_u)-fabs(x1)<0.1) printf("Priblizno manje\n");
		    	    else printf("Manje\n");
		    	}
		    }*/
		    
		    else if(fabs(x1-0)<EPSILON){
		    	if(fabs(x1_u-0)<EPSILON){
		    		printf("Tacno\n");
		    		break;
		    	}
		    	else if(x1_u>0){
		    		if(fabs(x1_u-x1)<0.1) printf("Priblizno vece\n");
		    		else printf("Vece\n");
		    	}
		    	else if(x1_u<0){
		    		if(fabs(x1_u-x1)<0.1) printf("Priblizno manje\n");
		    		else printf("Manje\n");
		    	}
		    }
		    
		    
		    
		}while(fabs(x1-x1_u)>EPSILON);
			
	    do{
			printf("Unesite rjesenje x2: ");
		    scanf("%lf",&x2_u);
		    
		    if(fabs(x2-x2_u)<EPSILON){
			     printf("Tacno\n");
			     break;
		    }
		    
		    else if(x2>0){
		    	if(x2_u>0){
		    		if(x2_u>x2){
		    			if(x2_u-x2<0.1) printf("Priblizno vece\n");
		    			else printf("Vece\n");
		    		}
		    		
		    		else if(x2_u<x2){
		    			if(x2-x2_u<0.1) printf("Priblizno manje\n");
		    			else printf("Manje\n");
		    		}
		    	    
		    	}
		    	
		    	else if(x2_u<0){
		    		if(fabs(fabs(x2_u)-x2)<EPSILON) printf("Manje\n");
		    		else printf("Manje\n");
		    	}
		    	else if(fabs(x2_u-0)<EPSILON){
		    		if(fabs(x2-x2_u)<0.1) printf("Priblizno manje\n");
		    		else printf("Manje\n");
		    		
		    	}
		    	
		    }
		    
		   else if(x2<0){
		    	if(x2_u>0){
		    		if(fabs(fabs(x2)-x2_u)<EPSILON) printf("Vece\n");
		    		else printf("Vece\n");
		    	}
		    	else if(x2_u<0){
		    		if(x2_u>x2){
		    			if(fabs(x2)-fabs(x2_u)<0.1) printf("Priblizno vece\n");
		    			else printf("Vece\n");
		    		}
		    	    else if(x2_u<x2){
		    	    	if(fabs(x2_u)-fabs(x2)<0.1) printf("Priblizno manje\n");
		    	    	else printf("Manje\n");
		    	    }	
		    	
		    	}
		    	else if(fabs(x2_u-0)<EPSILON){
		    		if(fabs(x2-x2_u)<0.1) printf("Priblizno vece\n");
		    		else printf("Vece\n");
		    	}
		    }
		      else if(fabs(x2-0)<EPSILON){
		    	if(fabs(x2_u-0)<EPSILON){
		    		printf("Tacno\n");
		    		break;
		    	}
		    	else if(x2_u>0){
		    		if(fabs(x2_u-x2)<0.1) printf("Priblizno vece\n");
		    		else printf("Vece\n");
		    	}
		    	else if(x2_u<0){
		    		if(fabs(x2_u-x2)<0.1) printf("Priblizno manje\n");
		    		else printf("Manje\n");
		    	}
		    }
		    
		    
		    
		}while(fabs(x2-x2_u)>EPSILON);
			
		}	
		
	
		
	return 0;
}
