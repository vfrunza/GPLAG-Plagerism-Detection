#include <stdio.h>

int main() {
	float bijela=0,siva=0,crna=0,crvena=0,plava=0,pb=0.0,ps=0.0,pc=0.0,pcrv=0.0,pp=0.0,uv=0;
	char unos;
	printf ("Unesite vozila: ");
	do {
	scanf ("%c", &unos);
	if ((unos=='c')||(unos =='C')){crna++; continue;}
	if ((unos=='b')||(unos=='B')) {bijela++; continue;}
	if ((unos=='s')||(unos=='S')) {siva++; continue;}
	if ((unos=='v')||(unos=='V')) {crvena++; continue;}
	if ((unos=='p')||(unos=='P')) {plava++; continue;}
	if ((unos!= 'c')&&(unos!='C')&&(unos!='b')&&(unos!='B')&&(unos!='s')&&(unos!='S')&&(unos!='v')&&(unos!='V')&&(unos!='p')&&(unos!='P')&&(unos!='k')&&(unos!='K')){ 
	printf ("Neispravan unos\n"); 
	continue;} }
	while ((unos!='k')&&(unos!='K'));
	uv=bijela+siva+crna+crvena+plava;
    pc=(crna/uv)*100;
    pb=(bijela/uv)*100;
    ps=(siva/uv)*100;
    pp=(plava/uv)*100;
    pcrv=(crvena/uv)*100;
	printf ("Ukupno evidentirano %g vozila. \n",uv);
	if (uv==0) {printf ("Najpopularnija boja je crna (0.00%%).");
	return 0; }
	if ((crna>=bijela)&&(crna>=siva)&&(crna>=crvena)&&(crna>=plava)) {
    printf ("Najpopularnija boja je crna (%.2f%%).",pc);
	return 0;}
	if ((bijela>=crna) && (bijela>=siva) && (bijela>=crvena) && (bijela>=plava)) {
	printf ("Najpopularnija boja je bijela (%.2f%%).",pb);
	return 0;}
    if ((siva>=crna) && (siva>=bijela) && (siva>=crvena) && (siva>=plava)) {
	printf ("Najpopularnija boja je siva (%.2f%%).",ps);
	return 0;}
	if ((crvena>=crna) && (crvena>=siva) && (crvena>=bijela) && (crvena>=plava)) {
	printf ("Najpopularnija boja je crvena (%.2f%%).",pcrv);
	return 0;}
	if ((plava>=crna) && (plava>=siva) && (plava>=crvena) && (plava>bijela)) {
	printf ("Najpopularnija boja je plava (%.2f%%).",pp);
	return 0;}
	return 0;
}
