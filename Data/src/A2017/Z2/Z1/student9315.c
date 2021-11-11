#include<stdio.h>
int main ()
{
  int N,i,j;
  do
  {
    printf("Unesite neki broj N ");
    scanf("%d",&N);
  }while(N<8 || N%4!=0);
  for(i=0;i<(N/2);i++){
      for(j=0;j<(N/2);j++){
          if(i==j){
           printf("+");   
          }
      else
      {
          printf(" ");
      }
  }
  printf("\n");
}

  return 0;
}