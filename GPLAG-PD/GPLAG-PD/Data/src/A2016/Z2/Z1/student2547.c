#include <stdio.h>
#include <math.h>	

int main() {
	int broj, rez=0, o1, o2, br=0;
	printf("Unesite broj: ");
	scanf("%d", &broj);
	while((broj=fabs(broj))!=0){
		if(broj>-10 && broj<10)
		break;
		o1=broj%10;
		broj/=10;
		o2=broj%10;
		rez+=fabs(o1-o2)*pow(10,br++);
	}
	printf("%d", rez);
	return 0;
}
