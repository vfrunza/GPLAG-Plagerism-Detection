#include <stdio.h>
//funkcija daje proste brojeve
int daj_prost(){
	static int n=2;
	int prost,j;
	for( ; ;n++){
		prost=1;
		for(j=2;j<n;j++){
			if(n%j==0) 
				prost=0;
		}
		if(prost==1) 
			return n++;
	}
}
// funkcija sabira brojeve na intervalu unesenih brojeva
int suma(int a, int b){
    int s=0;
    static int prostbroj=2;
	int i;
	for(i=2;i<=a;i++){
		prostbroj=daj_prost();
		if(prostbroj>a) 
			break;
	}
	for(i=(a+1);i<b;i++){
		if(prostbroj>=b) 
			break;
		if(prostbroj==a) { 
			prostbroj=daj_prost(); 
			continue;
		}
		s+=prostbroj;
		prostbroj=daj_prost();
	}
	return s;
}

int main() {
	int a, b;
	do{
		printf("\nUnesite brojeve A i B: ");
		scanf("%d %d",&a,&b);
		if(a<1) 
			printf("A nije prirodan broj.");
		if(a>=b) 
			printf("A nije manje od B.");
	}
	while(a<1 || a>=b);
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma(a,b));
	return 0;
}
