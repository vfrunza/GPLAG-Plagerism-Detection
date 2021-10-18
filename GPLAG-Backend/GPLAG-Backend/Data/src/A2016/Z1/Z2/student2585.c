#include <stdio.h>

int main(){
	float a1,a2,b1,b2,x,y;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f", &a1, &b1, &a2, &b2);
	
	if(a1==a2 && b1==b2) {printf("Poklapaju se");} /* Prave se poklapaju kada su im koeficijenti pravca i odsjecci na y osi jednaki*/
	if(a1==a2 && b1!=b2) {printf("Paralelne su");} /*Prave su paralelne kada su im koeficijenti pravca jednaki*/
	if(a1!=a2 && b1!=b2) {
		
		/*Rjesavanje sistema jednacina:
		y=a1*x+b i y=a2*x+b2;
		Izjednacimo: a1*x+b1=a2*x+b2;
		Prebacimo sve sto ima x uz sebe na lijevu stranu pa izvucemo x ispred zagrade: x*(a1-a2)=b2-b1;
		Izrazimo x=(b2-b1)/(a1-a2), te uvrstimo u y	*/
		
		x=(b2-b1)/(a1-a2);
		y=a1*x+b1;
		
		printf("Prave se sijeku u tacci (%.1f,%.1f)", x,y);
	}
	return 0;
}