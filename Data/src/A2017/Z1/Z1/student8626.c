#include <stdio.h>
#define P1K 6.8
#define H1K 3.3
#define C1K 5.0
#define P2T 8.0
#define H2T 3.0
#define C2T 3.9
#define P3L 5.3
#define H3L 5.0
#define C3L 6.0
#define popust 0.1


int main() {
	double H1=0, P1=0, C1=0, H2=0, P2=0, C2=0, H3=0, P3=0, C3=0, racun1=0, racun2=0, racun3=0,racun=0;
	char Tarik, Bojan, Mirza, novi_red;
	novi_red=('\n');
	printf("Unesite jelo za Tarika: ");
	scanf ("%c", &Tarik);
	scanf ("%c", &novi_red);
	printf ("Unesite jelo za Bojana: ");
	scanf ("%c", &Bojan);
	scanf ("%c", &novi_red);
	printf ("Unesite jelo za Mirzu: ");
	scanf ("%c", &Mirza);
	scanf ("%c", &novi_red);
    
    if (Tarik=='P'){
    	P1=P1+P1K;
    	P2=P2+P2T;
    	P3=P3+P3L;
    }
    	if (Tarik=='H'){
    		H1=H1+H1K;
    		H2=H2+H2T;
    		H3=H3+H3L;
    	}
	if (Tarik=='C'){
		C1=C1+C1K;
		C2=C2+C2T;
		C3=C3+C3L;
	}
	if (Bojan=='P'){
    	P1=P1+P1K;
    	P2=P2+P2T;
    	P3=P3+P3L;
    }
    	if (Bojan=='H'){
    		H1=H1+H1K;
    		H2=H2+H2T;
    		H3=H3+H3L;
    	}
	if (Bojan=='C'){
		C1=C1+C1K;
		C2=C2+C2T;
		C3=C3+C3L;
	}
	if (Mirza=='P'){
    	P1=P1+P1K;
    	P2=P2+P2T;
    	P3=P3+P3L;
    }
    	if (Mirza=='H'){
    		H1=H1+H1K;
    		H2=H2+H2T;
    		H3=H3+H3L;
    	}
	if (Mirza=='C'){
		C1=C1+C1K;
		C2=C2+C2T;
		C3=C3+C3L;
	}
	racun1=P1+H1+C1;
	racun2=P2+H2+C2;
	racun3=P3+H3+C3;
	
	if(racun1<racun2 && racun1<racun3)
	{
		printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", racun1);
		return 0;
	}
	else if (racun2<racun1 && racun2<racun3)
	{
		printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", racun2);
	}
	else if (racun3<racun1 && racun3<racun2)
	{
		printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", racun3);
	}
	if (Tarik=='P' || Bojan=='P' || Mirza=='P'){
		racun=P1-P1*0.1+H1+C1;
	}
	   else if ((Mirza!='P' && Bojan!='P' && Mirza!='P') && (Tarik=='H' || Bojan=='H' || Mirza=='H'))
	   {
	   	racun=P1+H1-H1*0.1+C1;
	   }
	   else 
	   {
	   	racun=P1+H1+C1-C1*0.1;
	   }
	   if(racun<racun2 && racun<racun3){
		printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",racun);
	}

	return 0;
}
