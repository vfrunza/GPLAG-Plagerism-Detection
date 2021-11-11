#include <stdio.h>

int main() {
	char i;
	int brojac_vozila=0;
	double vozila=0;
	double prosjek;
	int brojac_crnih=0;
	int brojac_plavih=0;
	int brojac_crvenih=0;
	int brojac_bijelih=0;
	int brojac_sivih=0;
printf("Unesite vozila: ");
do
{ scanf("%c", &i);
if(i=='k'|| i=='K') break;
  if(i=='c' || i=='C')  { brojac_crnih++; brojac_vozila++; }
 if(i=='p' || i=='P')  { brojac_plavih++; brojac_vozila++; }
 if(i=='v' || i=='V') {brojac_crvenih++; brojac_vozila++;}
  if(i=='s' || i=='S')  { brojac_sivih++; brojac_vozila++; }
  if(i=='b' ||i=='B') { brojac_bijelih++; brojac_vozila++; }
 if(i!='k' && i!='K' && i!='c' &&i!='C' && i!='v' && i!='V' && i!='p' && i!='P' && i!='b' && i!='B' && i!='s' && i!='S')
{
	printf("Neispravan unos\n");
	continue;
}
vozila=brojac_crnih+brojac_bijelih+brojac_sivih+brojac_crvenih+brojac_plavih;
  
} while(brojac_vozila<=1000000000000000);
	
	printf("Ukupno evidentirano %g vozila.\n", vozila);
	
if(brojac_crnih>=brojac_bijelih && brojac_crnih>=brojac_sivih && brojac_crnih>=brojac_crvenih && brojac_crnih>=brojac_plavih)
{
	prosjek=(brojac_crnih/vozila)*100;
	if(brojac_crnih==0)
	printf("Najpopularnija boja je crna (0.00%%).");
	else
	printf("Najpopularnija boja je crna (%.2f%%).", prosjek);
}
else if(brojac_bijelih>=brojac_crnih && brojac_bijelih>=brojac_sivih && brojac_bijelih>=brojac_crvenih && brojac_bijelih>=brojac_plavih)
{
	prosjek=(brojac_bijelih/vozila)*100;
	if(brojac_bijelih==0)
	printf("Najpopularnija boja je bijela (0.00%%).");
	else
	printf("Najpopularnija boja je bijela (%.2f%%).", prosjek);
}
else if(brojac_sivih>=brojac_crnih && brojac_sivih>=brojac_bijelih && brojac_sivih>=brojac_crvenih && brojac_sivih>=brojac_plavih)
{
	prosjek=(brojac_sivih/vozila)*100;
	if(brojac_sivih==0)
	printf("Najpopularnija boja je siva (0.00%%).");
	else
	printf("Najpopularnija boja je siva (%.2f%%).", prosjek);
}

else if(brojac_crvenih>=brojac_crnih && brojac_crvenih>=brojac_bijelih && brojac_crvenih>=brojac_sivih && brojac_crvenih>=brojac_plavih)
{
	prosjek=(brojac_crvenih/vozila)*100;
	if(brojac_crvenih==0)
	printf("Najpopularnija boja je crvena (0.00%%).");
	else
	printf("Najpopularnija boja je crvena (%.2f%%).", prosjek);
	
}
else if(brojac_plavih>=brojac_crnih && brojac_plavih>=brojac_bijelih && brojac_plavih>=brojac_sivih && brojac_plavih>=brojac_crvenih)
{
	prosjek=(brojac_plavih/vozila)*100;
	if(brojac_plavih==0)
	printf("Najpopularnija boja je plava (0.00%%).");
	else
	printf("Najpopularnija boja je plava (%.2f%%).", prosjek);
}

return 0;

}
