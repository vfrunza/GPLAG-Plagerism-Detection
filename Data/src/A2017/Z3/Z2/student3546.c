#include <stdio.h>
#include <math.h>

void zaokruzi1(float niz[],int vel){
    int i,b,a;float pom;
    int znak=0;
    for(i=0;i<vel;i++)
    {      
        znak=0;
        if(niz[i]<0) {znak=1;niz[i]*=-1;}
           
           
          
           a=niz[i];
           pom=(niz[i]-a)*100;
           b=pom;
          
          if(b%10>=5)
          {
              b/=10;
              b++;
             
          }
          else b/=10;
          
          pom=(float)b/10;
          
          
          
          niz[i]=a+pom;
          
            if(znak==1) niz[i]*=-1;
        
    } 
}

int suma(float n){

     int m;int suma=0;
     int znak=0;
     
     if(n<0){ znak=1; n*=-1;}
     
     m=n*10;
     
     while(m!=0){
         suma+=m%10;
         m/=10;
     }
     return suma;
    
}

void preslozi(float niz[],int vel,int k){
       
       
        int i,n,j;
        float temp;
        int br=0;
         zaokruzi1(niz,vel);
        for(i=0;i<vel;i++){
            n=suma(niz[i]);
           
            if(n>=k)
            {
                for(j=0;j<i;j++)
                {
                    temp=niz[i];
                    niz[i]=niz[j];
                    niz[j]=temp;
                }
                br++;
               
            }
        }
       
        for(i=0;i<br;i++)
        {
            for(j=0;j<i;j++)
            {
                
                    temp=niz[i];
                    niz[i]=niz[j];
                    niz[j]=temp;
                
            }
        }
        
}
    

int main() {
    
 int i;
float niz[] = { 3.2, -4.301, -123.1999, 6.1, 0.9 };
preslozi(niz, 5, 7);
printf("Niz glasi: ");
for (i=0; i<5; i++)
    printf("%g ", niz[i]);
 
    return 0;
}