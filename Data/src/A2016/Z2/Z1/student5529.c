#include <stdio.h>
#include<stdlib.h>
#include <math.h>
int main() {
	int  n,num=0,i=0,nums=0,k=0,suma=0,sumax=0, ks= 0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n<0){
		n=n*(-1);
	}
	if(n==0){
		printf("0");
	}
if(n>=1&&n<=9){
	printf("0");
}
while(n!=0){
	
	num=(num*10)+(n%10);
	n=n/10;
}

while(num!=0){
	
	i++;
	ks++;
	nums=num%10;
	suma=abs(suma-nums);
	
	if(k!=0 || suma!=0){
		if(ks != 1){
			printf("%d",suma);
		} else {}
		
	} else {
		sumax=1;
		
	}
	num=num/10;
	if(i==1){
		i=0;
		suma=nums;
	}
	k++;
}

if(sumax==1){
	printf("0");
}	
	return 0;
}
