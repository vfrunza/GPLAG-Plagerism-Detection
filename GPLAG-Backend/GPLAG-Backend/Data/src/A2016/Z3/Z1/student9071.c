#include <stdio.h>

int daj_prost(){
	static int mozdaprostbroj=1;
	int i=1,j=0;
		mozdaprostbroj++;
	for(i=1;i<=mozdaprostbroj;i++){
		if(mozdaprostbroj%i==0){
			j++;
		}


		if(j>2){
			i=0;
			j=0;
			mozdaprostbroj++;
		} 
	}


return mozdaprostbroj;
} /*funkcija koja radi :D*/

int main() {
int a,b,i,suma=0,x;
while(1){
	printf("Unesite brojeve A i B: ");
	scanf("%d %d",&a,&b);
	if(a>=b){
		printf("A nije manje od B.\n");
	}
	else if(a<1){
		printf("A nije prirodan broj.\n");
	} else if (b<1){
		printf("B nije prirodan broj.\n");
	}
	else {
		break;
	}
}

for(i=0;i<b;i++){
	x=daj_prost();
	if(x>a&&x<b){
		suma=suma+x;
	}
}

printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	return 0;
}


