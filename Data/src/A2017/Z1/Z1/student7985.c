#include <stdio.h>

int main() {
	
	double Rsuma=0, Fsuma=0, Bsuma=0;
	/*Rsuma=Restoran suma, F kao Fast-food, B kao Bistro*/
	int brojac_p=0, brojac_h=0, brojac_c=0;
	char T=' ', B=' ', M=' ';
	char enter=' ';
	/*inicijalizovala sve redom..*/
	printf("Unesite jelo za Tarika: ");
	scanf("%c%c", &T, &enter);
	printf("Unesite jelo za Bojana: ");
	scanf("%c%c", &B, &enter);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c%c", &M, &enter);
	
	
	if(T=='P')  brojac_p++;
	else if(T=='H') brojac_h++;
	else if(T=='C') brojac_c++;
	else printf("Belaj");
	
	
	if(B=='P') brojac_p++;
	else if(B=='H')brojac_h++;
	else if(B=='C')brojac_c++;
	else printf("Belaj");
	
	
	if(M=='P') brojac_p++;
	else if(M=='H') brojac_h++;
	else if(M=='C') brojac_c++;
	else printf("Belaj");
	
	Rsuma=brojac_p*6.8+brojac_h*3.3+brojac_c*5;
	Fsuma=brojac_p*8+brojac_h*3+brojac_c*3.9;
	Bsuma=brojac_p*5.3+brojac_h*5+brojac_c*6;
	
	
	printf("Najjeftiniji je ");
	if(Rsuma<Bsuma && Rsuma<Fsuma) {
		printf("Restoran \"Kod konja i konjusara\" (%.2f KM).", Rsuma);

	}
	else{
		if(Fsuma<Rsuma && Fsuma<Bsuma) printf("Fast-food \"Trovac\" (%.2f KM).", Fsuma);
		else printf("Bistro \"Lorelei\" (%.2f KM).", Bsuma);
		
		/*popust od najskupljeg ka najjeftinijem*/
		if(brojac_p>0) Rsuma=Rsuma-brojac_p*0.68;
		else if(brojac_c>0) Rsuma=Rsuma-brojac_c*.5;
		else Rsuma=Rsuma-brojac_h*0.33;
		
		if(Rsuma<=Fsuma && Rsuma<=Bsuma) /*jednakost upitna??*/
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", Rsuma);
	}
	
	return 0;
}
