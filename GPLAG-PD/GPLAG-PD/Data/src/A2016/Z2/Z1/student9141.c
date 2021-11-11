#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int broj=0, rezultat=0, a=0, b=0, razlika=0, temp=0, n=0, i, stepen=0, djelitelj=0;
	printf("Unesite broj: ");
	scanf("%d", &broj);
	temp=broj; 
	do{ 
	    temp=temp/10; 
	    n++; 
	    
	}while (temp!=0);
	
	for(i=1; i<n; i++){
	    stepen=(int)pow(10, n-i);
	    a=broj/pow(10, n-i);
	    b=(broj%stepen/pow(10, n-i-1));
	    razlika=abs(b-a);
	    djelitelj=pow(10, n-i);
	    broj=broj%djelitelj;
	    if(razlika==0 && rezultat==0) continue;
	    rezultat+=razlika;
	    if(i<n-1) rezultat*=10;
	    
	    
	}
	printf("%d", rezultat);
	return 0;
}
