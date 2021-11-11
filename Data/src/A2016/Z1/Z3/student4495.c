#include <stdio.h>

int main() {
	char ba;
	float ub=0,bc=0,bb=0,bs=0,bv=0,bp=0,bpop=0;
	double pst;
	
	printf("Unesite vozila: ");
	
	do{
		scanf("%c",&ba);
		
		if(ba!='C' &ba!='c' & ba!='B'  &ba!='b'  & ba!='S'  & ba!='s' & ba!='V' & ba!='v'  & ba!='P'  & ba!='p'  & ba!='K'  & ba!='k')
			printf("Neispravan unos\n");
		else if (ba=='K' || ba=='k')
			break;
		else {
			if(ba=='C' || ba=='c')
			bc++;
		else if(ba=='B' || ba=='b')
			bb++;
		else if(ba=='S' || ba=='s')
			bs++;
		else if(ba=='V' || ba=='v')
			bv++;
		else if(ba=='P' || ba=='p' )
			bp++;
			
			
			ub++;
			
		}
		
		
		
	}while(ba!='K'&& ba!='k');

	
		
		bpop=bp;
		if(bpop<=bv)
			bpop=bv;
		if(bpop<=bs)
			bpop=bs;
		if(bpop<=bb)
			bpop=bb;
		if(bpop<=bc)
			bpop=bc;
		
		if(ub==0.0)
			pst=0.0;
		else 
		pst=(bpop/ub)*100;
		
		printf("Ukupno evidentirano %g vozila.\n",ub);
		
		if(bpop==bc)
			printf("Najpopularnija boja je crna (%.2f%%).",pst);
		else if(bpop==bb)
			printf("Najpopularnija boja je bijela (%.2f%%).",pst);
		else if (bpop==bs)
			printf("Najpopularnija boja je siva (%.2f%%).",pst);
		else if (bpop==bv)
			printf("Najpopularnija boja je crvena (%.2f%%).",pst);
		else printf ("Najpopularnija boja je plava (%.2f%%).",pst);
		
		
		
		
		

	return 0;
}
