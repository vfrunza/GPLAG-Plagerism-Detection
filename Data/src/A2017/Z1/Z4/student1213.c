#include <stdio.h>

int main() {
   int i, j, n, m, k;
   do {
   	printf("Unesite broj redova: ");
   scanf("%d", &n);
   }while((n<=0) || (n>10));
   
   do{
   printf("Unesite broj kolona: ");
   scanf("%d", &m);
   }while((m<=0) || (m>10));
   
   do{
   printf("Unesite sirinu jedne kolone: ");
   scanf("%d", &k);
   }while ((k<=0) || (k>10));
   	
   
   
   
   for(i=0; i<2*n+1; i++)
   
   {
   	
   	if(i==0 || i%2==0)
   	{
   
   	for(j=0; j<(k+1)*m+1; j++)
   	{
   	
   	if(j==0 || j%(k+1)==0)
   	printf("+");
   	else printf("-");
   	}
   	
    printf("\n");
   }
   
   
   else
   {
   	for(j=0; j<(k+1)*m+1; j++)
   	{
   		if(j==0 || j%(k+1)==0)
   		{printf("|");}
   		else printf(" ");
   	}
   	printf("\n");
   }
   
	
}

return 0;
}
