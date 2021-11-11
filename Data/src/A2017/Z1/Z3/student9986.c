#include <stdio.h>
#include <math.h>

int main() {
	printf("Unesite koeficijente a, b i c: ");
	float a,b,c,d,x1,x2,rez;
	scanf("%f%f%f", &a,&b,&c);
	d=b*b-4*a*c;
  if(d<0) {printf("Rjesenja su imaginarni brojevi.");
  	return 0;
  }
  x1=(-b - sqrt(d))/(2 * a);
  x2=(-b + sqrt(d))/(2 * a);
  	int k=0;
  	do{
  		printf("Unesite rjesenje x1: ");
  		float pxl;
  		scanf("%f",&pxl);
  		if(x1<0){
  			rez=pxl-x1;
  		
  		if(rez>=-0.001 && rez<=0.001){printf("Tacno\n"); k=1;}
  		else if(rez>0 && rez<=0.1) printf("Priblizno vece\n");                      
  		else if(rez>0) printf("Vece\n");
  		else if(rez<0 && rez>-0.1) printf("Priblizno manje\n");
  		else if(rez<0) printf("Manje\n");
  		
  	}else
	
	{
	rez=x1-pxl;
	if(rez>=-0.001 && rez<=0.001) {printf("Tacno\n"); k=1;}
	else if(rez<0 && rez>=-0.1) printf("Priblizno vece\n");
    else if(rez<0) printf("Vece\n");
	else if(rez>0 && rez<=0.1) printf("Priblizno manje\n");
	else if(rez>0) printf("Manje\n");
}

}while(k==0);

k=0;
do{
	printf("Unesite rjesenje x2: ");
	float pxl;
		scanf("%f",&pxl);
	if(x2<0){
		rez=pxl-x2;
	if(rez>=-0.001 && rez<=0.001){printf("Tacno\n"); k=1;}
 	else if(rez>0 && rez <=0.1) printf("Priblizno vece\n");                      
  	else if(rez>0) printf("Vece\n");
  	else if(rez<0 && rez>-0.1) printf("Priblizno manje\n");
  	else if(rez<0) printf("Manje\n");
	
	}else
	{rez=x2-pxl;
	if(rez>=-0.001 && rez<=0.001){printf("Tacno\n"); k=1;}
	else if(rez<0 && rez>=-0.1) printf("Priblizno vece\n");
    else if(rez<0) printf("Vece\n");
	else if(rez>0 && rez<=0.1) printf("Priblizno manje\n");
	else if(rez>0) printf("Manje\n");
}
}while(k==0);
	
	

	return 0;
}
