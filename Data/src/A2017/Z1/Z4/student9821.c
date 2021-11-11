#include <stdio.h>

int main() {
	int n=1, i, j, z, m,x,a,y,u;
	do{
	   printf("Unesite broj redova: ");
	scanf("%d", &n);
	}while(n<=0||n>=11);
    do{
        printf("Unesite broj kolona: ");
	scanf("%d", &x);
    }while(x<=0||x>=11);
    do{
        printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &z);
    }while(z<=0||z>=11);
	m=z+1;
	u=n*2;
	y=z*x+x;
  for(i=0;i<=u;i++){
      
     if (i%2==0){
         for(j=0;j<=y;j++){
          if (j%m==0)printf("+");
          else printf("-");
             
         }
         }
        else {
            for(a=0;a<=y;a++){
                if(a%m==0)printf("|");
                else printf(" ");
            }
        }
            printf("\n");
     }
             
        

      
      
     
  
  return 0;
}



