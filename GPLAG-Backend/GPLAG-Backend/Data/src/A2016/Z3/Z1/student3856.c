#include <stdio.h>
int daj_prost ();
int main () {
	int x,y,a,suma=0,j,i;
	do {
	printf("Unesite brojeve A i B: ");
	scanf("%d %d",&x, &y);
	if(x>=y) printf ("A nije manje od B.\n");
	if(x<=0) printf ("A nije prirodan broj. \n");
	} while(x>=y || x<=0);
	for (;;){
		a=daj_prost();
		if(a>=y) break;
		if(a>x) suma+=a;
     	}
     printf("Suma prostih brojeva izmedju %d i %d je %d.",x,y,suma);
     return 0;
}
   
   
   
int daj_prost() {
     	static int i=2;
     	int j;
     	if(i==2) {
     		i++;
     		return 2;
     	
     	}
     	for(j=2; j<i; j++)
     	   if(i%j==0) {
     	   	i++;
     	   	j=1;
     	   }
     	   {
     	   	i++;
     	   	return (i-1);
     	   }}
    

		
		