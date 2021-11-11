#include <stdio.h>
#define cijena_pizzeRKKIK 6.80
#define cijena_pizzeFFT 8.0
#define cijena_pizzeBL 5.30
#define cijena_hamburgeraRKKIK 3.30
#define cijena_hamburgeraFFT 3.0
#define cijena_hamburgeraBL 5.0
#define cijena_cevapaRKKIK 5.0
#define cijena_cevapaFFT 3.90
#define cijena_cevapaBL 6.0

int main() {
	char Tarik; char Bojan; char Mirza; char novi_red; int P=1; int H=1; int C=1;
	float FFT; float BL; float RKKIK_bez_popusta; float RKKIK_s_popustom;
	
	printf ("Unesite jelo za Tarika: ");
	scanf ("%c", &Tarik);
	scanf ("%c", &novi_red);
	printf ("Unesite jelo za Bojana: ");
	scanf ("%c", &Bojan);
	scanf ("%c", &novi_red);
	printf ("Unesite jelo za Mirzu: ");
	scanf ("%c", &Mirza);
	scanf ("%c", &novi_red);
	
	
	if(Tarik==P && Bojan==P && Mirza==P) {
		RKKIK_bez_popusta=3*cijena_pizzeRKKIK;
		RKKIK_s_popustom = cijena_pizzeRKKIK-(cijena_pizzeRKKIK*0.1) + 2*cijena_pizzeRKKIK;
		FFT = 3*cijena_pizzeFFT;
		BL = 3*cijena_pizzeBL;
		if(BL<RKKIK_bez_popusta && BL<FFT) { 
			printf("Najjeftiniji je Bistro ""Lorelei"" ( %.2f KM)." , BL);
		if(RKKIK_s_popustom<BL) printf("S popustom bi Restoran bio jeftiniji (%.2f KM).", RKKIK_s_popustom);
		}
	else if (RKKIK_bez_popusta<BL && RKKIK_bez_popusta<FFT) printf("Najjeftiniji je Restoran ""Kod konja i konjusara"" (%.2f KM).", RKKIK_bez_popusta);
	else if(FFT<RKKIK_bez_popusta && FFT<BL) { 
		printf("Najjeftiniji je Fast-food ""Trovac"" (%.2f KM).", FFT);
	if(RKKIK_s_popustom<BL) printf("S popustom bi Restoran bio jeftiniji (%.2f KM).", RKKIK_s_popustom);
	}
	}
else if (Tarik== H && Bojan==H && Mirza==H) {
	RKKIK_bez_popusta=3*cijena_hamburgeraRKKIK;
	RKKIK_s_popustom=cijena_hamburgeraRKKIK-(cijena_hamburgeraRKKIK*0.1) + 2*cijena_hamburgeraRKKIK;
	FFT= 3*cijena_hamburgeraFFT;
	BL=3*cijena_hamburgeraBL;
	if(BL<RKKIK_bez_popusta && BL<FFT) { 
		printf("Najjeftiniji je Bistro ""Lorelei"" ( %.2f KM)." , BL);
		if(RKKIK_s_popustom<BL) printf("S popustom bi Restoran bio jeftiniji (%.2f KM).", RKKIK_s_popustom);
	}
	else if (RKKIK_bez_popusta<BL && RKKIK_bez_popusta<FFT) printf("Najjeftiniji je Restoran ""Kod konja i konjusara"" (%.2f KM).", RKKIK_bez_popusta);
	else if(FFT<RKKIK_bez_popusta && FFT<BL) { 
		printf("Najjeftiniji je Fast-food ""Trovac"" (%.2f KM).", FFT);
	if(RKKIK_s_popustom<BL) printf("S popustom bi Restoran bio jeftiniji (%.2f KM).", RKKIK_s_popustom);
	}
}
else if( Tarik==C && Bojan==C && Mirza==C) {
	RKKIK_bez_popusta=3*cijena_cevapaRKKIK;
	RKKIK_s_popustom=cijena_cevapaRKKIK - (cijena_cevapaRKKIK*0.1) + 2*cijena_cevapaRKKIK;
	FFT=3*cijena_cevapaFFT;
	BL=3*cijena_cevapaBL;
if(BL<RKKIK_bez_popusta && BL<FFT) { 
	printf("Najjeftiniji je Bistro ""Lorelei"" ( %.2f KM)." , BL);
		if(RKKIK_s_popustom<BL) printf("S popustom bi Restoran bio jeftiniji (%.2f KM).", RKKIK_s_popustom);
}
	else if (RKKIK_bez_popusta<BL && RKKIK_bez_popusta<FFT) printf("Najjeftiniji je Restoran ""Kod konja i konjusara"" (%.2f KM).", RKKIK_bez_popusta);
	else if(FFT<RKKIK_bez_popusta && FFT<BL) { 
		printf("Najjeftiniji je Fast-food ""Trovac"" (%.2f KM).", FFT);
	if(RKKIK_s_popustom<BL) printf("S popustom bi Restoran bio jeftiniji (%.2f KM).", RKKIK_s_popustom);
	}
}
else if((Tarik==P && Bojan==C && Mirza==H) || (Tarik==P && Bojan==H && Mirza==C) || (Tarik==H && Bojan==C && Mirza==P)
|| (Tarik==H && Bojan==P && Mirza==C) || (Tarik==C && Bojan==H && Mirza==P) || (Tarik==C && Bojan==P && Mirza==H)) {
	RKKIK_bez_popusta=cijena_cevapaRKKIK+cijena_hamburgeraRKKIK+cijena_pizzeRKKIK;
	RKKIK_s_popustom= cijena_pizzeRKKIK-(0.1*cijena_pizzeRKKIK) + cijena_hamburgeraRKKIK + cijena_cevapaRKKIK; 
	FFT=cijena_pizzeFFT+cijena_cevapaFFT+cijena_hamburgeraFFT;
	BL=cijena_cevapaBL+cijena_hamburgeraBL+cijena_pizzeBL;
		if(BL<RKKIK_bez_popusta && BL<FFT) {
			printf("Najjeftiniji je Bistro ""Lorelei"" ( %.2f KM)." , BL);
		if(RKKIK_s_popustom<BL) printf("S popustom bi Restoran bio jeftiniji (%.2f KM).", RKKIK_s_popustom);
		}
	else if (RKKIK_bez_popusta<BL && RKKIK_bez_popusta<FFT) printf("Najjeftiniji je Restoran ""Kod konja i konjusara"" (%.2f KM).", RKKIK_bez_popusta);
	else if(FFT<RKKIK_bez_popusta && FFT<BL) { 
		printf("Najjeftiniji je Fast-food ""Trovac"" (%.2f KM).", FFT);
	if(RKKIK_s_popustom<BL) printf("S popustom bi Restoran bio jeftiniji (%.2f KM).", RKKIK_s_popustom);
	}
}
else if((Tarik==P && Bojan==C && Mirza==C) || (Tarik==C && Bojan==P && Mirza==C) || (Tarik==C && Bojan==C && Mirza==P)) {
		RKKIK_bez_popusta=cijena_cevapaRKKIK+cijena_hamburgeraRKKIK+cijena_pizzeRKKIK;
		RKKIK_s_popustom= cijena_pizzeRKKIK-(0.1*cijena_pizzeRKKIK) + 2*cijena_cevapaRKKIK; 
    	FFT=cijena_pizzeFFT + 2*cijena_cevapaFFT;
    	BL=cijena_pizzeBL + 2*cijena_cevapaBL;
    	if(BL<RKKIK_bez_popusta && BL<FFT) {
    		printf("Najjeftiniji je Bistro ""Lorelei"" ( %.2f KM)." , BL);
		if(RKKIK_s_popustom<BL) printf("S popustom bi Restoran bio jeftiniji (%.2f KM).", RKKIK_s_popustom);
    	}
	else if (RKKIK_bez_popusta<BL && RKKIK_bez_popusta<FFT) printf("Najjeftiniji je Restoran ""Kod konja i konjusara"" (%.2f KM).", RKKIK_bez_popusta);
	else if(FFT<RKKIK_bez_popusta && FFT<BL) { printf("Najjeftiniji je Fast-food ""Trovac"" (%.2f KM).", FFT);
	if(RKKIK_s_popustom<BL) printf("S popustom bi Restoran bio jeftiniji (%.2f KM).", RKKIK_s_popustom);
	}
}
else if((Tarik==H && Bojan==P && Mirza==P) || (Tarik==P && Bojan==H && Mirza==P) || (Tarik==P && Bojan==P && Mirza==H)) {
		RKKIK_bez_popusta=cijena_hamburgeraRKKIK + 2*cijena_pizzeRKKIK;
		RKKIK_s_popustom= cijena_pizzeRKKIK-(0.1*cijena_pizzeRKKIK) + 2*cijena_hamburgeraRKKIK; 
    	FFT=2*cijena_pizzeFFT + cijena_hamburgeraFFT;
    	BL=2*cijena_pizzeBL + cijena_hamburgeraBL;
    	if(BL<RKKIK_bez_popusta && BL<FFT) { 
    		printf("Najjeftiniji je Bistro ""Lorelei"" ( %.2f KM)." , BL);
		if(RKKIK_s_popustom<BL) printf("S popustom bi Restoran bio jeftiniji (%.2f KM).", RKKIK_s_popustom);
    	}
	else if (RKKIK_bez_popusta<BL && RKKIK_bez_popusta<FFT) printf("Najjeftiniji je Restoran ""Kod konja i konjusara"" (%.2f KM).", RKKIK_bez_popusta);
	else if(FFT<RKKIK_bez_popusta && FFT<BL) { printf("Najjeftiniji je Fast-food ""Trovac"" (%.2f KM).", FFT);
	if(RKKIK_s_popustom<BL) printf("S popustom bi Restoran bio jeftiniji (%.2f KM).", RKKIK_s_popustom);
	}
}
else if((Tarik==C && Bojan==P && Mirza==P) || (Tarik==P && Bojan==C && Mirza==P) || (Tarik==P && Bojan==P && Mirza==C)) {
		RKKIK_bez_popusta=cijena_cevapaRKKIK + 2*cijena_pizzeRKKIK;
		RKKIK_s_popustom= cijena_pizzeRKKIK-(0.1*cijena_pizzeRKKIK) + 2*cijena_cevapaRKKIK; 
    	FFT=2*cijena_pizzeFFT + cijena_cevapaFFT;
    	BL=2*cijena_pizzeBL + cijena_cevapaBL;
    	if(BL<RKKIK_bez_popusta && BL<FFT) {
    		printf("Najjeftiniji je Bistro ""Lorelei"" ( %.2f KM)." , BL);
		if(RKKIK_s_popustom<BL) printf("S popustom bi Restoran bio jeftiniji (%.2f KM).", RKKIK_s_popustom);
    	}
	else if (RKKIK_bez_popusta<BL && RKKIK_bez_popusta<FFT) printf("Najjeftiniji je Restoran ""Kod konja i konjusara"" (%.2f KM).", RKKIK_bez_popusta);
	else if(FFT<RKKIK_bez_popusta && FFT<BL) {
		printf("Najjeftiniji je Fast-food ""Trovac"" (%.2f KM).", FFT);
	if(RKKIK_s_popustom<BL) printf("S popustom bi Restoran bio jeftiniji (%.2f KM).", RKKIK_s_popustom);
	}
}
else if((Tarik==P && Bojan==H && Mirza==H) || (Tarik==H && Bojan==H && Mirza==P) || (Tarik==H && Bojan==P && Mirza==H)) {
		RKKIK_bez_popusta=cijena_pizzeRKKIK + 2*cijena_hamburgeraRKKIK;
		RKKIK_s_popustom= cijena_pizzeRKKIK-(0.1*cijena_pizzeRKKIK) + 2*cijena_hamburgeraRKKIK; 
    	FFT=cijena_pizzeFFT + 2*cijena_hamburgeraFFT;
    	BL=cijena_pizzeBL + 2*cijena_hamburgeraBL;
    	if(BL<RKKIK_bez_popusta && BL<FFT) { 
    		printf("Najjeftiniji je Bistro ""Lorelei"" ( %.2f KM)." , BL);
		if(RKKIK_s_popustom<BL) printf("S popustom bi Restoran bio jeftiniji (%.2f KM).", RKKIK_s_popustom);
    	}
	else if (RKKIK_bez_popusta<BL && RKKIK_bez_popusta<FFT) printf("Najjeftiniji je Restoran ""Kod konja i konjusara"" (%.2f KM).", RKKIK_bez_popusta);
	else if(FFT<RKKIK_bez_popusta && FFT<BL) { 
		printf("Najjeftiniji je Fast-food ""Trovac"" (%.2f KM).", FFT);
	if(RKKIK_s_popustom<BL) printf("S popustom bi Restoran bio jeftiniji (%.2f KM).", RKKIK_s_popustom);
	}
}
else if((Tarik==H && Bojan==C && Mirza==C) || (Tarik==C && Bojan==H && Mirza==C) || (Tarik==C && Bojan==C && Mirza==H)) {
		RKKIK_bez_popusta=2*cijena_cevapaRKKIK + cijena_hamburgeraRKKIK;
		RKKIK_s_popustom= cijena_cevapaRKKIK-(0.1*cijena_cevapaRKKIK) + cijena_cevapaRKKIK+ cijena_hamburgeraRKKIK; 
    	FFT=2*cijena_cevapaFFT + cijena_hamburgeraFFT;
    	BL=2*cijena_cevapaBL + cijena_hamburgeraBL;
    	if(BL<RKKIK_bez_popusta && BL<FFT) { 
    		printf("Najjeftiniji je Bistro ""Lorelei"" ( %.2f KM)." , BL);
		if(RKKIK_s_popustom<BL) printf("S popustom bi Restoran bio jeftiniji (%.2f KM).", RKKIK_s_popustom);
    	}
	else if (RKKIK_bez_popusta<BL && RKKIK_bez_popusta<FFT) printf("Najjeftiniji je Restoran ""Kod konja i konjusara"" (%.2f KM).", RKKIK_bez_popusta);
	else if(FFT<RKKIK_bez_popusta && FFT<BL) { 
		printf("Najjeftiniji je Fast-food ""Trovac"" (%.2f KM).", FFT);
	if(RKKIK_s_popustom<BL) printf("S popustom bi Restoran bio jeftiniji (%.2f KM).", RKKIK_s_popustom);
	}
}
else if((Tarik==C && Bojan==H && Mirza==H) || (Tarik==H && Bojan==C && Mirza==H) || (Tarik==H && Bojan==H && Mirza==C)) {
		RKKIK_bez_popusta=cijena_cevapaRKKIK + 2*cijena_hamburgeraRKKIK;
		RKKIK_s_popustom= cijena_cevapaRKKIK-(0.1*cijena_cevapaRKKIK) + 2*cijena_hamburgeraRKKIK; 
    	FFT=cijena_cevapaFFT + 2*cijena_hamburgeraFFT;
    	BL=cijena_cevapaBL + 2*cijena_hamburgeraBL;
    	if(BL<RKKIK_bez_popusta && BL<FFT) { 
    		printf("Najjeftiniji je Bistro ""Lorelei"" ( %.2f KM)." , BL);
		if(RKKIK_s_popustom<BL) printf("S popustom bi Restoran bio jeftiniji (%.2f KM).", RKKIK_s_popustom);
    	}
	else if (RKKIK_bez_popusta<BL && RKKIK_bez_popusta<FFT) printf("Najjeftiniji je Restoran ""Kod konja i konjusara"" (%.2f KM).", RKKIK_bez_popusta);
	else if(FFT<RKKIK_bez_popusta && FFT<BL) { 
		printf("Najjeftiniji je Fast-food ""Trovac"" (%.2f KM).", FFT);
	if(RKKIK_s_popustom<BL) printf("S popustom bi Restoran bio jeftiniji (%.2f KM).", RKKIK_s_popustom);
	}
}
	return 0;
}
