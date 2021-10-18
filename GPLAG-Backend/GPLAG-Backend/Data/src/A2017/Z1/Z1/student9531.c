#include <stdio.h>
#define PR 6.80
#define PF 8.00
#define PB 5.30
#define HR 3.30
#define HF 3.00
#define HB 5.00
#define CR 5.00
#define CF 3.90
#define CB 6.00
int main()
{
	char ta, mi, bo, nr;
	float cr, cf, cb, min, posp, posh, posc, cpopp, cpoph, cpopc, minpop;
	int brp=0, brh=0, brc=0;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &ta);
	scanf("%c", &nr);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bo);
	scanf("%c", &nr);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mi);
	scanf("%c", &nr);
	switch(ta) {
	case 'P':
		brp++;
		break;
	case 'H':
		brh++;
		break;
	case 'C':
		brc++;
		break;
	}
	switch(bo) {
	case 'P':
		brp++;
		break;
	case 'H':
		brh++;
		break;
	case 'C':
		brc++;
		break;
	}
	switch(mi) {
	case 'P':
		brp++;
		break;
	case 'H':
		brh++;
		break;
	case 'C':
		brc++;
		break;
	}
	cr=(brp*PR)+(brh*HR)+(brc*CR);
	cf=(brp*PF)+(brh*HF)+(brc*CF);
	cb=(brp*PB)+(brh*HB)+(brc*CB);
	min=cr;
	if(cf<min) {
		min=cf;
		printf("Najjeftiniji je Fast-food \"Trovac\" (""%.2f"" KM).", min);
	}
	if(cb<min) {
		min=cb;
		printf("Najjeftiniji je Bistro \"Lorelei\" (""%.2f"" KM).", min);
	}
	if(cr<=min) {
		min=cr;
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (""%.2f"" KM).", min);
	}
	posp=(PR*10)/100;
	posh=(HR*10)/100;
	posc=(CR*10)/100;
	cpopp=((brp*PR)+(brh*HR)+(brc*CR))-(posp*brp);
	cpoph=((brp*PR)+(brh*HR)+(brc*CR))-(posh*brh);
	cpopc=((brp*PR)+(brh*HR)+(brc*CR))-(posc*brc);
	minpop=cpopp;
	if(cpoph<minpop)
		minpop=cpoph;
	if(cpopc<minpop)
		minpop=cpopc;
	if(cpopp<=minpop)
		minpop=cpopp;
	if(min==cr)
		return 0;
	else {
		if(minpop<min)
			printf("\nSa popustom bi Restoran bio jeftiniji (""%.2f"" KM).", minpop);
	}
	return 0;
}
