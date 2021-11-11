#include <stdio.h>

	int daj_prost(){
		int i,pb=1;
		static int ppb=1;
		ppb++;
		do{
			for(i=2; i<ppb; i++){
				pb=1;
				if(ppb%i==0){
					pb=0;
					break;	
				}
					
			}
			if(pb)
				break;
			ppb++;
		}while(1);
		return ppb;
	}
	
int main() {
	int	a,b,x=0,suma=0,i;
	do{
		printf("\nUnesite brojeve A i B: ");
		scanf("%d %d",&a,&b);
		if(a<=0)
			printf("A nije prirodan broj.");
		else if(a>=b)
			printf("A nije manje od B.");
		else if(b<=0)
			printf("B nije prirodan broj.");
		else
			break;
	}while(1);
	while(x<a){
		x=daj_prost();
	}
	for(i=a; i<b; i++){
		if((x>a)&&(x<b))
			suma+=x;
		if(x>=b)
			break;
		x=daj_prost();
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	return 0;
}
