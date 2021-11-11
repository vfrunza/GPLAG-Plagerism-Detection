#include <stdio.h>

int main() {
	char m='a';int i=0,c=0,b=0,s=0,v=0,p=0;double pc=0.,pb=0.,ps=0.,pv=0.,pp=0.,j;
	printf("Unesite vozila: ");
	while (m!='k' && m!='K'){
		scanf("%c",&m);
		if(m!='c' && m!='C'&& m!='b' && m!='B'&&m!='s' &&m!='S'&&m!='v' && m!='V'&&m!='p' && m!='P'){
			if(m!='k' && m!='K'){
			printf("Neispravan unos\n");continue;}
			else break;
		}
		if(m=='c' || m=='C')c++;
		if(m=='b' || m=='B')b++;
		if(m=='s' || m=='S')s++;
		if(m=='v' || m=='V')v++;
		if(m=='p' || m=='P')p++;
		i++;
	}
	j=i;
	if(c==0)pc=0.;
	else pc=(c*100/j);
	if(b==0)pb=0.;
	else pb=(b*100/j);
	if(s==0)ps=0.;
	else ps=(s*100/j);
	if(v==0)pv=0.;
	else pv=(v*100/j);
	if(p==0)pp=0.;
	else pp=(p*100/j);
	printf("Ukupno evidentirano %d vozila.\n",i);
	if(pc>=pb && pc>=ps && pc>=pv && pc>=pp )printf("Najpopularnija boja je crna (%.2f%%).",pc);
	else if(pb>pc && pb>=ps && pb>=pv && pb>=pp )printf("Najpopularnija boja je bijela (%.2f%%).",pb);
	else if(ps>pb && ps>pc && ps>=pv && ps>=pp)printf("Najpopularnija boja je siva (%.2f%%).",ps);
	else if(pv>pb && pv>ps && pv>pc && pv>=pp)printf("Najpopularnija boja je crvena (%.2f%%).",pv);
	else if(pp>pb && pp>ps && pp>pv && pp>pc)printf("Najpopularnija boja je plava (%.2f%%).",pp);
	return 0;
}
