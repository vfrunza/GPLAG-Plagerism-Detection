#include <stdio.h>

int main() {
    
   char xy[20][20];
   int bt=0,b,i,j,x,y;
   for(i=0;i<20;i++)
   {
       for(j=0;j<20;j++)
       {
           xy[i][j]=' ';
       }
   }
        
           while(bt==0)
           {   printf("Unesite broj tacaka: ");
               scanf("%d", &b);
               if(b<=10 && b>0 ) {
               bt=b;
               }
               else {
                   printf("Pogresan unos ");
                   printf("\n");
               }
           
       }
     b=0;
     while(b<bt)
     {
         printf("Unesite %d. tacku: ",b+1);
         scanf("%d %d", &x,&y);
         if(x>=0 && x<=19 && y>=0 && y<=19)
         {
             xy[y][x]='*';
             b++;
         }
         else {
             printf("Pogresan unos\n");
         }
         }
        for(i=0;i<20;i++)
        {
            for(j=0;j<20;j++)
            {
                printf("%c", xy[i][j]);
            }
            printf("\n");
        }
        return 0;
}