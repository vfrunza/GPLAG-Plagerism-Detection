#include <stdio.h>

int suma_cifara(int n)
{
    int m=n;
    if(m<0) m*=-1;
    int suma=0;
    if(m<=9 && m>=0)
    {
        return m;
    }
    else if(m>10){
        while(m!=0)
        {
            suma+=m%10;
            m/=10;
        }
    }
    else if(m==10) return 1;
    return suma;
}

void ubaci(int* niz, int vel)
{
    int nizi[10], i;
    for(i=0;i<vel;i++)
    {
       nizi[i]=niz[i];
    }
    for(i=0;i<2*vel;i++)
    {
        niz[i]=1987;
    }
    /*for(i=0;i<vel;i++)
    {
        niz[2*i]=nizi[i];
        niz[2*i+1]=suma_cifara(nizi[i]);
    }*/
    
    //drugi način -.o :(
    for(i=0;i<2*vel-1;i++)
    {
        if(i==0)
        {
            niz[0]=nizi[0];
            niz[1]=suma_cifara(nizi[0]);
            i++;
            continue;
        }
        niz[i]=nizi[i/2];
        niz[i+1]=suma_cifara(niz[i]);
        i++;
    }
}

int izbaci(int* niz, int vel)
{
    int fibonizi[50];
    int i=0, j, k;
    fibonizi[0]=1;
    fibonizi[1]=1;
    for(i=2;i<50;i++)
    {
        fibonizi[i]=fibonizi[i-1]+fibonizi[i-2];
    }
    for(i=0;i<vel;i++)
    {
        for(j=0;j<50;j++)
        {
            if(niz[i] == fibonizi[j])
            {
                for(k=i;k<vel-1;k++)
                {
                    niz[k]=niz[k+1];
                }
                vel--;
                i--;
                if(i==-1) break;
            }
        }
    }
    return vel;
}


int main() {
	int niz[20], i, vel;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++)
	{
	    scanf("%d",&niz[i]);
	}
	ubaci(niz,10);
	vel = izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	for(i=0;i<vel;i++)
	{
	    if(i==vel-1)
	        printf("%d.", niz[i]);
	    else
	        printf("%d, ", niz[i]);
	}
    return 0;
}
/*1 11 3 2 3 5 8 233 21 317811*/