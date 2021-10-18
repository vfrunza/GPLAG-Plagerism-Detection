#include <stdio.h>

int main() {
	char y, T, B, M, P, H, C;
	float PR=6.80, PF=8.00, PB=5.30,
		  HR=3.30, HF=3.00, HB=5.00,
		  CR=5.00, CF=3.90, CB=6.00,
		  PP, PH, PC,
		  R1=0, R2=0, R3=0, min;
	int FBP=0, FBH=0, FBC=0; /* FB - Feedback jela za racunanje popusta */
	
	printf ("Unesite jelo za Tarika: ");
	scanf ("%c%c", &T, &y);
	printf ("Unesite jelo za Bojana: ");
	scanf ("%c%c", &B, &y);
	printf ("Unesite jelo za Mirzu: "); 
	scanf ("%c%c", &M, &y);
	
	if (T=='H') {
		R1+=HR;
		R2+=HF;
		R3+=HB;
		FBH++; }
	else if (T=='P') {
		R1+=PR;
		R2+=PF;
		R3+=PB;
		FBP++; }
	else if (T=='C') {
		R1+=CR;
		R2+=CF;
		R3+=CB;
		FBC++; }

	if (B=='H') {
		R1+=HR;
		R2+=HF;
		R3+=HB;
		FBH++; }
	else if (B=='P') {
		R1+=PR;
		R2+=PF;
		R3+=PB;
		FBP++; }
	else if (B=='C') {
		R1+=CR;
		R2+=CF;
		R3+=CB;
		FBC++; }

 	if (M=='H') {
		R1+=HR;
		R2+=HF;
		R3+=HB;
		FBH++; }
	else if (M=='P') {
		R1+=PR;
		R2+=PF;
		R3+=PB;
		FBP++; }
	else if (M=='C') {
		R1+=CR;
		R2+=CF;
		R3+=CB;
		FBC++; }

if (R1<R2 && R1<R3) {
min = R1;
printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", R1); }
else if (R2<R1 && R2<R3) {
min = R2;
printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", R2); }
else if (R3<R1 && R3<R2) {
min = R3;
printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", R3); }

if (min!=R1) {
	PP=PR*0.1;
	PH=HR*0.1;
	PC=CR*0.1;

	if (FBP==FBH && FBP==FBC) {
		if (PR>HR && PR>CR) R1=R1-PP;
		if (HR>PR && HR>CR) R1=R1-PH;
		if (CR>HR && CR>PR) R1=R1-PC;
	}
	else if (FBP>FBH && FBP>FBC) R1=R1-(FBP*PP);
	else if (FBH>FBP && FBH>FBC) R1=R1-(FBH*PH);
	else if (FBC>FBH && FBC>FBP) R1=R1-(FBC*PC);
	
	if (R1<R2 && R1<R3) 
	printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", R1);
	
	}
	return 0;
}