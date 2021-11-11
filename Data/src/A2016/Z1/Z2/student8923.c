#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	float TackaA1,TackaB1,TackaA2,TackaB2,x,y;
	double const EPsiLoN=1e-10;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f", &TackaA1,&TackaB1,&TackaA2,&TackaB2);
	
	if(fabs(TackaA1 - TackaA2)>EPsiLoN*(fabs(TackaA1)+fabs(TackaA2))){
		x=(TackaB2-TackaB1)/(TackaA1-TackaA2);
		y=TackaA1*x+TackaB1;
		printf("Prave se sijeku u tacci (%.1f,%.1f)", x,y);
	}
	else if(fabs(TackaA1-TackaA2)<EPsiLoN*(fabs(TackaA1)+fabs(TackaA2)) && fabs(TackaB1-TackaB2)<EPsiLoN*(fabs(TackaB1)+fabs(TackaB2))){
		printf("Poklapaju se");
	}else{
		 printf("Paralelne su");
	}
	return 0;
}
