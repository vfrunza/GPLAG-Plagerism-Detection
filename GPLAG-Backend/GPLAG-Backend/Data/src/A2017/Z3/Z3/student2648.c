#include <stdio.h>
#include <math.h>
int izbaci_cifre(int niz1[],int velicina1,int niz2[],int velicina2)
{  int i,e,j,number=0,p,brojac=0,brojac_1=0,num;
   
   
   
   for(i=0;i<velicina2;i++)
   {
       if(niz2[i]<0 || niz2[i]>9)
        {  return 0;  }
       
       for(j=0;j<i;j++)
       {
           if(niz2[j]==niz2[i])
             { return 0;  }
           
       }
   }
   
        if(velicina2==0)
        { p=0;
          return p;
        } 
   
   for(i=0;i<velicina1;i++)
   {
       e=niz1[i];
       niz1[i]=fabs(niz1[i]);
       brojac=0;
       brojac_1=0;
      
       while(niz1[i]!=0)
       {   
           for(j=0;j<velicina2;j++)
           {   
               
               if(niz1[i]%10==niz2[j])
               {
                   num=1;
                   brojac++;
                   break;
               }
               else 
               {  num=0; }
           }
           
              if(num==0)
            {  
            
               number=(number+(niz1[i]%10))*10;
            }
       
              niz1[i]=(int)(niz1[i]/10);
              brojac_1++;
        }  
          if(brojac==brojac_1)
          {
              niz1[i]=0;
          }
          else 
          {
              number=number/10;
              niz1[i]=number;
              number=0;
              while(niz1[i]%10!=0)
              {   
                  number=(number+(niz1[i]%10))*10;
                  niz1[i]=niz1[i]/10;
              }
              
              number=number/10;
              
              if(e<0)
              {
                  niz1[i]=-number;
              }
              else 
              {
                  niz1[i]=number;
              }
              
              number=0;
          }
   }
   
   
   
   
   
   for(i=0;i<velicina1;i++)
   {
       for(j=0;j<i;j++)
       {
           if(niz1[i]==niz1[j] && niz1[i]!=0)
           {
               p=0;
               return p;
           }
           else 
           { p=1;}
       }
   }
   return p;
   
}   



int main(){
     int i,niz1[1000],niz2[1000],velicina1,velicina2;
     
     printf("Unesi velicinu niza1: ");
     scanf("%d", &velicina1);
     
     printf("Unesi clanove niza1: ");
     for(i=0;i<velicina1;i++)
     {   scanf("%d", &niz1[i]);
     }
     
     printf("Unesi velicinu niza2: ");
     scanf("%d", &velicina2);
     
     printf("\nUnesi cifre niza2: ");
     for(i=0;i<velicina2;i++)
     {
         scanf("%d", &niz2[i]);
     }
     
     izbaci_cifre(niz1,velicina1,niz2,velicina2);
   
    
    
    
    return 0;
}