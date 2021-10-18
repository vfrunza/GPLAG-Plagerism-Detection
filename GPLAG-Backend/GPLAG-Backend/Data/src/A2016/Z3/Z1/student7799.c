#include <stdio.h>
int daj_prost(){
	int i;
	static int br=1;
	br++;
	while(1) {
		int da=1;
		for(i=2;i<br;i++){
			if(br%i==0) 
			da=0;
		}
	if(da==0) br++;
		else return br;
	}
}
int main() {
	int a,b;
	int suma=0;
	int x;
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &a,&b);
	while (a>=b || a<=0){
		if(a<=0) { 
		printf("A nije prirodan broj.\n");
    	printf("Unesite brojeve A i B: ");
    	scanf("%d %d", &a,&b);
		}
		else{
		printf("A nije manje od B.\n");
		printf("Unesite brojeve A i B: ");
    	scanf("%d %d", &a,&b);}
	}
	printf("Suma prostih brojeva izmedju %d i %d je ", a,b);
    while(1){
    	x=daj_prost();
    	if(x<=a) continue;
    	if(x>=b) break;
    	suma+=x;
    }
	printf("%d.",suma);
	return 0;
}
