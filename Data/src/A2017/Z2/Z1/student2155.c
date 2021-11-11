#include <stdio.h>
#include <stdlib.h>

int main() {
int x,n,br=0,br1,br2,rez=0,rez1=0,i;
printf("Unesite broj: ");
scanf("%d", &x);
if(x>0 && x<10){
printf("0");
return 0;
}
n=x;
while (x!=0){
	x/=10;
	br++;}
	
for(i=0;i<br-1;i++){
  br1=n%10;
  n/=10;
  br2=n%10;
  rez+=abs(br1-br2);
  rez*=10;
}

rez/=10;
for(i=0;i<br-1;i++) {
	rez1+=rez%10;
	rez1*=10;
	rez/=10;
}
rez1/=10;
printf("%d", rez1);

return 0;
}

