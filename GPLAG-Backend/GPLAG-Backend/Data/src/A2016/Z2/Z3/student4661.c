#include <stdio.h>
#define konst 10
int main() {
    int nizx[konst],nizy[konst];
	int i,b,j,k,g;
	
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d",&b);
	if(b>10 || b<=0)
	printf("Pogresan unos\n");
	}while(b>10 || b<=0);
	
	
	
	for(i=0; i<b; i++)
	{
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&nizx[i],&nizy[i]);
		if((nizx[i]>=20)||(nizx[i]<0) || (nizy[i]>=20)||(nizy[i]<0))
		{
		    printf("Pogresan unos\n");
		    i=i-1;
		}
	}
	
	
    for(i=0;i<20;i++)
    {
        for(j=0;j<20;j++)
        {   g=1;
            for(k=0;k<b;k++)
            {
                if(nizx[k]==j && nizy[k]==i)
                {
                    printf("*");
                    g++;
                    break;
                }
                
            }
            if(g==1)
            printf(" ");
        }
        printf("\n");
    }
    
return 0;
}