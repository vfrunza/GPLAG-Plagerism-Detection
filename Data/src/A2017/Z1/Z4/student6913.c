#include <stdio.h>
int main()
{
    int i,j,r,k,sk;
    do
    {
       printf("Unesite broj redova: "); 
       scanf("%d",&r);
       printf("Unesite broj kolona: ");
       scanf("%d",&k);
       printf("Unesite sirinu jedne kolone: ");
       scanf("%d",&sk);
       for(i=0;i<r;i++)
          {
               for(j=0;j<k;j++)
               {
                   if(i==0 || i%2==0)
                   {
                   if(j==0 || j%(sk+1)==0 ) { printf("+"); }
                else 
                   
                 printf("-");
                   }
             
               }
                   if(j==0 || j%(sk+1)==0)
                   {
                       printf("|"); 
                 }
                 else  printf(" ");
       }
    
}
    
    while((r<0 || r>=10) && (k<0 || k>=10)&& (sk<0 || sk>=10));
    return 0;
}

