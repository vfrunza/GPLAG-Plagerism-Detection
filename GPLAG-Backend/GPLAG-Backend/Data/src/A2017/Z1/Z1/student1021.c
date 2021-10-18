#include <stdio.h>

int main() {
	int a, b, c;
	const double pizza1=6.80, pizza2=8.00, pizza3=5.30, hamburger1=3.30, hamburger2=3.00, hamburger3=5.00, cevapi1=5.00, cevapi2=3.90, cevapi3=6.00;
	double;
	char tarik, bojan, mirza, novi_red, navodnik='"';
	printf("Unesite jelo za Tarika: ");
	scanf("%c%c", &tarik,&novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c%c", &bojan,&novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c%c", &mirza,&novi_red);
	if(mirza == 'P' && tarik =='P' && bojan=='P') {
		double helpKKK, helpT,helpBL; helpKKK=3*pizza1; helpT=3*pizza2; helpBL=3*pizza3;
		if (helpKKK < helpT && helpKKK < helpBL) printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2lf KM).", navodnik, navodnik, helpKKK);
		else if (helpT<helpKKK && helpT<helpBL) {
			printf("Najjeftiniji je Fast-food %cTrovac%c (%.2lf KM).\n", navodnik, navodnik, helpT);
			double popust; popust=pizza1-pizza1*0.1; popust=3*popust; 
			if(popust< helpT) printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust);		}
		else if (helpBL<helpKKK && helpBL<helpT) {
			printf("Najjeftiniji je Bistro %cLorelei%c (%.2lf KM).\n", navodnik, navodnik, helpBL);
			double popust; popust=pizza1-pizza1*0.1; popust=3*popust; 
			if(popust< helpBL) printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust);		}
	}
	else if(mirza == 'H' && tarik =='H' && bojan=='H') {
		double helpKKK, helpT, helpBL; helpKKK=3*hamburger1; helpT=3*hamburger2; helpBL=3*hamburger3;
		if (helpKKK < helpT && helpKKK < helpBL) printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2lf KM).", navodnik, navodnik, helpKKK);
		else if (helpT<helpKKK && helpT<helpBL) {
			printf("Najjeftiniji je Fast-food %cTrovac%c (%.2lf KM).\n", navodnik, navodnik, helpT);
			double popust; popust=hamburger1-hamburger1*0.1; popust=3*popust; 
			if(popust< helpT) printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust);		}
		else if (helpBL<helpKKK && helpBL<helpT) {
			printf("Najjeftiniji je Bistro %cLorelei%c (%.2lf KM).\n", navodnik, navodnik, helpBL);
			double popust; popust=hamburger1-hamburger1*0.1; popust=3*popust; 
			if(popust< helpBL) printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust);		}
	}
	else if(mirza == 'C' && tarik =='C' && bojan=='C') {
		double helpKKK, helpT, helpBL; helpKKK=3*cevapi1; helpT=3*cevapi2; helpBL=3*cevapi3;
		if (helpKKK < helpT && helpKKK < helpBL) printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2lf KM).", navodnik, navodnik, helpKKK);
		else if (helpT<helpKKK && helpT<helpBL) {
			printf("Najjeftiniji je Fast-food %cTrovac%c (%.2lf KM).\n", navodnik, navodnik, helpT);
			double popust; popust=cevapi1-cevapi1*0.1; popust=3*popust; 
			if(popust< helpT) printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust);		}
		else if (helpBL<helpKKK && helpBL<helpT) {
			printf("Najjeftiniji je Bistro %cLorelei%c (%.2lf KM).\n", navodnik, navodnik, helpBL);
			double popust; popust=cevapi1-cevapi1*0.1; popust=3*popust; 
			if(popust< helpBL) printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust);		}
	}
	else if((mirza == 'P' && tarik =='P' && bojan=='H') || (mirza == 'P' && tarik =='H' && bojan=='P') || mirza == 'H' && tarik =='P' && bojan=='P') {
		double helpKKK,helpT,helpBL; helpKKK=2*pizza1+hamburger1; helpT=2*pizza2+hamburger2; helpBL=2*pizza3+hamburger3;
		if (helpKKK < helpT && helpKKK < helpBL) printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2lf KM).", navodnik, navodnik, helpKKK);
		else if (helpT<helpKKK && helpT<helpBL) {
			printf("Najjeftiniji je Fast-food %cTrovac%c (%.2lf KM).", navodnik, navodnik, helpT);
			double popust; popust=pizza1-pizza1*0.1; popust=2*popust+hamburger1; 
			if(popust< helpT) printf("\nSa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust);		}
		else if (helpBL<helpKKK && helpBL<helpT) {
			printf("Najjeftiniji je Bistro %cLorelei%c (%.2lf KM).", navodnik, navodnik, helpBL);
			double popust; popust=pizza1-pizza1*0.1; popust=2*popust+hamburger1; 
			if(popust< helpBL) printf("\nSa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust);		}
	}
		else if((mirza == 'P' && tarik =='H' && bojan=='H') || (mirza == 'H' && tarik =='P' && bojan=='H') || mirza == 'H' && tarik =='H' && bojan=='P') {
		double helpKKK,helpT,helpBL; helpKKK=pizza1+2*hamburger1; helpT=pizza2+2*hamburger2; helpBL=pizza3+2*hamburger3;
		if (helpKKK < helpT && helpKKK < helpBL) printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2lf KM).", navodnik, navodnik, helpKKK);
		else if (helpT<helpKKK && helpT<helpBL) {
			printf("Najjeftiniji je Fast-food %cTrovac%c (%.2lf KM).", navodnik, navodnik, helpT);
			double popust; popust=pizza1-pizza1*0.1; popust=popust+2*hamburger1; 
			if(popust< helpT) printf("\nSa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust);		}
		else if (helpBL<helpKKK && helpBL<helpT) {
			printf("Najjeftiniji je Bistro %cLorelei%c (%.2lf KM).",navodnik,navodnik,helpBL);
			double popust; popust=pizza1-pizza1*0.1; popust=2*popust+hamburger1; 
			if(popust< helpBL) printf("\nSa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust);		}
	}
		else if((mirza == 'P' && tarik =='C' && bojan=='C') || (mirza == 'C' && tarik =='C' && bojan=='P') || mirza == 'C' && tarik =='P' && bojan=='C') {
		double helpKKK, helpT, helpBL; helpKKK=pizza1+2*cevapi1; helpT=pizza2+2*cevapi2; helpBL=pizza3+2*cevapi3;
		if (helpKKK < helpT && helpKKK < helpBL) printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2lf KM).", navodnik, navodnik, helpKKK);
		else if (helpT<helpKKK && helpT<helpBL) {
			printf("Najjeftiniji je Fast-food %cTrovac%c (%.2lf KM).",navodnik, navodnik, helpT);
			double popust; popust=pizza1-pizza1*0.1; popust=popust+2*cevapi1; 
			if(popust< helpT) printf("\nSa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust);		}
		else if (helpBL<helpKKK && helpBL<helpT) {
			printf("Najjeftiniji je Bistro %cLorelei%c (%.2lf KM).", navodnik, navodnik, helpBL);
			double popust; popust=pizza1-pizza1*0.1; popust=popust+2*cevapi1; 
			if(popust< helpBL) printf("\nSa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust);		}
	}
		else if((mirza == 'P' && tarik =='P' && bojan=='C') || (mirza == 'P' && tarik =='C' && bojan=='P') || mirza == 'C' && tarik =='P' && bojan=='P') {
		double helpKKK, helpT, helpBL; helpKKK=2*pizza1+cevapi1; helpT=2*pizza2+cevapi2; helpBL=2*pizza3+cevapi3;
		if (helpKKK < helpT && helpKKK < helpBL) printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2lf KM).", navodnik, navodnik, helpKKK);
		else if (helpT<helpKKK && helpT<helpBL) {
			printf("Najjeftiniji je Fast-food %cTrovac%c (%.2lf KM).", navodnik, navodnik, helpT);
			double popust; popust=pizza1-pizza1*0.1; popust=2*popust+cevapi1; 
			if(popust< helpT) printf("\nSa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust);		}
		else if (helpBL<helpKKK && helpBL<helpT) {
			printf("Najjeftiniji je Bistro %cLorelei%c (%.2lf KM).", navodnik, navodnik, helpBL);
			double popust; popust=pizza1-pizza1*0.1; popust=2*popust+cevapi1; 
			if(popust< helpBL) printf("\nSa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust);		}
	}
		else if((mirza == 'C' && tarik =='C' && bojan=='H') || (mirza == 'C' && tarik =='H' && bojan=='C') || mirza == 'H' && tarik =='C' && bojan=='C') {
		double helpKKK, helpT, helpBL; helpKKK=pizza1+2*cevapi1; helpT=hamburger2+2*cevapi2; helpBL=hamburger3+2*cevapi3;
		if (helpKKK < helpT && helpKKK < helpBL) printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2lf KM).", navodnik, navodnik, helpKKK);
		else if (helpT<helpKKK && helpT<helpBL) {
			printf("Najjeftiniji je Fast-food %cTrovac%c (%.2lf KM).", navodnik, navodnik, helpT);
			double popust; popust=hamburger1-hamburger1*0.1; popust=popust+2*cevapi1; 
			if(popust< helpT) printf("\nSa popustom bi Restoran bio jeftiniji (%.2lf KM).",popust);		}
		else if (helpBL<helpKKK && helpBL<helpT) {
			printf("Najjeftiniji je Bistro %cLorelei%c (%.2lf KM).", navodnik, navodnik, helpBL);
			double popust; popust=hamburger1-hamburger1*0.1; popust=popust+2*cevapi1; 
			if(popust< helpBL) printf("\nSa popustom bi Restoran bio jeftiniji (%.2lf KM).",popust);		}
	}
		else if((mirza == 'H' && tarik =='C' && bojan=='H') || (mirza == 'H' && tarik =='H' && bojan=='C') || mirza == 'C' && tarik =='H' && bojan=='H') {
		double helpKKK, helpT, helpBL; helpKKK=2*pizza1+cevapi1; helpT=2*hamburger2+cevapi2; helpBL=2*hamburger3+cevapi3;
		if (helpKKK < helpT && helpKKK < helpBL) printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2lf KM).", navodnik, navodnik, helpKKK);
		else if (helpT<helpKKK && helpT<helpBL) {
			printf("Najjeftiniji je Fast-food %cTrovac%c (%.2lf KM).", navodnik, navodnik, helpT);
			double popust; popust=hamburger1-hamburger1*0.1; popust=2*popust+cevapi1; 
			if(popust< helpT) printf("\nSa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust);		}
		else if (helpBL<helpKKK && helpBL<helpT) {
			printf("Najjeftiniji je Bistro %cLorelei%c (%.2lf KM).", navodnik, navodnik, helpBL);
			double popust; popust=hamburger1-hamburger1*0.1; popust=2*popust+cevapi1; 
			if(popust< helpBL) printf("\nSa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust);		}
	}
			else if((mirza == 'P' && tarik =='C' && bojan=='H') || (mirza == 'C' && tarik =='H' && bojan=='P') || mirza == 'C' && tarik =='P' && bojan=='H' || mirza == 'H' && tarik =='P' && bojan=='C' || mirza == 'H' && tarik =='C' && bojan=='P' || mirza == 'P' && tarik =='H' && bojan=='C') {
		double helpKKK, helpT, helpBL; helpKKK=pizza1+cevapi1+hamburger1; helpT=pizza2+hamburger2+cevapi2; helpBL=pizza3+hamburger3+cevapi3;
		if (helpKKK < helpT && helpKKK < helpBL) printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2lf KM).", navodnik, navodnik, helpKKK);
		else if (helpT<helpKKK && helpT<helpBL) {
			printf("Najjeftiniji je Fast-food %cTrovac%c (%.2lf KM).", navodnik, navodnik, helpT);
			double popust; popust=pizza1-pizza1*0.1; popust=popust+hamburger1+cevapi1; 
			if(popust< helpT) printf("\nSa popustom bi Restoran bio jeftiniji (%.2lf KM).",popust);		}
		else if (helpBL<helpKKK && helpBL<helpT) {
			printf("Najjeftiniji je Bistro %cLorelei%c (%.2lf KM).", navodnik, navodnik, helpBL);
			double popust; popust=pizza1-pizza1*0.1; popust=popust+hamburger1+cevapi1; 
			if(popust< helpBL) printf("\nSa popustom bi Restoran bio jeftiniji (%.2lf KM).",popust);		}
	}
	
	

	return 0;
}
