#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926

int main() {
	int stepen, minute, sekunde;
	float niz[500];
	int n;
	int i;
	int brojac=0;
	
	do {
		printf("Unesite broj uglova: ");
		scanf("%d", &n);
	}while(n<1 || n>500);		
	
	for(i=0; i<n; i++) {
		scanf("%f", &niz[i]);
	}
	
	for(i=0; i<n; i++)  {
		sekunde=(((niz[i]*180)/PI)*3600);
		if(sekunde<0) {
			sekunde=(double) ((((niz[i]*180)/PI)*3600) - 0.5);
			sekunde=(abs(sekunde));
			minute=sekunde/60;
			sekunde=(sekunde%60);
			stepen=minute/60;
			minute=minute%60;
			if(stepen!=0) {
			stepen=stepen-(stepen*2);
			brojac++;
			goto dalje;
			} else {
				stepen=-stepen;
				
				
			}
		} else {
			if (sekunde>=0) {
			sekunde=(double) ((((niz[i]*180)/PI)*3600) + 0.5);
			sekunde=(abs(sekunde));
			minute=sekunde/60;
			sekunde=(sekunde%60);
			stepen=minute/60;
			minute=minute%60;
			brojac++;
			goto dalje;
			}
		}
	
dalje:		
		if(brojac==1){
			printf("Uglovi su: \n");
		}
		if(sekunde<=30){
			printf("%d stepeni %d minuta %d sekundi\n", stepen, minute, sekunde);
		}
	}

	return 0;
}
