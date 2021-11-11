#include <stdio.h>
#include <stdlib.h>

int main() {
	long int b, prva, druga, razlika,razlika1=0, i=1, a, broj;
	printf("Unesite broj: ");
	scanf("%ld", &broj);
	a=abs(broj);
	do{
		prva=a%10;
		b=a/10;
		druga=b%10;
		if(abs(broj)==abs(broj%(i*10)))
			break;
		razlika=prva-druga;
		if(razlika<0)
			razlika=razlika*(-1);
		razlika1=razlika1+i*razlika;	
		a=b;
		i*=10;
	}while(1);
	printf("%ld", razlika1);
	return 0;
}
