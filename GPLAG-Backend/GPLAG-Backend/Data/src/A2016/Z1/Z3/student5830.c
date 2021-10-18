#include <stdio.h>
int main() {
	char a;
	int bc=0,bb=0,bs=0,bv=0,bp=0,v=0;
	float pc,pb,ps,pv,pp,n;
	printf("Unesite vozila: ");
	do
	{
		scanf("%c",&a);
		if(a!='C' && a!='c' && a!='B' && a!='b' && a!='s' && a!='S' && a!='P' && a!='p' && a!='V' && a!='v' && a!='K' && a!='k')
		{
			printf("Neispravan unos\n");
		}
	if (a=='C'	|| a=='c')
	{
		bc++;v++;
	}
	if (a=='B'	|| a=='b')
	{
		bb++;v++;
	}
	if (a=='S'	|| a=='s')
	{
		bs++;v++;
	}
	if (a=='P'	|| a=='p')
	{
		bp++;v++;
	}
	if (a=='V'	|| a=='v')
	{
		bv++;v++;
	}
	}
    while(a!='k' && a!='K');
    pc=((float)bc/v)*100;
    pb=((float)bb/v)*100;
    ps=((float)bs/v)*100;
    pp=((float)bp/v)*100;
    pv=((float)bv/v)*100;
    printf("Ukupno evidentirano %d vozila.\n",v);
    if (v==0){printf ("Najpopularnija boja je crna (0.00%).");}
    if (pc>=pb && pc>=ps && pc>=pp && pc>=pv){printf("Najpopularnija boja je crna (%.2f%).",pc);return 0;}
    if (pb>=pc && pb>=ps && pb>=pp && pb>=pv){printf("Najpopularnija boja je bijela (%.2f%).",pb);return 0;}
    if (ps>=pb && ps>=pc && ps>=pp && ps>=pv){printf("Najpopularnija boja je siva (%.2f%).",ps);return 0;}
    if (pv>=pb && pv>=ps && pv>=pp && pv>=pc){printf("Najpopularnija boja je crvena (%.2f%).",pv);return 0;}
    if (pp>=pb && pp>=ps && pp>=pc && pp>=pv){printf("Najpopularnija boja je plava (%.2f%).",pp);return 0;}
    return 0;
}