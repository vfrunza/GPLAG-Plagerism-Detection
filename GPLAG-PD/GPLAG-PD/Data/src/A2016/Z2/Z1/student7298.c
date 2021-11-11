#include <stdio.h>
#include <math.h>

int main() {
	int broj,rezultat=0,ostatak1,ostatak2,br=0,razlika;
	printf("Unesite broj: ");
	scanf("%d", &broj);
	if(broj>-10 && broj<10) printf("%d", rezultat);
	else{
		while(1){
			if(broj<0) broj=fabs(broj);
			ostatak1=broj%10;
			broj/=10;
			if(broj==0) break;
			ostatak2=broj%10;
			razlika=fabs(ostatak1-ostatak2);
			rezultat=rezultat+razlika*pow(10,br);
			br++;
		}
	printf("%d", rezultat);
	}
	return 0;
}
