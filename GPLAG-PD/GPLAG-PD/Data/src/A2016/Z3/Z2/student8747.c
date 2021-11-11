#include <stdio.h>
#include <stdlib.h>

void ubaci(int niz[],int vel) {
	int i,j,c;
	int suma=0;
	int a=2*vel;
	for(i=1;i<vel;i+=2) {
		for(j=0;j<vel-i;j++) {
			niz[vel-j]=niz[vel-j-1];
		}
		c=abs(niz[i-1]);
		do{
			suma += c%10;
			c /=10;
		}while(c>0);
		niz[i]=suma;
		suma=0;
		vel++;
		if(vel==a-1){
			c=abs(niz[vel-1]);
			do{
				suma += c%10;
				c/=10;
			}while(c>0);
			niz[vel]=suma;
			return;
		}
	}
}
int Fibonnaci( int s) {
	int f1=1,f2=1,f;
	if(s==1) 
		return 1;
	do{
		f=f1+f2;
		f1=f2;
		f2=f;
	}while(f<s);
	return f;
}
int izbaci(int niz[], int vel) {
	int i,c,j;
	for(i=0;i<vel;i++) {
		if(niz[i]<0)
			continue;
		c=Fibonnaci(niz[i]);
		if(niz[i]==c){
			for(j=i;j<vel-1;j++){
				niz[j]=niz[j+1];
			}
			vel--;
			i--;
		}
		
	}
	return vel;
}

int main(){
	int niz[100],i,c;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++) {
		scanf("%d",&niz[i]);
	}
	ubaci(niz,10);
	c=izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	for(i=0;i<c;i++){
		if(i==c-1)
			printf("%d.",niz[i]);
		else printf("%d, ",niz[i]);
	}
	return 0;
}