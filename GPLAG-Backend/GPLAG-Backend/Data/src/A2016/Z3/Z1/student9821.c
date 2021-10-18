#include <stdio.h>
int f2(int n){
	int i;
	for(i=2; i<n; i++){
		if(n%i==0)
		return 0;
	}
	return 1;
}
int daj_prost(){
	static int a=1;
	a++;
	while(f2(a)==0){
		a++;
	}
	return a;
}
void f(int a, int b){
	a++;
	int i=daj_prost(), suma=0;
	while(i<a){
		i=daj_prost();
	}
	suma=0;
	while (i<b){
		if(f2(i)==1)
		suma+=i;
		i=daj_prost();
	}
	a--;
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
}
int main(){
	int a, b;
	do{
	    printf("Unesite brojeve A i B: ");
	    scanf("%d %d", &a, &b);
	    if(a<1){
		    printf("A nije prirodan broj.\n");
	    }
	    else if(a>=b){
		    printf("A nije manje od B.\n");
	    }
	}
	while(a<1 || a>=b);
	f(a, b);
	return 0;
}
