#include <stdio.h>

int main() {
	char vozila;
	float c=0;
	float b=0;
	float s=0;
	float v=0;
	float p=0;
	float ukupnovozila=0;
	float procenatcrna=0.0;
	float procenatcrvena=0.0;
	float procenatbijela=0.0;
	float procenatsiva=0.0;
	float procenatplava=0.0;
	
	/*Unos vozila*/
	
	printf("Unesite vozila: ");
	
	do {
	scanf("%c", &vozila);
	
	if ((vozila=='C')||(vozila=='c')) {
		c++; continue;}
	if ((vozila=='B')||(vozila=='b')) {
		b++; continue;}
	if ((vozila=='S')||(vozila=='s')) {
		s++; continue;}
	if ((vozila=='V')||(vozila=='v')) {
		v++; continue;}
	if ((vozila=='P')||(vozila=='p')) {
		p++; continue;}
	if (((vozila!='C')&&(vozila!='c'))&&((vozila!='B')&&(vozila!='b'))&&((vozila!='S')&&(vozila!='s'))&&((vozila!='V')&&(vozila!='v'))&&((vozila!='P')&&(vozila!='p'))&&((vozila!='K')&&(vozila!='k')))
	{ printf("Neispravan unos\n");}}
	while ((vozila!='K')&&(vozila!='k'));
	
	/*Zbir vozila i procenat istih*/
	
	ukupnovozila=c+b+s+v+p;
	printf("Ukupno evidentirano %g vozila.\n", ukupnovozila);
	if(ukupnovozila!=0){
	procenatcrna=(c*100)/ukupnovozila;
	procenatbijela=(b*100)/ukupnovozila;
	procenatsiva=(s*100)/ukupnovozila;
	procenatcrvena=(v*100)/ukupnovozila;
	procenatplava=(p*100)/ukupnovozila; }
	
	/*Najpopularnija boja*/
	
	if((c>=s)&&(c>=v)&&(c>=b)&&(c>=p)) {
	printf("Najpopularnija boja je crna (%.2f%%).", procenatcrna);
	return 0;}
	if((b>=c)&&(b>=v)&&(b>=p)&&(b>=s)) {
	printf("Najpopularnija boja je bijela (%.2f%%).", procenatbijela);
	return 0;}
	if((s>=v)&&(s>=c)&&(s>=b)&&(s>=p)) {
	printf("Najpopularnija boja je siva (%.2f%%).", procenatsiva);
	return 0;}
	if((v>=b)&&(v>=s)&&(v>=c)&&(v>=p)) {
	printf("Najpopularnija boja je crvena (%.2f%%).", procenatcrvena);
	return 0;}
	if((p>=s)&&(p>=v)&&(p>=c)&&(p>=b)) {
	printf("Najpopularnija boja je plava (%.2f%%).", procenatplava);
	return 0;}
	
	return 0;
}
