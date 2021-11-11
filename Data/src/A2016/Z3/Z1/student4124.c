#include <stdio.h>
static trenutni_prost=1;
int daj_prost(){
    int broj=trenutni_prost,i,prost;
    while(1){
        broj++;
        prost=1;
    for(i=2 ; i<broj ; i++){
        if(broj%i==0) prost=0;
        
        }
        if(prost==1){
            trenutni_prost=broj;
            return broj;
}
}
}


int main() {
    int A,B;
    do{
printf("Unesite brojeve A i B: ");
scanf("%d %d",&A,&B);
if(A>=B){
    printf("A nije manje od B.\n"); continue;
}
if(A<1){
    printf("A nije prirodan broj.\n"); continue;
}
if(B<1){
    printf("B nije prirodan broj.\n"); continue;
}


}
while(A<1 || B<1 || A>=B);
	int suma=0,j,temp;
	trenutni_prost=A;
	for(j=0; j<B-A; j++){
	    temp=daj_prost();
	    if(temp>=B) break;
	    suma+=temp;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	return 0;
	
}
