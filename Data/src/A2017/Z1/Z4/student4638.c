#include <stdio.h>
int main ()
{
  int a,b,c,i,j;
  do{
    printf("Unesite broj redova: ");
    scanf("%d",&a);
  }while(a > 10 || a <= 0);
  do{
    printf("Unesite broj kolona: ");
    scanf("%d",&b);
  }while(b > 10 || b <= 0);
  do{
    printf("Unesite sirinu jedne kolone: ");
    scanf("%d",&c);
  }while(c > 10 || c <= 0);
  
 


  for(i=0; i<=a*2; i++) {
    for(j=0; j<=(c*b)+b; j++) {

      if(i%2==0) {
        if(j%(c+1)==0) printf("+");
        else
          printf("-");
      } else {
        if (j%(c+1)==0) printf("|");
        else
          printf(" ");
      }

    }
    printf("\n");
  }

  return 0;
}
