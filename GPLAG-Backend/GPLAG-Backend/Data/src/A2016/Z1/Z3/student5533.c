#include <stdio.h>

int main() {
	int broj_automobila=0, broj_crnih=0, broj_bijelih=0, broj_sivih=0, broj_crvenih=0, broj_plavih=0;
	float procenat=0, najveci=0;
	char slovo='a';
	printf("Unesite vozila: ");
	while(1)
	{
		
		if (slovo=='K' || slovo=='k')
		    break;
		scanf ("%c", &slovo);
	    if (slovo=='c' || slovo=='C')
		    broj_crnih++;
	    else if (slovo=='b' || slovo=='B')
		    broj_bijelih++;
	    else if (slovo=='s' || slovo=='S')
		    broj_sivih++;
	    else if (slovo=='v' || slovo=='V')
		    broj_crvenih++;
	    else if (slovo=='p' || slovo=='P')
		    broj_plavih++;
		else if (slovo!='C' && slovo!='c' && slovo!= 'B' && slovo!='b' && slovo!='S' && slovo!='s' && slovo!='V' && slovo!='v' && slovo!='P' && slovo!='p' && slovo!='K' && slovo!='k' && slovo!='\n')
		 {   printf ("Neispravan unos\n"); continue; } }
		broj_automobila=broj_crnih+broj_bijelih+broj_sivih+broj_crvenih+broj_plavih;
		    printf ("Ukupno evidentirano %d vozila.\n", broj_automobila);
		if (broj_crnih>=broj_bijelih && broj_crnih>=broj_sivih && broj_crnih>= broj_crvenih && broj_crnih>=broj_plavih)
		{    
			najveci=broj_crnih*1.0;
			procenat=(najveci/broj_automobila)*100;
			if (broj_automobila==0)
			procenat=0;
			printf ("Najpopularnija boja je crna (%.2f%%).", procenat);
		}
		else if (broj_bijelih>broj_crnih && broj_bijelih>=broj_sivih && broj_bijelih>=broj_crvenih && broj_bijelih>=broj_plavih)
		{
			najveci=broj_bijelih*1.0;
			procenat=(najveci/broj_automobila)*100;
			if (broj_automobila==0) procenat=0;
			printf ("Najpopularnija boja je bijela (%.2f%%).", procenat);
		}
		else if (broj_sivih>broj_crnih && broj_sivih>broj_bijelih && broj_sivih>=broj_crvenih && broj_sivih>=broj_plavih)
		{
			najveci=broj_sivih*1.0;
			procenat=(najveci/broj_automobila)*100;
			if (broj_automobila==0) procenat=0;
			printf ("Najpopularnija boja je siva (%.2f%%).", procenat);
		}
		else if (broj_crvenih>broj_crnih && broj_crvenih>broj_bijelih && broj_crvenih>broj_sivih && broj_crvenih>=broj_plavih)
		{
			najveci=broj_crvenih*1.0;
			procenat=(najveci/broj_automobila)*100;
			if (broj_automobila==0) procenat=0;
			printf ("Najpopularnija boja je crvena (%.2f%%).", procenat);
		}
		else 
		{
			najveci=broj_plavih*1.0;
			procenat=(najveci/broj_automobila)*100;
			if (broj_automobila==0) procenat=0;
			printf ("Najpopularnija boja je plava (%.2f%%).", procenat);
			
		}
		
		    
		
		 
	
	return 0;
}
