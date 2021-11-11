#include <stdio.h>

int main() {
	char n;
	int suma;
	int brc,brv,brp,brb,brs;
	float a;
	printf("Unesite vozila: ");
	brc=0;
	brv=0;
	brp=0;
	brs=0;
	brb=0;
	suma=0;
	while(1<2){
		scanf("%c",&n);
		if(n=='c' || n=='C')brc++;
		else if(n=='b' || n=='B')brb++;
		else if(n=='s' || n=='S')brs++;
		else if(n=='v' || n=='V')brv++;
		else if(n=='p' || n=='P')brp++;
		else if(n=='k' || n=='K')break;
		else printf("Neispravan unos\n");
	}
	suma=brp+brs+brv+brb+brc;
	printf("Ukupno evidentirano %d vozila.\n",suma);
	if(brc>=brb && brc>=brs && brc>=brv && brc>=brp) {
		if(brc==0) a=0;
		else
		a=((float)brc/suma)*100;
		printf("Najpopularnija boja je crna (%.2f%%).",a);
	}
	else if(brb>brc && brb>=brs && brb>=brv && brb>=brp){
		if(brb==0) a=0;
		else
		a=((float)brb/suma)*100;
		printf("Najpopularnija boja je bijela (%.2f%%).",a);
	}
	else if(brs>brc && brs>brb && brs>=brv && brs>=brp){
		if(brs==0) a=0;
		else
		a=((float)brs/suma)*100;
		printf("Najpopularnija boja je siva (%.2f%%).",a);
	}
	else if(brv>brc && brv>brb && brv>brs && brv>=brp){
		if(brv==0) a=0;
		a=((float)brv/suma)*100;
		printf("Najpopularnija boja je crvena (%.2f%%).",a);
	}
	else {
		if(brp==0) a=0;
		else
		a=((float)brp/suma)*100;
		printf("Najpopularnija boja je plava (%.2f%%).",a);
	}
	return 0;
}
