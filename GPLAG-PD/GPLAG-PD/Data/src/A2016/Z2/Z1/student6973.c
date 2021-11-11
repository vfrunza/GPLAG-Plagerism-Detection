#include <stdio.h>
#include <math.h>

int main() {
	int n,br1,br2,rezz = 1,br = 0,stepen,rezultat = 0;;
	printf("Unesite broj: ");
	scanf("%d", &n);
	n = fabs(n);
	if(n > 1 && n < 10) {
		rezultat = 0;
		printf("%d", rezultat);
		return 0;
	}
	//printf("%d",n);
	while(n > 10) {
		br1 = n % 10;
		//printf("\nbr1 %d",br1);
		n = n / 10;
		//printf("\nn %d",n);
		br2 = n % 10;
		//printf("\nbr2 %d",br2);
		rezz = fabs(br1 - br2);
		//printf("\n rezz nakon oduzimanja: %d",rezz);
		//printf("\nbrojac prije %d",br);
		stepen = pow(10,br);
		rezz = rezz * stepen;
		rezultat += rezz; 
		//printf("\n rezz nakon stepenovanja: %d",rezz);
		br++;
		//printf("\nbrojac poslije %d",br);
	}
	printf("%d",rezultat);
	return 0;
}
