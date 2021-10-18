#include <stdio.h>
#define FF(P) 8.00 /*FF-fast food, B-Bistro (oznake u zagradama predstavljaju jela:pizza, hamburger, cevapi)*/
#define FF(H) 3.00
#define FF(C) 3.90
#define B(P)  6.30
#define B(H)  5.00
#define B(C)  6.00
int main() {
	
	char tarik, bojan, mirza;
	float Pr=6.80, Hr=3.30, Cr=5.00, Pp, Hp, Cp, Pu, Hu, Cu, Cf;
	
	
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	
	Pp=6.80/100*10;       /*Popust u Restoranu "Kod konja i konjusara"*/
	Hp=3.30/100*10;
	Cp=5.00/100*10;
	
	Pu=Pr-Pp;             /*Cijena jela sa uracunatim popustom*/
	Hu=Hr-Hp;
	Cu=Cr-Cp;
	
	
	
    
	
	
	
	

	return 0;
}
