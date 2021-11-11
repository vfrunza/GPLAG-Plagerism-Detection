#include <stdio.h>

int main() {
	char unos;
	int crna=0;
	int plava=0;
	int bijela=0;
	int siva=0;
	int crvena=0;
	
	printf("Unesite vozila:");
	scanf("%c",&unos);
	
	while (unos !='k'&&unos!='K'){
	if(unos=='c' || unos=='C'){
	crna ++;
	}
		else if (unos=='b' || unos=='B'){
	bijela ++;
	}
		else if (unos=='s' || unos=='S'){
	siva ++;
	}
		else if (unos=='v' || unos=='V'){
	crvena ++;
	}
	else if (unos=='p' || unos=='P'){
	plava ++;
	}
	else if (unos=='v' || unos=='V'){
	crvena ++;
	}
	scanf("%c",&unos);
	}
 	int ukupno ;
 	float procenat ;
 	ukupno=crna + plava + bijela + siva + crvena;
 	
 	printf(" Ukupno evidentirano %d vozila. ",ukupno);
 	
 	
 	if (crna>=plava&&crna>=bijela&&crna>=siva&&crna>=crvena){
 		procenat=(crna*100)/(float)ukupno;
 		printf("\nNajpopularnija boja je crna (%.2f%%).",procenat);
 	}
 		else if(bijela>=crna&&bijela>=plava&&bijela>=siva&&bijela>=crvena){
 		procenat=(bijela*100)/(float)ukupno;
 		printf("\nNajpopularnija boja je bijela (%.2f%%).",procenat);
 	}
 	else if (siva>=crna&&siva>=plava&&siva>=bijela&&siva>=crvena){
 		procenat=(siva*100)/(float)ukupno;
 		printf("\nNajpopularnija boja je siva (%.2f%%).",procenat);
 	}
 			else if (crvena>=crna&&crvena>=plava&&crvena>=bijela&&crvena>=siva){
 		procenat=(crvena*100)/(float)ukupno;
 		printf("\nNajpopularnija boja je crvena (%.2f%%).",procenat);
 	}
 		else if (plava>=crna&&plava>=bijela&&plava>=siva&&plava>=crvena){
 		procenat=(plava*100)/(float)ukupno;
 		printf("\nNajpopularnija boja je plava (%.2f%%).",procenat);
 	}
 	else {
 		printf("Neispravan unos");
 	}
	return 0;
	
}
