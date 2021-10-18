#include <stdio.h>
#include <math.h>

int main()
{
	char a;
	int bc=0, bb=0, bv=0, bs=0, bp=0, uk=0, x=0, rbc=0, rbb=0, rbv=0, rbs=0, rbp=0;
	float pc, pb, pv, ps, pp, ukp=0;
	printf("Unesite vozila: ");
	do {
		scanf("%c", &a);
		if((a!='c' && a!='C' && a!='b' && a!='B' && a!='v' && a!='V' && a!='s' && a!='S' && a!='p' && a!='P' && a!='k' && a!='K') ||  a==' ') {
			printf("Neispravan unos\n");
		}
		x++;

		if((a=='c' || a=='C') && rbc==0)
			rbc=x;
		else if((a=='b' || a=='B') && rbb==0)
			rbb=x;
		else if((a=='v' || a=='V') && rbv==0)
			rbv=x;
		else if((a=='s' || a=='S') && rbs==0)
			rbs=x;
		else if((a=='p' || a=='P') && rbp==0)
			rbp=x;
		if (a=='c' || a=='C')
			bc++;
		if (a=='b' || a=='B')
			bb++;
		if (a=='v' || a=='V')
			bv++;
		if (a=='s' || a=='S')
			bs++;
		if (a=='p' || a=='P')
			bp++;

	} while(a!='k' && a!='K');

	uk=bp+bs+bv+bb+bc;
	ukp=uk;
	if(uk!=0){
	pc=(bc/ukp)*100;
	pv=(bv/ukp)*100;
	pb=(bb/ukp)*100;
	ps=(bs/ukp)*100;
	pp=(bp/ukp)*100;
	}
	else{
	pc=0;
	pv=0;
	pb=0;
	ps=0;
	pp=0;	
	}

	printf("Ukupno evidentirano %d vozila.\n", uk);
	if(uk==0)
		printf("Najpopularnija boja je crna (%.2f%%).", pc);
	else if((bc>bs || (bc==bs && rbc<rbs)) && (bc>bv || (bc==bv && rbc<rbv)) && (bc>bb || (bc==bb && rbc<rbb)) && (bc>bp || (bc==bp && rbc<rbp)))
		printf("Najpopularnija boja je crna (%.2f%%).", pc);
	else if((bs>bc || (bs==bc && rbs<rbc)) && (bs>bv || (bs==bv && rbs<rbv)) && (bs>bb || (bs==bb && rbs<rbb)) && (bs>bp || (bs==bp && rbs<rbp)))
		printf("Najpopularnija boja je siva (%.2f%%).", ps);
	else if((bv>bs || (bv==bs && rbv<rbs)) && (bv>bc || (bv==bc && rbv<rbc)) && (bv>bb || (bv==bb && rbv<rbb)) && (bv>bp || (bv==bp && rbv<rbp)))
		printf("Najpopularnija boja je crvena (%.2f%%).", pv);
	else if((bb>bs || (bb==bs && rbb<rbs)) && (bb>bv || (bb==bv && rbb<rbv)) && (bb>bc || (bb==bc && rbb<rbc)) && (bb>bp || (bb==bp && rbb<rbp)))
		printf("Najpopularnija boja je bijela (%.2f%%).", pb);
	else if((bp>bs || (bp==bs && rbp<rbs)) && (bp>bv || (bp==bv && rbp<rbv)) && (bp>bb || (bp==bb && rbp<rbb)) && (bp>bc || (bp==bc && rbp<rbc)))
		printf("Najpopularnija boja je plava (%.2f%%).", pp);
	return 0;
}
