#include <stdio.h>

int main() 
{
	int broj_c=0, broj_b=0, broj_s=0, broj_v=0, broj_p=0, ukupno=0;
	float procenat=0.0;
	char slovo;
	
	printf("Unesite vozila: ");
    do
    {
    	scanf("%c", &slovo);
 
	if(slovo == 'K' || slovo == 'k') continue;
	else if(slovo == 'C' || slovo == 'c') 
		{
			ukupno += 1;
			broj_c += 1;
		}
	else if(slovo == 'B' || slovo == 'b') 
		{
			ukupno += 1;
			broj_b += 1;
		}
	else if(slovo == 'S' || slovo == 's') 
		{
			ukupno += 1;
			broj_s += 1;
		}
	else if(slovo == 'V' || slovo == 'v') 
		{
			ukupno += 1;
			broj_v += 1;
		}
	else if(slovo == 'P' || slovo == 'p') 
		{
			ukupno += 1;
			broj_p += 1;
		}
	else
	    {
		printf("Neispravan unos\n");
	    }
    } while(slovo != 'K' && slovo != 'k');

	printf("Ukupno evidentirano %d vozila.\n", ukupno);

    if(ukupno > 0)
    {
    	if(broj_c >= broj_b && broj_c >= broj_s && broj_c >= broj_v && broj_c >= broj_p)
    	{
    		procenat = (float) broj_c/ukupno * 100.0f;
    		printf("Najpopularnija boja je crna (%.2f%%).", procenat);
    	}
    	else if(broj_b >= broj_s && broj_b >= broj_v && broj_b >= broj_p && broj_b > broj_c)
    	{
    		procenat = (float) broj_b/ukupno * 100.0f;
    		printf("Najpopularnija boja je bijela (%.2f%%).", procenat);
    	}
    	else if(broj_s >= broj_v && broj_s >= broj_p && broj_s > broj_c && broj_s > broj_b)
    	{
    		procenat = (float) broj_s/ukupno * 100.0f;
    		printf("Najpopularnija boja je siva (%.2f%%).", procenat);
    	}
    	else if(broj_v >= broj_p && broj_v > broj_c && broj_v > broj_b && broj_v > broj_s)
    	{
    		procenat = (float) broj_v/ukupno * 100.0f;
    		printf("Najpopularnija boja je crvena (%.2f%%).", procenat);
    	}
    	else if(broj_p > broj_c && broj_p > broj_s && broj_p > broj_v && broj_p > broj_b)
    	{
    		procenat = (float) broj_p/ukupno * 100.0f;
    		printf("Najpopularnija boja je plava (%.2f%%).", procenat);
    	}
    }
    else if(ukupno == 0) printf("Najpopularnija boja je crna (0.00%%).");
	
	return 0;
}
