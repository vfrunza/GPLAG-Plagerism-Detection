#include <stdio.h>

int main() {
    int br,i,j;
    while(1){
        printf("Unesite broj n: ");
        scanf("%d", &br);
        if(br>0 && br<=50)break;
        else printf("Pogresan unos\n");
    }
    if(br==1)printf("***");
    else{
        for(i=0;i<br;i++){
       for(j=0;j<2*br-1;j++){
           if(i==j || i+j==2*br-2){
               printf("*");
           }
           else printf(" ");
       }
       for(j=0;j<2*br-2;j++){
           if(i==j+1 || i+j==2*br-3){
               printf("*");
           }
           else printf(" ");
       }
       printf("\n");
    }
    }
	return 0;
}

