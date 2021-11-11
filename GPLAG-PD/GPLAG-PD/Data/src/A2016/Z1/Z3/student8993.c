#include <stdio.h>

int main() {
	char znak=0;
	int crna=0,bijela=0,siva=0,crvena=0,plava=0;
	float s=0;
	float x=0;
printf("Unesite vozila: ");
while(1) {
	scanf("%c",&znak);
	if(znak=='C' || znak=='c')
	crna++;
	else if(znak=='B' || znak=='b')
	bijela++;
	else if(znak=='S' || znak=='s')
	siva++;
	else if(znak=='V' || znak=='v')
	crvena++;
	else if(znak=='P' || znak=='p')
	plava++;
	if(znak!='C' && znak!='c' && znak!='S' && znak!='s' && znak!='V' && znak!='v' && znak!='P' && znak!='p' && znak!='B' && znak!='b' && znak!='k' && znak!='K'){
	printf("Neispravan unos");
	printf("\n");}
	if(znak=='k' || znak=='K') break;
}
s=crna+crvena+siva+bijela+plava;
printf("Ukupno evidentirano %.f vozila.",s);
if(crna>=bijela && crna>=siva && crna>=crvena && crna>=plava) {
x=(crna/s)*100;
if(s==0)
x=0;
printf("\nNajpopularnija boja je crna (%.2f%%).",x); }
else if(bijela>crna && bijela>=siva && bijela>=crvena && bijela>=plava) {
	x=(bijela/s)*100;
	printf("\nNajpopularnija boja je bijela (%.2f%%).",x);
}
else if(siva>crna && siva>bijela && siva>=crvena && siva>=plava) {
	x=(siva/s)*100;
	printf("\nNajpopularnija boja je siva (%.2f%%).",x);
}
else if(crvena>crna && crvena>bijela && crvena>siva && crvena>=plava) {
	x=(crvena/s)*100;
	printf("\nNajpopularnija boja je crvena (%.2f%%).",x);
}
else if(plava>crna && plava>bijela && plava>siva && plava>crvena) {
	x=(plava/s)*100;
	printf("\nNajpopularnija boja je plava (%.2f%%).",x);
}

	return 0;
}
