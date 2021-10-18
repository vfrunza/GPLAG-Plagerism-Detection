#include <stdio.h>
int daj_prost(){
	static int prost=1;
	int i;
	prost++;
	while(1){
		for(i=prost-1;i>1;i--)
			if(prost%i==0) 
				break;
				
		if(i==1) {
			/*printf("Prost: %d\n",prost);*/
			return prost;
		}
		else prost++;
	}
	return prost;
}
int main() {
	int a,b,i=0;
	int suma=0;
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d%d", &a, &b);
		if(a<1)
			printf("A nije prirodan broj.\n");
		else if(b<a || a==b)
			printf("A nije manje od B.\n");
	} while(a<1 || b<1 || a>b || a==b);
	
	suma = a-1;
	do{
		suma = daj_prost();
	}while(a>suma);
	
	i=a;
	if(a==suma || suma>b)
		suma=0;
	while(i<b){
		suma+= i = daj_prost();
	}
	suma-=i;
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	/*printf("Zadaća 3, Zadatak 1");*/
	return 0;
}
