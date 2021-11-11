#include <stdio.h>
#include <math.h>
#define PI 3.1415926


int main() {
	int n, i, j;
	double niz[500]; 
	double pom=0,  brstepeni=0 , brminuta=0, brsekundi=0;
	
printf("Unesite broj uglova: ");
scanf("%d",&n);


for (i=0; i<n; i++)
	{	
		scanf("%lf",&niz[i]);
	}
	
	printf("Uglovi su: \n");
	for(i=0; i<n; i++)
 	{ 
 		pom=niz[i] * (180/PI);
 		brstepeni= (int)pom ;
 		brminuta= (int)((pom-brstepeni)*60);
 		if(pom>=0) brsekundi= (int)((((pom-brstepeni)*60) - brminuta)* 60 + 0.5) ;
 		else brsekundi= (int)((((pom-brstepeni)*60) - brminuta)* 60 - 0.5) ;
 		
 		if(brsekundi>=60){brminuta++;brsekundi=0;}
 		if(brminuta>=60){brstepeni++;brminuta=0;}
 		
 		if(brsekundi<=-60){brminuta--;brsekundi=0;}
 		if(brminuta<=-60){brstepeni--;brminuta=0;}
 		
 		if (brsekundi > 30 || brsekundi < -30)
 		{
 				for(j=i; j<n-1; j++) 
 					niz[j]=niz[j+1];
 				i--;
 				n--;
		}
		else 
		{
			if(pom<0 && brstepeni==0)printf("-%.f stepeni %.f minuta %.f sekundi\n",brstepeni,fabs(brminuta),fabs(brsekundi));
			else printf("%.f stepeni %.f minuta %.f sekundi\n",brstepeni,fabs(brminuta),fabs(brsekundi));
		}
 	}
	
	return 0;
}
