#include <stdio.h>
#include <math.h>

int main() {
	float B=0, S=0, C=0, V=0, P=0, pb=0.0, ps=0.0, pc=0.0, pv=0.0, pp=0.0, ubv;
	char boja;
	printf("Unesite vozila: ");
	do { 
		scanf("%c", &boja);
		while(boja=='\n' ){
			scanf("%c",&boja);
		}
		if ((boja=='c')||(boja=='C')){C++; continue;}
		if ((boja=='b')||(boja=='B')){B++; continue;}
		if ((boja=='s')||(boja=='S')){S++; continue;}
		if ((boja=='v')||(boja=='V')){V++; continue;}
		if ((boja=='p')||(boja=='P')){P++; continue;}
		if ((boja != 'c') && (boja != 'C') && (boja != 'B') && (boja !='b')&&(boja != 's') && (boja !='S')&&(boja != 'V') && (boja !='v')&&(boja != 'p') && (boja !='P')&&(boja!='k')&&(boja!='K')){
			printf ("Neispravan unos\n");
			continue;
		}
	} while (boja!='K' && boja!='k');
	ubv=B+S+C+V+P;
	pc=C*100/ubv;
	pb=B*100/ubv;
	ps=S*100/ubv;
	pv=V*100/ubv;
	pp=P*100/ubv;
	printf ("Ukupno evidentirano %g vozila. \n",ubv);
	if(ubv==0){printf ("Najpopularnija boja je crna (0.00%%).");
		return 0;
	}
	if (C>=B && C>=S && C>=V && C>=P){printf ("Najpopularnija boja je crna (%.2f%%).",pc);
		return 0;
	}	if (B>=C && B>=S && B>=V && B>=P){printf ("Najpopularnija boja je bijela (%.2f%%).",pb);
		return 0;
	}	if (S>=C && S>=B && S>=V && S>=P){printf ("Najpopularnija boja je siva (%.2f%%).",ps);
		return 0;
	}	if (V>=C && V>=S && V>=B && V>=P){printf ("Najpopularnija boja je crvena (%.2f%%).",pv);
		return 0;
	}	if (P>=C && P>=S && P>=V && P>=B){printf ("Najpopularnija boja je plava (%.2f%%).",pp);
		return 0;
	}
	return 0;
}

