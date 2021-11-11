#include <stdio.h>
#include <math.h>
#define Broj_Elemenata 500
#define PI 3.1415926

int main() {
	float niz[Broj_Elemenata],promjenjeno,promjenjeno1,promjenjeno2,ostatak,ostatak1,ostatak2;
	int i,broj,stepeni,minute,sekunde;
	printf("Unesite broj uglova: ");
	scanf("%d",&broj);
	for(i=0;i<broj;i++){
		scanf("%f",&niz[i]);
		promjenjeno=niz[i]*(180/PI);
		stepeni=promjenjeno;
		ostatak=promjenjeno-stepeni;
		promjenjeno1=ostatak*60;
		minute=promjenjeno1;
		ostatak1=promjenjeno1-minute;
		promjenjeno2=ostatak1*60;
		sekunde=promjenjeno2;
		ostatak2=promjenjeno2-sekunde;
		if(ostatak2>=0.5){
			sekunde=promjenjeno2+1;
		}
		if(sekunde>30){
			broj--;
			i--;
		}
	}
	printf("Uglovi su: \n");
	for(i=0;i<broj;i++){
		promjenjeno=niz[i]*(180/PI);
		stepeni=promjenjeno;
		ostatak=promjenjeno-stepeni;
		promjenjeno1=ostatak*60;
		minute=promjenjeno1;
		ostatak1=promjenjeno1-minute;
		promjenjeno2=ostatak1*60;
		sekunde=promjenjeno2;
		ostatak2=promjenjeno2-sekunde;
		if(ostatak2>=0.5){
			sekunde=promjenjeno2+1;
		}
		printf("%d stepeni %d minuta %d sekundi\n",stepeni,minute,sekunde);
	}
	return 0;
}