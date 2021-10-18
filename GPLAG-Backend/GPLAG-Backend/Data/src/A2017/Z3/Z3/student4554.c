#include <stdio.h>
#include <math.h>


int izbaci_cifre(int *niz,int vel,int *cifre,int vel1)
{
	
	int i,j,c,broj=0,k=1;int neg=0,n;
	
	for(i=0;i<vel1;i++)
		if(cifre[i]<0 || cifre[i]>9) return 0;
	
	for(i=0;i<vel1;i++)
		for(j=i+1;j<vel1;j++)
			if(cifre[i]==cifre[j]) return 0;
	
	if(vel1==0) return 0;
	
	for(i=0;i<vel;i++)
	{    
		if(niz[i]<0){neg=1;niz[i]*=-1;}
		k=1;broj=0;
	
	    
	   for(n=niz[i];n!=0;n/=10)
	     {  

	     	for(j=0;j<vel1;j++)
	     		if(n%10==cifre[j]){ c=0; break;}
	     			else c=n%10;

	     	broj=broj+c*k;
	   
	     	if(c!=0) k*=10;
	     	
	     }
	     
	     if(neg==1) broj*=-1;
		niz[i]=broj;
		neg=0;
		
	}
	 
	return 1;
}

int main() {
int brojevi[] = {54321, -54321};
int cifre[] = {5,1};
izbaci_cifre(brojevi, 2, cifre, 0);
printf("%d %d\n", brojevi[0], brojevi[1]);
izbaci_cifre(brojevi, 2, cifre, 2);
printf("%d %d", brojevi[0], brojevi[1]);

	return 0;
}