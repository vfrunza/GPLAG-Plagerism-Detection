#include <stdio.h>
#include <math.h>
#define P1 6.80
#define P2 8.00
#define P3 5.30
#define H1 3.30
#define H2 3.00
#define H3 5.00
#define C1 5.00
#define C2 3.90
#define C3 6.00

int main() {
	char T,B,M,novi_red;
	double RKK=0,FFT=0,BL=0,RKK1=0,min=0, T1, B1, M1;
	 
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &T);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &B);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &M);
	scanf("%c", &novi_red);
	  
	if(T=='P'){
	  	RKK+=P1;
	  	FFT+=P2;
	  	BL+=P3;
	  	T1=P1;
	}
	
	else if(T=='H'){
	  	RKK+=H1;
	  	FFT+=H2;
	  	BL+=H3;
	  	T1=H1;
	}
	
	else {
		RKK+=C1;
		FFT+=C2;
		BL+=C3;
		T1=C1;
	}
	
	
	if(B=='P'){
		RKK+=P1;
		FFT+=P2;
		BL+=P3;
		B1=P1;
	}
	
	else if(B=='H'){
		RKK+=H1;
		FFT+=H2;
		BL+=H3;
		B1=H1;
	}
	
	else{
		RKK+=C1;
		FFT+=C2;
		BL+=C3;
		B1=C1;
	}

	
	if(M=='P'){
		RKK+=P1;
		FFT+=P2;
		BL+=P3;
		M1=P1;
	}
	
	else if(M=='H'){
	    RKK+=H1;
	    FFT+=H2;
	    BL+=H3;
	    M1=H1;
    }
    
    else {
    	RKK+=C1;
    	FFT+=C2;
    	BL+=C3;
    	M1=C1;
    }
	
	  	
	min=RKK;
	if(min>FFT) min=FFT;
	if(min>BL) min=BL;
	   
	if(fabs(min-RKK)<0.001) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",RKK);
	else if(fabs(min-FFT)<0.001) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",FFT);
	else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",BL);
	  
	if(T==M && T==B) {
		RKK1=3*T1-(3*T1*0.1);
	}
	  
	else if(fabs(B1-T1)<0.001 && fabs(T1-M1)>0.001) {
		if(B1>M1) RKK1=2*B1-(2*B1*0.1)+M1;
		else RKK1=2*B1+M1-M1*0.1;
	}
	
	else if(fabs(B1-M1)<0.001 && fabs(B1-T1)>0.001) {
		if(B1>T1) RKK1=2*B1-(2*B1*0.1)+T1;
		else RKK1=2*B1+T1-T1*0.1;
	}
	
	else if(fabs(M1-T1)<0.001 && fabs(M1-B1)>0.001) {
		if(M1>B1) RKK1=2*M1-(2*M1*0.1)+B1;
		else RKK1=2*M1+B1-B1*0.1;
	}
	
	else {
		if(M1>B1 && M1>T1) RKK1=M1-M1*0.1+B1+T1;
		else if(B1>M1 && B1>T1) RKK1=B1-B1*0.1+M1+T1;
		else RKK1=T1-T1*0.1+B1+M1;
	}
	  
	if(RKK1<min && fabs(min-RKK)>0.001) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", RKK1);
	  	
	  
	  
	   
	 
	   	
	   	
	   
	  
	   
	  	
	  	
	  
	return 0;
}
