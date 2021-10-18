#include <stdio.h>
#include <math.h>

int main() {
	int unos,rezultat=0,razlika,zadnji,pot=0;
	printf("Unesite broj: ");
	scanf("%d",&unos);
	
	if(unos<0) {
		unos=unos*(-1);
	}
	while (unos>10) {
		zadnji=unos%10;
		unos=unos/10;
		razlika=zadnji-(unos%10);
		if(razlika<0) {
			razlika=razlika*(-1);
		}
		rezultat=rezultat+pow(10,pot)*razlika;
		pot++;
	}
	printf("%d",rezultat);
	
	return 0;
}
