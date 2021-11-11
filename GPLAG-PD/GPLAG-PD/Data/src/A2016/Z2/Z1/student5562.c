#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	
	int br, a;
	int c = 0;
	int b = 0;
	int rez = 0;
	int n = -1;
	
	printf("Unesite broj: ");
	
	scanf("%d", &br);
	
	if (br < 0)
		br = abs(br);
	
	while (br > 0){
		
		
		a = br%10;
		
		
		if (n > -1){
			c = abs(a - b);
		}
		
		b = a;
		
		rez = rez + c*pow(10, n);
		n++;
		
		br = (br - a)/10; 
	}
	
	printf("%d", rez);
	
	return 0;
}
