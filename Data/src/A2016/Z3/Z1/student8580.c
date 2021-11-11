#include <stdio.h>
long int daj_prost(){
	long int i;
	static long int a=1;
	a++;
	for(i=2;i<a;i++)
	if(a%i==0){
	 a++;
	 i=1;
	 continue;}
	
	return a;
}

int main() {
	long int A,B,i,suma=0,k=1;
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%ld %ld",&A,&B);
		if(A<=0)
		     printf("A nije prirodan broj.\n");
		else if(A>=B)  
		     printf("A nije manje od B.\n");     
		     }
		     while(A>=B||A<=0||B<=0);
		   
		   do{
		   	i=daj_prost();
		   }
		   while(i<=A);
		   
		   suma=i;
		   
		while(i<B){
			i=daj_prost();
			if(i<B)
			suma=suma+i;
			k=0;
		}
		if(k)
		suma=0;
		printf("Suma prostih brojeva izmedju %ld i %ld je %ld.",A,B,suma);
	return 0;
}
