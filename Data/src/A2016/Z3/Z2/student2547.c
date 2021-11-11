#include <stdio.h>
#include <math.h>
void ubaci(int* niz, int vel){
	int suma=0,i,j,broj;
	for(i=0;i<vel;i++){
		if(i%2==0){
			for(j=vel-1;j>i;j--){
				niz[j+1]=niz[j];
			}
			broj=fabs(niz[i]);
			while(broj!=0){
				suma+=broj%10;
				broj/=10;
			}
			niz[i+1]=suma;
			vel++;
			i++;
		}
		suma=0;
	}
	
}
int fibonaccijeve(int n){
	int a=1,b=1;
	while(a<n && b<n){
		a=a+b;
		b=b+a;
	}
	if(a==n || b==n) return 1;
	
	return 0;
}
int izbaci(int* niz, int vel){
	int i,j;
	for(i=0;i<vel;i++){
		if(fibonaccijeve(niz[i])==1){
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
	int niz[20],vel,i;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++) scanf("%d", &niz[i]);
	ubaci(niz,10);
	vel=izbaci(niz,20);
	printf("Modificirani niz glasi:");
	for(i=0;i<vel;i++){
		if(i==vel-1) printf(" %d.", niz[i]);
		else printf(" %d,", niz[i]);
	}
	return 0;
}
