#include <stdio.h>
int Prost(int n){
	int i;
	for(i=2; i<n; i++){
		if(n%i==0) return 0;
	}
	return 1;
}
int daj_prost(){
	static int n=2;
	int x=n,i;
	for(i=0;i<n;i++){
		if(Prost(x)==1){
			n++;
			return x;
		} else {
			n++; 
			x++;
		}
	}
}
int main() {
	int a,b,i,suma=0,c;
	do{
	printf("Unesite brojeve A i B: ");
	scanf("%d %d",&a,&b);
	if(a<=0 || (a<=0 && b<=0)) printf("A nije prirodan broj.\n");
	else if(b<=a) printf("A nije manje od B.\n");
	}while(a<=0 || b<=0 || b<=a);
	for(i=0; i<=b; i++){
		c=daj_prost();
		if(c>a && c<b) suma+=c;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	
	return 0;
}
