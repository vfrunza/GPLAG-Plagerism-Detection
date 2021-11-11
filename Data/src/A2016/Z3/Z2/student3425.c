#include <stdio.h>

int Fibonacci(int p){
	int FibonacciNiz[46]={1,1},a=1,b=1,c,i=0,rezultat=0;
	for(i=2;i<46;i++){
		c=a+b;
		a=b;
		b=c;
		FibonacciNiz[i]=c;
	}
	for(i=0;i<46;i++){
		if(p==FibonacciNiz[i]){
			rezultat=1;
			break;
		}
		else 	
			rezultat=0;
	}
		return rezultat;
}

int izbaci(int *niz, int vel){
	int uslov,i,j,temp=vel,temp2=vel-1;
	
	for(j=0;j<temp;j++){
		uslov=Fibonacci(*niz);
		if(uslov==1){
			if(j==temp-1){
				vel--;
				return vel;
			}
			for(i=0;i<temp2;i++){
				*niz=*(niz+1);
				niz++;
			}
			vel--;
			niz=niz-temp2;

		}
		else{
			if(j==temp-1)
				niz--;
			niz++;
		}
		temp2--;
	}
	return vel;
}
int Suma(int broj){
	int c,suma=0;
	if(broj<0)
		broj*=-1;
	while(broj>0){
		c=broj%10;
		suma+=c;
		broj/=10;
	}
	return suma;
}
void ubaci(int *p,int vel){
	int pocetno,suma,i=0,j=0,temp,temp2;
	temp=vel;
	temp2=vel;
	for(i=0;i<temp;i++){
		if(i==temp-1){
			pocetno=*p;
			suma=Suma(pocetno);
			*(p+1)=suma;
			return;
		}
		pocetno=*p;
		suma=Suma(pocetno);
		for(j=0;j<temp-1;j++){
			while(vel>0){
				*(p+vel)=*(p+vel-1);
				vel--;
			}
		}
		*(p+1)=suma;
		p=p+2;
		temp2--;
		vel=temp2;
	}
}

int main() {
	int niz[20]={0},i=0,vel;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++)
		scanf("%d",&niz[i]);
	ubaci(niz,10);
	vel=izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	if(vel>0){
	for(i=0;i<vel-1;i++)
		printf("%d, ",niz[i]);
	printf("%d.",niz[vel-1]);
	}
	else 
		printf(" ");
	return 0;
}