#include <stdio.h>
#include <stdlib.h>
int sum(int a){
	int suma=0;
	a=abs(a);
	while(a!=0){
		suma+=a%10;
		a/=10;
	}
	return suma;
}
void ubaci(int *niz,int vel){
	int n1[10],n2[20];
	int i,j=0;
	for(i=0;i<vel;i++){
		n1[i]=sum(niz[i]);
	}
	
	for(i=0;i<vel*2;i+=2){
		n2[i]=niz[j];
		n2[i+1]=n1[j];
		j++;
		if(j==vel) break;
	}
	for(i=0;i<vel*2;i++){
        niz[i]=n2[i];
		}
	
}
int fibonacci(int a){
	int i=1,j=1,k=0;
	if (a==1) return 1;
	while(2){
		k=i+j;
		if(k==a) return 1;
		if(k>a) return 0;
		i=j;
		j=k;
	}
	return k;
}
int izbaci(int *niz,int vel){
	int i,j;
	int y;
	for(i=0;i<vel;i++){
		y=fibonacci(niz[i]);
		if(y){
		for(j=i;j<vel-1;j++){
			niz[j]=niz[j+1];
		}
		vel--;
		i--;
		}
	}
	return vel;
}
int main() {
	int niz[20],i,a;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++){
		scanf("%d", &niz[i]);
	}
	ubaci(niz,10);
	a=izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	
	for (i=0;i<a;i++){
		if(i==a-1){
			printf("%d.", niz[i]);
		}
		else printf("%d, ", niz[i]);
	}
	return 0;
}
