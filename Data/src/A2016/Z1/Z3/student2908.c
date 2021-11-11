#include <stdio.h>

int main() {
	int ukupno=0;
	int crna=0,plava=0,bijela=0,siva=0,crvena=0,popular=0;
	float posto;
	char slovo,p;
	printf("Unesite vozila: ");
	do {
		scanf("%c",&slovo);
		if (slovo!='C' && slovo !='c' &&slovo!='B' && slovo!='b' && slovo!='S' && slovo!='s' && slovo!='V' && slovo!='v' && slovo!='P' && slovo!='p' && slovo!='k' && slovo!='K') {
			printf("Neispravan unos\n"); }
		if(slovo=='C') {crna++;ukupno++;}
		if(slovo=='c') {crna++;ukupno++;}
		if(slovo=='b') {bijela++; ukupno++;}
		if(slovo=='B') {bijela++; ukupno++;}
		if(slovo=='s') {siva++; ukupno++;}
		if(slovo=='S') {siva++; ukupno++;}
		if(slovo=='v') {crvena++; ukupno++;}
		if(slovo=='V') {crvena++; ukupno++;}
		if(slovo=='p') {plava++;ukupno++;}
		if(slovo=='P') {plava++; ukupno++;}
		if( ((ukupno-bijela)>(ukupno-crna))&& ((ukupno-siva)>(ukupno-crna)) && ((ukupno-plava)>(ukupno-crna)) && ((ukupno-crvena)>(ukupno-crna)) )
			{popular=crna; p='c';}
		if( ((ukupno-crna)> (ukupno-siva) && ((ukupno-bijela)>(ukupno-siva)) && ((ukupno-plava)>(ukupno-siva)) && ((ukupno-crvena)>(ukupno-siva)) ))
			{popular=siva;p='s';}
		if( ((ukupno-siva)>(ukupno-bijela)) && ((ukupno-crna)>(ukupno-bijela)) && ((ukupno-plava)>(ukupno-bijela)) && ((ukupno-crvena)>(ukupno-bijela)) )
			{popular=bijela; p='b';}
		if( ((ukupno-siva)>(ukupno-plava)) && ((ukupno-bijela)>(ukupno-plava)) && ((ukupno-crna)>(ukupno-plava)) && ((ukupno-crvena)>(ukupno-plava)) ) 
			{popular=plava; p='p';}
		if(((ukupno-bijela)>(ukupno-crvena)) && ((ukupno-crna)>(ukupno-crvena)) && ((ukupno-plava)>(ukupno-crvena)) && ((ukupno-siva)>(ukupno-crvena)) )
			{popular=crvena;p='v';}
	} while (slovo!='K' && slovo!='k');
	if(popular==0){
		printf("Ukupno evidentirano 0 vozila.");
		printf("\nNajpopularnija boja je crna (0.00%%).");
	} 
	if(popular>0){
		posto=(popular*(1./ukupno))*100;
		printf("Ukupno evidentirano %d vozila.",ukupno);
		if(p=='c') {printf("\nNajpopularnija boja je crna (%.2f%%).",posto);}
		if(p=='s') {printf("\nNajpopularnija boja je siva (%.2f%%).",posto);}
		if(p=='b') {printf("\nNajpopularnija boja je bijela (%.2f%%).",posto);}
		if(p=='p') { printf("\nNajpopularnija boja je plava (%.2f%%).",posto);}
		if(p=='v') {printf("\nNajpopularnija boja je crvena (%.2f%%).",posto);}
	}
	return 0; 
}
