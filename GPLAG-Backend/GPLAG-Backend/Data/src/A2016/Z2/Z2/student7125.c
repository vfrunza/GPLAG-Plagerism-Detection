#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main()
{
    double fabs (double x);
    int a,i,j,c,l,p,d,f;
    double u[500],k[500],b[500],temp[500],temp2[500];
   do{
    printf("Unesite broj uglova: ");
    scanf("%d",&a);
    if(a<=0 || a>500)
    printf("Pogresan unos\n");
   }while(a<=0 || a>500);
    //input
    for(i=0;i<a;i++)
        scanf("%lf",&u[i]);
        
    //convert
    for(j=0;j<a;j++){
        u[j] = u[j]*(180/PI);
        if(u[j]>0)
        temp[j]=(u[j]-(int)u[j]);
        else
        temp[j]=(u[j]+fabs((int)u[j]));
        u[j] = (int)u[j];
    }
    //separate
    for(c=0;c<a;c++)
    {
        //minute
        k[c]=temp[c]*60;
        if(k[c]>0)
        temp2[c]=(k[c]-(int)k[c]);
        else
        temp2[c]=(k[c]+fabs((int)k[c]));
        k[c]=(int)k[c];
        
        //sekunde
        b[c]=temp2[c]*60;
        if(b[c]>=0)
        b[c]=b[c]+0.5;
        else
        b[c]=b[c]-0.5;
        b[c]=(int)b[c];
        
        //
        if(fabs(b[c])>=60){
            b[c]=0;
            if(k[c]>0)
            k[c]+=1;
            else
            k[c]-=1;
        }
        if(fabs(k[c])>=60)
        {
            k[c]=0;
            if(u[c]>0)
            u[c]+=1;
            else
            u[c]-=1;
        }
    }
    //delete
 for(d=0;d<a;d++)
    if (fabs(b[d]) > 30)
        {
            for(l=d;l<a-1;l++){
            u[l] = u[l+1];
            b[l] = b[l+1];
            k[l] = k[l+1];
            }
            a--;
            d--;
        }
        for(f=0;f<a;f++)
        {
         if(u[f]!=0)
         {
             b[f]=fabs(b[f]);
             k[f]=fabs(k[f]);
         }
         else if(u[f]==0 && k[f]!=0)
        b[f]=fabs(b[f]);
        }
    printf("Uglovi su:\n");
    for(p=0;p<a;p++){
    printf("%.0lf stepeni %.0lf minuta %.0lf sekundi\n",u[p],k[p],b[p]);
    }
    return 0;

}
