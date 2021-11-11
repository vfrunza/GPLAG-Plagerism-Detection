#include <stdio.h>

int main() {
	
	char tarik, bojan, mirza, red;
	double konj=0, trovac=0, lore=0, kp=6.8, tp=8, lp=8, kh=3.3, th=3, lh=5, kc=5, tc=3.9, lc=6;
	int ham=0, pizza=0, cev=0;
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &red);
	
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &red);
	
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &red);
	
	if(tarik=='H') ham++;
	else if(tarik=='P') pizza++;
	else if(tarik=='C') cev++;
	
	if(bojan=='H') ham++;
	else if (bojan=='P') pizza++;
	else if (bojan=='C') cev++;
	
	if(mirza=='H') ham++;
	else if(mirza=='P') pizza++;
	else if(mirza=='C') cev++;
	
	konj = kh * ham + kp * pizza + kh * cev;
	trovac = th * ham + tp * pizza + tc * cev;
	lore = lh * ham + lp * pizza + lc * cev;
	
	if(konj < trovac && konj < lore){
	
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", konj);
	
	}	
	else if(trovac < konj && trovac < lore){
		
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", trovac);
		
	}
		
	else{
		
	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", lore);
		
	}
	
		if (ham > pizza && ham > cev)
		kh *= 0.9;
		
		else if(cev > ham && cev > pizza)
		kc *= 0.9;
		
		else
		kp *= 0.9;
		
		konj = ham * kh + pizza * kp + cev * kc;
		
		if(konj < trovac && konj < lore) 
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", konj);
	
	
	
	return 0;
}
