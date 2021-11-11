#include <stdio.h>

int main() {
	
	char slovo; 
	int i=0,brojac_unesenih=0, brojac_c=0, brojac_b=0, brojac_p=0, brojac_s=0, brojac_v=0, max=0;
	float procenat=0;
	
	printf("Unesite vozila: ");
	
	for(i=0; i<3000; i++) {
		scanf("%c", &slovo);
		if(slovo=='k' || slovo=='K') {
			break;
		}	
		
		
		
		if(slovo=='c' || slovo=='C') {
			brojac_c++;
		}
		else if(slovo=='b' || slovo=='B') {
			brojac_b++;
		}
		else if(slovo=='s' || slovo=='S') {
			brojac_s++;
		}
		else if(slovo=='p' || slovo=='P') {
			brojac_p++;
		}
		else if(slovo=='v' || slovo=='V') {
			brojac_v++;
		}
	
		else if(slovo!='C' && slovo!='c' && slovo!='b' && slovo!='B' && slovo!='s' && slovo!='S' && slovo!='p' && slovo!='P' && slovo!='V' && slovo!='v' && slovo!='k'){
			printf("Neispravan unos\n");
			continue;
		}
		brojac_unesenih++;
	
	}
	printf("Ukupno evidentirano %d vozila.\n", brojac_unesenih);
	
	if(brojac_p>=brojac_c && brojac_p>=brojac_s && brojac_p>=brojac_v && brojac_p>=brojac_b) {
		max=brojac_p;
	}
	if(brojac_v>=brojac_c && brojac_v>=brojac_s && brojac_v>=brojac_p && brojac_v>=brojac_b) {
		max=brojac_v;
	}
	if(brojac_s>=brojac_c && brojac_s>=brojac_p && brojac_s>=brojac_v && brojac_s>=brojac_b) {
		max=brojac_s;
	}
	if(brojac_b>=brojac_c && brojac_b>=brojac_p && brojac_b>=brojac_s && brojac_b>=brojac_v) {
		max=brojac_b;
	}
	if(brojac_c>=brojac_b && brojac_c>=brojac_p && brojac_c>=brojac_s && brojac_c>=brojac_v) {
		max=brojac_c;
	}
	if(brojac_unesenih==0) procenat=0;
	else{
		procenat=((float)max/brojac_unesenih)*100;
	}
	
	printf("Najpopularnija boja je ");
	
	if(max==brojac_c) {
		printf("crna (%.2f%%).", procenat);
	}
	else if(max==brojac_b) {
		printf("bijela (%.2f%%).", procenat);
	}
	else if(max==brojac_s) {
		printf("siva (%.2f%%).", procenat);
	}
	else if(max==brojac_v) {
		printf("crvena (%.2f%%).", procenat);
	}
	else if(max==brojac_p) {
		printf("plava (%.2f%%).", procenat);
	}
	

	return 0;
}
