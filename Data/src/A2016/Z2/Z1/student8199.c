#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int in1 = 0, br = 0, ctr = 0, num = 0, out = 0, temp, in, rem, var1, var2;
	
	/*Unos broja*/
	
	printf ("Unesite broj: ");
	scanf ("%d", &in);
	
	/*Postavljanje absolutne*/
	
	in = abs(in);
	temp = in;
	
	/*Racun*/
	
	while (temp != 0) {
		temp = temp / 10;
		num++;
	}
	
	temp = 0;
	
	if (in < 10 && in > -10) {
		out = 0;
	}
	
	else {
		while (in != 0 && num > 1) {
			var2 = in % 10;
			in = in / 10;
			var1 = in % 10;
			
			temp = var2 - var1;
			
				if (temp < 0) {
					temp = -temp;
				}
			
			out = temp * pow(10, br) + out;
			
			num--;
			br++;
		}
	}
	
	/*Ispis*/
	
	printf ("%d", out);
	
	return 0;
}
