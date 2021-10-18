#include <stdio.h>
#include <math.h>
int main () {
    int i,j,niz1[100],nizp[1000],nizf[1000],dniz1,broj1,broj2,a,b,c,d,da,k,brojac,l,clan,r,x,z;
    do {
    printf("Unesite velicinu niza");
    scanf("%d",&dniz1);
    }
    while (dniz1<0 || dniz1>100);
    printf("Unesite clanove niza: ");
    for(i=0;i<dniz1;i++) 
    {
    
  scanf("%d",&x);
  if(x>=0){
      niz1[i]=x;
  }
  else{
      i--;
  }
  j=0;
    for(i=0;i<dniz1;i++)
    {
        clan=niz1[i];
        if(clan==0){
         nizp[j]=0;
         j++;
        }
        broj1=0;
        while(clan>0) 
        {
            clan=clan/10;
            broj1++;
        }
        clan=niz1[i];
        r=0;
        broj2=broj1;
        b=0;
        da=0;
        while (clan>0)
        {
            if (b==0 && clan%10==0) 
                da=1;
            
            r=r+(clan%10)*pow(10,broj1);
           
            broj1--;
            clan=clan/10;
            b++;
        }
        while(r>0) 
        {
            d=r%10;
            r=r/10;
            nizp[j]=k;
            j++;
        }

        if(da==0)
        {
            for(z=0;z<broj2-1;z++) {
                nizp[j]=0;
                j++;}
                
            }
            }
            brojac=1;
            l=0;
            for(i=0;i<j-1;i++)
            {
                printf("%d ",nizp[i]);
                if(nizp[i]==nizp[i+1])
                brojac++;
                else
                {
                    nizf[l]=nizp[i];
                    nizf[l+1]=brojac;
                    brojac=1;
                    l=l+2;
                    if(i==j-2)
                    {
                        nizf[l]=nizp[i+1];
                        nizf[l+1]=1;
                        l=l+2;
                    }
                }
                if((nizp[i]==nizp[i+1]) || (i==j-1)) 
                {
                    nizf[l]=nizp[i+1];
                    nizf[l+1]=brojac;
              l=l+2;
              }
            }
            
            printf("finalni niz glasi:");
            for(i=0;i<1;i++) {
                printf("%d ",nizf[i]);
            }
        
    return 0;
}