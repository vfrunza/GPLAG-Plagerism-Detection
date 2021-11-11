#include <stdio.h>
#include<math.h>

void zaokruzi1 (float *niz, int vel)
	{ 
	    int i;
	    float *p=niz;
	for(i=0;i<vel;i++)
		{
		*p=round(*p*10)/10;
		p++;
	 	}
	 }

void preslozi(float niz[],int vel,int k)
    {
     zaokruzi1(niz,vel);
     int i,j;
     int br1=0,br2=0;
     int suma=0,temp=0;
     float niz1[1000],niz2[1000];
     float switchrooo;
     
     float* pocetak=niz;
     
        for(i=0;i<vel;i++)
        { 
        
        suma=0;
        temp=(fabs)(*(niz+i)*10);

        do{
        	suma+=temp%10;
        	temp=temp/10;
        }while(temp>0);
        
        
        if (suma<k)
        {
            niz1[br1]=*(niz+i);
            br1++;
        }
        else if(suma >=k) 
        {
            niz2[br2]=*(niz+i);
            br2++;
        }
    }
     for(i=0;i<vel;i++)
     {
         if (i<br2) 
         *(niz+i)=*(niz2+i);
         else
         *(niz+i)=*(niz1+i-br2);
     }
   }
    int main ()
    {
        
    int i;
    float niz[] = { 13.1, 15.749999, 15.75, 9.222, 78.1 };//noob
    preslozi(niz, 5, 14);
    printf("Niz glasi: ");
    for (i=0; i<5; i++)
        printf("%g ", niz[i]);
 
        
        return 0;
    }