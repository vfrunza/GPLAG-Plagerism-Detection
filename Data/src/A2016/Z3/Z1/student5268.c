#include <stdio.h>
int daj_prost(){
	int i,j,prost;
static int g=2;
for(i=g;i<10000;i++){
	prost=1;
	for(j=2;j<i;j++){
		if(i%j==0){
			prost=0;
		}
		
	}
	g++;
	if(prost==0) continue;
	if(prost==1) return i;
}

}


int main () {
     int i,a,b,suma=0,s;
     for(i=0;i<1;i++){
     printf("Unesite brojeve A i B: ");
     scanf("%d%d",&a,&b);
     if(a<1){
     	i--;
     	printf("A nije prirodan broj.\n");
     	continue;
     }
     if(a>=b){
     	printf("A nije manje od B.\n");
     	i--;
     }
	
}
for(i=0;i<b;i++){
	s=daj_prost();
	if(s>a && s<b){
		suma=suma+s;
	}

}
printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);

return 0;
}
