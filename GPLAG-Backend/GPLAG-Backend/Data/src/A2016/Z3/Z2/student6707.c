#include <stdio.h>
#include <math.h>
int sumacifara(int x)
{
	int suma=0,a;
	while(x!=0)
	{
		a=x%10;
		suma+=a;
		x=x/10;
	}
	return suma;
}

void ubaci( int* niz, int vel)
{
	
	int i,j;
	j=vel-1;
		for(i=vel*2-2; i>1; i-=2)
	{
		niz[i]=niz[j];	
		j--;
	}

	for(i=1; i<vel*2;i++)
	{
		if(i%2!=0)
		{
		  niz[i]=sumacifara(fabs(niz[i-1]));		
		}
	}
}
int fibonaci(int x )
    {int i;
     int provjera=0;
     int niz[100];
     niz[0]=1;
     niz[1]=1;
     if(x==1) provjera=1;
     else{
         for(i=2; i<100; i++)
         {
             niz[i]=niz[i-1]+niz[i-2];
             if(x==niz[i]) {
                 provjera=1; 
                 break;
             }
         }
     }
     return provjera;
    }
int izbaci(int* niz, int vel)
		{
			
			int i, j,provjera;
			for(i=0;i<vel; i++)
    {
        provjera=fibonaci(niz[i]);
        if(provjera==1)
        {
            for(j=i; j<vel-1; j++) niz[j]=niz[j+1];
            vel--;
        	i--;
        }
        
    }
    
    return vel;
		}
int main() {
	
	int niz[20],i;
	int vel=10,j;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<vel; i++)
	{
		scanf("%d", &niz[i]);
	}
	
	ubaci(niz,vel);
	
	j=izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	for(i=0;i<j; i++)
	{
		if(i==j-1) printf("%d.", niz[i]);
		else printf("%d, ", niz[i]);
	}
	return 0;
}
