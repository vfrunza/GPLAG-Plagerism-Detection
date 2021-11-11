#include <stdio.h>



int suma(int n)
{
	int s=0;
	if(n<0) n*=-1;
	while(n!=0)
	{
		s+=n%10;
		n/=10;
	}
	return s;
}


void ubaci(int niz[],int vel)
{
	int i,j;
	
	for(i=1;i<vel;i++)
	{
		if(i%2!=0)
		{
			for(j=vel;j!=i;j--)
				niz[j]=niz[j-1];
			vel++;
			niz[i]=suma(niz[i-1]);
		}
	}
	
	niz[vel]=suma(niz[vel-1]);
}

int Fibonaci(int n)
{
	int a=1,b=1,c;
	
	if(n==1 || n==2) return 1;
	
	while(a+b<=n)
    {   
    	if(a+b==n) return 1;
    	c=a;
    	a=b;
    	b=c+b;
    }
	
	return 0;
}

int izbaci(int niz[],int vel)
{
	int i,j;
	for(i=0;i<vel;i++)
	{
		if(Fibonaci(niz[i]))
		{
			for(j=i;j<vel-1;j++)
				niz[j]=niz[j+1];
			vel--;
			i--;
		}
	}
	
	
	return vel;
	
	
}


int main() {
   
    int niz[200];
    int i;int vel;
    
    
    printf("Unesite niz od 10 brojeva: ");
    for(i=0;i<10;i++)
    	scanf("%d",&niz[i]);
    	
    ubaci(niz,10);
    vel=izbaci(niz,20);
   printf("Modificirani niz glasi: ");
    for(i=0;i<vel;i++){
    	if(i==vel-1)printf("%d.",niz[i]);
    	else printf("%d, ",niz[i]);
    }
    
	return 0;
}