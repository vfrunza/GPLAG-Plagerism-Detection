#include <stdio.h>

int main() {
	int n,tuna,tuna2,rez, gaba,rep,brojac,finito, kraj; 
	printf("Unesite broj: ");
	scanf("%d", &n); 
	
	if ((n/10)==0) { 
		rez=0;
		printf ("%d", rez);
		return 1;  
	}
	if ( n<0 ) n*=-1;  
	rez=0; 
	gaba=0; 
	
	while(n>0) { 
		tuna=n%10;
	   n/=10; 
	   	tuna2=n%10; 
		 	
		 		rez= tuna-tuna2;  
		 		if (rez<0) rez=rez*(-1);  
		  gaba= gaba *10; 
		 gaba =  gaba + rez; 
		 
	}
	brojac=1; 
	rep=gaba%10;  
	gaba= gaba -rep;
	gaba/=10; 
	rez=gaba; 
	
	while (gaba>0){ 
		brojac*=10;     
		gaba/=10;  
	} 
	brojac/=10;
	finito=0; 
	kraj=0; 
	
	
	while(rez>0){ 
		finito=rez%10; 
		rez/=10; 
		gaba=finito * brojac; 
		kraj+= gaba;  
		brojac/=10;
	
	
	}
		printf("%d", kraj);
	 
	return 0;
}
