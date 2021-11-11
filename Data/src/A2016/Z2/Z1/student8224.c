#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	int broj, jedinica, desetica, t, brojac=0, rezultat=0;
	
	printf("Unesite broj: ");
	scanf("%d", &broj);
	if(broj/10!=0){
		do{
			jedinica=broj%10;
			desetica=(broj%100);
			desetica=(desetica-desetica%10)/10;
			t=jedinica-desetica;
			t=abs(t);
			brojac++;
			t=t*pow(10,(brojac-1));
			rezultat+=t;
			broj=broj/10;
			if(broj/10==0){
				break;
			}
			
		}
		while(broj!=1);
		printf("%d", rezultat);
	}
	else{
		printf("0");
	}
	
	return 0;
}

