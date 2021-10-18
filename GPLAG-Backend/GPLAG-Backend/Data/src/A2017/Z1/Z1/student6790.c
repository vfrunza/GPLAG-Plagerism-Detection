#include <stdio.h>
#define PIZZAK 6.80
#define PIZZAT 8.00
#define PIZZAL 5.30
#define HAMBK 3.30
#define HAMBT 3.00
#define HAMBL 5.00
#define CEVAPK 5.00
#define CEVAPT 3.90
#define CEVAPL 6.00

int main() {
	char jT,jB,jM,novi_red;
	double racun,postotak_jela,racun_popust;
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&jT); scanf("%c",&novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&jB); scanf("%c",&novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&jM); scanf("%c",&novi_red);
	
	if(jT=='P' && jB=='P' && jM=='P') {
		racun=3*PIZZAL;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",racun);
	}
	else if(jT=='H' && jB=='H' && jM=='H') {
		racun=3*HAMBT;
		postotak_jela=3*HAMBK/10;
		racun_popust=3*HAMBK-postotak_jela;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",racun);
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",racun_popust);
	}
	else if(jT=='C' && jB=='C' && jM=='C') {
		racun=3*CEVAPT;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",racun);
	}
	else if((jT=='P' && jB=='P' && jM=='H')||(jT=='P' && jB=='H' && jM=='P')||(jT=='H' && jB=='P' && jM=='P')) {
		racun=2*PIZZAL+HAMBL;
		postotak_jela=2*PIZZAK/10;
		racun_popust=2*PIZZAK+HAMBK-postotak_jela;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",racun);
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",racun_popust);
	}
	else if((jT=='H' && jB=='P' && jM=='H')||(jT=='H' && jB=='H' && jM=='P')||(jT=='P' && jB=='H' && jM=='H')) {
		racun=2*HAMBK+PIZZAK;
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",racun);
	}
	else if((jT=='H' && jB=='H' && jM=='C')|(jT=='H' && jB=='C' && jM=='H')||(jT=='C' && jB=='H' && jM=='H')) {
		racun=2*HAMBT+CEVAPT;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",racun);
	}
	else if((jT=='H' && jB=='C' && jM=='C')||(jT=='C' && jB=='C' && jM=='H')||(jT=='C' && jB=='H' && jM=='C')) {
		racun=2*CEVAPT+HAMBT;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",racun);
	}
	else if((jT=='P' && jB=='C' && jM=='C')||(jT=='C' && jB=='C' && jM=='P')||(jT=='C' && jB=='P' && jM=='C')) {
		racun=2*CEVAPT+PIZZAT;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",racun);
	}
	else if((jT=='P' && jB=='P' && jM=='C')||(jT=='P' && jB=='C' && jM=='P')||(jT=='C' && jB=='P' && jM=='P')) {
		racun=2*PIZZAL+CEVAPL;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",racun);
	}
	else {
		racun=PIZZAT+HAMBT+CEVAPT;
		postotak_jela=PIZZAK/10;
		racun_popust=HAMBK+CEVAPK+PIZZAK-postotak_jela;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",racun);
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",racun_popust);
	}
	return 0;
}
