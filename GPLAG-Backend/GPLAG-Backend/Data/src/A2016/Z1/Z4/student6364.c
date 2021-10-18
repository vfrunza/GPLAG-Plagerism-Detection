#include <stdio.h>
#include <math.h>
int main() {
	int height, width, modifier;
	int y, x;
	do {
	printf ("Unesite broj n: ");
	scanf ("%i", &height);
	if (floor(height)!=height || height<1 || height>50) {
		printf("Pogresan unos\n");
			} 
		}
	while (height<1|| height>50 || floor(height)!=height);
	if (height==1) {
		printf("***\n");
		return 0;
		
	}
	width = 4 * height - 3;
	modifier = height - 1;
	for (y = height - 1; y >= 0; y--) {
		for (x=0; x<width; x++){
			if (y==(int)fabs (x % (modifier * 2) - modifier)) {
				printf("*");
		} else {
			printf(" ");
			} 
		}
		printf("\n");
	
	}
	return 0;
}
