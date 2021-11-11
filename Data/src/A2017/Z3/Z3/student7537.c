#include <stdio.h>
#include <math.h>

int izbaci_cifre(int*niz1, int vel1, int* niz2, int vel2){
    
    int i, j, a, h, b[100]={0}, c, r=0;
    
    for(i=0; i<vel2; i++)
    if(niz2[i]<0 || niz2[i]>9) return 0;
    for(i=0; i<vel2; i++)
    for(j=i+1; j<vel2; j++)
    if(niz2[i]==niz2[j]) return 0;
    
    for(i=0; i<vel1; i++){
       a=fabs(niz1[i]);
       for(j=0; j<100; j++){
           b[j]=a%10;
           a=(a-a%10)/10;
           c=j;
           if(a==0) break;
       }
       for(j=0; j<vel2; j++){
       for(r=0; r<=c; r++)
       if(b[r]==niz2[j]){ 
          for(h=r; h<c; h++)
          b[h]=b[h+1]; c--; r--; 
        }
       }
       a=0;
       for(j=0; j<=c; j++){
           a+=b[j]*pow(10, j);
       }
       if(niz1[i]>0)
       niz1[i]=a;
       else niz1[i]=(-1)*a;
   }
    return 1;
}

int main(){
    int i, niz1[100]={0}, niz2[100]={0}, vel1, vel2;
    scanf("%d %d", &vel1, &vel2);
    for(i=0; i<vel1; i++)
    scanf("%d", &niz1[i]);
    for(i=0; i<vel2; i++);
    scanf("%d", &niz2[i]);
    i=izbaci_cifre(niz1, vel1, niz2, vel2);
    return 0;
}


