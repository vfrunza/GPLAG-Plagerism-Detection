#include <stdio.h>
#define PI 3.1415926

int main() {
	int n,j,k=0;
	int step, min, sek;
	float ugao[500], tmp, rnd;
	
	printf("\nUnesite broj uglova: ");
	scanf("%d", &n);
	printf("Uglovi su: \n");
	
	while(k<n)
	{
		scanf("%f", &ugao[k]);
		k++;
	}
	for(k=0;k<n;k++)
	{
		tmp=ugao[k]*(180/PI);
		step=tmp;
		min=(tmp-step)*60;
		sek=(((tmp-step)*60)-min)*60;
		
		if(sek>30)
		{
			for(j=k;j<n-1;j++)
			{
				ugao[j]=ugao[j+1];
			}
			n--;
			k--;
		}
	}

	
	for(k=0;k<n;k++)
	{
		tmp=ugao[k]*(180/PI);
		step=tmp;
		min=(tmp-step)*60;
		sek=(((tmp-step)*60)-min)*60;
		rnd=((((tmp-step)*60)-min)*60)-sek;
		
		if(rnd>0.5)
		sek++;
		
		printf("%d stepeni %d minuta %d sekundi\n", step, min, sek);
	}
	return 0;
}
