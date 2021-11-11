#include <stdio.h>

int main() {
	char boja;
	int crna,bijela,siva,crvena,plava,suma;
	float udioboje;
	crna=0;
	bijela=0;
	siva=0;
	crvena=0;
	plava=0;
	printf ("Unesite vozila: ");
	do {
		scanf ("%c",&boja);
		if (boja=='c' || boja=='C')
			crna++;
	    	else if (boja=='B' || boja=='b')
				bijela++;
			else if (boja=='S' || boja=='s')
				siva++;
			else if (boja=='V' || boja=='v')
				crvena++;
	    	else if (boja=='P' || boja=='p')
				plava++;
			else if (boja=='K' || boja=='k')
			break;
			else if((boja!='c'|| boja!='C') || (boja!='b'|| boja!='B') || (boja!='s' ||	boja!='S')
			|| (boja!='v'|| boja!='V') || (boja!='p'||boja!='P') || (boja!='k'|| boja!='K')) { 
				printf("Neispravan unos\n");}
		}
	while(1==1);
	suma=crna+bijela+siva+crvena+plava;
	printf("Ukupno evidentirano %d vozila.\n",suma);
	if (suma==0) 
		{ printf ("Najpopularnija boja je crna (0.00%%).");
		return 0; }
		else if (crna>=bijela && crna>=siva && crna>=crvena && crna>=plava) 
			{ udioboje=(100.*crna)/suma;
			printf ("Najpopularnija boja je crna (%.2f%%).",udioboje);
			return 0; }
		else if (bijela>=crna && bijela>=siva && bijela>=crvena && bijela>=plava) 
			{ udioboje=(100.*bijela)/suma;
			printf ("Najpopularnija boja je bijela (%.2f%%).",udioboje);
			return 0; }
		else if (siva>=crna && siva>=bijela && siva>=crvena && siva>=plava) 
			{ udioboje=(100.*siva)/suma;
			printf ("Najpopularnija boja je siva (%.2f%%).",udioboje);
			return 0; }
		else if (crvena>=crna && crvena>=bijela && crvena>=siva && crvena>=plava) 
			{ udioboje=(100.*crvena)/suma;
			printf ("Najpopularnija boja je crvena (%.2f%%).",udioboje);
			return 0; }
		else if (plava>=crna && plava>=bijela && plava>=siva && plava>=crvena)
			{ udioboje=(100.*plava)/suma;
			printf ("Najpopularnija boja je plava (%.2f%%).",udioboje);
			return 0; }
	return 0;
}
