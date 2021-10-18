#include <stdio.h>
#include <stdlib.h>

int izbaci_cifre(int *niz1,int vel1,int *niz2,int vel2){
	int c=0,k=1,j=0,l=0,m=0,x=0,cifra=0;
	
	for(l=0;l<vel2;l++){
		if(niz2[l]<0 || niz2[l]>9)return 0;
		for(m=0;m<vel2;m++){
			if(niz2[l]==niz2[m] && l!=m)return 0;
		}
	}
	
	for(c=0;c<vel1;c++){
		x=niz1[c];
		niz1[c]=0;
		do{
			cifra=x%10;
			for(j=0;j<vel2;j++){
				if(abs(cifra)==niz2[j])break;
			}
			if(j==vel2){
				niz1[c]+=cifra*k;
				k*=10;
				}
			x/=10;
		}while(abs(x)>0);
		k=1;
	
	}
	return 1;
}


int main() {
	
	int a[5],b[5],i=0,x=0,c,d;
	printf("Unesi vel1\n");
	scanf("%d",&c);
	printf("Unesite brojeve\n");
	for(i=0;i<c;i++){
		scanf("%d",&a[i]);
		}
	printf("Unesi broj cifara\n");
	scanf("%d",&d);
	printf("unesite cifre\n");
	for(i=0;i<d;i++){
		scanf("%d",&b[i]);
		}
		
		x=izbaci_cifre(a,c,b,d);
		printf("\n%d\n",x);
		for(i=0;i<c;i++){
			printf("%d ",a[i]);
		}
	return 0;
}
