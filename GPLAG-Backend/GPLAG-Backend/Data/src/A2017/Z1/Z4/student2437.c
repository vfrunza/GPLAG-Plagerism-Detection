#include <stdio.h>

int main() {
int red,kolona,sirina,i,j;

do{printf("Unesite broj redova: ");
scanf("%d", &red);
    if(red>0 && red<=10)
    break;
}
while(red>0 || red<=10) ;

do{printf("Unesite broj kolona: ");
scanf("%d", &kolona);
if(kolona>0 && kolona<11)
break;

}
while (kolona>0 || kolona<=10);

do{printf("Unesite sirinu jedne kolone: ");
scanf("%d", &sirina);
    if(sirina>0 && sirina<11)
    break;
}
while(sirina>0 || sirina<=10);


for(i=0;i<=red*2;i++){
    for(j=0;j<=(kolona*sirina)+kolona;j++){
    
    if((j%(sirina+1))==0 && i%2==0)

 printf("+");
else if(i%2==0)printf("-");
if(i%2==1 && (j%(sirina+1)==0))printf("|");

else if(i%2==1)printf(" ");
            
        }printf("\n");

}

	return 0;
}
