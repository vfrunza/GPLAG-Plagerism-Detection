#include<stdio.h>
#include <stdlib.h>


int main()
{
int niz[100]={0},i,n,cifra=0,inindex=0,interval=0,nnindex=0,intniz[1000]={0},noviniz[1000]={0}, broj=0,temp=0 ;
printf("Unesite velicinu niza: ");
scanf("%d",&n);
printf("Unesite clanove niza: ");
  for(i=0;i<n;i++)
   {
    scanf("%d",&niz[i]);
     
   }
 for (i=n-1;i>=0;i--)
 
    {
       broj = niz[i];
       if (broj == 0)
         {intniz[inindex] = 0;
             inindex++;
         }
          else 
            {while (broj)
          {
              cifra = broj % 10;
              broj /= 10;
              intniz[inindex] = cifra;
              inindex++;
          }
                
            }
    } 
 inindex--; 

for (i=0;i<=inindex/2;i++) 
    { 
        temp = intniz[i];
        intniz[i] = intniz[inindex - i];
        intniz[inindex - i] = temp;
        
    }
    
cifra = intniz[0];
interval++;

 for (i=1; i<=inindex;i++)
   {
       if (intniz[i] == cifra && i!= inindex) {interval++;}
       else if (i != inindex)
        {
            noviniz[nnindex] = cifra;
            noviniz[nnindex+1] = interval;
            cifra=intniz[i];
            nnindex += 2;
            interval=1;
        }
       else {
           if (cifra==intniz[i])
              {noviniz[nnindex] = cifra;
               nnindex++;
              noviniz[nnindex] = interval+1;}
           else {
               noviniz[nnindex]=cifra;
               nnindex++;
               noviniz[nnindex]=interval;
               nnindex++;
               noviniz[nnindex]=intniz[i];
               nnindex++;
               noviniz[nnindex]=1;
           }
         }   
         
   } 
  
  
   printf("Finalni niz glasi:\n");
 for (i=0;i<nnindex+1;i++)
   {
       printf("%d ", noviniz[i]);
   }
return 0;

}