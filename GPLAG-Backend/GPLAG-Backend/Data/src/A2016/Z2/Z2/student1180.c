#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
	int n,i,j,d,e,f;
	double a,b,c;
	double niz[500];
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	if(n>=500) return 0;
	for(i=0;i<n;i++)
	{
		scanf("%lf", &niz[i]);
		
	}
		printf("Uglovi su: \n");
		for(i=0;i<n;i++)
		{
			a=(niz[i]*180)/PI;
			d=(int)a;
			b=fabs((a-(int)a)*60);
			f=(int)b;
			c=fabs((b-(int)b)*60);
			e=(int)(c+0.5);
				if(e==60) {
					e=0;
					f=f+1;
					if(f==60) {
						f=0;
						if(d<0)  d=d-1;
						else d=d+1;
					}
				}
	
		if(fabs(e)>30){
			for(j=i;j<n-1;j++)
			{
				niz[j]=niz[j+1];
			}
			n--;
			i--;
			 
		}
	
		
		else printf("%d stepeni %d minuta %d sekundi\n", d,f,e);
		
		}
	
	return 0;
}
