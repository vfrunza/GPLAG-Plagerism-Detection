#include <stdio.h>
#include <stdlib.h>
#define pi 3.1415926
int main() {
	double niz[500],sekunde;
	int n,step,min,sek,i,j,sekk;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lf",&niz[i]);
	}
	printf("Uglovi su:\n");
	for(i=0;i<n;i++)
	{
		sekunde=((niz[i]*180)/pi)*3600;
		if(sekunde >= 0)
		{
			sekk=(int)(sekunde+0.5);
		}
		else sekk = (int)(sekunde-0.5);
		step = (int)sekk/3600;
		min = (int)((sekk-step*3600)/60);
		sek = (int)((sekk-step*3600-min*60));
		if(abs(sek)>30)
		{
			for(j=i;j<n-1;j++)
			{
				niz[j] = niz[j+1];
			}
			n--;
			i--;
		}
		else printf("%d stepeni %d minuta %d sekundi\n",step,abs(min),abs(sek));
	}
	return 0;
}
