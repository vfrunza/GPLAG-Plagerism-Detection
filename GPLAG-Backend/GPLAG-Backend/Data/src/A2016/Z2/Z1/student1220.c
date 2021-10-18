#include <stdio.h>
#include <math.h>

int main() {
	int uneseni_broj,novi_broj=0,brojac=0;
	printf("Unesite broj: ");
	scanf("%d", &uneseni_broj);
	do{
		if(uneseni_broj>-10 && uneseni_broj<10) break;
		novi_broj+=fabs(fabs(uneseni_broj%10)-fabs((uneseni_broj/10)%10))*pow(10,brojac++);
	}
	while((uneseni_broj/=10)!=0);
	printf("%d", novi_broj);
	return 0;
}
