#include <stdio.h>
#include <math.h>

#define PizzaRestoran 6.80
#define HamburgerRestoran 3.30
#define CevapiRestoran 5.00
#define PizzaFastfood 8.00
#define HamburgerFastfood 3.00
#define CevapiFastfood 3.90
#define PizzaBistro 5.30
#define HamburgerBistro 5.00
#define CevapiBistro 6.00

int main() {
	char tarik,bojan,mirza,novi_red;
	float ukupnorestoran=0,ukupnofastfood=0,ukupnobistro=0,najjeftinije;
		printf("Unesite jelo za Tarika: ");
		scanf("%c",&tarik);
		scanf("%c",&novi_red);
		printf("Unesite jelo za Bojana: ");
		scanf("%c",&bojan);
		scanf("%c",&novi_red);
		printf("Unesite jelo za Mirzu: ");
		scanf("%c",&mirza);
		scanf("%c",&novi_red);
	
	if(tarik=='P'){
		ukupnorestoran+=PizzaRestoran;
		ukupnofastfood+=PizzaFastfood;
		ukupnobistro+=PizzaBistro;
	}else if(tarik=='H'){
		ukupnorestoran+=HamburgerRestoran;
		ukupnofastfood+=HamburgerFastfood;
		ukupnobistro+=HamburgerBistro;
	}else if(tarik=='C'){
		ukupnorestoran+=CevapiRestoran;
		ukupnofastfood+=CevapiFastfood;
		ukupnobistro+=CevapiBistro;
	}
	
	if(bojan=='P'){
		ukupnorestoran+=PizzaRestoran;
		ukupnofastfood+=PizzaFastfood;
		ukupnobistro+=PizzaBistro;
	}else if(bojan=='H'){
		ukupnorestoran+=HamburgerRestoran;
		ukupnofastfood+=HamburgerFastfood;
		ukupnobistro+=HamburgerBistro;
	}else if(bojan=='C'){
		ukupnorestoran+=CevapiRestoran;
		ukupnofastfood+=CevapiFastfood;
		ukupnobistro+=CevapiBistro;
	}
	
	if(mirza=='P'){
		ukupnorestoran+=PizzaRestoran;
		ukupnofastfood+=PizzaFastfood;
		ukupnobistro+=PizzaBistro;
	}else if(mirza=='H'){
		ukupnorestoran+=HamburgerRestoran;
		ukupnofastfood+=HamburgerFastfood;
		ukupnobistro+=HamburgerBistro;
	}else if(mirza=='C'){
		ukupnorestoran+=CevapiRestoran;
		ukupnofastfood+=CevapiFastfood;
		ukupnobistro+=CevapiBistro;
	}
	
	najjeftinije=ukupnorestoran;
	if(ukupnorestoran>ukupnofastfood)
		najjeftinije=ukupnofastfood;
	if(najjeftinije>ukupnobistro)
		najjeftinije=ukupnobistro;
	
	
	if(fabs(najjeftinije-ukupnorestoran)<0.000001){
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",najjeftinije);
	}else if(fabs(najjeftinije-ukupnofastfood)<0.000001){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",najjeftinije);
	}else{
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",najjeftinije);
	}
	
	if(fabs(najjeftinije-ukupnorestoran)<0.0001){}
	
	else if(fabs(najjeftinije-ukupnorestoran)>0.001){
			if(mirza=='H'&&bojan=='H'&&tarik=='H'){
				ukupnorestoran=ukupnorestoran*9/10;
			}
			else if(mirza=='P'&&bojan=='P'&&tarik=='P'){
				ukupnorestoran=ukupnorestoran*9/10;
			}
			else if(mirza=='C'&&bojan=='C'&&tarik=='C'){
				ukupnorestoran=ukupnorestoran*9/10;
			}
			else if((mirza=='P'&&bojan=='P'&&tarik=='H')||(mirza=='P'&&tarik=='P'&&bojan=='H')||(bojan=='P'&&tarik=='P'&&mirza=='H')){
				ukupnorestoran=PizzaRestoran*2*9/10+HamburgerRestoran;
			}else if((mirza=='P'&&bojan=='P'&&tarik=='C')||(mirza=='P'&&tarik=='P'&&bojan=='C')||(bojan=='P'&&tarik=='P'&&mirza=='C')){
				ukupnorestoran=PizzaRestoran*2*9/10+CevapiRestoran;
			}else if((mirza=='C'&&bojan=='C'&&tarik=='H')||(mirza=='C'&&tarik=='C'&&bojan=='H')||(bojan=='C'&&tarik=='C'&&mirza=='H')){
				ukupnorestoran=CevapiRestoran*2*9/10+HamburgerRestoran;
			}else if((mirza=='C'&&bojan=='C'&&tarik=='P')||(mirza=='C'&&tarik=='C'&&bojan=='P')||(bojan=='C'&&tarik=='C'&&mirza=='P')){
				ukupnorestoran=CevapiRestoran*2*9/10+PizzaRestoran;
			}else if((mirza=='H'&&bojan=='H'&&tarik=='C')||(mirza=='H'&&tarik=='H'&&bojan=='C')||(bojan=='H'&&tarik=='H'&&mirza=='C')){
				ukupnorestoran=HamburgerRestoran*2*9/10+CevapiRestoran;
			}else if((mirza=='H'&&bojan=='H'&&tarik=='P')||(mirza=='H'&&tarik=='H'&&bojan=='P')||(bojan=='H'&&tarik=='H'&&mirza=='P')){
				ukupnorestoran=HamburgerRestoran*2*9/10+PizzaRestoran;
			}else if((tarik=='H'&&bojan=='P'&&mirza=='C')||(tarik=='C'&&bojan=='H'&&mirza=='P')||(tarik=='P'&&bojan=='C'&&mirza=='H')||
			(tarik=='H'&&bojan=='C'&&mirza=='P')||(tarik=='C'&&bojan=='P'&&mirza=='H')||(tarik=='P'&&mirza=='C'&&bojan=='H')){
				ukupnorestoran=PizzaRestoran*9/10+HamburgerRestoran+CevapiRestoran;
			}
		
		if(ukupnorestoran<najjeftinije){
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",ukupnorestoran);
		}
	}
	return 0;
}