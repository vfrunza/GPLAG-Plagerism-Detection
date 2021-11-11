#include <stdio.h>
#define crna
#define bijela
#define siva
#define crvena
#define plava

int main() {
	char u;               \\\\
	int i,n,br,C,B,S,V,P,pc,pb,ps,pv,pp;
	double npa;
	
	printf("Unesite boju auta: ");
	for (i=0;i<n;i++)
	{
		n=n++;
	scanf ("%c", &u);
	if (u!='C' or u!='c')
	{
		printf("Neispravan unos!"); 
		else (br=++)&&(C++);
	}
	if (u!='B' or u!='b')
	{
		printf("Neispravan unos!"); 
		else (br=++)&&(B++);
	}
	if (u!='S' or u!='s')
	{
		printf("Neispravan unos!"); 
		else (br=++)&&(S++);
	}
	if (u!='V' or u!='v')
	{
		printf("Neispravan unos!"); 
		else (br=++)&&(V++);
	}
	if (u!='P' or u!='p')
	{
		printf("Neispravan unos!"); 
		else (br=++)&&(P++);
	}
	if (u=='K' or u=='k')
	{
		printf ("\n Broj evidentiranih auta je %d:", br);
		pc=(C/br)*100;
		pb=(B/br)*100;
		ps=(S/br)*100;
		pv=(V/br)*100;
		pp=(P/br)*100;
		if ((pc>pb)&&(pc>ps)&&(pc>pv)&&(pc>pp))
		{
			printf ("\n Najpopularnija boja auta je %c (%%):", crna,pc);
			else if ((pc>=pb)or(pc>=ps)or(pc>=pv)or(pc>=pp))
			{
				printf ("\n Najpopularnija boja auta je %c (%%):", crna,pc);
				else break;
			}
		}
			if ((pb>pc)&&(pb>ps)&&(pb>pv)&&(pb>pp))
		{
			printf ("\n Najpopularnija boja auta je %c (%%):", bijela,pb);
			else if ((pb>=pc)
			{
				printf ("\n Najpopularnija boja auta je %c (%%):", crna,pc);
				else break;
			}
				if ((pb>=ps)
			{
				printf ("\n Najpopularnija boja auta je %c (%%):", bijela,pb);
				else break;
			}
				if ((pb>=pv)
			{
				printf ("\n Najpopularnija boja auta je %c (%%):", bijela,pb);
			    else break;
			}
			    if ((pb>=pp)
			{
				printf ("\n Najpopularnija boja auta je %c (%%):", bijela,pb);
				else break; 
				}
		}
				if ((ps>pc)&&(ps>pb)&&(pb>pv)&&(pb>pp))
		{
			printf ("\n Najpopularnija boja auta je %c (%%):", siva,pb);
			else if ((ps>=pc)
			{
				printf ("\n Najpopularnija boja auta je %c (%%):", crna,pc);
				else break;
			}
				if ((ps>=pb)
			{
				printf ("\n Najpopularnija boja auta je %c (%%):", bijela,pb);
				else break;
			}
				if ((ps>=pv)
			{
				printf ("\n Najpopularnija boja auta je %c (%%):", siva,ps);
			    else break;
			}
			    if ((pb>=pp)
			{
				printf ("\n Najpopularnija boja auta je %c (%%):", siva,ps);
				else break; 
				}
		}
				if ((pv>pc)&&(pv>pb)&&(pv>ps)&&(pv>pp))
		{
			printf ("\n Najpopularnija boja auta je %c (%%):", crvena,pv);
			else if ((pv>=pc)
			{
				printf ("\n Najpopularnija boja auta je %c (%%):", crna,pc);
				else break;
			}
				if ((pv>=pb)
			{
				printf ("\n Najpopularnija boja auta je %c (%%):", bijela,pb);
				else break;
			}
				if ((pv>=ps)
			{
				printf ("\n Najpopularnija boja auta je %c (%%):", siva,ps);
			    else break;
			}
			    if ((pv>=pp)
			{
				printf ("\n Najpopularnija boja auta je %c (%%):", crvena,pv);
				else break; 
				}
		}
				if ((pp>pc)&&(pp>pb)&&(pp>ps)&&(pp>pv))
		{
			printf ("\n Najpopularnija boja auta je %c (%%):", plava,pb);
			else if ((pp>=pc)
			{
				printf ("\n Najpopularnija boja auta je %c (%%):", crna,pc);
				else break;
			}
				if ((pp>=pb)
			{
				printf ("\n Najpopularnija boja auta je %c (%%):", bijela,pb);
				else break;
			}
				if ((pp>=ps)
			{
				printf ("\n Najpopularnija boja auta je %c (%%):", siva,ps);
			    else break;
			}
			    if ((pp>=pv)
			{
				printf ("\n Najpopularnija boja auta je %c (%%):", crvena,pv);
				else break; 
				}
				}
	else break;
		}
	}
	return 0;
	
}
