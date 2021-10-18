#include <stdio.h>
#include <math.h>
void zaokruzi1(float niz[], int broj)
{   
	int i,n;
    for(i=0;i<broj;i++)
	{   n=niz[i];
		niz[i]*=10;
		niz[i]=round(niz[i]);
		niz[i]=niz[i]/10;
	}
	
}

void preslozi(float niz[], int broj,int k)
{
	int i,j;
	float p,c,s=0,niz1[1000],temp;
	 
    zaokruzi1(niz,broj);
	for(i=0;i<broj;i++)
	{   
	
		p=niz[i];
		niz[i]=niz[i]*10;
		niz[i]=fabs(niz[i]);
		s=0;
	    while(niz[i]!=0)
		{
			c=((int)niz[i])%10;
			s+=c;
			niz[i]=(niz[i]/10);
			
	    }
			niz1[i]=s;
			niz[i]=p;
			
	}
		for(i=0;i<broj;i++)
		{    
			for(j=(i+1);j<broj;j++)
			{    
				if((niz1[i]<k) && (niz1[j]>=k))
				{
					temp=niz[i];
					niz[i]=niz1[j];
					niz[j]=temp;
					
				
				}
			}
		}
	}
	
    int main() {
    float niz[1000];
	int i,broj,k;
	
	
    printf("Unesi velicinu niza:");
	scanf("%d", &broj);
	
	printf("\nUnesi clanove niza: ");
	for(i=0;i<broj;i++)
	{
		scanf("%f", &niz[i]);
	}

     
     printf("\nUnesi broj k:");
     scanf("%d", &k);
	
     
    
     
     preslozi(niz,broj,k);
     	printf("\nNiz glasi:");
		for(i=0;i<broj;i++)
		{
		printf("%g ", niz[i]);
		}
     

	
	return 0;
}
