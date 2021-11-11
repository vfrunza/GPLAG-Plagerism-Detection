#include <stdio.h>
#include <stdlib.h>


int SumaCifara(int x)
{
	int suma=0;
	while(x>0)
	{
		suma+=x%10;
		x/=10;
	}
	return suma;
}
void ubaci (int *niz,int velicina)
{
	int i,j;

	for(i=0;i<velicina;i++)
	 {
	for(j=velicina;j>(i+1);j--)
	  {
	niz[j]=niz[j-1];	
	  }
	i++;
	niz[i]=SumaCifara(abs(niz[i-1]));
	velicina++;
     }
}

int izbaci(int* niz,int velicina)
{
	int *pomocni=niz;
	int max=50;
	int i,a=1,b=1,j,k;
	pomocni=niz;
	int Fib[10000];Fib[0]=1;Fib[1]=1;
	for(i=2;i<max;i++)
	{
	Fib[i]=a+b;
	a=b;
	b=Fib[i];
    }
    for(i=0;i<velicina;i++)
    {
    	for(j=0;j<50;j++)
    	{
    		if(niz[i]==Fib[j])
    		{
    			for(k=i;k<velicina-1;k++)
    			{
    				niz[k]=niz[k+1];
    			}
    			i--;
    		velicina--;	
    		break;
    		}
    	}
    }
    niz=pomocni;
    return i;
}



int main() {
	int niz[100],i,vel;
	printf("Unesite niz od 10 brojeva: ");
	for (i=0;i<10;i++){	
		scanf("%d",&niz[i]);
	}
	ubaci(niz,10);
	vel=izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	for(i=0;i<vel;i++)
	{
		if(i==vel-1)
		printf("%d.\n",niz[i]);
		else printf("%d, ",niz[i]);
	}
	return 0;
}
