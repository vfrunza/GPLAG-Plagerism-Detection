#include <stdio.h>
int main ()
{
int i,j,k,a,b,c,niz1[4]={1,2,3,5},niz2[5]={1,2,4,6,7},niz3[6]={1,3,4,8,9,10},vel1=3,vel2=3,vel3=3,brojac=0;
vrati:
 for(i=0;i<vel1;i++){
        a=niz1[i];
        for(j=0;j<vel2;j++){
            b=niz2[j];
            for(k=0;k<vel3;k++){
            	c=niz3[k];
            if(a==b && b!=c){
            	brojac++;
            }
            else if ((a==c && c!=b)){
            brojac++;
            break;
            }
            else if(c!=a && b==c)
                {
                brojac++;
            }
            else if (a==b && a==c){
            	brojac--;
            	goto vrati;
            }
            }
            }

   }
   printf("%d",brojac);
   return 0;
}
