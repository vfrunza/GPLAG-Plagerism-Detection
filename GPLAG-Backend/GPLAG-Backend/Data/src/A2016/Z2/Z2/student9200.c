#include <stdio.h>

#define PI 3.1415926

int main() {
	printf("Unesite broj uglova: ");
	int n;
	scanf("%d",&n);
	int i=0,j=0;
	double niz[500];
	for(i=0;i<n;i++)
	{
		scanf("%lf",&niz[i]);
	}
	
	printf("Uglovi su:\n");
	for(i=0;i<n;i++)
	{
		double s=niz[i]*180/PI;
		if(s<0) s*=-1;
		int stepeni=(int) s;
		s=s-stepeni;
		s*=60;
		int minute=(int) s;
		s-=minute;
		s*=60;
		double sekunde= s;
		if(sekunde>30)
		{
			for(j=i;j<n-1;j++)
			{
				niz[j]=niz[j+1];
			}
			n--;
			i--;
		}
			
	}
	
	for(i=0;i<n;i++)
	{
		int uslov=1;
		if(niz[i]<0){ uslov=0; niz[i]*=-1;}
		double s=niz[i]*180/PI;
		int stepeni=(int) s;
		s=s-stepeni;
		s*=60;
		int minute=(int) s;
		s-=minute;
		s*=60;
		double sekunde=s;
		if(uslov) printf("%d stepeni %d minuta %0.f sekundi\n",stepeni,minute,sekunde);
		else printf("%d stepeni %d minuta %0.f sekundi\n",(-1)*stepeni,minute,sekunde);
	}
	
	return 0;
}
