#include <stdio.h>

int main() {
	int ic=0,ib=0,is=0,iv=0,ip=0,i=0;
	double pc,pb,ps,pv,pp;
	char c;
	printf("Unesite vozila: ");
	do {
		scanf("%c",&c);
		if((c=='c' || c=='C' || c=='b' || c=='B' || c=='s' || c=='S' || c=='v' || c=='V' || c=='p' || c=='P') && c!='k' && c!='K'){
			i++;
		    if(c=='c' || c=='C') ic++;
			if(c=='b' || c=='B') ib++;
		    if(c=='s' || c=='S') is++;
		    if(c=='v' || c=='V') iv++;
		    if(c=='p' || c=='P') ip++;
		   } else if(c!='k' && c!='K') printf("Neispravan unos\n");
	}while(c!='k' && c!='K');
	printf("Ukupno evidentirano %d vozila.",i);
	if(i==0) pc=0.;
	else {
	pc=100./i*ic;
	pb=100./i*ib;
	ps=100./i*is;
	pv=100./i*iv;
	pp=100./i*ip;
	}
	if(ic>=ib && ic>=is && ic>=iv && ic>=ip) printf("\nNajpopularnija boja je crna (%.2f%%).",pc);
	else if(ib>ic && ib>=is && ib>=iv && ib>=ip) printf("\nNajpopularnija boja je bijela (%.2f%%).",pb);
	else if(is>ic && is>ib && is>=iv && is>=ip) printf("\nNajpopularnija boja je siva (%.2f%%).",ps);
	else if(iv>ic && iv>ib && iv>is && iv>=ip) printf("\nNajpopularnija boja je crvena (%.2f%%).",pv);
	else if(ip>ic && ip>ib && ip>is && ip>iv) printf("\nNajpopularnija boja je plava (%.2f%%).",pp);
	else if(ic==0 && ib==0 && is==0 && iv==0 && ip==0) printf("\nNajpopularnija boja je crna (%.2f%%).",pc);
	return 0;
}
