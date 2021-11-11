#include <stdio.h>
#include<math.h>
#define EPSILON 0.001

int main() {
	
	char x, C, c, B, b, S, s, V, v, P, p, K, k;
	int suma_crniha1=0, suma_crniha2=0, suma_bijeliha1=0, suma_bijeliha2=0, suma_siviha1=0, suma_siviha2=0, suma_crveniha1=0, suma_crveniha2=0, suma_plaviha1=0,suma_plaviha2=0;
	float suma, sumaCRNIH, sumaBIJELIH, sumaSIVIH, sumaCRVENIH, sumaPLAVIH;
	double procenat;
	printf("Unesite vozila: "); 
	for(;;){
	scanf("%c", &x);
		if(x=='C'){
			suma_crniha1++;
		}
		if(x=='c') {
			suma_crniha2++;
		}
		if(x=='B'){
			suma_bijeliha1++;
		}
		if(x=='b'){
			suma_bijeliha2++;
		}
	
		if(x=='S'){
			suma_siviha1++;
		}
		if(x=='s'){
			suma_siviha2++;
		}
		
		if(x=='V'){
			suma_crveniha1++;
		}
		if(x=='v'){
			suma_crveniha2++;
		}
		
		if(x=='P'){
			suma_plaviha1++;
		}
		if(x=='p'){
			suma_plaviha2++;
		}
		
		if(x!='C' && x!='c'&& x!='B' && x!='b' && x!='S' && x!='s' && x!='V' && x!='v' && x!='P' && x!='p' && x!='K' && x!='k'){
			
			printf("Neispravan unos\n");
			
		}
		if (x=='K' || x=='k'){
			break;
		
		}
		
	}
	suma=suma_crniha1+suma_crniha2+suma_bijeliha1+suma_bijeliha2+suma_siviha1+suma_siviha2+suma_crveniha1+suma_crveniha2+suma_plaviha1+suma_plaviha2;
	printf("Ukupno evidentirano %.f vozila.\n", suma); 
	sumaCRNIH=suma_crniha1+suma_crniha2;
	sumaBIJELIH=suma_bijeliha1+suma_bijeliha2;
	sumaSIVIH=suma_siviha1+suma_siviha2;
	sumaCRVENIH=suma_crveniha1+suma_crveniha2;
	sumaPLAVIH=suma_plaviha1+suma_plaviha2;
	if(fabs(suma-0)<EPSILON){
		printf("Najpopularnija boja je crna (0.00%).");
	} else{
	if(sumaCRNIH>=sumaCRVENIH && sumaCRNIH>=sumaBIJELIH && sumaCRNIH>=sumaSIVIH && sumaCRNIH>=sumaPLAVIH){
		procenat=(sumaCRNIH*100)/suma;
		printf("Najpopularnija boja je crna (%4.2f%).", procenat);
	}
	if(sumaBIJELIH>sumaCRNIH && sumaBIJELIH>=sumaSIVIH && sumaBIJELIH>=sumaCRVENIH && sumaBIJELIH>=sumaPLAVIH){
		procenat=(sumaBIJELIH*100)/suma;
		printf("Najpopularnija boja je bijela (%4.2f%).", procenat);
	}
	if(sumaSIVIH>sumaCRNIH && sumaSIVIH>sumaBIJELIH && sumaSIVIH>=sumaCRVENIH && sumaSIVIH>=sumaPLAVIH){
		procenat=(sumaSIVIH*100)/suma;
		printf("Najpopularnija boja je siva (%4.2f%).", procenat);
	}
	if(sumaCRVENIH>sumaCRNIH && sumaCRVENIH>sumaBIJELIH && sumaCRVENIH>sumaSIVIH && sumaCRVENIH>=sumaPLAVIH){
		procenat=(sumaCRVENIH*100)/suma;
		printf("Najpopularnija boja je crvena (%4.2f%).", procenat);
	}
	if(sumaPLAVIH>sumaCRNIH && sumaPLAVIH>sumaBIJELIH && sumaPLAVIH>sumaSIVIH && sumaPLAVIH>sumaCRVENIH){
		procenat=(sumaPLAVIH*100)/suma;
		printf("Najpopularnija boja je plava (%4.2f%).", procenat);
	}
	
	}
		return 0;
	}
	

