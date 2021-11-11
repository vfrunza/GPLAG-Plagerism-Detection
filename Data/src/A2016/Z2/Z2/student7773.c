#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926

int main()
{
    float niz[500];
    int n,i,j,step,min,sec;
    float x,m,s;
    printf("Unesite broj uglova: ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%f",&niz[i]);
    }
    printf("Uglovi su:\n");
    for(i=0; i<n; i++)
    {
        x=niz[i]*(180/PI);
        step=(int)x;
        m=(x-step)*60;
        min=(int)m;
        s=((m-min)*60);
        if(s>0)
            s=s+0.5;
        if(s<0)
            s=s-0.5;
        sec=(int)s;
        if(sec==60)
        {
            sec=0;
            min++;
            if(min==60)
            {
                min=0;
                step++;
            }
        }
        if(min==60)
        {
            min=0;
            step++;
        }
        if(sec==-60)
        {
            sec=0;
            min--;
            if(min==-60)
            {
                min=0;
                step--;
            }
        }
        if(min==-60)
        {
            min=0;
            step--;
        }
        if(step<0)
        {
            min=abs(min);
            sec=abs(sec);
        }
        if(sec>30 || sec<-30)
        {
            for (j=i; j<n-1; j++)
            {
                niz[j] = niz[j+1];
            }
            n--;
            i--;
        }
        else
            printf("%d stepeni %d minuta %d sekundi\n", step, min, sec);
    }
    return 0;
}