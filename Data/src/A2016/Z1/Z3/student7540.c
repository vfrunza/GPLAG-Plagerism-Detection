#include <stdio.h>
int main() {
	int bp, bc, bv, bs, bb, s, max;
	float udio=0;
	char slovo;
	bp=0;bc=0;bv=0;bb=0;bs=0;
	printf("Unesite vozila: ");
	do { 
	scanf("%c", &slovo);
    if ((slovo!='C')&&(slovo!='c')&&(slovo!='B')&&(slovo!='b')&&(slovo!='V')&&(slovo!='v')&&(slovo!='K')&&(slovo!='k')&&(slovo!='S')&&(slovo!='s')&&(slovo!='P')&&(slovo!='p'))
    printf("Neispravan unos\n");
	if (slovo == 'K') slovo='k';
	if (slovo == 'C') slovo='c';
	if (slovo == 'B') slovo='b';
	if (slovo == 'S') slovo='s';
	if (slovo == 'P') slovo='p';
	if (slovo == 'V') slovo='v';
	if (slovo == 'p') bp++;
	if (slovo == 'c') bc++;
	if (slovo == 'v') bv++;
	if (slovo == 's') bs++;
	if (slovo == 'b') bb++;
	}
	while(slovo!= 'k');
s=bp+bc+bv+bs+bb;
printf("Ukupno evidentirano %d vozila.\n", s);
max=bc;
if (bb >=max) max=bb;
if (bs>=max) max=bs;
if (bv>=max) max=bv;
if (bp>=max) max=bp;
if (s!=0)
udio=((float)max/s)*100;
if (max==bc)
printf("Najpopularnija boja je crna (%.2f%%).", udio);
else if (max==bb)
printf("Najpopularnija boja je bijela (%.2f%%).", udio);
else if (max==bs)
printf("Najpopularnija boja je siva (%.2f%%).", udio);
else if (max==bv)
printf("Najpopularnija boja je crvena (%.2f%%).", udio);
else if (max==bp)
printf("Najpopularnija boja je plava (%.2f%%).", udio);
return 0;
}
