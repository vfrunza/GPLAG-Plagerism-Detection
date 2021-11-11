#include <stdio.h>
#include <stdlib.h>

int suma(int n){
	int s=0,a,m;
	m=abs(n);
	while(m!=0){
		a=m%10;
		m/=10;
		s+=a;
	}
	
	return s;
}
void ubaci(int*niz, int vel){
	int i, j;
	for(i=0; i<2*vel; i++){
		if(i%2==0){
			for(j=2*vel-2; j>i; j--){
				niz[j+1]=niz[j];
			}
			niz[i+1]=suma(niz[i]);
			i++;
		}
	}
}
int fib(int n){
	int a=1, b=1;
	if(n<0) return 0;
	while(a<n && b<n){
		a=a+b;
		b=a+b;
	}
	if(a==n || b==n){
		return 1;
	}
	return 0;
}


int izbaci(int *niz, int vel){
	int a,i,j,*q;
	q=niz;
	
	for(i=0;i<vel;i++){
		a=fib(*(q+i));
		if(a==1){
			for(j=i;j<vel-1;j++){
				*(q+j)=*(q+1+j);
			}
			
		vel--;
		i--;
		}
	}
	
	return vel;
}
int main(){
	int i,v,niz[20];
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++){
		scanf("%d", &niz[i]);
	}
	
	ubaci(niz,10);
	v=izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	for(i=0;i<v;i++){
		if(i==v-1) {
			printf("%d.", niz[i]);
			break;
		}
		
		printf("%d, ", niz[i]);
		
	}
	
return 0;
	
}