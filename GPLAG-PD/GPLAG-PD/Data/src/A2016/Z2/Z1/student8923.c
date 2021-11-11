#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
	int a,num=0,b=1,diff;
	printf("Unesite broj: ");
	scanf("%d", &a);
	a = abs(a);
	while(a>10){
		/*razlika zadnje i predzadnje cifre u prolazu kroz petlju*/
		diff = a%10 - (a%100)/10;
		num += b*abs(diff);
		/*pomjera cifru svaki put za jedno mjesto*/
		b *= 10;
		a /= 10;
	}
	printf("%d",num);
	return 0;
}
