#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main(){
    
    float niz[500];
    float a;
    int b,c;
    int i,n,e,f,g;
    int k,j;
    
    printf("Unesite broj uglova: ");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%f",&niz[i]);
    }
    for(i=0; i<n; i++)
    {
        niz[i]=niz[i]*180/PI;
    }
    
     for(i=0; i<n; i++)
    {
        a=niz[i];
        if(a<0) a=fabs(a);
    for(k=0; k<3; k++)
    {
        if(k==0)
        {
            b=a;
            e=a;
        }
        
        else if(k==1)
        {
            f=a;
            b=a;
        }
        else {
            b=a;
            g=a;
            a=a-b;
            a=a*10;
            c=a;
            if(c>=4) g++;
            if(g==60) {g=0; f++;}
            if(f==60){ f=0; e++;}
        }
         a=a-b;
        a=a*60;
    }
    if(g>30)
    {
        for(j=i; j<n-1; j++) {niz[j]=niz[j+1];}
         n--;
    i--;
    }
   
    }
    printf("Uglovi su: \n");
     for(i=0; i<n; i++)
    {
        a=niz[i];
        if(a<0) a=fabs(a);
    for(k=0; k<3; k++)
    {
        if(k==0)
        {
            b=a;
            e=a;
        }
        
        else if(k==1)
        {
            f=a;
            b=a;
        }
        else {
            b=a;
            g=a;
            a=a-b;
            a=a*10;
            c=a;
            
            if(c>=5) g++;
            if(g==60) {g=0; f++;}
            if(f==60){ f=0; e++;}
            if(niz[i]<0) e=(-1)*e;
        }
         a=a-b;
        a=a*60;
    }
    
    printf("%d stepeni %d minuta %d sekundi\n", e,f,g);
    }
    return 0;
    
    
    
    
    
    
    
    
}