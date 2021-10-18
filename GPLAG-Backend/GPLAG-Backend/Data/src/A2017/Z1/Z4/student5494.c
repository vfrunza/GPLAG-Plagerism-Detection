#include <stdio.h>
int main() {
int i,j,k,br,bk,sk,a,b;
do{
printf("Unesite broj redova: ");
scanf("%d",&br);
}
while(br<=0 || br>10);
do{
printf("Unesite broj kolona: ");
scanf("%d",&bk);
}
while(bk<=0 || bk>10);
do{
printf("Unesite sirinu jedne kolone: ");
scanf("%d",&sk);
}
while(sk<=0 || sk>10);
for(i=0;i<(br*2+1);i++){
if(i%2==1){
for(j=0;j<=bk;j++){
printf("|");
for(k=0;k<sk;k++)
printf(" ");
}
printf("\n");
}
else{
for(a=0;a<=bk;a++){
printf("+");
if(a==bk){
continue;
}
for(b=0;b<sk;b++)
printf("-");
}
printf("\n");
}
}
return 0;
}
