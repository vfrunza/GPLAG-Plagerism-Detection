#include <stdio.h>

int main() {
	int n;
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	if(n>10 || n<1){ printf("Pogresan unos\n");
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
		if(n>10  || n<1) printf("Pogresan unos\n");
	}
	}while(n>10 || n<1);
	int x1[20],x2[20];
	int i,j,k;
	for(i=0;i<n;i++){
		while(1)
		{
			printf("Unesite %d. tacku: ",i+1);
			scanf("%d %d",&x1[i],&x2[i]);
			
			if(x1[i]<=19 && x1[i]>=0 && x2[i]<=19 && x2[i]>=0) break;
			else printf("Pogresan unos\n");
		}
	}
    for(i=0;i<20;i++)
    {
    	for(j=0;j<20;j++)
    	{
    		int uslov=1;
    		for(k=0;k<n;k++)
    		{
    			if(j==x1[k] && i==x2[k]) {printf("*");uslov=0; break;}
    		} 
    		
    	 if(uslov)	printf(" ");
    	}
         printf("\n");
    }
  
	return 0;
}
