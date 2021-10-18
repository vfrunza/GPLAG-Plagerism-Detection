#include <stdio.h>
int JelProst(int x){
	int i;
	if(x==1) return 0;
	for(i=2; i<=x/2; i++){
	if(i%x==0) return 0;
}
return 1;
}
int daj_prost(){
	static int a=1;
	while(!JelProst(a)) a++;
	return a++;
}
int main(){
	int a;
	int b;
	int prost;
	int suma=0;
	while(1){
		printf("Unesi brojeve A i B:");
		scanf("%d %d", &a,&b);
		if(a<=0) printf("A nije prirodan broj.\n");
		if(b<=0) printf("B nije prirodan broj.\n");
		if(a>=b) printf("A nije manje od B.\n"); 
		if(a>0 &&b>0&& a<b) break;
	}
	while ((prost=daj_prost()) <=a);
	while(prost<b){
		suma=prost+suma;
		prost=daj_prost();
	}
	printf("suma prostih brojeva izmedju %d i %d", a, b, suma);
	
	return 0;
}

	
