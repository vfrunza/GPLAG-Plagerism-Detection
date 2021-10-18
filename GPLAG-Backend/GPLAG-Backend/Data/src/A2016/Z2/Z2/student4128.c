#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
	int n,minute[500],sekunde[500],stepen[500],i,j;
	float ugao,s,m,uglovi[500];
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%f",&uglovi[i]);
	   ugao=uglovi[i]*(180/PI);
	   stepen[i]=ugao;
	   m=fabs((ugao-stepen[i]))*60;
	   minute[i]=m;
	  
	   s=fabs((m-minute[i]))*60;
	   sekunde[i]=(s+0.5);
	   if(sekunde[i]==60)
	   {
	   	minute[i]++; sekunde[i]=0;
	   }
	    if(minute[i]==60)
	   {
	    minute[i]=0;
	    if(stepen[i]<0)
	    {
	    	 stepen[i]--;
	   }
		else if(stepen[i]>0)
		{
			stepen[i]++;
		}
	}	
		
	}
	

 for(i=0;i<n;i++)
 {
 	if(sekunde[i]>30)
 	{
 		for(j=i;j<n-1;j++){
 		sekunde[j]=sekunde[j+1];
 		stepen[j]=stepen[j+1];
 		minute[j]=minute[j+1];
 			
 		}	
 		n--;
 		i--;
 	
 		       
 		}
 }
 
 
 printf("Uglovi su: \n");
  for(i=0;i<n;i++)
  {
  	printf("%d stepeni %d minuta %d sekundi \n", stepen[i],minute[i],sekunde[i]);
  }
	return 0;
}
