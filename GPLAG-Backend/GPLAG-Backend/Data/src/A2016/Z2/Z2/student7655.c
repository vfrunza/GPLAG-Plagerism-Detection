#include <stdio.h>
#include<math.h>
#define PI 3.1415926
#define brojEl 500
int main() {
	float niz[brojEl], minuta, sekundi;
	int brUglova,i, stepeni;
	printf("Unesite broj uglova: ");
	scanf("%d", &brUglova);
	for(i=0; i<brUglova; i++){
		scanf("%f", &niz[i]);
		niz[i]*=180/PI;
		minuta=(niz[i]-(int)niz[i])*60;
		sekundi=(minuta-(int)minuta)*60;
		if(fabs(sekundi)>=59.5) continue;
		if(fabs(sekundi)>30){
			i--;
			brUglova--;
		}
	}
	printf("Uglovi su:\n");
	for(i=0; i<brUglova; i++){
		stepeni=(int)niz[i];
		minuta=(niz[i]-(int)niz[i])*60;
		sekundi=(minuta-(int)minuta)*60;
		if(sekundi>=59.5) {sekundi=0; minuta=0; stepeni++;}
		if(sekundi<=-59.5) {sekundi=0; minuta=0; stepeni--;}
		printf("%d stepeni ", stepeni);
		printf("%.0f minuta ", fabs(minuta));
		printf("%.0f sekundi\n", fabs(sekundi));
	}
	return 0;
}
