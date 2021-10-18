#include <stdio.h>

#define popust 10
#define PizzaR 6.80
#define PizzaT 8.00
#define PizzaL 5.30
#define HamburgerR 3.30
#define HamburgerT 3.00
#define HamburgerL 5.00
#define CevapiR 5.00
#define CevapiT 3.90
#define CevapiL 6.00

int main () {

char tarik,bojan,mirza;
float RKK=0,FFT=0,LOR=0;
int Pizza=0,Hamburger=0,Cevapi=0;
float MIN;

    printf("Unesite jelo za Tarika: ");
	scanf(" %c", &tarik);

	printf("Unesite jelo za Bojana: ");
	scanf(" %c", &bojan);

	printf("Unesite jelo za Mirzu: ");
	scanf(" %c", &mirza);


if (tarik=='P')
	Pizza++;
else if (tarik == 'H')
	Hamburger++;
else if (tarik == 'C')
	Cevapi++;

if (bojan=='P')
	Pizza++;
else if (bojan == 'H')
	Hamburger++;
else if (bojan == 'C')
	Cevapi++;

if (mirza=='P')
	Pizza++;
else if (mirza == 'H')
	Hamburger++;
else if (mirza == 'C')
	Cevapi++;


RKK=PizzaR*Pizza + HamburgerR*Hamburger + CevapiR*Cevapi;
FFT=PizzaT*Pizza + HamburgerT*Hamburger + CevapiT*Cevapi;
LOR=PizzaL*Pizza + HamburgerL*Hamburger + CevapiL*Cevapi;


if ((RKK<FFT) && (RKK<LOR)) 
    MIN=RKK; 
else if ((FFT<RKK) && (FFT<LOR))
	MIN=FFT;
else if ((LOR<RKK) && (LOR<FFT))
	MIN=LOR;


if(MIN==RKK)
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",RKK );
else if(MIN==FFT)
	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",FFT );
else if(MIN==LOR)
	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",LOR );

if(MIN!=RKK){
	if(Pizza>0) 
	RKK = RKK - (PizzaR/popust)*Pizza;
	else if(Hamburger>0) 
	RKK = RKK -(HamburgerR/popust)*Hamburger;
	else if (Cevapi>0) 
	RKK = RKK - (CevapiR/popust)*Cevapi;

if (MIN>=RKK)
printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",RKK);
}

return 0;
}

