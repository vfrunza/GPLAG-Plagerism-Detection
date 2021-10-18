#include <stdio.h>

int main() {
	char C;
	int br=-1, brc=0,brb=0,brs=0,brv=0,brp=0;
	float c1,b1,s1,v1,p1, br1;
printf("Unesite vozila: ");
	while (1)
	{
		scanf("%c", &C);  
		if (C=='c' || C=='C') brc++; 
		if (C=='b' || C=='B') brb++; 
		if (C=='s' || C=='S') brs++; 
		if (C=='v' || C=='V') brv++; 
		if (C=='p' || C=='P') brp++; 

	 if(C!='c' && C!='C' &&C!='b'&&C!='B'&&C!='s' && C!='S' &&C!='v'&&C!='V'&&C!='p'&&C!='P' && C!='k' && C!='K')  printf("Neispravan unos\n");
	 else br++;
	 if(C=='k' || C=='K') break; 
	 
	}
	printf("Ukupno evidentirano %d vozila.\n",br);
	br1=brc+brb+brs+brv+brp;
	if (br1==0) {printf("Najpopularnija boja je crna (0.00%%)."); return 0;}
	 if (brc>=brb && brc>=brs && brc>=brv && brc>=brp) { c1=(brc/br1)*100; printf("Najpopularnija boja je crna (%.2f%%).",c1);}
	 if (brb>brc && brb>=brs && brb>=brv && brb>=brp) { b1=(brb/br1)*100; printf("Najpopularnija boja je bijela (%.2f%%).",b1);}
	 if (brs>brc && brs>brb && brs>=brv && brs>=brp) { s1=(brs/br1)*100; printf("Najpopularnija boja je siva (%.2f%%).",s1);}
	 if (brv>brc && brv>brs && brv>brb && brv>=brp) { v1=(brv/br1)*100; printf("Najpopularnija boja je crvena (%.2f%%).",v1);}
	 if (brp>brc && brp>brs && brp>brv && brp>brb) { p1=(brp/br1)*100; printf("Najpopularnija boja je plava (%.2f%%).",p1);}



	return 0;
}
