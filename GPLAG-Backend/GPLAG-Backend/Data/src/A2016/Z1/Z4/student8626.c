#include <stdio.h>

int main (){
int i,j,n;
printf("Unesi broj:");
scanf("%d",&n);
while(n<=0 ||n>50){
    printf("Pogresan unos");}
    if(n==1){
        printf("***");
    }else
for(i=1;i<=n;i++){
for(j=1;j<=4*n-3;j++){
if(i==j || i+j==2*n || i+j==4*n-2 || j-i==2*n-2) 
printf ("*");
else
printf(" ");
}
printf("\n");
}

return 0;
}