#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	
	long long int brojJ, brojD=0, ostatak, varJ, varD, ispis=0;
	int brojac=0, br=0,brPOMOCNI=0, spas;
	
	printf("Unesite broj: ");
	scanf("%lld", &brojJ);
	
	brojJ=abs(brojJ);
	spas=brojJ;
	while(spas!=0){
		spas=spas/10;
		brPOMOCNI++;
	}
	spas=0;
	
	if(brojJ<10 && brojJ>-10){
		ispis=0;
	}
	
	else{
		while(brojJ!=0 && brPOMOCNI>1){
			varJ=brojJ%10;
			brojJ=brojJ/10;
			varD=varJ;
			varJ=brojJ%10;
			
			spas=varD-varJ;
			if(spas<0){
				spas=-spas;
			}
			
			ispis=spas*pow(10,br)+ispis;
			
			brPOMOCNI--;
			br++;
					
		}
	}
	
	printf("%d", ispis);
		
	return 0;
}
