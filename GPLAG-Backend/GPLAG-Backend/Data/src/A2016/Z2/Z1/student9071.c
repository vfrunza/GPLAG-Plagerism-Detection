#include <stdio.h>
#include <stdlib.h>

int main() {
int a=0,b=0,c=0,zh=0,brojdodavanja=1;
int n;
printf("Unesite broj: ");
scanf("%d",&n);
if (n<0){
    n=abs(n);
}

if (n<10){
    printf("0");
} else {
    while(1){
    if(n>9){
        a=n%10;
    n/=10;
    b=n%10;
    c=a-b;
    c=abs(c);
    
    zh=(brojdodavanja*c)+zh;
    brojdodavanja*=10;
    } else {
        break;
    }
    
    
    }
    
    printf("%d",zh);
}



	return 0;
}
