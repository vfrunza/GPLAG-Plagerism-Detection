#include <stdio.h>

int main() {
	char letter;
	int numOfCars=0,black=0,white=0,grey=0,blue=0,red=0;
	printf("Unesite vozila: ");
	for(;;){
		scanf("%c", &letter);
		if(letter=='k' || letter=='K') break;
		numOfCars++;
		if(letter=='c' || letter=='C') black++;
		else if(letter=='b' || letter=='B') white++;
		else if(letter=='s' || letter=='S') grey++;
		else if(letter=='p' || letter=='P') blue++;
		else if(letter=='v' || letter=='V') red++;
		else{
			numOfCars--;
			printf("Neispravan unos\n");
		}
	}
	printf("Ukupno evidentirano %d vozila.\n",numOfCars);
	
	 if(numOfCars==0)
		printf("Najpopularnija boja je crna (0.00%%).");
	else if(black>= white && black >= grey && black>=red && black>=blue)
	   printf("Najpopularnija boja je crna (%.2f%%).", (float)black/numOfCars*100);
	else if(white>=black && white>=grey && white>=red && white>=blue)
	   printf("Najpopularnija boja je bijela (%.2f%%).",(float)white/numOfCars*100);
	else if(grey>=black && grey>=white && grey>=red && grey>=blue)
	   printf("Najpopularnija boja je siva (%.2f%%).", (float)grey/numOfCars*100);
	else if(red>=black && red>=white && red>=grey && red>=blue)
	   printf("Najpopularnija boja je crvena (%.2f%%).", (float)red/numOfCars*100);
	else if(blue>=black && blue>=white && blue>=grey && blue>=red)
	   printf("Najpopularnija boja je plava (%.2f%%).", (float)blue/numOfCars*100);
	   
	   
	return 0;
}
