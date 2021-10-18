#include <stdio.h>
/*  restoran 1- Kod konja i konjusara 
	restoran 2- trovac
	restoran 3- lorelei */
#define P_restoran1 6.80
#define P_restoran2 8.00
#define P_restoran3 5.30
#define H_restoran1 3.30
#define H_restoran2 3.00
#define H_restoran3 5.00
#define C_restoran1 5.00
#define C_restoran2 3.90
#define C_restoran3 6.00

int main() {
	char tarik, bojan, mirza, novi_red;
	int p_brojac=0, h_brojac=0, c_brojac=0;
	double restoran1=0, restoran2=0, restoran3=0, popust; /*cijene*/
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	
	/*TARIK*/
	if(tarik == 'P') p_brojac++;
	else if(tarik == 'H') h_brojac++;
	else c_brojac++;
	
	/* BOJAN */
	if(bojan == 'P') p_brojac++;
	else if(bojan == 'H') h_brojac++;
	else c_brojac++;
	
	/*MIRZA*/
	if(mirza == 'P') p_brojac++;
	else if(mirza == 'H') h_brojac++;
	else c_brojac++;
	
	/* restoran1 */
	restoran1 = p_brojac*P_restoran1 + h_brojac*H_restoran1 + c_brojac*C_restoran1;
	restoran2 = p_brojac*P_restoran2 + h_brojac*H_restoran2 + c_brojac*C_restoran2;
	restoran3 = p_brojac*P_restoran3 + h_brojac*H_restoran3 + c_brojac*C_restoran3;
		
	if(restoran1<restoran2 && restoran1<restoran3){
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", restoran1);
		return 0;
	}
	if(restoran2<restoran1 && restoran2<restoran3)	{
			if (p_brojac>0) 
				popust = p_brojac*(P_restoran1-P_restoran1/10.) + h_brojac*H_restoran1 + c_brojac*C_restoran1;
			else if(h_brojac>0) 
				popust = p_brojac*P_restoran1 + h_brojac*(H_restoran1-H_restoran1/10.) + c_brojac*C_restoran1;
			else popust = p_brojac*P_restoran1 + h_brojac*H_restoran1 + c_brojac*(C_restoran1-H_restoran1/10.);
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", restoran2);
			if(popust < restoran2)
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
		    return 0;
	}
	if(restoran3<restoran1 && restoran3<restoran2)	{
			if (p_brojac>0) 
				popust = p_brojac*(P_restoran1-P_restoran1/10.) + h_brojac*H_restoran1 + c_brojac*C_restoran1;
			else if(h_brojac>0) 
				popust = p_brojac*P_restoran1 + h_brojac*(H_restoran1-H_restoran1/10.) + c_brojac*C_restoran1;
			else popust = p_brojac*P_restoran1 + h_brojac*H_restoran1 + c_brojac*(C_restoran1-H_restoran1/10.);
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", restoran3);
			if(popust < restoran3)
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
	}
	
	/*oduzeti cijene najskupljih za rest2 i rest3 */
		return 0;
}
