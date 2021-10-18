#include <stdio.h>

int main() {
	double cijena; 
	char tarik, mirza, bojan, H, P, C;
	printf("Unesite jelo za Tarika:\n"); 
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu:\n"); 
	scanf("%c", &mirza); 
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana:\n"); 
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	
	if(tarik == H || bojan == H || mirza == H) {
		printf("Najjeftinije je Fast-food "Trovac" (9.00 KM"); 
		printf("Sa popustom ")
	}
	else if (tarik == P || bojan == P || mirza == P) {
		printf("Najjeftiniji je Bisto "Lorelei" (15.90 KM)");
		printf("Sa popustom bi Restoran bio jeftiniji  ")
	}
	else if(tarik == C || tarik == C || mirza == C) {
		printf("Najjeftiniji je Fast-food "Trovac" (11.70 KM)");
	}
	else if(tarik == H || bojan == C || mirza == P) {
		printf("Naje")
	}
	
	printf("Zadaća 1, Zadatak 1");
	return 0;
}
