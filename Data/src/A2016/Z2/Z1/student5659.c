
#include <stdio.h>
#include<math.h>

int main() {
	
	int broj,a,b,c,d,brcif=0,i,m;
	printf("Unesite broj: ");
	scanf("%d", &broj);
	
	if(broj<0)	broj=-broj;
	if(broj>=0 && broj<10) { printf("0"); return 0; }
		m=broj;
	do { 
		m=m/10;
		brcif++;
	} while(m!=0);
	
	
	for(i=1;i<brcif;i++) {
		a=broj/pow(10,brcif-i);
		d=pow(10,brcif-i);
		broj=broj%d;
		b=broj/pow(10,brcif-i-1);
		c=b-a;
		if(i==1 && c==0) continue;
		if(c<0) c=-c;
		printf("%d",c);
	}
		
	
	

	
	return 0;
}
