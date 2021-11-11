#include <stdio.h>
/*  Date su dvije linearne jednačine:

	y1=a1x+b1
	y2=a2x+b2

Ove dvije jednačine opisuju dvije prave u koordinatnom prostoru.
Potrebno je napisati program koji određuje tačku u kojoj se te dvije prave sijeku (x za koje je y1=y2) ili, ako su prave paralelne, ispisati poruku "Paralelne su". 
Program najprije omogućuje unos četiri realna koeficijenta a1, b1, a2, b2, a zatim ispisuje koordinate tačke sjecišta zaokružene na jednu decimalu.

Primjer ulaza i izlaza:
	Unesite a1,b1,a2,b2: 3.1,5.2,2.1,1.0
	Prave se sijeku u tacci (-4.2,-7.8) */
	
int main() {
	double a1,a2,b1,b2;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf,%lf,%lf,%lf", &a1, &b1, &a2, &b2);
	 
	float x, y;
	//	y1=a1*x + b1;
	//  y2=a2*x + b2;
	// a1x - a2x = b2- b1;
	// x(a1-a2) = b2-b1
	// x= b2-b1 / a1-a2
	
	x= (b2-b1)/(a1-a2);
	y = a1*x + b1;
	if(a1==a2 && b1!=b2) printf("Paralelne su");
	else if(a1==a2 && b1==b2) printf("Poklapaju se");
	else printf("Prave se sijeku u tacci (%.1f,%.1f)", x, y);
	return 0;
}
