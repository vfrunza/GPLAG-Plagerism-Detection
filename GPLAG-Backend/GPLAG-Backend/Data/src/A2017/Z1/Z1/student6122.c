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
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	
	float max;
	if(P1>H1) max=P1; 
	else max=H1;
	if(C1>max) max=C1;
	
	int s=(int)tarik+(int)mirza+(int)bojan;
	
	if(s==219){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", P2+H2+C2);
		if(P2+H2+C2>max*0.9+H1+C1){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", max*0.9+H1+C1);	
		}
	}
	if(s==232){
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", P3+H3+P3);
		if(P3+H3+P3>P1*0.9*2+H1){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", P1*0.9*2+H1);
		}
	}
	if(s==227){
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", P3+P3+C3);
		if(P3+P3+C3>2*P1*0.9+C1){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", P1*0.9*2+C1);
		}
	}
	if(s==211){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", H2+H2+C2);
		if(H2+H2+C2>C1*0.9+2*H1){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", C1*0.9+2*H1);
		}
	}
	if(s==224){
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", H1+H1+P1);
	}
	if(s==206){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", C2+C2+H2);
		if(C2+C2+H2>C1*2*0.9+H1){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", C1*2*0.9+H1);
		}
	}
	if(s==214){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", C2+C2+P2);
		if(C2+C2+P2>P1*0.9+2*C1){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", P1*0.9+2*C1);
		}
	}
	if(s==240){
	    printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", P3*3);
	    if(P3*3>P1*0.9*3){
	    	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", P1*0.9*3);
	    }
	}
	if(s==216){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", H2*3);
		if(H2*3>H1*0.9*3){
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", H1*0.9*3); 
		}
	}
	if(s==201){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", C2*3);
		if(C2*3>C1*0.9*3){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", C1*0.9*3); 
		}
	}
	return 0;
}
