#include <stdio.h>
#include <math.h>

int reverse(int n) {
		if(!n) return 0;
		int length=(int)ceil(log10(n));
		int remainder=n%(int)pow(10,length-1);
		int first_digit=n/(int)pow(10, length-1);
		return reverse(remainder)*10+first_digit;
	}
	
int main() {
	int num;
	printf("\nUnesite broj: ");
	scanf("%d", &num);
	int output=0;
	int last_digit=0;
	int this_digit=0; /*zadnja znamenka desno*/
	last_digit=num%10;
	num/=10;
	while(num) {
		output*=10; /*uzmi zadnju znamenku zdesna preostalog broja*/
		this_digit=num%10;
		num/=10; /*stavi razliku znamenki u izlazni broj*/
		output= output+fabs(last_digit-this_digit); /*pomakni se*/
	 	last_digit=this_digit; /*moramo obrnuti ovaj broj*/
	}
	printf("%d\n", reverse(output));
	return 0;
}
