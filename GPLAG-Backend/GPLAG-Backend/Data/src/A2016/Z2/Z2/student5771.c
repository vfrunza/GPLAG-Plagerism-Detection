#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define brojel 500
int main() {
	int u,i,j;
	double a[brojel],stepen, ostatakminut,minut,sekund,ostatakstepen,pravistepen,pravisekund,praviminut;
	printf("Unesite broj uglova: ");
	scanf("%d", &u);
	for(i=0; i<u; i++){
		scanf("%lf", &a[i]);

	}
	printf("Uglovi su: \n");
	for(i=0; i<u; i++){
		stepen=(a[i])*(180/PI);
		pravistepen=(int)stepen;
		ostatakstepen=fabs(stepen-pravistepen);
		minut=ostatakstepen*60;
		praviminut=(int) minut; 
		if(praviminut==60){ praviminut=0; pravistepen=pravistepen+1;}
		ostatakminut=fabs(minut-praviminut);
		sekund=(ostatakminut*60) + 0.5;
    	pravisekund=(int)sekund;
    	if(pravisekund==60 ){ praviminut=praviminut+1; pravisekund=0;
    		if(praviminut==60 ){ praviminut=0; if(a[i]<0) pravistepen=pravistepen-1;
    			else pravistepen=pravistepen+1;
    		}
    
    	}
    	if(fabs(pravisekund)>30 && fabs(pravisekund)!=0){for(j=i; j<u-1; j++){ a[j]=a[j+1];
    	} u--; i--;}
else{	printf("%.f stepeni %.f minuta %.f sekundi \n", pravistepen,praviminut,pravisekund );}	
	}
    	


	
	return 0;
}
