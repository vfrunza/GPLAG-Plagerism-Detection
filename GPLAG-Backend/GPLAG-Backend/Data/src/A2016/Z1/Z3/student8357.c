#include <stdio.h>
#include <math.h>

int main() {
	float Bijela=0, Siva=0, Crna=0, Crvena=0, Plava=0, pb=0.0, ps=0.0, pc=0.0, pv=0.0, pp=0.0, ukv;
	char c;
	printf("Unesite vozila: ");
	do { 
		scanf("%c", &c);
		while(c=='\n' ){
			scanf("%c",&c);
		}
		if ((c=='c')||(c=='C')){Crna++; continue;}
		if ((c=='b')||(c=='B')){Bijela++; continue;}
		if ((c=='s')||(c=='S')){Siva++; continue;}
		if ((c=='v')||(c=='V')){Crvena++; continue;}
		if ((c=='p')||(c=='P')){Plava++; continue;}
		if ((c != 'c') && (c != 'C') && (c != 'B') && (c !='b')&&(c != 's') && (c !='S')&&(c != 'V') && (c !='v')&&(c != 'p') && (c !='P')&&(c!='k')&&(c!='K')){
			printf ("Neispravan unos\n");
			continue;
		}
	} while (c!='K' && c!='k');
	ukv=Bijela+Siva+Crna+Crvena+Plava;
	pc=Crna*100/ukv;
	pb=Bijela*100/ukv;
	ps=Siva*100/ukv;
	pv=Crvena*100/ukv;
	pp=Plava*100/ukv;
	printf ("Ukupno evidentirano %g vozila. \n",ukv);
	if(ukv==0){printf ("Najpopularnija boja je crna (0.00%%).");
		return 0;
	}
	if (Crna>=Bijela && Crna>=Siva && Crna>=Crvena && Crna>=Plava){printf ("Najpopularnija boja je crna (%.2f%%).",pc);
		return 0;
	}	if (Bijela>=Crna && Bijela>=Siva && Bijela>=Crvena && Bijela>=Plava){printf ("Najpopularnija boja je bijela (%.2f%%).",pb);
		return 0;
	}	if (Siva>=Crna && Siva>=Bijela && Siva>=Crvena && Siva>=Plava){printf ("Najpopularnija boja je siva (%.2f%%).",ps);
		return 0;
	}	if (Crvena>=Crna && Crvena>=Siva && Crvena>=Bijela && Crvena>=Plava){printf ("Najpopularnija boja je crvena (%.2f%%).",pv);
		return 0;
	}	if (Plava>=Crna && Plava>=Siva && Plava>=Crvena && Plava>=Bijela){printf ("Najpopularnija boja je plava (%.2f%%).",pp);
		return 0;
	}
	return 0;
}