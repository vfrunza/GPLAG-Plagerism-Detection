#include <stdio.h>
//pozivanje funkcije daj_prost, koja se izvrsava od n=2 do nekog beskonacno velikog broja
int daj_prost(){
		
	static int n=2;
	int prost,j;
	for( ; ;n++)
	{ 
	prost=1; //ispitivanje da li su brojevi prosti
	for(j=2;j<n;j=j+1)
	if(n%j==0)
	prost=0;
	if(prost==1)
	{
		n++; 
		return n-1;}
		
	}
	
}

int main(){
	int A,B,broj;
	int suma=0;
	//unos prirodnih brojeva A i B takvih da je A<B
	    do{
	    printf("\nUnesite brojeve A i B: ");
		scanf("%d %d",&A,&B);
		
		if(A<=0) printf("A nije prirodan broj.\n");
	    if(A>=B)printf("A nije manje od B.\n");}
		
		while( A<=0 || A>=B );
		
		
	  do{
      broj=daj_prost();
      if(broj>A&&broj<B) // broj se nalazi u intervalu od (A,B), tj. ogranicavamo broj u naznacenim intervalima ne ukljucujuci ih 
      suma+=broj;}
      while(broj<B);
			
		
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);//ispis sume svih prostih brojeva strogo vecih od A a strogo manjih od B
    return 0;}