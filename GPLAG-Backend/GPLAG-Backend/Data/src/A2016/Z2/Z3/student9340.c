#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define broj_tacaka 10
#define broj 20
int main() {
  char matrica[broj][broj];
   int i,j,n,x,y;
   for(i=0;i<20;i++){
   for(j=0;j<20;j++){
   matrica[i][j]=' ';
   }
  }
  do {
  printf("Unesite broj tacaka: ");   
   scanf("%d",&n);
   if(n<=0 || n>10){
    printf("Pogresan unos\n");
   }
   }while(n<=0 || n>10);
  
 
      for(j=0;j<n;j++){
          printf("Unesite %d. tacku: ",j+1);
          scanf("%d %d",&x,&y);
          if(x<0 || x>19 || y<0 || y>19){
           printf("Pogresan unos\n");
            j--;
            continue;
      }
      else if((x>=0 && x<=19)&&(y>=0 && y<=19))
      matrica[y][x]='*';
      } 
  

 for(i=0;i<20;i++){
  for(j=0;j<20;j++){
printf("%c",matrica[i][j]);
}
printf("\n");
}
return 0;
}
