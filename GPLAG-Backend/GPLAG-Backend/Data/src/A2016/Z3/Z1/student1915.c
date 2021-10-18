#include <stdio.h>
#include<math.h>

 int daj_prost(){
	static int a=2;
     int i,j;
	
	for(i=a; i<100000; i++){
		int prost=1;
       for(j=2; j<=sqrt(i); j++)
	     	if(i % j==0){ prost=0; break;}
		
	if(prost==1){
		a=i;
		break;
	}
	}

	return a++;
	
}


int main() {
	int A,B;
	int pom1=1,pom2=1,sum=0;
	
	do{

     printf("Unesite brojeve A i B: ");
	scanf("%d %d",&A,&B);
	
	if(A<=0) printf("A nije prirodan broj.\n");
	
	else if (A>=B) printf("A nije manje od B.\n");
		
	}while(A>=B || A<=0);
	
	while(pom1 < A ){
		
		pom1=daj_prost();
		
		if(pom1>A && pom1<B) sum=pom1; 
	     
	}
	while(pom2 < B){
		
		pom2=daj_prost();
		
	     if(pom2>=B) break;
	     
	     sum+=pom2;
	}
	

	
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,sum);
	
	
	return 0;
}
