
#include <stdio.h>

int daj_prost()
{
static int x=1;
int brojac=0, i;
x++;
if(x==2) return x;
for(i=2;i<x;i++){
	if(x%i==0)brojac++;
}
if(x==1) return daj_prost();
if(brojac>0) return daj_prost();
else return x;
}


int main() {
	int a, b, n=0, temp, suma=0, y=2;
	
	while(n<1){
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &a,&b);
	if(a<=0){
	printf("A nije prirodan broj.\n"); }
	else if(a>=b){
	printf("A nije manje od B.\n");}
	else (n++);
}  while(y<b){
	temp=daj_prost();
	if(temp>a && temp<b){
	suma=suma+temp;}
	y++;
}
	
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	
	return 0;
}
