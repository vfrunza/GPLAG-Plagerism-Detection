#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, rez=0, raz=0, c1, c, k=1, n1;
printf("Unesite broj: ");
scanf("%d", &n);
if (n<0) { n=abs(n);}
else if (n==1 || n==2 || n==3 || n==4 || n==5 || n==6 || n==7 || n==8 || n==9){ rez=0; }
n1=n;
while(n1!=0){
    if (n==1 || n==2 || n==3 || n==4 || n==5 || n==6 || n==7 || n==8 || n==9){ 
    raz=0;
    rez+=raz*k;
    break;}
    c=n%10;
    n=n/10;
    c1=n%10;
    raz=c-c1;
    if(raz<0) raz=abs(raz);
    rez+=raz*k;
    k*=10;
    n1/=10;
}
printf("%d", rez);

	return 0;
}
