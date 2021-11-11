#include <stdio.h>
int Fibonaci(int p)
   {
   	int Fibonacijev_niz[46]={1,1},i=0,a=1,b=1,c,rezultat=0;
   	for (i=2;i<46;i++)
        {
        	c=a+b;
        	a=b;
        	b=c;
        	Fibonacijev_niz[i]=c;
        }
    for (i=0;i<46;i++)
        {
        	if (p==Fibonacijev_niz[i])
        	   {
        	   	rezultat=1;
        	   	break;
        	   }
        	else
        	    rezultat=0;
        }
    return rezultat;    
   	}
int izbaci(int *niz, int vel)
    {
    	int uvjet,temp1=vel,temp2=vel-1,i,j;
    	for (j=0; j<temp1; j++)
    	    {
    	    	uvjet=Fibonaci(*niz);
    	    	if (uvjet==1)
    	    	   {
    	    	   	if (j==temp1-1)
    	    	   	   {
    	    	   	   	vel--;
    	    	   	   	return vel;
    	    	   	   }
    	    	   	for (i=0; i<temp2; i++)
    	    	   	    {
    	    	   	    	*niz=*(niz+1);
    	    	   	    	niz++;
    	    	   	    }
    	    	   	vel--;
    	    	   	niz=niz-temp2;
    	    	   }
    	    	else
    	    	    {
    	    	    	if (j==temp1-1)
    	    	    	   niz--;
    	    	    	niz++;   
    	    	    }
    	    	temp2--;    
    	    }
    	 return vel;   
    }
int Suma(int broj)
    {
        int suma=0,c;
        if (broj<0)
           broj*=-1;
        while (broj>0)
              {
                  c=broj%10;
                  suma+=c;
                  broj/=10;
              }
        return suma;      
    }
void ubaci(int *p, int vel)
     {
     	int poc,suma=0,i,j,temp1,temp2;
     	temp1=vel;
     	temp2=vel;
     	for (i=0; i<temp1; i++)
     	    {
     	    	if (i==temp1-1)
     	    	   {
     	    	   	poc=*p;
     	    	   	suma=Suma(poc);
     	    	   	*(p+1)=suma;
     	    	   return;
     	    }
     	poc=*p;
     	suma=Suma(poc);
     	for (j=0; j<temp1-1; j++)
     	    {
     	        while (vel>0)
     	              {
     	                  *(p+vel)=*(p+vel-1);
     	                  vel--;
     	              }
     	    }
     	*(p+1)=suma;
     	p=p+2;
     	temp2--;
     	vel=temp2;
     	 }
   }
int main() {
	int niz[20]={0},vel,i;
	printf ("Unesite niz od 10 brojeva: ");
	for (i=0; i<10; i++)
	     scanf ("%d", &niz[i]);
	ubaci(niz,10);
	vel=izbaci(niz,20);
	printf ("Modificirani niz glasi: ");
	if (vel>0)
	   {
	   	for (i=0; i<vel-1; i++)
	   	    printf ("%d, ", niz[i]);
	   	printf ("%d.", niz[vel-1]);
	   }
    else
        printf (" ");
    return 0;
}