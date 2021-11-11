#include <stdio.h>
#include <math.h>
#define P_Restoran 6.80
#define H_Restoran 3.30
#define C_Restoran 5.00
#define P_Ffood 8.00
#define H_Ffood 3.00
#define C_Ffood 3.90
#define P_Bistro 5.30
#define H_Bistro 5.00
#define C_Bistro 6.00
#define EPSILON 0.0001

int main() {
	/*printf("Zadaća 1, Zadatak 1");*/
	char tarik,bojan,mirza,novi_red;
	double suma_r=0.0,suma_f=0.0,suma_b=0.0,min_suma=0.0,suma_r1=0.0,suma_r2=0.0,suma_r3=0.0,popust1=0.0,popust2=0.0,popust3=0.0;
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&tarik);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&bojan);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&mirza);
	scanf("%c",&novi_red);
	tarik=(int)tarik;
	bojan=(int)bojan;
	mirza=(int)mirza;
	
	

	if(tarik=='P'){
		suma_r+=P_Restoran;
		suma_f+=P_Ffood;
		suma_b+=P_Bistro;
	}
	else if(tarik=='H'){
		suma_r+=H_Restoran;
		suma_f+=H_Ffood;
		suma_b+=H_Bistro;
	}
	else if(tarik=='C'){
		suma_r+=C_Restoran;
		suma_f+=C_Ffood;
		suma_b+=C_Bistro;
	}	
	if(bojan=='P'){
		suma_r+=P_Restoran;
		suma_f+=P_Ffood;
		suma_b+=P_Bistro;
	}	
	else if(bojan=='H'){
		suma_r+=H_Restoran;
		suma_f+=H_Ffood;
		suma_b+=H_Bistro;
	}	
	else if(bojan=='C'){
		suma_r+=C_Restoran;
		suma_f+=C_Ffood;
		suma_b+=C_Bistro;
	}	
	if(mirza=='P'){
		suma_r+=P_Restoran;
		suma_f+=P_Ffood;
		suma_b+=P_Bistro;
	}	
	else if(mirza=='H'){
		suma_r+=H_Restoran;
		suma_f+=H_Ffood;
		suma_b+=H_Bistro;
	}	
	else if(mirza=='C'){
		suma_r+=C_Restoran;
		suma_f+=C_Ffood;
		suma_b+=C_Bistro;
	}
	
	min_suma=suma_r;
	if(suma_b<suma_r) min_suma=suma_b;
	if(suma_f<suma_r) min_suma=suma_f;
	
    if(fabs(min_suma-suma_r)<EPSILON) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",suma_r);
	else if(fabs(min_suma-suma_f)<EPSILON){
	    printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",suma_f);
	    if(tarik=='H' && bojan=='H' && mirza=='H'){
	    	suma_r1=3*H_Restoran;
	    	popust1=suma_r1-(3*(H_Restoran/10.0));
	    	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",popust1);
	    }
	    else if((tarik=='P' && bojan=='H' && mirza=='C')||
	          (tarik=='P' && bojan=='C' && mirza=='H')||
	          (tarik=='H' && bojan=='C' && mirza=='P')||
	          (tarik=='H' && bojan=='P' && mirza=='C')||
	          (tarik=='C' && bojan=='H' && mirza=='P')||
	          (tarik=='C' && bojan=='P' && mirza=='H')){
	          	suma_r2=P_Restoran+H_Restoran+C_Restoran;
	          	popust2=suma_r2-(P_Restoran/10.0);
	            printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",popust2);
	          }
	}
	   
	
	else if(fabs(min_suma-suma_b)<EPSILON){ 
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",suma_b);
		if((tarik=='H' && bojan=='P' && mirza=='P')||
		    (tarik=='P' && bojan=='H' && mirza=='P')||
		    (tarik=='P' && bojan=='P' && mirza=='H')){
		    	suma_r3=2*P_Restoran+H_Restoran;
		    	popust3=suma_r3-(2*(P_Restoran/10.0));
		    	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",popust3);
		    }
	}	
	return 0;
}
