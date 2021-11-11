#include <stdio.h>

int main() {
	char a;
	a=='m';
	int brc, brp, brv, brb, brs, u;
	brc=0; brb=0; brs=0; brv=0; brp=0; u=0;
	printf("Unesite vozila: ");
	do {
		scanf("%c", &a);
		if (a=='c' || a=='C') brc++;
		else if (a=='b' || a=='B') brb++;
		else if (a=='s' || a=='S') brs++;
		else if (a=='v' || a=='V') brv++;
		else if (a=='p' || a=='P') brp++;
		else if (a!='c' && a!='C' && a!='b' && a!='B' && a!='s' && a!='S' && a!='v' && a!='V' && a!='p' && a!='P' && a!='k' && a!='K') {
			printf("Neispravan unos\n");
	}
		else if (a=='k' || a=='K') break;
		
	}
	while (a!='k' && a!='K');
	double x;
	u = brc + brb + brs + brv + brp;
	printf("Ukupno evidentirano %d vozila.\n",u);
	if (u!=0) {
	if (brc>=brp && brc>=brv && brc>=brb && brc>=brs) {
		x = (brc*100.)/u;
		printf("Najpopularnija boja je crna (%.2f%%).", x);
	}
	else if (brb>=brc && brb>=brv && brb>=brs && brb>=brp) {
		x = (brb*100.)/u;
		printf("Najpopularnija boja je bijela (%.2f%%).", x);
	}
    else if (brs>=brp && brs>=brc && brs>=brb && brs>=brv) {
		x = (brs*100.)/u;
		printf("Najpopularnija boja je siva (%.2f%%).", x);
	}
    else if (brv>=brp && brv>=brb && brv>=brc && brv>=brs) {
		x = (brv*100.)/u;
		printf("Najpopularnija boja je crvena (%.2f%%).", x);
	}
	else if (brp>=brs && brp>=brv && brp>=brb && brp>=brc) {
		x = (brp*100.)/u;
		printf("Najpopularnija boja je plava (%.2f%%).", x);
	}
	}
	else if (u==0) {
	if (brc>=brp && brc>=brv && brc>=brb && brc>=brs) {
		printf("Najpopularnija boja je crna (0.00%%).");
	}
	else if (brb>=brc && brb>=brv && brb>=brs && brb>=brp) {
		printf("Najpopularnija boja je bijela (0.00%%).");
	}
    else if (brs>=brp && brs>=brc && brs>=brb && brs>=brv) {
		printf("Najpopularnija boja je siva (0.00%%).");
	}
    else if (brv>=brp && brv>=brb && brv>=brc && brv>=brs) {
		printf("Najpopularnija boja je crvena (0.00%%).");
	}
	else if (brp>=brs && brp>=brv && brp>=brb && brp>=brc) {
		printf("Najpopularnija boja je plava (0.00%%).");
	}
}
	/*printf("Zadaća 1, Zadatak 3");*/
	return 0;
}
