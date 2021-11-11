#include <stdio.h>
#include <stdlib.h>

void zaokruzi1 (float *niz,int vel)
{
	float *p=niz;
	while(p<niz+vel)
	{
		*p*=10;
		if(*p<0)
		{
			*p=(int) (*p-0.5);
		}
		else
		{
			*p=(int) (*p+0.5);
		}
		*p++/=10;
	}
}
		
		void preslozi(float *niz,int vel,int k)
		{
			int i,j,duzina,suma,broj;
			float pom;
			duzina=0;
			zaokruzi1(niz, vel);
			for(i=vel-1;i>duzina-1;i--)
			{
				suma=0;
				broj=abs((int) ((*(niz+i))*10));
				do
				{
					suma+=broj%10;
					broj/=10;
				}while(broj>0);
				if(suma>=k)
				{
					duzina++;
					pom=*(niz+i);
					for(j=i; j>0;j--)
					{
						*(niz+j)=*(niz+j-1);
					}
					i++;
					*niz=pom;
				}
			}
		}
		



int main() 
{
	int i,k,vel;
	float niz[100];
	printf("Velicina:");
	scanf("%d", &vel);
	printf("NIZ:");
	for(i=0;i<vel;i++) 
	{
		scanf("%f", &niz[i]);
	}
	printf("Unesi k:");
	scanf("%d", &k);
	preslozi(niz,vel,k);
	printf("Niz:");
	for(i=0;i<vel;i++)
	{
		printf(" %g",niz[i]);
	}
	printf("\n");
	return 0;
}
