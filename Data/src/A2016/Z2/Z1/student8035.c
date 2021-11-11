#include <stdio.h>
#include <stdlib.h>

int main() {
	int br, c1, c2, br2 = 0, dec = 1;
	short prva = 1;
	printf("Unesite broj: ");
	scanf("%d", &br);
	
	br = abs(br);
	if (br < 10) {
		printf("0");
	} else {
		
		while (br) {
			c2 = c1;
			c1 = br % 10;
			br /= 10;
			
			if (prva) {
				prva = 0;
			} else {
				br2 += abs(c2 - c1) * dec;
				dec *= 10;
			}
		}
		
		printf("%d", br2);
	}
	
	return 0;
}
