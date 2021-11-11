#include <stdio.h>
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
	
	char tarik, bojan, mirza, novi_red;
	int P = 0;
	int H = 0;
	int C = 0;
	float r = 0;
	float f = 0;
	float b = 0;
	float p;
	float a;
	int t;
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	
	switch(tarik){
		
		case 'P':
		P++;
		break;
		
		case 'H':
		H++;
		break;
		
		case 'C':
		C++;
		break;
	}
	
	switch(bojan){
		
		case 'P':
		P++;
		break;
		
		case 'H':
		H++;
		break;
		
		case 'C':
		C++;
		break;
	}
	
	switch(mirza){
		
		case 'P':
		P++;
		break;
		
		case 'H':
		H++;
		break;
		
		case 'C':
		C++;
		break;
		
	}
	
	r = (P*P1 + H*H1 + C*C1);
	if(P>0){
		
		p = ((P*P1-(10*P1)/100*P) + H*H1 + C*C1);
		
	}else if(C>0){
		
		p = ((C*C1-(10*C1)/100*C) + P*P1 + H*H1);
		
	}else{
		
		p = ((H*H1 - (10*H1)/100*H) + P*P1 + C*C1);
	}
	
		f = (P*P2 + H*H2 + C*C2);
        b = (P*P3 + H*H3 + C*C3);
        
    if(r<f && r<b){
    	
    	a = r;
    	t = 1;
    }else if(f<r && f<b){
    	
    	a = f;
    	t = 2;
    }else{
    	
    	a = b;
    	t = 3;
    }
    
    switch(t){
    	
    	case 1:
    	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", r);
    	break;
    	
    	case 2:
    	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", f);
        break;
        
        case 3:
        printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", b);
        break;
        
    }
    
    if(a>p && a!=r){
    	
    	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", p);
    }
	
	return 0;
}
