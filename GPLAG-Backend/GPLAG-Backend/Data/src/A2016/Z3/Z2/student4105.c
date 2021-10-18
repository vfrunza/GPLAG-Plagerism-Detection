#include <stdio.h>
#include <math.h>
void ubaci(int *p, int n){
	int i,br=0;
	while(br!=n){
		p[2*n-(1+2*br)]=p[n-br-1];
		p[2*n-2*(1+br)]=p[n-br-1];
		br++;
		
	}
	for(i=1;i<2*n;i++){
		int suma=0, pom=p[i-1];
		if(i%2==0) continue;
		if(pom<0) pom=pom*(-1);
		while(pom!=0){
			suma+=pom%10;
			pom/=10;
		}
		p[i]=suma;
	}
}
int fibonacijev_broj(int n){
	int a=1,b=1,c;
	if(n==a) return 0;
	for(;;){
		c=a+b;
		a=b;
		b=c;
		if(n==c) return 0;
		if(c>n) return 1;
	}
}
int izbaci(int *p, int n){
	int i, nova_velicina=n;
	for(i=0;i<nova_velicina;i++){
		if(fibonacijev_broj(p[i])==0){
			int j=i;
			while(j!=nova_velicina-1){
				p[j]=p[j+1];
				j++;
			}
			i--;
			nova_velicina--;
			
		}
	}
	return nova_velicina;
}
int main() {
	int i,x,a[20];
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	ubaci(a,10);
	x=izbaci(a,20);
	printf("Modificirani niz glasi: ");
	for(i=0;i<x;i++){
		if(i!=x-1) printf("%d, ",a[i]);
		else printf("%d. ",a[i]);
	}
	
	
	return 0;
}
