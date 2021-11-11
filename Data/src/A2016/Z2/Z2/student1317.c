#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_BROJ 500
#define PI 3.1415926

int main() 
{
	int i, j, broj_uglova;
	int step, min, sec;
	double rad, stepf, secf, minf;
	double niz_rad[MAX_BROJ];
	
	/* Unos broja uglova i provjera da li je broj uglova izmedju 0 i 500 */
	do{
	printf("Unesite broj uglova: ");
	scanf("%d", &broj_uglova);
	} while(broj_uglova < 1 || broj_uglova > 500);
	
	/* Unos uglova */ 
	for(i=0; i < broj_uglova; i++)
	{
	    scanf("%lf", &rad);
	    
	    niz_rad[i] = rad;
	    
	    /* Pretvaranje radijana u stepene, minute i sekunde */
	    stepf = rad * 180.0 / PI;
	    step = (int) stepf;
	    minf = ((stepf - step) * 60.0);
	    min = (int) minf;
	    secf = ((minf - min) * 60.0);
	    
	    /* Zaokruzivanje sekundi(pozitivni i negativni broj sec) */
	    if(secf > 0) secf += 0.5;
	    
	    else if(secf < 0) secf -= 0.5;	
	    	
	    sec = (int) secf;
	}

	for(i=0; i < broj_uglova; i++)
	{
	    stepf = niz_rad[i] * 180.0 / PI;
	    step = (int) stepf;
	    minf = ((stepf - step) * 60.0);
	    min = (int) minf;
	    secf = ((minf - min) * 60.0);
	    
	    if(secf > 0) secf += 0.5;
	    
	    else if(secf < 0) secf -= 0.5;
	    
	    sec = (int) secf;
	    
	    /* Zaokruzivanje sekundi i pretvaranje u minute */ 
	    if(sec==60) 
	    {
	    	min = min+1;
	    	sec = 0;
	    }
	   
	    if(min==60)
	    {
	    	step++;
	    	min=0;
	    }
	    
	    if(sec==-60) 
	    {
	    	min = min-1;
	    	sec = 0;
	    }
	   
	    if(min==-60)
	    {
	    	step--;
	    	min=0;
	    }
	    
	    /* Izbacivanje ugla koji ima broj sekundi veci od 30 */
	    if(sec < -30 || sec > 30)
	    {
	    	for(j=i; j < broj_uglova-1; j++)
			{
				niz_rad[j] = niz_rad[j + 1];
			}
			broj_uglova--;
			i--;
	    }
	}
	
	printf("Uglovi su:\n");
	
	/* Ispis uglova */ 
	for(i=0; i < broj_uglova; i++)
	{
		stepf = niz_rad[i] * 180.0 / PI;
	    step = (int) stepf;
	    minf = ((stepf - step) * 60.0);
	    min = (int) minf;
	    secf = ((minf - min) * 60.0);
	    
	    if(secf > 0) secf += 0.5;
	    
	    else if(secf < 0) secf -= 0.5;
	    
	    sec = (int) secf;
	    
	    if(sec==60) 
	    {
	    	min = min+1;
	    	sec = 0;
	    }
	   
	    if(min==60)
	    {
	    	step++;
	    	min=0;
	    }
	    
	    if(sec==-60) 
	    {
	    	min = min-1;
	    	sec = 0;
	    }
	   
	    if(min==-60)
	    {
	    	step--;
	    	min=0;
	    }
		
		min = abs(min);
		sec = abs(sec);
		printf("%d stepeni %d minuta %d sekundi\n", step, min, sec);
	}
	return 0;
}
