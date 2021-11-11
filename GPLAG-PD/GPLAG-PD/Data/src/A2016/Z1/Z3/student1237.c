#include <stdio.h>
#include <math.h>
int main() {
char slovo;
int brojac=0,j,mjc,mjb,mjs,mjv,mjp;
float bc=0,bb=0,bs=0,bv=0,bp=0;
float crna,bijela,siva,crvena,plava;

	printf("\nUnesite vozila: ");

for(j=0;j<10000;j++){
scanf("%c",&slovo);



if(slovo=='c' || slovo=='C') {brojac++; bc++; }
else if(slovo=='b' || slovo=='B') {brojac++; bb++;  }
else if(slovo=='s' || slovo=='S') {brojac++; bs++; }
else if(slovo=='v' || slovo=='V') {brojac++; bv++;}
else if(slovo=='p' || slovo=='P') {brojac++; bp++;}
else if(slovo=='k' || slovo=='K') break;
else if(slovo!='c' || slovo!='C' || slovo!='b' || slovo!='B' || slovo!='s' || slovo!='S' || slovo!='v' || slovo!='V' || slovo!='p' || slovo!='P' || slovo!='k' || slovo!='K') printf("Neispravan unos\n");


}
printf("Ukupno evidentirano %d vozila.\n",brojac);

if(bc>=bb  && bc>=bs && bc>=bv &&  bc>=bp )

	{
		if(bc==0) printf("Najpopularnija boja je crna (0.00%%).");
		else {
	crna=(bc/brojac)*100;
	printf("\nNajpopularnija boja je crna (%.2f%%).",crna);}
} 
if(bb>bc && bb>=bs  && bb>=bv && bb>=bp){
	bijela=(bb/brojac)*100;
	printf("\nNajpopularnija boja je bijela (%.2f%%).",bijela);
}
if(bs>bc && bs>bb && bs>=bv && bs>=bp ){
	siva=(bs/brojac)*100;
	printf("\nNajpopularnija boja je siva (%.2f%%).",siva);
}
if(bv>bc && bv>bb && bv>bs && bv>bp){
	crvena=(bv/brojac)*100;
	printf("\nNajpopularnija boja je crvena (%.2f%%).",crvena);
}
if(bp>bc && bp>bb && bp>bs && bp>bv){
	plava=(bp/brojac)*100;
	printf("\nNajpopularnija boja je plava (%.2f%%).",plava);
}
	return 0;
}
