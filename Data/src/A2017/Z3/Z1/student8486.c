#include<stdio.h>
int main ()
{
int i,j,k,a=0,b=0,c=0,brojac=0,niz1[4]={1,2,3,5},niz2[5]={1,2,4,6,7},niz3[6]={1,3,4,8,9,10},vel1=4,vel2=5,vel3=6;
if((vel1<vel2) && (vel2<vel3)){
for(i=0;i<vel1;i++){
        a=niz1[i];
        for(j=0;j<vel2;j++){
            b=niz2[j];
            if(a==b){
                brojac++;
            }
            else if(a!=b){
                brojac++;
            }
        }
        }
            i=0;
            j=0;
            for(j=0;j<vel2;j++){
            b=niz2[j];
            for(k=0;k<vel3;k++){
            	c=niz3[k];
            	if(b!=c){
                    brojac++;
            	}
            	else if(b==c){
                    brojac++;
            	}
            }
            }
 }
 printf("%d",brojac);
 return 0;
}
