#include <stdio.h>
#include <math.h>
#include <limits.h>

void ubaci(int *niz, int velicina)
{
	int i,j,broj,vel,suma=0;
	int temp=0;
	vel=2*velicina;
	for(j=vel-2;j>=2;j-=2)
	{
		niz[j]=niz[j/2];
	}
	for(i=1;i<vel;i=i+2)
	{
		niz[i]=0;
	}
	for(i=1;i<vel;i=i+2)
	{
		if(niz[i-1]>0)  temp=niz[i-1];
		else            temp=-niz[i-1];
		do
		{
			broj=temp%10;
			temp=temp/10;
			suma+=broj;
		}
		while(temp!=0);
		niz[i]=suma;
		suma=0;
	}
}

long int fibonacci(long int n)
{
	long int i,niz[100];
	for(i=0;i<100;i++)
	{
		if(i==0) niz[i]=0;
		if(i==1) niz[i]=1;
		if(i>1)
		{
			niz[i]=niz[i-2]+niz[i-1];
		}
		if(niz[i]==n) return 1;
		
	}
	return 0;
	
}

int izbaci(int *niz,int vel)
{
	int i,j;
	long int temp;
	double p,q;
		
		if( sizeof(niz[0])>sizeof(int) )
			{
			for(i=0;i<vel;i++)
			{
					if(i<0) i=0;
					else if (i==vel) i=vel-1;
					if(niz[i]>0)
					{
						p=sqrt(5*niz[i]*niz[i]+4);
						if(niz[i]>0)  q=sqrt(5*niz[i]*niz[i]-4);
						else          q=0;
						if( p==(long int)p  || q==(long int)q  || fibonacci(niz[i])==1)
						{
							for(j=i;j<vel-1;j++)
							{
								temp=niz[j];
								niz[j]=niz[j+1];
								niz[j+1]=temp;
							}
							vel--;
							if(vel==0) return 0;
							if(i!=-1) i--;
						}
					}
			}
		}
	
	else
	{
		for(i=0;i<vel;i++)
		{
			if(i<0) i=0;
			else if (i==vel) i=vel-1;
			if(niz[i]>0)
				{
					p=sqrt(5*niz[i]*niz[i]+4);
					if(niz[i]>0)  q=sqrt(5*niz[i]*niz[i]-4);
					else          q=0;
					if( p==(long int)p  || q==(long int)q || fibonacci(niz[i])==1)
					{
						for(j=i;j<vel-1;j++)
						{
							temp=niz[j];
							niz[j]=niz[j+1];
							niz[j+1]=temp;
						}
						vel--;
						if(vel==0) return 0;
						if(i!=-1) i--;
					}
				}
		}		
	}
	return vel;
}


int main() {
	int vel=10,i;
	int niz[20];
	printf("Unesite niz od 10 brojeva: ");
	
	for(i=0;i<vel;i++)
	{
		scanf("%ld",&niz[i]);
	}
	
	for(i=0;i<vel;i++)
	{
		niz[vel+i]=0;
	}
	ubaci(niz,vel);
	vel=izbaci(niz,2*vel);
	printf("Modificirani niz glasi: ");
	
	for(i=0;i<vel;i++)
	{
		if(i==vel-1)  printf("%d.",niz[i]);
		else printf("%d, ",niz[i]);
	}
	return 0;
}
