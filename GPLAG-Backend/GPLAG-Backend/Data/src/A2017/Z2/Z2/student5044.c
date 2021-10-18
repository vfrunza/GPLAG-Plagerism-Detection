#include<stdio.h>
#include<stdlib.h>


int prebrojavanje(int br)
    {
        int brojac=0;
        while(br!=0)
            {
            br/=10;
            brojac++;
            }
        return brojac;
    }
    
int cenerpow(int n)
    {
        int i,br=1;
            for(i=1;i<=n;i++){
            br*=10;}
        return br;
    }
    
int t(int niz[],int v,int *r)
    {
        int i,j=0,p,c,n,br,brojac;
        char el[10000];
            for(i=0;i<v;i++)
            {
            p=niz[i];
            n=prebrojavanje(p);
                while(n!='0')
                {
                c=cenerpow(n-1);
                br=p/c;
                el[j] = br + '0';
                j++;
                p=p%c;
                n--;
                }
            }
    
    el[j]='\0';
    i=0;
    char *s=el;
    while(*s!='\0')
        {
            br=*s;
            brojac=0;
                 while(*s==br)
                {
                    s++;
                 brojac++;
                }
            r[i++]=br-'0';
            r[i++]=brojac;
        }
        
    return i;
}

int main()
{
    int nizA[]={233,38,17777,7787,15};
    int nizB[1000];
    int p=t(nizA,5,nizB);
    int i;
       for(i=0;i<p;i++)
            {
            printf("%d ",nizB[i]);
            }
   
  return 0;
}
    