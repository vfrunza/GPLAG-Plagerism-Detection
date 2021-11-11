#include <stdio.h>
 int main(){
     int i,a,b,c,n,nizA[100],brojac_uneseni=0,nizB[1000],m,brojac_ponavljanja=1,nizC[1000],k,t;
     for(i=0;i<100;i++){
      nizA[i]=0;}
     for(i=0;i<1000;i++){
      nizB[i]=0;
      nizC[i]=0;}

    
     do{
      printf("Unesite velicinu niza: ");
      scanf("%d",&n);} while (n<1 || n>100);
    
    
    printf("Unesite clanove niza: ");
    for(i=0;i<n;i++){
     scanf("%d",&nizA[i]);
     if(nizA[i]==0)brojac_uneseni++;
      a=nizA[i];
      while(a!=0){
       a=a/10;
       brojac_uneseni++;}
    }
       
        m=brojac_uneseni;
        t=m;
     
     for(i=n-1;i>=0;i--){
       b=nizA[i];
       if(b==0){
       nizB[m-1]=b;
       m--;}
        while(b!=0){
         c=b%10;
        nizB[m-1]=c;
        m--;
         b=b/10;}
      }
        k=1;
         brojac_ponavljanja=1;
         nizC[0]=nizB[0];
     for(i=1;i<=t;i++){
      
      if (nizB[i-1]==nizB[i]){
      brojac_ponavljanja++;
       if(i==t)
       {
        brojac_ponavljanja--;
        nizC[k]=brojac_ponavljanja;
        k+=2;
       }
      }
      
      
      
      if (nizB[i-1]!=nizB[i]){
       nizC[k]=brojac_ponavljanja;
       brojac_ponavljanja=1;
       k++;
       nizC[k]=nizB[i];
       k++;}}
        printf("Finalni niz glasi:\n");
      for(i=0;i<k-1;i++){
       printf("%d ",nizC[i]);
      }
      
     return 0;
 }