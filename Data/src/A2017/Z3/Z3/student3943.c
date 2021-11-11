#include <stdio.h>
#include <math.h>
int izbaci_cifre(int *niz1,int vel1,int *niz2,int vel2)
{
    int i,j;
    int desilo_se=0;
    int brojaci[10]={0};
    int broj=niz1[0];
    int cifra=broj%10;
    int nalazi_se=0;
    int brojac=0;
    for(i=0;i<vel2;i++)
    {
        if(niz2[i]<0 || niz2[i]>9)           // 1.uslov za niz2
        return 0;
        
    }
    for(i=0;i<vel2;i++)
    {
        brojaci[niz2[i]]++;
                                              //2.uslov za niz2
    }
    for(i=0;i<10;i++)
    {
        if(brojaci[i]>1)
        return 0;
        
    }
    
    
    for(i=0;i<vel1;i++)
    {
        brojac=0;
        desilo_se=0;
        broj=niz1[i];
        if(broj<0)
        {
            broj=-broj;
            desilo_se=1;                   //negativni brojevi
            
        }
        
        niz1[i]=0;
    
    while(broj!=0)   
    {
        cifra=broj%10;
        
        
        nalazi_se=0;
        for(j=0;j<vel2;j++)
        {
            if(cifra==niz2[j])                  //provjera da li se cifra 1. niza  nalazi kao clan u 2. nizu
            {
                nalazi_se=1;
                break;
                
            }
        
        }
        if(!nalazi_se)
        {
            
          niz1[i]=niz1[i]+cifra*pow(10,brojac);
            brojac++;
        }
        broj=broj/10;
        
    }
    if(desilo_se)
    niz1[i]=-niz1[i];
      
    }
   return 1; 
}
int main()
{
    int i,a;
 int niz1[]={12345,-12345,12345};
 int niz2[]={3,5};
 a=izbaci_cifre(niz1,3,niz2,2);
 for(i=0;i<3;i++)
 {
     printf("%d ",niz1[i]);
     
 }
    
   printf("\n%d",a);
    
    
    
return 0;    
}

