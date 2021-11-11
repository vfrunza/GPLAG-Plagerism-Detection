#include <stdio.h>
int prost(int i) {
	int j,br=0;
	for(j=1;j<=i;j++) {
		if(i%j==0) br++;
	}
	
	if (br==2)
	return 1;
	else 
	return 0;
	
}
int daj_prost() {
	static int i=1;
	again: i++;
	if(prost(i))
	return i;
	else goto again;
}


int main() {
	int a,b,suma=0,x;
	do {
	printf("Unesite brojeve A i B: ");
	scanf("%d %d",&a,&b);
	if(a==0||a<0) printf("A nije prirodan broj.\n");
	else if(a>b) printf("A nije manje od B.\n");
	else if(a==b) printf("A nije manje od B.\n");
	else if(a>0&&b<=0) printf("A nije manje od B.\n");
	} while(a>b||a==0||a<0||a==b);
	
	do {
		x=daj_prost();
		if(x>a && x<b)
		suma=suma+x;
	}
	while(x<b);	 
     printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);



	return 0;
}

	
