#include <stdio.h>

int main() {
	char vozilo=' ';
	int br=0;
	int brc=0,brb=0,brs=0,brv=0,brp=0;
	double procenat=0;
	printf("Unesite vozila: ");
	while(1){
	      scanf("%c", &vozilo);
	      if(vozilo=='K' || vozilo=='k') break;
	      else if(vozilo=='C' || vozilo=='c' || vozilo=='B' || vozilo=='b' || vozilo=='S' || vozilo=='s' || vozilo=='V' || vozilo=='v' || vozilo=='P' || vozilo=='p') br++;
	      else printf("Neispravan unos\n");
	      if(vozilo=='C' || vozilo=='c') brc++;
	      if(vozilo=='B' || vozilo=='b') brb++;
	      if(vozilo=='S' || vozilo=='s') brs++;
	      if(vozilo=='V' || vozilo=='v') brv++;
	      if(vozilo=='P' || vozilo=='p') brp++;
	}
	/*if((br==1 || (br%10)==1) && br!=11) printf("Ukupno evidentirano %d vozilo.\n", br);*/
	printf("Ukupno evidentirano %d vozila.\n", br);
	if(brc>=brb && brc>=brb && brc>=brs && brc>=brv && brc>=brp){
		if(brc==0) {printf("Najpopularnija boja je crna (%.2f%%).", procenat); return 0;}
		procenat=(brc*1./br)*100;
		printf("Najpopularnija boja je crna (%.2f%%).", procenat);
	}
	else if(brb>brc && brb>=brs && brb>=brv && brb>=brp){
		if(brb==0) {printf("Najpopularnija boja je bijela (%.2f%%).", procenat); return 0;}
		procenat=(brb*1./br)*100;
		printf("Najpopularnija boja je bijela (%.2f%%).", procenat);
	}
	else if(brs>brc && brs>brb && brs>=brv && brs>=brp){
		if(brs==0) {printf("Najpopularnija boja je siva (%.2f%%).", procenat); return 0;}
		procenat=(brs*1./br)*100;
		printf("Najpopularnija boja je siva (%.2f%%).", procenat);
	}
	else if(brv>brc && brv>brb && brv>brs && brv>=brp){
		if(brv==0) {printf("Najpopularnija boja je crvena (%.2f%%).", procenat); return 0;}
		procenat=(brv*1./br)*100;
		printf("Najpopularnija boja je crvena (%.2f%%).", procenat);
	}
	else if(brp>brc && brp>brb && brp>brs && brp>brv){
		if(brp==0) {printf("Najpopularnija boja je plava (%.2f%%).", procenat); return 0;}
		procenat=(brp*1./br)*100;
		printf("Najpopularnija boja je plava (%.2f%%).", procenat);
	}
	return 0;
}
