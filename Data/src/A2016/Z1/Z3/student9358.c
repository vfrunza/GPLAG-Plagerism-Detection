#include <stdio.h>

int main() {
	char boja_auto='a';
	int brojc=0,brojp=0,brojv=0,brojb=0,brojs=0,brojuk=0;
	float pc,pb,ps,pv,pp;
	printf("Unesite vozila: ");
	while(boja_auto!='k' && boja_auto!='K')
	{
		scanf("%c",&boja_auto);
		if(boja_auto!='c' && boja_auto!='C' && boja_auto!='b' && boja_auto!='B' && boja_auto!='s' && boja_auto!='S' && boja_auto!='V' && boja_auto!='v' && boja_auto!='p' && boja_auto!='P' && boja_auto!='k' && boja_auto!='K') {printf("Neispravan unos\n"); continue;}
		if(boja_auto=='c' || boja_auto=='C') brojc++;
		if(boja_auto=='b' || boja_auto=='B') brojb++;
		if(boja_auto=='s' || boja_auto=='S') brojs++;
		if(boja_auto=='v' || boja_auto=='V') brojv++;
		if(boja_auto=='p' || boja_auto=='P') brojp++;
		brojuk=brojc+brojp+brojv+brojb+brojs;
		if(brojuk==0)
		{
			printf("Ukupno evidentirano 0 vozila. \nNajpopularnija boja je crna (0.00%).");
			return 0;
			
		}
		pc=((float)brojc/(float)brojuk)*100;
		pb=((float)brojb/(float)brojuk)*100;
		ps=((float)brojs/(float)brojuk)*100;
		pv=((float)brojv/(float)brojuk)*100;
		pp=((float)brojp/(float)brojuk)*100;
		
	}
	printf("Ukupno evidentirano %d vozila.\n",brojuk);
	if(pc>=pb && pc>=ps && pc>=pv && pc>=pp) printf("Najpopularnija boja je crna (%.2f%%).",pc);
	else if(pb>pc && pb>=ps && pb>=pv && pb>=pp) printf("Najpopularnija boja je bijela (%.2f%%).",pb);
	else if(ps>pb && ps>pc && ps>=pv && ps>=pp) printf("Najpopularnija boja je siva (%.2f%%).",ps);
	else if(pv>pc && pv>pb && pv>ps && pv>=pp) printf("Najpopularnija boja je crvena (%.2f%%).",pv);
	else if(pp>pc && pp>pb && pp>ps && pp>pv) printf("Najpopularnija boja je plava (%.2f%%).",pp);
	return 0;
}
