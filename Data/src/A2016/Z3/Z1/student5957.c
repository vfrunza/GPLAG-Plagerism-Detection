#include <stdio.h>
int prost(int x){
	int y=0,j=0,br=0;
	if(x==1)
	y=0;
	else{
	for(j=2; j<=x/2; j++)
		if(x%j==0)
			br++;

	if(br==0)
		y=1;
	else 
		y=0;}
	return y;
}
int daj_prost(){
	static int i=1;
	int y=0,b=0;
	do{
	int j=0,br=0;
	if(i==1)
	y=0;
	else{
	for(j=2; j<=i/2; j++)
		if(i%j==0)
			br++;

	if(br==0)
		y=1;
	else 
		y=0;}
		i++;
	}while(y!=1);
	b=i-1;
	return b;
}

int main() {
	int i=0,a=0,b=0,suma=0,j=0;
	do{
	printf("Unesite brojeve A i B: ");
	scanf("%d %d",&a,&b);
	if(a>b){
		
			printf("A nije manje od B.\n");
		
	}
	if(a<=0){
		
			printf("A nije prirodan broj.\n");
	}
	if(a==b){
		
			printf("A nije manje od B.\n");
}
	}while(a<=0 || a>b || a==b);
	for(i=1;i<b;i++){
		if(i>a && prost(i)==1)
		suma=suma+daj_prost();
		else if(i<=a && prost(i)==1)
		daj_prost();
		}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	
	return 0;
}
