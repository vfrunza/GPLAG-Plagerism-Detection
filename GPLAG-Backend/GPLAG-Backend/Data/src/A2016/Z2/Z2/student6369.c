#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
	int n,stepeni = 0,minuta = 0,sekunde = 0,i,j;
	float niz[500],stepen,minute,sekunda,razlika1,razlika2,ukupno_sekundi=0;
	printf("Unesite broj uglova: Uglovi su:  \n");
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		scanf("%f",&niz[i]);
	}
	for(i = 0 ; i < n ; i++)
	{
		
		if(niz[i] < 0)
		{
			ukupno_sekundi = (niz[i] * (180./ PI) * 3600) - 0.5;
		}
		else 
		{
			ukupno_sekundi = (niz[i] * (180./ PI) * 3600) + 0.5;
		}
			stepen = ukupno_sekundi/3600.;
			stepeni =(int) stepen;
			razlika1 = stepen - stepeni;
			minute = fabs(razlika1 * 60);
			minuta = (int) minute;
			razlika2 = minute - minuta;
			sekunda = fabs(razlika2 * 60) ;
			sekunde = (int) sekunda;
			
			if(sekunde > 30)
			{
				for(j = i ; j < n - 1; j++)
				{
					niz[j] = niz[j+1];
				}
				n--;
				i--;
			}
			else
			{
				if(sekunde >= 60)
				{
					minuta++;
					sekunde -= 60;
				}
				if(minuta >= 60)
				{
					stepeni++;
					minuta -= 60;
				}
				printf("%d stepeni %d minuta %d sekundi\n",stepeni,minuta,sekunde);
			}
			
	}	
			
	return 0;
}
