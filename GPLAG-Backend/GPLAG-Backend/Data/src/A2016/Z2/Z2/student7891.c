#include <stdio.h>


#define pi 3.1415926
#include <stdlib.h>

int main() {
	
	double niz[500];
	double c=0, m=0, s=0, sec=0;
	int a,j,N=0;
	
	printf("Unesite broj uglova: ");
	scanf("%d", &N);
	
	while (N>500) return 0;
	
	for(a=0; a<N; a++)
	{
		scanf("%lf", &niz[a]);
		niz[a]=(niz[a]*180)/pi;
	}
	printf("Uglovi su: \n");
	for(a=0; a<N; a++)
	{
		if(niz[a]>=0)
		{
		c=niz[a];
		s=(int)c;
		m=((c-s)*60);
		sec=((m-(int)m)*60);
		if(sec>59.4999)
		{
			sec=0; m++;
		}
		if(m>59.4999)
		{
			m=0; s++;
		}
			
		if(sec>30)
		{
			for(j=a; j<N-1; j++)
			{
				niz[j]=niz[j+1];
			}
			N--; a--; continue; 
		}
		
	 printf("%.lf stepeni %.lf minuta %.lf sekundi\n", s,m,sec);
		}
		
		
		
		
		else if(niz[a]<0)
		{
			c=niz[a];
		s=(int)c;    
		m=((c-s)*(-60)); if(s==-180) m=abs(m);
		sec=((m-(int)m)*60);
		
		if(sec>59.4999)
		{
			sec=0; m++;
		}
		if(m>59.4999)
		{
			m=0; s--;
		}
			
		if(sec>30)
		{
			for(j=a; j<N-1; j++)
			{
				niz[j]=niz[j+1];
			}
			N--; a--; continue; 
		}
		
	 printf("%.lf stepeni %.lf minuta %.lf sekundi\n", s,m,sec);
			
		}
		
}


	return 0;
}
