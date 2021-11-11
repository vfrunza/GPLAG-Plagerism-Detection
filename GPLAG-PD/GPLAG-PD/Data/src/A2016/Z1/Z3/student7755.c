#include <stdio.h>
int main() {
	int broj_pojavljivanja=0,suma=0;
	int broj_pojavljivanja_c=0, broj_pojavljivanja_b=0, broj_pojavljivanja_s=0, broj_pojavljivanja_p=0, broj_pojavljivanja_v=0;
	
	float pc,pb,ps,pv,pp;
	char unos='?',znak='o';
	printf("Unesite vozila: ");
	while(unos!='K' && unos!='k')
	{
		scanf("%c", &unos);
		if(unos=='K' || unos=='k') break;
	
		if(unos=='C' || unos=='c' || unos=='B' || unos=='b' || unos=='S' || unos=='s' || unos=='V' || unos=='v' || unos=='P' || unos=='p')
		{
			suma++;
			if(unos=='C' || unos=='c')
			{ 
				broj_pojavljivanja_c++;
				if(znak==unos) {
					broj_pojavljivanja++;
				}
				if(broj_pojavljivanja_c>broj_pojavljivanja) {
					znak=unos;
				}
				
				
			}
			else if(unos=='B' || unos=='b')
			{
					broj_pojavljivanja_b++;
				
				if(znak==unos) {
					broj_pojavljivanja++;
				}
				if(broj_pojavljivanja_b>broj_pojavljivanja) {
					znak=unos;
				}
				
			}
			else if(unos=='S' || unos=='s')
			{
					broj_pojavljivanja_s++;
				if(znak==unos) {
					broj_pojavljivanja++;
				}
				if(broj_pojavljivanja_s>broj_pojavljivanja) {
					znak=unos;
				}
				

			}
			else if(unos=='V' || unos=='v')
			{
				
					broj_pojavljivanja_v++;
				if(znak==unos) {
					broj_pojavljivanja++;
				}
				if(broj_pojavljivanja_v>broj_pojavljivanja) {
					znak=unos;
				}
				
			}
			else if(unos=='P' || unos=='p')
			{
			
					broj_pojavljivanja_p++;
				if(znak==unos) {
					broj_pojavljivanja++;
				}
				if(broj_pojavljivanja_p>broj_pojavljivanja) {
					znak=unos;
				}
				
			}

		}
		else {
			printf("Neispravan unos\n");
			continue;
		}
			
		
	}
		pc=(((float)broj_pojavljivanja_c/suma))*100;
		pb=(((float)broj_pojavljivanja_b/suma))*100;
		ps=(((float)broj_pojavljivanja_s/suma))*100;
		pv=(((float)broj_pojavljivanja_v/suma))*100;
		pp=(((float)broj_pojavljivanja_p/suma))*100;
	
	
	printf("Ukupno evidentirano %d vozila.\n", suma);
	if(suma==0)
	{
		printf("Najpopularnija boja je crna (0.00%%).");
		return 0;
	}
	if(broj_pojavljivanja_c>=broj_pojavljivanja && broj_pojavljivanja_c>=broj_pojavljivanja_p && broj_pojavljivanja_c>=broj_pojavljivanja_v && broj_pojavljivanja_c>=broj_pojavljivanja_s && broj_pojavljivanja_c>=broj_pojavljivanja_b)
	{
		printf("Najpopularnija boja je crna (%.2f%%).", pc);
	}
	else if(broj_pojavljivanja_b>=broj_pojavljivanja && broj_pojavljivanja_b>=broj_pojavljivanja_s && broj_pojavljivanja_b>=broj_pojavljivanja_v && broj_pojavljivanja_b>=broj_pojavljivanja_p)
	{
		printf("Najpopularnija boja je bijela (%.2f%%).", pb);
	}
	else if(broj_pojavljivanja_s>=broj_pojavljivanja && broj_pojavljivanja_s>=broj_pojavljivanja_v && broj_pojavljivanja_s>=broj_pojavljivanja_p)
	{
		printf("Najpopularnija boja je siva (%.2f%%).", ps);
	}
	else if(broj_pojavljivanja_v>=broj_pojavljivanja && broj_pojavljivanja_v>=broj_pojavljivanja_p)
	{
		printf("Najpopularnija boja je crvena (%.2f%%).", pv);
	}
	else if(broj_pojavljivanja_p>=broj_pojavljivanja)
	{
		printf("Najpopularnija boja je plava (%.2f%%).", pp);
	}
	return 0;
}
