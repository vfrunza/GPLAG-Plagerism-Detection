#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
char boja,znak='%';
int brc=0,brb=0,brs=0,brv=0,brp=0,zbir=0;
float max,null=0;
int i=0;
printf("Unesite vozila: ");
for(i=0;i<100000;i++){
	scanf("%c",&boja);
	if(boja=='k'||boja=='K') {  break;}
	else if(boja!='C' && boja!='c' && boja!='B'&& boja!='b'&& boja!='S'&& boja!='s' && boja!='P' && boja!='p'&&boja!='v'&&boja!='V') printf("Neispravan unos \n");
	else if(boja=='C'|| boja=='c') brc++;
	else if(boja=='B'|| boja=='b') brb++;
	else if(boja=='S'|| boja=='s') brs++;
	else if(boja=='P'|| boja=='p') brp++;
	else if(boja=='V'|| boja=='v') brv++;
}
zbir=brc+brb+brs+brp+brv;
printf("Ukupno evidentirano %d vozila. \n",zbir);
if(zbir==0) {printf("Najpopularnija boja je crna (%.2f%c).",null,znak); return 0;}
if ((brc>=brb)&&(brc>=brs)&&(brc>=brp)&&(brc>=brv)){
	max = brc;
	printf("Najpopularnija boja je crna (%.2f%c).",(max/zbir)*100,znak);
}
else if ((brb>brc)&&(brb>=brs)&&(brb>=brv)&&(brb>=brp)){
	max=brb;
	printf("Najpopularnija boja je bijela (%.2f%c).",(max/zbir)*100,znak);
	
}
else if((brs>brc)&&(brs>brb)&&(brs>=brv)&&(brs>=brp)){
	max=brs;
	printf("Najpopularnija boja je siva (%.2f%c).",(max/zbir)*100,znak);
}
else if((brv>brc)&&(brv>brb)&&(brv>brs)&&(brv>=brp)){
	max=brv;
	printf("Najpopularnija boja je crvena (%.2f%c).",(max/zbir)*100,znak);
}
else if((brp>brc)&&(brp>brb)&&(brp>brs)&&(brp>brv)){
	max=brp;
	printf("Najpopularnija boja je plava (%.2f%c).",(max/zbir)*100,znak);
}
	return 0;
}
