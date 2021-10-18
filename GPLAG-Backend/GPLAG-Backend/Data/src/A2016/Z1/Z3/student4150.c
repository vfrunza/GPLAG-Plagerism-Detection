#include <stdio.h>
int main() {
int brc=0,brauto=0,brb=0,brs=0,brv=0,brp=0;
float udioc=0, udiob=0,udios=0,udiov=0,udiop=0;
char boja;   

printf("Unesite vozila: ");

for(;;) {
	scanf("%c", &boja);
	if(boja>='A' && boja<='Z') boja+=32;
if(boja=='c') {
	brc++;
	brauto++;
	continue;
}
if(boja=='s') {
	brs++;
	brauto++;
	continue;
}
if(boja=='p') {
	brp++;
	brauto++;
	continue;
}
if(boja=='b') {
	brb++;
	brauto++;
	continue;
}
if(boja=='v') {
	brv++;
	brauto++;
	continue;
}
if(boja=='k') break;
else printf("Neispravan unos\n");

}


udioc+=(brc/(float)brauto)*100.0;
udiob+=(brb/(float)brauto)*100.0;
udios+=(brs/(float)brauto)*100.0;
udiov+=(brv/(float)brauto)*100.0;
udiop+=(brp/(float)brauto)*100.0;

printf("Ukupno evidentirano %d vozila.", brauto);
if(brc>0 && brc>=brb && brc>=brs && brc>=brv && brc>=brp) printf("\nNajpopularnija boja je crna (%.2f%%).",udioc);
if(brb>brc && brb>=brs && brb>=brv && brb>=brp) printf("\nNajpopularnija boja je bijela (%.2f%%).",udiob);
if(brs>brc && brs>brb && brs>=brv && brs>=brp) printf("\nNajpopularnija boja je siva (%.2f%%).",udios);
if(brv>brc && brv>brb && brv>brs && brv>=brp) printf("\nNajpopularnija boja je crvena (%.2f%%).",udiov);
if(brp>brc && brp>brb && brp>brv && brp>brs) printf("\nNajpopularnija boja je plava (%.2f%%).",udiop);
if(brc==0 && brs==0 && brp==0 && brv==0 && brb==0) printf("\nNajpopularnija boja je crna (0.00%%).");
	return 0;
} 
