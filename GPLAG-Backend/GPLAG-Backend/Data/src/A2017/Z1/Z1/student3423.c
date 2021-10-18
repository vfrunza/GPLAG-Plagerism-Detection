#include <stdio.h>

int main() {
	double p1=6.8, p2=8.00, p3=5.30, h1=3.30, h2=3.0, h3=5.00,c1=5.0, c2=3.90, c3=6.00;
	char tarik,bojan,mirza,novired;
	double cijena1,cijena2,cijena3;
	double cijena1popust;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novired);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novired);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	
	if (tarik=='H' && mirza=='H' && bojan =='H'){
		cijena1=3*h1;
		cijena2=3*h2;
		cijena3=3*h3;
		
		if (cijena1<cijena2 && cijena2<cijena3) printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijena1);
		else if(cijena2<cijena1 && cijena1<cijena3) printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", cijena2);
		else if (cijena3<cijena1 && cijena1<cijena2) printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", cijena3);
		
		if ((cijena2<cijena1 && cijena1<cijena3) || (cijena3<cijena1 && cijena1<cijena2)){
			cijena1popust=h1*0.9*3;
			if (cijena1popust<cijena2 || cijena1popust<cijena3){
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena1popust);
			} 
		}

	}
	else if (tarik=='C' && mirza=='C' && bojan=='C'){
		cijena1=3*c1; // restoran kod konja i konjusara
		cijena2=3*c2; //trovac
		cijena3=3*c3; //bistro lorelei
	
		if (cijena1<cijena2 && cijena2<cijena3) printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijena1);
		else if(cijena2<cijena1 && cijena1<cijena3) printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", cijena2);
		else if (cijena3<cijena1 && cijena1<cijena2) printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", cijena3);
		
	
		
	}
	else if (tarik=='P' && bojan=='P' && mirza=='P'){
		cijena1=3*p1; // restoran kod konja i konjusara
		cijena2=3*p2; // trovac
		cijena3=3*p3; // bistro lorelei
		
		if (cijena1<cijena2 && cijena2<cijena3) printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijena1);
		else if(cijena2<cijena1 && cijena1<cijena3) printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", cijena2);
		else if (cijena3<cijena1 && cijena1<cijena2) printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", cijena3);
		
	
	}
	else if ((tarik=='H' && bojan=='H' && mirza=='P') || (tarik=='H' && bojan=='P' && mirza=='H') || (tarik=='P'&& bojan=='H' && mirza=='H')){
		cijena1=2*h1+p1;
		cijena2=2*h2+p2;
		cijena3=2*h3+p3;
		
		if (cijena1<cijena2 && cijena2<cijena3) printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijena1);
		else if(cijena2<cijena1 && cijena1<cijena3) printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", cijena2);
		else if (cijena3<cijena1 && cijena1<cijena2) printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", cijena3);
		
			if ((cijena2<cijena1 && cijena1<cijena3) || (cijena3<cijena1 && cijena1<cijena2)){
			cijena1popust=p1*0.9+2*h1;
			if (cijena1popust<cijena2 || cijena1popust<cijena3){
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena1popust);
			}
		}
	
	}
	else if((tarik=='H' && bojan=='H' && mirza=='C') || (tarik=='H' && bojan=='C' && mirza=='H') || (tarik=='C' && bojan=='H' && mirza=='H')){
		cijena1=2*h1+c1;
		cijena2=2*h2+c2;
		cijena3=2*h3+c3;
		
		if (cijena1<cijena2 && cijena2<cijena3) printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijena1);
		else if(cijena2<cijena1 && cijena1<cijena3) printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", cijena2);
		else if (cijena3<cijena1 && cijena1<cijena2) printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", cijena3);
		
		
	}
	else if((tarik=='P' && bojan=='P' && mirza=='C') || (tarik=='P' && bojan=='C' && mirza=='P') || (tarik=='C' && bojan=='P' && mirza=='P')){
		cijena1=2*p1+c1;
		cijena2=2*p2+c2;
		cijena3=2*p3+c3;
		
		if (cijena1<cijena2 && cijena2<cijena3) printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijena1);
		else if(cijena2<cijena1 && cijena1<cijena3) printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", cijena2);
		else if (cijena3<cijena1 && cijena1<cijena2) printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", cijena3);
		
		
	}
	else if((tarik=='P' && bojan=='P' && mirza=='H') || (tarik=='H' && bojan=='P' && mirza=='P') || (tarik=='P' && bojan=='H' && mirza=='P')){
		cijena1=2*p1+h1;
		cijena2=2*p2+h2;
		cijena3=2*p3+h3;
		
		if (cijena1<cijena2 && cijena2<cijena3) printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijena1);
		else if(cijena2<cijena1 && cijena1<cijena3) printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", cijena2);
		else if (cijena3<cijena1 && cijena1<cijena2) printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", cijena3);
		
			if ((cijena2<cijena1 && cijena1<cijena3) || (cijena3<cijena1 && cijena1<cijena2)){
			cijena1popust=0.9*p1*2+h1;
			if (cijena1popust<cijena2 || cijena1popust<cijena3){
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena1popust);
			}
		}
		
	}
	else if((tarik=='C' && bojan=='H' && mirza=='C') || (tarik=='H' && bojan=='C' && mirza=='C') || (tarik=='C' && bojan=='C' && mirza=='H')){
		cijena1=2*c1+h1;
		cijena2=2*c2+h2;
		cijena3=2*c3+h3;
		
		if (cijena1<cijena2 && cijena2<cijena3) printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijena1);
		else if(cijena2<cijena1 && cijena1<cijena3) printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", cijena2);
		else if (cijena3<cijena1 && cijena1<cijena2) printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", cijena3);
		
		
	}
		else if((tarik=='C' && bojan=='P' && mirza=='C') || (tarik=='P' && bojan=='C' && mirza=='C') || (tarik=='C' && bojan=='C' && mirza=='P')){
		cijena1=2*c1+p1;
		cijena2=2*c2+p2;
		cijena3=2*c3+p3;
		
		if (cijena1<cijena2 && cijena2<cijena3) printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijena1);
		else if(cijena2<cijena1 && cijena1<cijena3) printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", cijena2);
		else if (cijena3<cijena1 && cijena1<cijena2) printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", cijena3);
		
		
	}
	else if((tarik=='H' && bojan=='P' && mirza=='C') || (tarik=='H' && bojan=='C' && mirza=='P')||(tarik=='P' && bojan=='H' && mirza=='C')||(tarik=='P' && bojan=='C' && mirza=='H')||(tarik=='C' && bojan=='P' && mirza=='H')||(tarik=='C' && bojan=='H' && mirza=='P')){
		cijena1=c1+p1+h1;
		cijena2=c2+p2+h2;
		cijena3=c3+p3+h3;
		
		if (cijena1<cijena2 && cijena2<cijena3) printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijena1);
		else if(cijena2<cijena1 && cijena1<cijena3) printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", cijena2);
		else if (cijena3<cijena1 && cijena1<cijena2) printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", cijena3);
		
			if ((cijena2<cijena1 && cijena1<cijena3) || (cijena3<cijena1 && cijena1<cijena2)){
			cijena1popust=p1*0.9+c1+h1;
			if (cijena1popust<cijena2 || cijena1popust<cijena3){
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena1popust);
			}
		}
	}
	
	return 0;
}


















