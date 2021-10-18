#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
	int i,n,j,predznak;
	
	double ugl_rad[500]={0},ugl_stup[500]={0}; /*ugao u radijanima, ugao u stupnjevima*/
	int brojsekundi[500]={0},brojstupnjeva[500]={0},brojminuta[500],ukupnosekundi[500]={0};
	double ostatak[500]={0};
	predznak=0;

	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lf",&ugl_rad[i]);
		if(ugl_rad[i]<0)
		{
			predznak=1;
			ugl_rad[i]*=-1;
		}	
		ugl_stup[i]=ugl_rad[i]*(180.0/PI); 							

		ukupnosekundi[i]=ugl_stup[i]*3600; 							
		
		ostatak[i]=ugl_stup[i]*3600-(int)(ugl_stup[i]*3600);  		
		if(ostatak[i]>=0.5)ukupnosekundi[i]++;
		
		brojstupnjeva[i]=ukupnosekundi[i]/3600; 					
		brojminuta[i]=(ukupnosekundi[i]%3600)/60; 	
		brojsekundi[i]=(ukupnosekundi[i]%3600)-brojminuta[i]*60; 																			/*	printf("brojsekundi1.1-%f\n",brojsekundi[i]);*/
		
	}
	
	for(i=0;i<n;i++)
	{
		if(brojsekundi[i]>30) {
			for(j=i;j<n-1;j++)
			{
				brojstupnjeva[j]=brojstupnjeva[j+1];
				brojsekundi[j]=brojsekundi[j+1];
				brojminuta[j]=brojminuta[j+1];
			}
			n--;
			i--;
		}
	
	}
	printf("Uglovi su:\n");
	if(predznak!=1)
		for(i=0;i<n;i++){
			printf("%d stepeni %d minuta %d sekundi\n",brojstupnjeva[i],brojminuta[i],brojsekundi[i]);
		}
	else for(i=0;i<n;i++)
		printf("-%d stepeni %d minuta %d sekundi\n",brojstupnjeva[i],brojminuta[i],brojsekundi[i]);
	
	return 0;
}

