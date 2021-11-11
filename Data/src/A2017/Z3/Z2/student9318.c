#include <stdio.h>

void zaokruzi1 (float niz[], int vel)
{
    float pom;
    int z, z1, p;
    int i;
    for(i=0; i<vel; i++)
    {
        z = niz[i];
        pom = niz[i]-z;
        p = pom*10;
        if ((pom*10)-p >= 0.5)
        	pom = pom + 0.1;
        pom = pom*10;
        z1 = pom;
        pom = z1/10.;
        niz[i] = z+pom;
    }
}

int suma (double n)
{  
	int pom;
    double cifra, sum=0;
    pom=(int)n;
    cifra= n-pom;
    while(pom!=0)
    {
        sum = sum + (pom%10); printf("%d, ", sum);
        pom /= 10;
    } 
    cifra = cifra*10; printf("%f, ", cifra);
    
    sum += cifra;
    return sum;
}

void preslozi (float niz[], int vel, int k)
{
    int i;
    zaokruzi1 (niz, vel);
    float niz1[100]; int br=0,nova, n=0;
    for(i=0;i<vel;i++)
    {
        if(suma(niz[i])<k)
        {
                  
            niz1[br]=niz[i];
            br++;
                
        }
        niz[i]=niz[i+1]; i--;
    }
    nova=vel-br;
    for(i=nova; i<vel;i++)
    {
        niz[i]=niz1[n++];
    }
}

int main()
{
	
    return 0;
}