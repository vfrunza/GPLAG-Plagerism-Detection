#include <stdio.h>
#define PI 3.1415926

int main() {
	int i, j, n;
	double stepen, minute, sekunde, broj=0;
	double niz[500]={0};
	double pomocna_sec;
	
	do
	{
		printf("Unesite broj uglova: ");
		scanf("%d", &n);
		if(n>500 || n<0) 
			printf("Pogresan unos!\n");
	} 	while(n>500 || n<0);

	for(i=0; i<n; i++)
	{
			scanf("%lf", &niz[i]);
	}
	
		for(i=0; i<n; i++)
		{
			if(niz[i]<0)
			{
				niz[i]*=(-1);
				
				broj = niz[i]*180/PI;
				stepen = (int)broj;
				minute = (int)((broj-stepen)*60);
				sekunde = ((broj-stepen-minute/60)*3600);
				pomocna_sec = (sekunde-(int)sekunde)*10;
			
			if((int)pomocna_sec>=5)
			{
				sekunde=(int) sekunde;
				sekunde+=1;
				if(sekunde>=60)
				{
					sekunde-=60;
					minute+=1;
				}
				if(minute>=60)
				{
					minute-=60;
					stepen+=1;
				}
			}
			niz[i]*=(-1);
			
			if(sekunde>30) 
			{
				for(j=i; j<n; j++)
				{
					niz[j]=niz[j+1];
				}
				n--;
				i--;
			}
		}
		else
		{
			broj = niz[i]*180/PI;
			stepen = (int)broj;
			minute = (int)((broj-stepen)*60);
			sekunde = ((broj-stepen-minute/60)*3600);
			pomocna_sec = (sekunde-(int)sekunde)*10;
			
			if((int)pomocna_sec >= 5)
			{
				sekunde = (int)sekunde;
				sekunde+=1;
				if(sekunde>=60)
				{
					sekunde-=60;
					minute+=1;
				}
				if(minute>=60)
				{
					minute-=60;
					stepen+=1;
				}
			}
			if(sekunde>30)
			{
				for(j=i; j<n; j++)
				{
					niz[j]=niz[j+1];
				}
				n--; 
				i--;
			}
		}
	}
	
	printf("Uglovi su:\n");
	for(i=0; i<n; i++)
	{
		if(niz[i]<0) 
		{
			niz[i]*=(-1);
			
			broj = niz[i]*180/PI;
			stepen = (int)broj;
			minute = (int)((broj-stepen)*60);
			sekunde = ((broj-stepen-minute/60)*3600);
			pomocna_sec = (sekunde-(int)sekunde)*10;
			
			if((int)pomocna_sec>=5)
			{
				sekunde=(int) sekunde;
				sekunde+=1;
				if(sekunde>=60)
				{
					sekunde-=60;
					minute+=1;
				}
				if(minute>=60)
				{
					minute-=60;
					stepen+=1;
				}
			}
			if(sekunde>30) 
			{
				for(j=i; j<n; j++)
				{
					niz[j]=niz[j+1];
				}
				n--; 
				i--;
			}
			if(stepen!=0)
			stepen=-stepen;
		}
		else
		{
			broj = niz[i]*180/PI;
			stepen = (int)broj;
			minute = (int)((broj-stepen)*60);
			sekunde = ((broj-stepen-minute/60)*3600);
			pomocna_sec = (sekunde-(int)sekunde)*10;
			
			if((int)pomocna_sec >= 5)
			{
				sekunde = (int)sekunde;
				sekunde+=1;
				if(sekunde>=60)
				{
					sekunde-=60;
					minute+=1;
				}
				if(minute>=60)
				{
					minute-=60;
					stepen+=1;
				}
			}
		}
		printf("%.0f stepeni %.0f minuta %.0f sekundi\n", stepen, minute, sekunde);
	}

	return 0;
}