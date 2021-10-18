#include <stdio.h>
#include <math.h>
void ubaci(int *p, int a) {
	int i,k,l,d=1,b,c=0,j,o,temp,suma=0;
		for(i=a; i<2*a; i++) {
			p[i]=0;
		}
	for(i=a; i<2*a; i++) {
		for(j=i; j>d; j--) {
			temp=p[j-1];
			p[j-1]=p[j];
			p[j]=temp;
		}
		d=d+2;
	}
	b=a;
	for(i=0; i<2*b; i=i+2) {
		k=p[i];
		suma=0;
		do {
			c=fabs(k%10);
			k=k/10;
			suma=suma+c;
		}while(k!=0);
		p[i+1]=suma;
		a++;
	}
}

int izbaci(int*p, int a){
	int x,y,z=1,u=1,i,j,max;
	max=p[0];
	for(i=0; i<a; i++){
		if(p[i]>max){
			max=p[i];
		}
	}
	do{
		x=0;
		y=z+u;
		for(i=0; i<a; i++){
			if(p[i]==y){
				x=1;
				break;
			}
			else if(p[i]==1){
				x=1;
				break;
			}
		}
		if(x){
			for(j=i; j<a-1; j++){
				p[j]=p[j+1];
			}
			a--;
			continue;
		}
		u=z;
		z=y;
	}while(y<=max);
	return a;
}
int main() {
	int i,a[20]={0}, duz=10;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++) {
		scanf("%d", &a[i]);
	}
	ubaci(a, duz);
	duz=izbaci(a, 20);
	printf("Modificirani niz glasi: ");
	for(i=0; i<duz; i++){
		if(i!=(duz-1)){
			printf("%d, ", a[i]);
		}
		else{
			printf("%d.", a[i]);
		}
	}
	return 0;
}
