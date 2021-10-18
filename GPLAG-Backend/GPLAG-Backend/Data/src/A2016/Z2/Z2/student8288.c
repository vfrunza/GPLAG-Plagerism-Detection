#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,j,i,stepeni,minute,sekunde,predznak;
	float niz[500],ugao;
	float pi=3.1415926;
	
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	
	if(n>0 && n<=500)
	{
		for(i=0;i<n;i++)
		{
			scanf("%f", &niz[i]);
		}
		printf("Uglovi su: \n");
		for(i=0;i<n;i++)
		{
			ugao=niz[i];
			if(ugao<0)
			{
				predznak=-1;
				ugao*=-1;
			}
			else predznak = 1;
			stepeni = ugao*180./pi;
			minute =(ugao*180./pi - stepeni)*60.;
			sekunde=((ugao*180./pi - stepeni)*60. - minute)*60. + 0.5;
			if(sekunde == 60)
			{
				sekunde-=60;
				minute++;
			}
			
			if(minute==60)
			{
				minute-=60;
				stepeni++;
			}
			
			if(stepeni==360)
			{
				stepeni-=360;
				
			}
			stepeni*=predznak;
			
			if(sekunde>30)
			{
				for(j=i;j<n-1;j++)
				{
					niz[j]=niz[j+1];
				}
				n--;
				i--;
			}
			else
			{
				printf("%d stepeni %d minuta %d sekundi \n",stepeni,minute,sekunde);
			}
		}
	}
	else
	{
		printf("Pogresan unos! ");
	}
	
	
	return 0;
	
	
	
	
	
	
}