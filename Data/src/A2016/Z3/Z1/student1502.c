#include <stdio.h>
int daj_prost(){
	static int j=2;
	int i;
	while(1==1){
		int prost=1;
		for(i=2;i<j;i++){
			if(j%i==0)prost=0;
		}
		if(prost==0) j++;
		else{
			j++;
			return j-1;
		}
	}
}

int main() {
	int m,n;
	int suma=0;
	p:
	printf("Unesite brojeve A i B: ");
	scanf("%d %d",&m,&n);
	if(n<=m){
		printf("A nije manje od B.\n");
		goto p;
	}else if(m<=0 && n<=0){
		printf("A nije prirodan broj.\n");
	    goto p;
	}else if(m<=0){
		printf("A nije prirodan broj.\n");
        goto p;
	}
	int b;
	while(1==1){
		b=daj_prost();
		if(b<=m)continue;
		if(b>=n)break;
		suma+=b;
		}
		printf("Suma prostih brojeva izmedju %d i %d je %d.",m,n,suma);
	return 0;
}
