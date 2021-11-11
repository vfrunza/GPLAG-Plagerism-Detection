#include <stdio.h>

int zbir_cifara(int a){
	int suma=0;
	while(a!=0){
		suma+=a%10;
		a/=10;
	}
	return suma;
}

void ubaci (int niz[], int vel){
	int i,a,j,vel1=vel;
	for(i=0;i<vel*2;i++){
		a=*(niz+i); //a=niz[i];
		if(a<0) a=-a;
		for(j=vel1;j>i+1;j--){
			niz[j]=niz[j-1];
		}
		niz[i+1]=zbir_cifara(a);
		vel1++;
		i++;
	}
	
}

int da_li_je_fib (int a){
	int fib, prvi=1,drugi=1,i;
	if(a==1 || a==2) return 1;
	for(i=2;i<=a;i++){
		fib=prvi+drugi;
		prvi=drugi;
		drugi=fib;
		if(fib==a) return 1;
		else if(fib>a) return 0;
	}
	return 0;
}


int izbaci (int niz[], int vel){
	int i,j;
	for(i=0;i<vel;i++){
		if(niz[i]>0){
			if(da_li_je_fib(niz[i])){
				for(j=i;j<vel-1;j++)
					niz[j]=niz[j+1];
				vel--;
				i--;
			}
		}
	}
	
	return vel;
}


int main(){
	int niz[20],i,pom,vel=10;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<vel;i++){
		scanf("%d",&niz[i]);
	}
	ubaci(niz,10);
	vel+=vel;
	pom=izbaci(niz,vel);
	printf("Modificirani niz glasi: ");
	for(i=0;i<=pom-2;i++){
		printf("%d, ",niz[i]);
	}
	for(i=pom-1;i<pom;i++)
		printf("%d.",niz[i]);
	
	return 0;
	
}
