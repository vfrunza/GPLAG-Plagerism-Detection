#include <stdio.h>
#include <math.h>
#define eps 0.0001

int main() {
	
	char Tarik, Bojan, Mirza, novi_red;
	double Restoran_pizza=6.8, Restoran_hamburger=3.3, Restoran_cevapi=5.0;
	double Fast_food_pizza=8.0, Fast_food_hamburger=3.0, Fast_food_cevapi=3.9;
	double Bistro_pizza=5.3, Bistro_hamburger=5.0, Bistro_cevapi=6.0;
	double Restoran=0, Restoran_sa_popustom=0, Fast_food=0, Bistro=0, t=0, b=0, m=0;
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c%c", &Tarik, &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c%c", &Bojan, &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c%c", &Mirza, &novi_red);
	
	switch(Tarik) {
		case 'P': 
			Restoran+=Restoran_pizza;
			Fast_food+=Fast_food_pizza;
			Bistro+=Bistro_pizza;
			t=Restoran_pizza;
			break;
		case 'H':
			Restoran+=Restoran_hamburger;
			Fast_food+=Fast_food_hamburger;
			Bistro+=Bistro_hamburger;
			t=Restoran_hamburger;
			break;
		case 'C':
			Restoran+=Restoran_cevapi;
			Fast_food+=Fast_food_cevapi;
			Bistro+=Bistro_cevapi;
			t=Restoran_cevapi;
			break;
	}
	
	switch(Bojan) {
		case 'P':
			Restoran+=Restoran_pizza;
			Fast_food+=Fast_food_pizza;
			Bistro+=Bistro_pizza;
			b=Restoran_pizza;
			break;
		case 'H':
			Restoran+=Restoran_hamburger;
			Fast_food+=Fast_food_hamburger;
			Bistro+=Bistro_hamburger;
			b=Restoran_hamburger;
			break;
		case 'C':
			Restoran+=Restoran_cevapi;
			Fast_food+=Fast_food_cevapi;
			Bistro+=Bistro_cevapi;
			b=Restoran_cevapi;
			break;
		
	}
	
	switch(Mirza) {
		case 'P':
			Restoran+=Restoran_pizza;
			Fast_food+=Fast_food_pizza;
			Bistro+=Bistro_pizza;
			m=Restoran_pizza;
			break;
		case 'H':
			Restoran+=Restoran_hamburger;
			Fast_food+=Fast_food_hamburger;
			Bistro+=Bistro_hamburger;
			m=Restoran_hamburger;
			break;
		case 'C':
			Restoran+=Restoran_cevapi;
			Fast_food+=Fast_food_cevapi;
			Bistro+=Bistro_cevapi;
			m=Restoran_cevapi;
			break;
	}
	
	
	if(t>b && t>m) Restoran_sa_popustom=t-(t*10/100)+b+m;
	else if(b>t && b>m) Restoran_sa_popustom=b-(b*10/100)+t+m;
	else if(m>t && m>b) Restoran_sa_popustom=m-(m*10/100)+t+b;
	else if(fabs(t-b)<eps && t>m) Restoran_sa_popustom=2*(t-(t*10/100))+m;
	else if(fabs(t-m)<eps && t>b) Restoran_sa_popustom=2*(t-(t*10/100))+b;
	else if(fabs(b-m)<eps && b>t) Restoran_sa_popustom=2*(b-(b*10/100))+t;
	else Restoran_sa_popustom=(t-(t*10/100))*3;
	
	if(Restoran<Fast_food && Restoran<Bistro) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", Restoran);
	else if(Fast_food<Restoran && Fast_food<Bistro) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", Fast_food);
		if(Restoran_sa_popustom<Fast_food) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", Restoran_sa_popustom);
	}
	else {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", Bistro);
		if(Restoran_sa_popustom<Bistro) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", Restoran_sa_popustom);
	}
	
	return 0;
}
