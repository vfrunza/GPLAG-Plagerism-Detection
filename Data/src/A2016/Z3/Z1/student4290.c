#include <stdio.h>
int Prostak(int n){
	int prost=1;
	int i;
	for(i=2;i<n;i++){
		if(n%i==0){
			prost=0;
			break;
		}
	}
	if(i==n)prost=1;
	return prost;
}
int daj_prost(){
	static int i=1;
	while(i<10000){
		i++;
		if(Prostak(i)==1){
			return i;
		}
	}
	
}

int main() {
	int a,b,i;
	int niz[10000];
	int suma=0;
	printf("Unesite brojeve A i B: ");
	scanf("%d %d",&a,&b);
	do{
		if(a<1){
		printf("A nije prirodan broj.\n");
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&a,&b);}
		
		else if(a>=b){
			printf("A nije manje od B.\n");
			printf("Unesite brojeve A i B: ");
			scanf("%d %d",&a,&b);
		}
	}while((a>=b)||(a<1));
	for(i=0;i<b;i++){
		niz[i]=daj_prost();
		if((niz[i]>a)&&(niz[i]<b)){
			suma+=niz[i];
		}
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	
	return 0;
}
