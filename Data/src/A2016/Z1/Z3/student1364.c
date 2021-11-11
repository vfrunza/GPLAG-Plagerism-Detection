#include <stdio.h>

int main() {
	
	char boja='c';
	int broj_crna=0, broj_bijela=0, broj_siva=0, broj_crvena=0, broj_plava=0,brojac=0;
	
	printf("Unesite vozila: ");
	while (boja!='k' && boja!='K')
	{
		scanf ("%c", &boja);
	
		brojac++;
		if (boja=='c' || boja=='C')
		broj_crna++;
		else
		if (boja=='b' || boja=='B')
		broj_bijela++;
		else 
		if (boja=='s' || boja=='S') 
		broj_siva++;
		else 
		if (boja=='v' || boja=='V')
		broj_crvena++;
		else
		if (boja=='p' || boja=='P')
		broj_plava++;
		else
		if (boja==' ' || boja=='\n')
		{
			printf ("Neispravan unos\n");
			brojac--;
		}
		else if (boja=='k' || boja=='K')
		{
			brojac--;
			break;
			
		}
		else
		{
			printf ("Neispravan unos\n");
			brojac--;
		}
		
	}
	
	printf ("Ukupno evidentirano %d vozila.", brojac);
	if (brojac!=0)
	{
	if (broj_crna>=broj_crvena && broj_crna>=broj_plava && broj_crna>=broj_siva && broj_crna>=broj_bijela)
	printf ("\nNajpopularnija boja je crna (%.2f%%).", (float)broj_crna/(float)brojac*100);
	else
	if (broj_crvena>broj_crna && broj_crvena>=broj_plava && broj_crvena>broj_siva && broj_crvena>broj_bijela)
	printf ("\nNajpopularnija boja je crvena (%.2f%%).", (float)broj_crvena/(float)brojac*100);
	else
	if (broj_bijela>broj_crna && broj_bijela>=broj_plava && broj_bijela>=broj_siva && broj_crvena<broj_bijela)
	printf ("\nNajpopularnija boja je bijela (%.2f%%).", (float)broj_bijela/(float)brojac*100);
	else
	if (broj_siva>broj_crna && broj_siva>=broj_plava && broj_siva>=broj_crvena && broj_siva>broj_bijela)
	printf ("\nNajpopularnija boja je siva (%.2f%%).", (float)broj_siva/(float)brojac*100);
	else
	printf ("\nNajpopularnija boja je plava (%.2f%%).", (float)broj_plava/(float)brojac*100);
	}
	
	else
	printf ("\nNajpopularnija boja je crna (0.00%%).");
	
	return 0;
}
