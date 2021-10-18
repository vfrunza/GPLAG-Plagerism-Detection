#include <stdio.h>

int main(){
	int n, c, d, razlika, b, p, broj=0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n<0) n*=-1;
	if(n>=0 && n<10){
		printf("0");
		return 0;
	}
		p=1;
		do{

		c=n%10;
		b=n/10;
		d=b%10;
		razlika= c-d;
		if(razlika<0)razlika*=-1;
		broj+=razlika*p;
		p*=10;
		n=b;
		}while(n>10);
	printf("%d", broj);
	
	return 0;
}