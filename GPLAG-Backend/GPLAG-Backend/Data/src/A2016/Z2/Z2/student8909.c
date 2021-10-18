/* zadaca 2, zadatak 2. */

#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define broj_elemenata 500


int main() 
{
	int ugl, stepeni, minuta, sekundi, i, k;
	double niz[broj_elemenata], minuta1, sekundi1;
	
	
	printf("Unesite broj uglova: ");
	scanf("%d", &ugl);
	
	for(i=0; i<ugl; i++)
	{
		scanf("%lf", &niz[i]);
	}
	
	printf("Uglovi su: ");
	
	for(i = 0; i < ugl; i++)
	{
		stepeni = (int)(niz[i]*180/PI);
		minuta = fabs((int) ((float)((niz[i]*180/PI) - (int)(niz[i]*180/PI))*60));
		minuta1 = (niz[i]*180/PI - (int)(niz[i]*180/PI))*60;
		
		sekundi1 = (minuta1 - (int)minuta1)*60;
		sekundi1 += 0.5;
		sekundi = fabs(sekundi1);
		
		if(fabs(sekundi) >= 60)
		{
			minuta++;
			sekundi = sekundi - 60;
		}
	
		if(fabs(minuta) >= 60)
		{
			stepeni++;
			minuta = minuta - 60;
		}
		
		if(fabs(sekundi) > 30)
		{
			for(k=i; k<ugl-1; k++)
			{
				niz[k] = niz[k+1];
				i--;
				ugl--;
				
			}
			continue;
		}
		
		printf("\n%d stepeni %d minuta %d sekundi", stepeni, minuta, sekundi);
	}
	
	return 0;
}
