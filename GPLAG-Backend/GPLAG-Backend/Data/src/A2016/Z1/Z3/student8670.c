#include <stdio.h>
int main() {
	char l;
	int uA=0, cU=0, bU=0, sU=0, pU=0, rU=0;
	float Najp;
	printf("Unesite vozila: ");
	for (;;){
		scanf("%c", &l);
		if(l=='K' || l=='k')  break;
		if(l!='K' && l!='k') {
			if(l=='C' || l=='c') { uA=uA+1; cU=cU+1;
			} else if (l=='B'|| l=='b') { uA=uA+1; bU=bU+1;
			} else if(l=='S' || l=='s') { uA=uA+1; sU=sU+1;
			} else if(l=='P' || l=='p') { uA=uA+1; pU=pU+1;
			} else if(l=='V' || l=='v') { uA=uA+1; rU=rU+1;
			} else { printf("Neispravan unos \n");
			}
			}
	}
	printf ("Ukupno evidentirano %d vozila.\n", uA); 
	if(uA==0) { printf("Najpopularnija boja je crna (0.00%).", Najp); } else 
	if(cU>=sU && cU>=bU && cU>=pU && cU>=rU) { Najp=(cU*(float)100)/uA;
	printf("Najpopularnija boja je crna (%.2f%).", Najp); } else if (bU>=cU && bU>=sU && bU>=pU && bU>=rU) { Najp=(bU*(float)100)/uA;
	printf("Najpopularnija boja je bijela (%.2f%).", Najp);} else if (sU>=cU && sU>=bU && sU>=pU && sU>=rU) { Najp=(sU*(float)100)/uA;
	printf("Najpopularnija boja je siva (%.2f%).", Najp); } else if (pU>=cU && pU>=bU && pU>=sU && pU>=rU) { Najp=(pU*(float)100)/uA;
	printf("Najpopularnija boja je plava (%.2f%).", Najp); } else { Najp=(rU*(float)100)/uA;
	printf("Najpopularnija boja je crvena (%.2f%).", Najp); }
	return 0;
	}
