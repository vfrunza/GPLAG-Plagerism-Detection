#include <stdio.h>

int main() {
   int x[10],y[10],n,i,j,k;
   printf("Unesite broj tacaka: ");
   scanf("%d",&n);
  while(n>10 ||n<0 )
  {
  	printf("Pogresan unos");
  
  	 scanf("%d",&n);
  }
   for(i=0;i<n;i++)
   {
   	printf("Unesite %d. tacku: ",i+1);
   	scanf("%d %d",&x[i],&y[i]);
   	 while( x[i]>19 || x[i]<0 || y[i]>19 || y[i]<0 )
   	 {
   	         printf("Pogresan unos");
   	 		scanf("%d %d",&x[i],&y[i]);
   	 	
   	 }
   	 
   }
   	i=0;
   	while(i<n)
  		{
   	 			
   	 		
   	  for(k=0;k<20;k++)
   	 {
   	 	for(j=0;j<20;j++)
   	 	{
   	 		if(  j==x[i] && k==y[i])
   	 		{
   	 			printf("*");i++;
   	 		}
   	 else printf(" ");
   	 	}
   	  
   	 	 printf("\n");
   	 	
   	 }
   	  i++;
   	    }
   	    
    return 0;
}
