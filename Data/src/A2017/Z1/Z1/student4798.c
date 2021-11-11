#include <stdio.h>

#define RP 6.80
#define RH 3.30
#define RC 5.00

#define FP 8.00
#define FH 3.00
#define FC 3.90

#define BP 5.30
#define BH 5.00
#define BC 6.00

int main() {
	float suma_r=0, suma_f=0, suma_b=0, popust;
	int pica=0, hamburger=0, cevapi=0;
	char tarik, bojan, mirza, nr;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&tarik);
	scanf("%c",&nr);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&bojan);
	scanf("%c",&nr);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&mirza);
	scanf("%c",&nr);
	
	if (tarik=='P'){
		pica++;
		suma_r+=RP;
		suma_f+=FP;
		suma_b+=BP;
	}
	else if (tarik=='C'){
		cevapi++;
		suma_r+=RC;
		suma_f+=FC;
		suma_b+=BC;
	}
	else {
		hamburger++;
		suma_r+=RH;
		suma_f+=FH;
		suma_b+=BH;
	}
	
	if (bojan=='P'){
		pica++;
		suma_r+=RP;
		suma_f+=FP;
		suma_b+=BP;
	}
	else if (bojan=='H'){
		hamburger++;
		suma_r+=RH;
		suma_f+=FH;
		suma_b+=BH;
	}
	else {
		cevapi++;
		suma_r+=RC;
		suma_f+=FC;
		suma_b+=BC;
	}
	
	if (mirza=='P'){
		pica++;
		suma_r+=RP;
		suma_f+=FP;
		suma_b+=BP;
	}
	else if (mirza=='H'){
		hamburger++;
		suma_r+=RH;
		suma_f+=FH;
		suma_b+=BH;
	}
	else {
		cevapi++;
		suma_r+=RC;
		suma_f+=FC;
		suma_b+=BC;
	}
	
	popust=cevapi*RC*0.1;
	if (pica*RP*0.1>popust){
		popust=pica*RP*0.1;
	}
	if (hamburger*RH*0.1>popust){
		popust=hamburger*RH*0.1;
	}
	
	if (suma_r<suma_b && suma_r<suma_f){
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", suma_r);
	}
	else if (suma_f<suma_r && suma_f<suma_b){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma_f);
		if (suma_r-popust<suma_f) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", suma_r-popust);
	}
	else{
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma_b);
		if (suma_r-popust<suma_b) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", suma_r-popust);
	}
	return 0;
}
