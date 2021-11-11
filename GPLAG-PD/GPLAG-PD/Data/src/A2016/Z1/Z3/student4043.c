#include <stdio.h>

int main() {
	char slovo;
	int brC=0,brB=0,brS=0,brV=0,brP=0,max=0,ukupno=0;
	char najvise=0;
	printf("Unesite vozila: ");
	do{
		scanf("%c", &slovo);
		if(slovo!='C' && slovo!='c' && slovo!='B' && slovo!='b' && slovo!='S' && slovo!='s' && slovo!='V' && slovo!='v' && slovo!='P' && slovo!='p' && slovo!='K' && slovo!='k' && slovo!='\n'){
			printf("Neispravan unos\n");
		}
		switch(slovo){
			case 'C':
			case 'c':
				brC++;
				if(brC>max){
					max=brC;
					najvise='C';
				}
				break;
			case 'B':
			case 'b':
				brB++;
				if(brB>max){
					max=brB;
					najvise='B';
				}
				break;
			case 'S':
			case 's':
				brS++;
				if(brS>max){
					max=brS;
					najvise='S';
				}
				break;
			case 'V':
			case 'v':
				brV++;
				if(brV>max){
					max=brV;
					najvise='V';
				}
				break;
			case 'P':
			case 'p':
				brP++;
				if(brP>max){
					max=brP;
					najvise='P';
				}
				break;
			default:
				continue;
				break;
		}
		ukupno++;
	} while(slovo!='K' && slovo!='k');
	printf("Ukupno evidentirano %d vozila.\n", ukupno);
	printf("Najpopularnija boja je ");
	switch(najvise){
		case 'C':
			printf("crna (%.2f%%).", max/(double)ukupno*100);
			break;
		case 'B':
			printf("bijela (%.2f%%).", max/(double)ukupno*100);
			break;
		case 'S':
			printf("siva (%.2f%%).", max/(double)ukupno*100);
			break;
		case 'V':
			printf("crvena (%.2f%%).", max/(double)ukupno*100);
			break;
		case 'P':
			printf("plava (%.2f%%).", max/(double)ukupno*100);
			break;
		default:
			printf("crna (0.00%%).");
	}
	/*printf("Zadaća 1, Zadatak 3");*/
	return 0;
}
