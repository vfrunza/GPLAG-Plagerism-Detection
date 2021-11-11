#include <stdio.h>
#include <math.h>

#define PI 3.1415926

int main() {
  double  Niz[500],Pom[500];
  int a,b,c;
  int n,i,j;
  int neg=0;
  
  printf("Unesite broj uglova: ");
  while(1==1)
  {
   scanf("%d",&n);
   if(n<0 || n>500) printf("Neispravan unos");
   else break;
  }
  
  
 for(i=0;i<n;i++){
    scanf("%lf",&Niz[i]);
    
     
 }
 printf("Uglovi su: \n");
 for(i=0;i<n;i++)
 {      
        neg=0;
        if(Niz[i]<0) neg=1;
        Niz[i]=fabs(Niz[i]);
        Pom[i]=((Niz[i]*180/PI)*3600)+0.5;
        a=(int)Pom[i]/3600;
        b=(int)(((int)Pom[i]%3600)/60);
        c=(int)(((int)Pom[i]%3600)%60);
        
        if(neg==1) a*=-1;
        
        if(c>30){
            for(j=i;j<n-1;j++)
            {
                Niz[j]=Niz[j+1];
                Pom[j]=Pom[j+1];
            }
            i--;
            n--;
        }
        else
        printf("%d stepeni %d minuta %d sekundi \n",a,b,c);
 }
	
	
	

	return 0;
}
