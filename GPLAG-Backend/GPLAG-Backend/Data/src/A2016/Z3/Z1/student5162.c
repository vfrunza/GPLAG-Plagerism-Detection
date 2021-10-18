#include <stdio.h>
int daj_prost(){
	static int a=1;
	int i;
	a++;
	for(i=2;i<a;i++){
		if(i==a) return a;
		if(a%i==0){
			a++;
			i=1;
		}
	}
	if (i==a)
	return a;
}

int main() {
	int a,b,i,s=0,t,j;
	while(1==1){
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&a,&b);
		if(a<=0){ printf("A nije prirodan broj.\n"); continue;}
		else if(a>=b){printf("A nije manje od B.\n"); continue;}
		else if(a<=0 && b<=0){printf("A nije prirodan broj.\n");continue;}
		else if(b<=0){printf("B nije prirodan broj.\n");continue;}
		break;
	}
	for(i=a+1;i<b;i++){
		j=i;
		t=daj_prost();
		if(t<i){
			while(t!=i){
				t=daj_prost();
			}
			s+=t; 
		}
		if(t>i){
			while(j<b){
				j++;
				if(j==t) s+=t; 
			}
		}
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,s);
	return 0;
}
