#include <stdio.h>
#include <math.h>
int main() {
	double niz[500];
	int n, y, i, j, pret, h, m, s, p=0;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%lf",&niz[i]);
	}
	
	for (i=0; i<n; i++)
	{
		pret=1;
		p=0;
		y = (niz[i]*180*3600)/3.1415926;
		if(y<0){y*=-1; p=1;}
		if(fabs(y-((niz[i]*180*3600)/3.1415926))>0.5)
		y++;
		h = y/3600;
		m = (y%3600)/60;
		s = (y%3600)%60;
		if(s>30) pret=0;
		if(pret==0)
		{
			for(j=i; j<n-1; j++)
		niz[j] = niz[j+1];
		n--;
		i--;
	}
	}
	printf("Uglovi su: \n");
	
	for(i=0;i<n;i++)
	{
		p=0;
		y = (niz[i]*180*3600)/3.1415926;
		if(y<0){y*=-1; p=1;}
		if(fabs(y-((niz[i]*180*3600)/3.1415926))>0.5)
		y++;
		h = y/3600;
		m = (y%3600)/60;
		s = (y%3600)%60;
		if(p==1)printf("-");
		printf("%d stepeni %d minuta %d sekundi\n",h,m,s);
	}
	
	return 0;
}
