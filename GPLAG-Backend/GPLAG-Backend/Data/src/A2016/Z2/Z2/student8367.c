#include<stdio.h>
#define PI 3.1415926


int main()
{
	int n, i, j;
	float a[500], stepeni, minuta, sekundi;
	
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	
	for(i=0; i<n; i++)
	{scanf("%f", &a[i]);
	}
	
	
	for(i=0; i<n; i++)
	{  
		float step=(int)(a[i]*180/PI);
		float min=((a[i]*180/PI)-step)*60;
		float sek=(min-(int)min)*60;
		
		if(sek>30)
	
	{
		for(j=i; j<n-1; j++)
		{
			a[j]=a[j+1];
		}
		n--;
		i--;
	}
	}
	
	
	printf("Uglovi su:\n");
	for(i=0; i<n; i++)
	{  stepeni=(int)(a[i]*180/PI);
	   minuta=((a[i]*180/PI)-stepeni)*60;
	   sekundi=(minuta-(int)minuta)*60;
		printf("%.0f stepeni %.0f minuta %.0f sekundi \n", stepeni, minuta, sekundi);
	}
	

	return 0;
}