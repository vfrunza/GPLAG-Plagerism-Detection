#include <stdio.h>
#include <math.h>
#define BROJ_EL 10
#define PI 3.1415926
int main() {
	int i,n,j,k,a;
	int x[BROJ_EL],y[BROJ_EL];
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	if(n>10 || n<=0)
	printf("Pogresan unos\n");
	}while(n>10 || n<=0);
	
	
	for(i=0; i<n; i++)
	{
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&x[i],&y[i]);
		if((x[i]>=20)||(x[i]<0) || (y[i]>=20)||(y[i]<0) )
		{
		    printf("Pogresan unos\n");
		    i-=1;
		}
	}
	
	
    for(i=0;i<20;i++)
    {
        for(j=0;j<20;j++)
        {   a=1;
            for(k=0;k<n;k++)
            {
                if(x[k]==j && y[k]==i)
                {
                    printf("*");
                    a++;
                    break;
                }
                
            }
            if(a==1)
            printf(" ");
        }
        printf("\n");
    }
    
	return 0;
}