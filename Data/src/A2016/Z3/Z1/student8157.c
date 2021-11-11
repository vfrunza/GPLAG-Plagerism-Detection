#include <stdio.h>
int daj_prost(){
		int i,brojac=0;
		static int x=1;
		do{
			x++;
			brojac=0;
			for (i=1;i<=x;i++){
		if(x%i==0){
			brojac++;
		}
		}
		}while(brojac!=2);
return x;
}
int main() {
	int a,b,sum=0,z;
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d%d",&a,&b);
		if(a<=0){
			printf("A nije prirodan broj.\n");
		}
		else if(a>=b){
			printf("A nije manje od B.\n");
		}
	
		
	}while(a<=0 || a>=b); 

do{
	z=daj_prost();
	if(z>a && z<b){
		sum=sum+z;
	}
	
}while(z<b);
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,sum);
	return 0;
}
