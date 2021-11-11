#include <stdio.h>

int main() {
	int brc=0, brb=0, brs=0, brcr=0, brp=0, br=0;
	float posto=0, max=0;
	char a;
	printf("Unesite vozila: ");
	while(0==0)
	{
		scanf("%c", &a);
		if(a=='K' || a=='k' ) { break;}
		else if(a=='B' || a=='b') { brb++;}
		else if(a=='S' || a=='s') { brs++;}
		else if(a=='V' || a=='v') { brcr++;}
		else if(a=='P' || a=='p') { brp++;}
		else if(a=='C' || a=='c') {  brc++; }
		else printf("Neispravan unos\n");
	}
	br=brb+brs+brcr+brp+brc;
	if(brc>=brb && brc>=brs && brc>=brcr && brc>=brp) max=brc;
	else if(brb>=brc && brb>=brs && brb>=brcr && brb>=brp) max=brb;
	else if(brs>=brb && brs>=brc && brs>=brcr && brs>=brp) max=brs;
	else if(brcr>=brb && brcr>=brs && brcr>=brc && brcr>=brp) max=brcr;
	else if(brp>=brb && brp>=brs && brp>=brcr && brp>=brc) max=brp;
	posto=(max/br)*100;
	printf("Ukupno evidentirano %d vozila.\n", br);
	if(br==0) posto=0;
	if(max==brc) printf("Najpopularnija boja je crna (%.2f%%).", posto);
	else if(max==brb) printf("Najpopularnija boja je bijela (%.2f%%).", posto);
	else if(max==brs) printf("Najpopularnija boja je siva (%.2f%%).", posto);
	else if(max==brcr) printf("Najpopularnija boja je crvena (%.2f%%).", posto);
	else if(max==brp) printf("Najpopularnija boja je plava (%.2f%%).", posto);

	return 0;
}
