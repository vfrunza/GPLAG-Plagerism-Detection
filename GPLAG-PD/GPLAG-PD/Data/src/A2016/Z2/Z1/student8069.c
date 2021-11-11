#include <stdio.h>
#include <math.h>

int main() {
	int bc=0;
	int i,k,p,d,a,pp,n,z;
	printf("Unesite broj: ");
	scanf("%d", &a);
	pp=fabs(a);
	n=pp;
	while(pp!=0){
		pp=pp/10;
		bc++;
	}
	if(bc==1){
		printf("0");
		return 0;
	}
	z=0;
	k=1;
	{

for(i=0;i<bc-1;i++){
	
	p=n%10;
	d=(n/10)%10;
	n=n/10;
	z=z+(fabs(p-d))*k;
	k=k*10;
}
		printf("%d",z);
		
	}
	return 0;
}
