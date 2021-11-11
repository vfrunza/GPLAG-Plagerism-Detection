#include <stdio.h>
int main()
{
	float c=0,b=0,s=0,p=0,v=0;
	float uv=0,pc=0.0,pv=0.0,pb=0.0,ps=0.0,pp=0;
	char suma;
	printf("Unesite vozila: ");
	do {
		scanf("%c",&suma);

		if((suma=='c')||(suma=='C')) {
			c++;
			continue;
		}
		if((suma=='b')||(suma=='B')) {
			b++;
			continue;
		}
		if((suma=='S')||(suma=='s')) {
			s++;
			continue;
		}
		if((suma=='v')||(suma=='V')) {
			v++;
			continue;
		}
		if((suma=='p')||(suma=='P')) {
			p++;
			continue;
		}
		if ((suma!='S') && (suma!='s') && (suma!='b') && (suma!='B') && (suma!='C') && (suma!='c') && (suma!='V') && (suma!='v') && (suma!='P') && (suma!='p') && (suma!='k') && (suma!='K')) {
			printf("Neispravan unos\n");
		}
	} while((suma!='K') && (suma!='k'));

	uv=c+b+s+v+p;

	printf ("Ukupno evidentirano %g vozila.\n" ,uv);
	if(uv!=0) {
		pc=(c*100)/uv;
		pb=(b*100)/uv;
		pv=(v*100)/uv;
		ps=(s*100)/uv;
		pp=(p*100)/uv;
	}

	if(pc>=pb && pc>=pv && pc>=pp && pc>=ps) {
		printf("Najpopularnija boja je crna (%.2f%%).",pc);


	}

	else if(pb>=pc && pb>=pv && pb>=pp && pb>=ps) {
		printf("Najpopularnija boja je bijela (%.2f%%).",pb);

	} else if(ps>=pc && ps>=pv && ps>=pp && ps>=pb) {
		printf("Najpopularnija boja je siva (%.2f%%).",ps);


	}

	else if(pv>=pc && pv>=pb && pv>=pp && pv>=ps) {
		printf("Najpopularnija boja je crvena (%.2f%%).",pv);


	} else if(pp>pc && pp>pv && pp>pb && pp>ps) {
		printf("Najpopularnija boja je plava (%.2f%%).",pp);


	}

	return 0;

}