#include <stdio.h>

int main() {
	double PR=6.80, HR=3.30, CR=5.00, PF=8.00, HF=3.00, CF=3.90, PB=5.30, HB=5.00, CB=6.00;
	double Rukupno=0, Fukupno=0, Bukupno=0, rukupno;
	int Pbr=0, Hbr=0, Cbr=0;
	char tarik, bojan, mirza, novi_red;
	
    printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	

	switch (tarik) {
		case 'P': Rukupno+=PR; Fukupno+=PF; Bukupno+=PB; Pbr++;
		break;
		case 'H': Rukupno+=HR; Fukupno+=HF; Bukupno+=HB; Hbr++;
		break;
		case 'C': Rukupno+=CR; Fukupno+=CF; Bukupno+=CB; Cbr++;
		break;
	}

	switch (bojan) {
		case 'P': Rukupno+=PR; Fukupno+=PF; Bukupno+=PB; Pbr++;
		break;
		case 'H': Rukupno+=HR; Fukupno+=HF; Bukupno+=HB; Hbr++;
		break;
		case 'C': Rukupno+=CR; Fukupno+=CF; Bukupno+=CB; Cbr++;
		break;
	}	

	switch (mirza) {
		case 'P': Rukupno+=PR; Fukupno+=PF; Bukupno+=PB; Pbr++;
		break;
		case 'H': Rukupno+=HR; Fukupno+=HF; Bukupno+=HB; Hbr++;
		break;
		case 'C': Rukupno+=CR; Fukupno+=CF; Bukupno+=CB; Cbr++;
		break;
	}
	
	if (Rukupno<Fukupno && Rukupno<Bukupno) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", Rukupno);
		return 0;
	}
	else if (Fukupno<Rukupno && Fukupno<Bukupno) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", Fukupno);
		{
			if (Pbr>=Hbr && Pbr>=Cbr)
			Rukupno-=Pbr*0.1*PR;
			else if (Hbr>=Pbr && Hbr>=Cbr)
			Rukupno-=Hbr*0.1*HR;
			else if (Cbr>=Pbr && Cbr>=Hbr)
			Rukupno-=Cbr*0.1*CR;
			if (Rukupno<Fukupno && Rukupno<Bukupno){
			printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", Rukupno);
		}
	}		
	}
	else if (Bukupno<Rukupno && Bukupno<Fukupno) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", Bukupno);
		{
			if (Pbr>=Hbr && Pbr>=Cbr)
			Rukupno-=Pbr*0.1*PR;
			else if (Hbr>=Pbr && Hbr>=Cbr)
			Rukupno-=Hbr*0.1*HR;
			else if (Cbr>=Pbr && Cbr>=Hbr)
			Rukupno-=Cbr*0.1*CR;
			if (Rukupno<Fukupno && Rukupno<Bukupno){
			printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", Rukupno);
		}
}
}
return 0;
}

