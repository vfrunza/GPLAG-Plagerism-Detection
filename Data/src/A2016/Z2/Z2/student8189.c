#include <stdio.h>
#include <math.h>
#define BROJ_U 500
#define PI 3.1415926

int main() {
    double niz[BROJ_U];
    int i,n,j;
    double x,s,m1,m2,s1,s2,s3;
    
    printf("Unesite broj uglova: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        { scanf("%lf",&niz[i]); }
        printf("Uglovi su:\n");
          for(i=0;i<n;i++)
       {
        x=niz[i]*180/PI;
        s=(int)(x);
        m1=fabs(x-s)*60;
        m2=(int)fabs(m1);
        s1=(m1-m2)*60;
        s2=(int)(fabs(s1)+0.5);
        s3=fabs(s2);
       
        if(s3>=60) { s3-=60;   m2++; }
       
        if(m2>=60){
            m2-=60;
        
            if(s<=0) s--;
            else s++;
        }
       if(s3<=30) printf("\n%g stepeni %g minuta %g sekundi\n",s,m2,s3);
        if(s3>30)
        {  for(j=1;j<=n-1;j++) {
         niz[j]=niz[j+1];
        }
          n--;
          i--;
        }
       
       }

     return 0;
}
  