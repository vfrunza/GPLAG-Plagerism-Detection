#include <stdio.h>

int main() {
	char vozilo;
	int c=0, b=0, s=0, v=0, p=0, UV;
	float P, UV1;
	
	/* Unos vozila*/
	
	printf("Unesite vozila: ");
	
	do {
		
		scanf("%c", &vozilo);
		
		if(vozilo == 'c' || vozilo == 'C'){
			c=c+1;
		} else if (vozilo == 'b' || vozilo == 'B'){
			b=b+1;
		} else if (vozilo == 's' || vozilo == 'S'){
			s=s+1;
		} else if (vozilo == 'v' || vozilo == 'V'){
			v=v+1;
		} else if (vozilo == 'p' || vozilo == 'P'){
			p=p+1;
		} else if (vozilo == 'k' || vozilo == 'K'){
			break;
		} else {
			printf("Neispravan unos \n");
			continue;
		}
		
	}
	
	while(vozilo != 'k' || vozilo != 'K');
	
	/*Najpopularnije boje vozila i njihov postotak*/
	
	UV=c+b+s+v+p;
	
	printf("Ukupno evidentirano %d vozila. \n", UV);
	
	UV1=UV;
	
	if(UV1==0){
		P=0;
		printf("Najpopularnija boja je crna (%.2f%%).", P);
	} else if(c >= b && c >= s && c >= v && c >= p){
		P=100*(c/UV1);
		printf("Najpopularnija boja je crna (%.2f%%).", P);
	} else if (b > c && b >= s && b >= v && b >= p){
		P=100*(b/UV1);
		printf("Najpopularnija boja je bijela (%.2f%%).", P);
	} else if (s > c && s > b && s >= v && s >= p){
		P=100*(s/UV1);
		printf("Najpopularnija boja je siva (%.2f%%).", P);
	} else if (v > c && v > b && v > s && v >= p){
		P=100*(v/UV1);
		printf("Najpopularnija boja je crvena (%.2f%%).", P);
	} else if (p > c && p > b && p > s && p > v){
		P=100*(p/UV1);
		printf("Najpopularnija boja je plava (%.2f%%).", P);
	} 
	
	return 0;
}
