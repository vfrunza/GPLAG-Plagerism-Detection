#include <stdio.h>

int main() {
int col,row,mod;
int r,c;
do{ printf("Unesite broj redova: ");
scanf("%d",&row );

}

while(row<=0 || row>10);

do{ 
    printf("Unesite broj kolona: ");
scanf("%d",&col );

}
while(col<=0 || col>10);
 
do{
 printf("Unesite sirinu jedne kolone: ");
scanf("%d", &mod);}
while(mod<=0 || mod>10);

for(r=0;r<2*row+1;r++)
{ for(c=0;c<col*(mod+1)+1;c++)
{if (c%(mod+1))
{if (r%2)
{printf("%c", ' ');}
else 
{printf("%c",'-');}
}
else{
if(r%2)
{printf("%c",'|');}
else 
{printf("%c", '+');}
}
}
printf("\n"); } 
 
 







getchar();



	return 0;
}
