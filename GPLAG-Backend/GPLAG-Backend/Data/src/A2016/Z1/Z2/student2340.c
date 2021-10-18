/*Date su dvije linearne jednačine:


	y1=a1x+b1
	y2=a2x+b2
	
Ove dvije jednačine opisuju dvije prave u koordinatnom prostoru. */

#include <stdio.h>
#include <math.h>
#define epsilon 0.00001

int main() {
	float x,y, a1,b1,a2,b2;

	/*Potrebno je napisati program koji određuje tačku u kojoj se te dvije prave sijeku (x za koje je y1=y2) ili, 
	ako su prave paralelne, ispisati poruku "Paralelne su", 
	a ako se prave poklapaju treba ispisati poruku "Poklapaju se". 
	Program najprije omogućuje unos četiri realna koeficijenta a1, b1, a2, b2, 
	a zatim ispisuje koordinate tačke sjecišta zaokružene na jednu decimalu.*/
	
	//Unosimo realne koeficijente a1,b1,a2,b2
	
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f", &a1, &b1, &a2, &b2);

	//Postavljamo uslove da li su prave paralelne ili se poklapaju

	if ((fabs(a1-a2)<epsilon) && (fabs(b1-b2)>epsilon)) {
		printf("Paralelne su");
		return 0;
	}
	if ((fabs(a1-a2)<epsilon) && (fabs(b1-b2)<epsilon)) {
		printf("Poklapaju se");
		return 0;
	}
	
	//Ukoliko nijedan od uslova nije ispunjen, racunamo tacku u kojoj se sijeku date prave

		x=(b2-b1)/(a1-a2);
		y=a1*x+b1;
		printf ("Prave se sijeku u tacci (%.1f,%.1f)", x,y);
		
		/*Primjer ulaza i izlaza:
			Unesite a1,b1,a2,b2: 3.1,5.2,2.1,1.0
			Prave se sijeku u tacci (-4.2,-7.8)
		*/
	
	
	return 0;
}
