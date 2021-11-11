#include <stdio.h>



	int DaLiJeProst(int n){
	int i;
	for(i=2;i<n;i++){
		if (n%i==0){
			n=0; 
			break;
		}
	}
	return n;

}

int daj_prost(){
	static int a=1;
	while(1){
		if(DaLiJeProst(++a))
		return a;
	}
}

int main(){
	int m,n,s=0,br,c,d,i;
	do{
		printf("Unesite brojeve A i B:");
		scanf("%d%d",&n,&m);
		if(n<=0)
		printf(" A nije prirodan broj.\n");
		else if (n>=m)
		printf(" A nije manje od B.\n");
	
	}
	while (n<=0 || n>=m);
	
	c=n;
	d=m;
	
	for(;;){
		br=daj_prost();
		if (br>=d) break;
		else if (br>c)
		s=s+br;
	}
	
	printf(" Suma prostih brojeva izmedju %d i %d je %d.",n,m,s);
	return 0;
}
