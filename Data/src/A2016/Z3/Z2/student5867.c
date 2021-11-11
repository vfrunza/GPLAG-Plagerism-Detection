#include <stdio.h>
#include <math.h>

void ubaci (int *niz, int vel)
{
    int vel1, i, pomocna, temp, ostatak, pomocni_niz[100], j, brojac;
    vel1=2*vel;
    pomocna=vel1/2-1;
    brojac=1;
    
    for(i=0; i<vel; i++)
    {
        int suma=0, n;
        n=niz[i];
        if(n<0)
        {
            n=n*-1;
        }
        while(n!=0)
        {
            ostatak=n%10;
            suma+=ostatak;
            n/=10;
        }
        
        for(j=i; j<vel; j++)
        {
            pomocni_niz[j]=suma;
        }
    }
    
    for(i=0; i<vel1/2; i++)
    {
        
        temp=niz[pomocna];
        niz[pomocna]=niz[pomocna*2];
        niz[pomocna*2]=temp;
        pomocna--;
    }
    
    for(i=0; i<vel1; i++)
    {
        if(i%2!=0)
        {
            niz[i]=pomocni_niz[i-brojac];
            brojac++;
        }
    }
    
    /*for(i=0; i<vel1; i++)
    {
        if(i==vel1-1)
        printf("%d", niz[i]);
        else
        printf("%d, ", niz[i]);
    }*/
}

int izbaci(int *niz, int vel)
{
    int i, j, k, pomocni_niz[90];
    
    /*pomocni_niz[0]=1;
    pomocni_niz[1]=1;*/
    
    for(i=0; i<90; i++)
    {
        if(i==0)
        {
            pomocni_niz[i]=1;
        }
        else if(i==1)
        {
            pomocni_niz[i]=1;
        }
        else
        {
            pomocni_niz[i]=pomocni_niz[i-1]+pomocni_niz[i-2];
        }
    }
    
    for(i=0; i<vel; i++)
    {
        for(j=0; j<90; j++)
        {
            if(niz[i]==pomocni_niz[j])
            {
                for(k=i; k<vel-1; k++)
                {
                    niz[k]=niz[k+1];
                }
                i--;
                vel--;
                if(i==-1)
                break;
            }
        }
    }
    return vel;
}

int main() 
{
	int vel, niz[20], i, vel1;
	vel=10;
	
	printf("Unesite niz od 10 brojeva: ");
	 for(i=0; i<vel; i++)
	 {
	     scanf("%d", &niz[i]);
	 }
	 
	 ubaci(niz, vel);
	 vel1=izbaci(niz, vel*2);
	 
	 printf("Modificirani niz glasi: ");
	 for(i=0; i<vel1; i++)
	 {
	     if(i==vel1-1)
	     {
	         printf("%d.", niz[i]);
	     }
	     else
	     {
	         printf("%d, ", niz[i]);
	     }
	 }
	 
	return 0;
}







