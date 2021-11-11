#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    printf("Unesite broj: ");
    
int brojx;
scanf("%d",&brojx);
int broj=abs(brojx);
int j,r=0,i=0;
int a=0;int sum=0;
while(broj>=10){
    a=broj%10;
    broj/=10;
    r=abs(broj%10-a);
    int n=1;
    for(j=1;j<=i;j++){
    n*=10;
        
    }
sum+=r*n;
i++;
}
printf("%d",sum);
return 0;
}
