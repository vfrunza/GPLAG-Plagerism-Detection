#include <stdio.h>

int daj_prost(){
	//posto nasa funkcija nema parametara,deklarisat cemo staticku promjenljivu i dodijeliti joj vrijednost 1
	int static br=1;
	int i,s=0;
	while(s==0){
		br++;
		s=1;
	//prolazimo kroz for petlju i trazimo sve proste brojeve 
	for(i=2;i<br;i++){
		//ako nema takvih brojeva program se prekida
		if(br%i==0){
			s=0;
			break;
		}
	}if(s==1)
	return br;
	
	}
}
int main() {
	int A,B,suma=0,br;
	br=daj_prost();
	do{
	printf("Unesite brojeve A i B: ");
	scanf("%d %d",&A,&B);
	if(A<=0 ){
		printf("A nije prirodan broj.\n");
	continue;	
	}
	if(A>=B){
		printf("A nije manje od B.\n");
	}
	}
	while(A<=0 || B<0 || A>=B);
	while(br<B){
	if(br>A){
	suma+=br;
	}
	br=daj_prost();
	if(br>=B) break;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.\n",A,B,suma);
	return 0;
}
	

