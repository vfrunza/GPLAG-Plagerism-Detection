#include <stdio.h>
#include <math.h>

void zaokruzi1(float* niz,int duzina)
{
	int i;
	
	for(i=0;i<duzina;i++)
	niz[i]=roundf(niz[i]*10)/10;
	
}

void preslozi(float* niz,int duzina,int k)
{
	
	zaokruzi1(niz,duzina);
	
	int i,j;
	int zbir_cifri=0,brojac=0;
	int temp;
	float tempd;
	for(i=0;i<duzina;i++)
	{
		temp=(fabs)(niz[i]*10);
		zbir_cifri=0;
		while(temp!=0)
		{
			zbir_cifri+=temp%10;
			temp/=10;
		}
		
		if(zbir_cifri>=k)
		{
			for(j=i;j>brojac;j--)
			{
				tempd=niz[j];
				niz[j]=niz[j-1];
				niz[j-1]=tempd;
			}
			brojac++;
			
		}
		
	}
	
}

int main() {

	return 0;
}
