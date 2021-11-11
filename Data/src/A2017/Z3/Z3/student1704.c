#include <stdio.h>
#include <math.h>

int izbaci_cifre(int niz1[], int vel1, int niz2[], int vel2)
{
    int i,j, logicko1=0, logicko2=0, logicko=0, T;
    int niz[100000], k=0, z, p;
    
    for(i=0; i<vel2; i++) 
    {
        if(niz2[i]<0 || niz2[i]>9)
        logicko1=1;
    }
    
    for(i=0; i<vel2; i++)
    {
        for(j=i+1; j<vel2; j++)
        {
            if(niz2[i]==niz2[j])
            logicko2=1;
        }
    }
    
    if(logicko1==0 && logicko2==0) 
    {
        for(p=0; p<vel1; p++) {
            
            if(niz1[p]<0)
            {
                niz1[p]=niz1[p]*(-1);
                logicko=1;
            }
            
            for(z=0; z<vel2; z++) {
                
                while (niz1[p]>0) 
                {
                    niz[k]=niz1[p]%10;
                    k++;
                    niz1[p]=niz1[p]/10;
                }
                
                for(i=0; i<k; i++) {
                    if(niz[i]==niz2[z])
                    {
                        for(j=i; j<k-1; j++) {
                            niz[j]=niz[j+1];
                        }
                        k--;
                        i--;
                    }
                }
                
                for(i=k-1; i>=0; i--)
                {
                    niz1[p]=niz1[p]+niz[i]*(pow(10,i));
                }
                
                k=0;
            }
            if(logicko==1)
            niz1[p]=niz1[p]*(-1);
            logicko=0;
        }
        
       T=1; 
    }
    
    else
    {
        T=0;
    }
    
    return T;
}

int main() {
    
    int i, vel1, vel2, niz1[1000], niz2[1000], T;
    
    printf("Unesite velicinu prvog niza: ");
    scanf("%d", &vel1);
    
    printf("Unesite elemente prvog niza: ");
    for(i=0; i<vel1; i++)
    scanf("%d",&niz1[i]);
    
    printf("Unesite velicinu niza cifara: ");
    scanf("%d", &vel2);
    
    printf("Unesite cifre: ");
    for(i=0; i<vel2; i++)
    scanf("%d", &niz2[i]);
    
    T=izbaci_cifre(niz1,vel1,niz2,vel2);
    
    printf("%d\n", T);
    for(i=0; i<vel1; i++)
    printf("%d ", niz1[i]);
    
return 0;
    
}

