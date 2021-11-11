#include <stdio.h>

int daj_prost(){
	static int i=1;
	int br=0,j;
	pocetak:
	for(j=1;j<=i;j++){
		if(i%j==0){
			br++;
		}
	}
	if(br!=2){
		i++;
		br=0;
		goto pocetak;
	}
	br=0;
	return i++;
}

int main() {
	int a,b,s=0,y=0;
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&a,&b);
		if(b<=a){
			printf("A nije manje od B.\n");
		}
		else if(a<=0){
			printf("A nije prirodan broj.\n");
		}
		else if(b<=0){
			printf("B nije prirodan broj.\n");
		}
	}
	while(a<=0 || b<=0 || b<=a);
	while(y<b){
		y=daj_prost();
		if(y>a && y<b){
			s=s+y;
		}
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,s);
	return 0;
}
