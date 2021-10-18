#include <stdio.h>
#include <math.h>
void zaokruzi1(float *niz, int x)
	{	
		int i;
						
		for(i=0;i<x;i++)
			{
						
				if(*(niz+i)>=0)
					*(niz+i)=(int)(*(niz+i)*10+0.5)/10.;
				else
					{		
						*(niz+i)=-*(niz+i);
							*(niz+i)=(int)(*(niz+i)*10+0.5)/10.;
						*(niz+i)=-*(niz+i);
					}				
			}	
		
	}	
	
	int suma(float broj)
	
	{
		int suma=0;
		int	broj1=broj*10;
		if(broj1<0)
			broj1*=-1;
		
		while(broj1!=0)
		{
			suma+=broj1%10;
				
				broj1/=10;
				
		}
		
		
		
		return suma;	
	}
	
	void preslozi(float *niz, int x, int k)
		{
			int i,j,brojac1=0;
		
				
				
			float temp;
			
			zaokruzi1(niz,x);
			
			for(i=0;i<x;i++)
				{
					
					
					
					if(fabs(suma(niz[i]))>=k)
					{	
						for(j=0;j<i;j++)
					{
						
						temp=*(niz+i);
						*(niz+i)=*(niz+j);
						*(niz+j)=temp;
					
						
					}
					brojac1++;
				}
			
			}
			
			
			/*for(i=0;i<x;i++)
				printf(" %.1f",niz[i]);*/
				
				// Poseban slucaj kada su sume svakoga broja ili veca ili manja od poslanog broja
			if(brojac1==x)
			{
				for(i=0;i<x;i++)
				{
					
					
				
					if(fabs(suma(niz[i]))>=k)
					{	
						for(j=0;j<i;j++)
					{
						
						temp=*(niz+i);
						*(niz+i)=*(niz+j);
						*(niz+j)=temp;
					
						
					}
					
				}
			
			}
			
			}
			
			else
			{
			for(i=0;i<brojac1;++i)
				for(j=i+1;j<brojac1;++j)
					{	
						if(niz[i]<0 && niz[j]<0){
							if(fabs((int)(niz[i]*10))>fabs((int)(niz[j]*10))) // Ovdje zbog nekoga razloga fabs(niz[i])>fabs(niz[j]) ne daje isto rjesenje (SKONTAO) {Zato sto operacija 
						// poredjenja vraca ili 1 ili -1, a sa fabs uvijek vraca 1}
						{
							temp=niz[i];
							niz[i]=niz[j];
							niz[j]=temp;
						}
						}	
					
					else if(niz[i]>0 && niz[j]<0)
					{
						if((int)(niz[i]*10)<fabs((int)(niz[j]*10)))
						{
							temp=niz[i];
							niz[i]=niz[j];
							niz[j]=temp;
						}
					}
					else if(niz[i]<0 && niz[j]>0)
					{
						if(fabs((int)(niz[i]*10))<(int)(niz[j]*10))
						{
							temp=niz[i];
							niz[i]=niz[j];
							niz[j]=temp;
						}
						
					}
						
					else 
					{
						
						if((int)(niz[i]*10)>(int)(niz[j]*10))
						{
							temp=niz[i];
							niz[i]=niz[j];
							niz[j]=temp;
						}
					}
					}
					
					
				
			}
		}

int main() {
int i;
float niz[] = { 3.2, -4.301, -123.1999, 1.1, 0.9 };
preslozi(niz, 5, 8);
printf("Niz glasi: ");
for (i=0; i<5; i++)
    printf("%g ", niz[i]);	
	return 0;
}
