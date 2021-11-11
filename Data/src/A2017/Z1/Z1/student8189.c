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
char Jt,Jb,Jm, novi_red;
double racun,postotak,popust;

printf("Unesite jelo za Tarika: ");
scanf("%c",&Jt); scanf("%c",&novi_red);
printf("Unesite jelo za Bojana: ");
scanf("%c",&Jb); scanf("%c", &novi_red);
printf("Unesite jelo za Mirzu: ");
scanf("%c",&Jm); scanf("%c",&novi_red);

if(Jt=='P' && Jb=='P' && Jm=='P'){
	racun=3*PIZZAL;
	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",racun);
}
else if(Jt=='H' && Jb=='H' && Jm=='H'){
	racun=3*HAMBT;
	postotak=3*HAMBK/10;
	popust=3*HAMBK-postotak;
	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",racun);
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",popust);
}
else if(Jt=='C' && Jb=='C' && Jm=='C'){
	racun=3*CEVAPT;
	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", racun);
	
}
else if ((Jt=='P' && Jb=='P' && Jm=='H') || (Jt=='P' && Jb=='H' && Jm=='P') || (Jt=='H' && Jb=='P' && Jm=='P')){
	racun=2*PIZZAL+HAMBL;
	postotak=2*PIZZAK/10;
	popust=2*PIZZAK+HAMBK-postotak;
	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",racun);
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",popust);
	
}
else if((Jt=='H' && Jb=='P' && Jm=='H') || (Jt=='H' && Jb=='H' && Jm=='P') || (Jt=='P' && Jb=='H' && Jm=='H')){
	racun=2*HAMBK+PIZZAK;
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",racun);
	
	}
	else if((Jt=='H' && Jb=='H' && Jm=='C') || (Jt=='H' && Jb=='C' && Jm=='H') || (Jt=='C' && Jb=='H' && Jm=='H')){
		racun=2*HAMBT+CEVAPT;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",racun);
		
	}
	else if((Jt=='H' && Jb=='C' && Jm=='C') || (Jt=='C' && Jb=='C' && Jm=='H') || (Jt=='C' && Jb=='H' && Jm=='C')){
		racun=2*CEVAPT+HAMBT;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",racun);
		
	}
	else if((Jt=='P' && Jb=='C' && Jm=='C') || (Jt=='C' && Jb=='C' && Jm=='P') || (Jt=='C' && Jb=='P' && Jm=='C')){
		racun=2*CEVAPT+PIZZAT;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", racun);
		
	}
	else if((Jt=='P' && Jb=='P' && Jm=='C') || (Jt=='P' && Jb=='C' && Jm=='P') ||(Jt=='C' && Jb=='P' && Jm=='P' )){
		racun=2*PIZZAL+CEVAPL;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",racun);
		
	}
	else{
		racun=PIZZAT+HAMBT+CEVAPT;
		postotak=PIZZAK/10;
		popust=HAMBK+CEVAPK+PIZZAK-postotak;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",racun);
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",popust);
	}
	
	


	
	return 0;
}
