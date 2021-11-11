#include <stdio.h>
#include <math.h>

int main() {
	int brojac=0,broj=0,broj2;
	int z_cifra1,z_cifra2,z_cifra3,z_cifra4,z_cifra5,z_cifra6,z_cifra7,z_cifra8,z_cifra9;
	int c1,c2,c3,c4,c5,c6,c7,c8;
	printf("Unesite broj: ");
	scanf("%d",&broj2);
	if(broj<0) broj=fabs(broj);
	broj=broj2;
	
	 while(broj2!=0){
	  	z_cifra1=broj2%10;
	  	brojac++;
	  	broj2=broj2/10;
	 }
	 if(brojac==1) printf("%d",0);
	 
	 if(brojac==9)
	
	 {
	 	z_cifra1=broj%10;
		broj=broj/10;
		z_cifra2=broj%10;
		c1=fabs(z_cifra1-z_cifra2);
		
		
		broj=broj/10;
		z_cifra3=broj%10;
		c2=fabs(z_cifra2-z_cifra3);
		
		broj=broj/10;
		z_cifra4=broj%10;
		c3=fabs(z_cifra3-z_cifra4);
		
		broj=broj/10;
		z_cifra5=broj%10;
		c4=fabs(z_cifra4-z_cifra5);
		
		broj=broj/10;
		z_cifra6=broj%10;
		c5=fabs(z_cifra5-z_cifra6);
		
		broj=broj/10;
		z_cifra7=broj%10;
		c6=fabs(z_cifra6-z_cifra7);
		
		broj=broj/10;
		z_cifra8=broj%10;
		c7=fabs(z_cifra7-z_cifra8);
		
		broj=broj/10;
		z_cifra9=broj%10;
		c8=fabs(z_cifra8-z_cifra9);
	
		
		printf("%d%d%d%d%d%d%d%d ",c8,c7,c6,c5,c4,c3,c2,c1);
	 }
	 
	 else if(brojac==8)
	 {
	 	z_cifra1=broj%10;
		broj=broj/10;
		z_cifra2=broj%10;
		c1=fabs(z_cifra1-z_cifra2);
		
		
		broj=broj/10;
		z_cifra3=broj%10;
		c2=fabs(z_cifra2-z_cifra3);
		
		broj=broj/10;
		z_cifra4=broj%10;
		c3=fabs(z_cifra3-z_cifra4);
		
		broj=broj/10;
		z_cifra5=broj%10;
		c4=fabs(z_cifra4-z_cifra5);
		
		broj=broj/10;
		z_cifra6=broj%10;
		c5=fabs(z_cifra5-z_cifra6);
		
		broj=broj/10;
		z_cifra7=broj%10;
		c6=fabs(z_cifra6-z_cifra7);
		
		broj=broj/10;
		z_cifra8=broj%10;
		c7=fabs(z_cifra7-z_cifra8);
		printf("%d%d%d%d%d%d%d",c7,c6,c5,c4,c3,c2,c1);
		
	 }
	  else if(brojac==7)
	 {
	 	z_cifra1=broj%10;
		broj=broj/10;
		z_cifra2=broj%10;
		c1=fabs(z_cifra1-z_cifra2);
		
		
		broj=broj/10;
		z_cifra3=broj%10;
		c2=fabs(z_cifra2-z_cifra3);
		
		broj=broj/10;
		z_cifra4=broj%10;
		c3=fabs(z_cifra3-z_cifra4);
		
		broj=broj/10;
		z_cifra5=broj%10;
		c4=fabs(z_cifra4-z_cifra5);
		
		broj=broj/10;
		z_cifra6=broj%10;
		c5=fabs(z_cifra5-z_cifra6);
		
		broj=broj/10;
		z_cifra7=broj%10;
		c6=fabs(z_cifra6-z_cifra7);
		
		printf("%d%d%d%d%d%d",c6,c5,c4,c3,c2,c1);
		
	 }
	 else if(brojac==6)
	 {
	 	z_cifra1=broj%10;
		broj=broj/10;
		z_cifra2=broj%10;
		c1=fabs(z_cifra1-z_cifra2);
		
		
		broj=broj/10;
		z_cifra3=broj%10;
		c2=fabs(z_cifra2-z_cifra3);
		
		broj=broj/10;
		z_cifra4=broj%10;
		c3=fabs(z_cifra3-z_cifra4);
		
		broj=broj/10;
		z_cifra5=broj%10;
		c4=fabs(z_cifra4-z_cifra5);
		
		broj=broj/10;
		z_cifra6=broj%10;
		c5=fabs(z_cifra5-z_cifra6);
		if(z_cifra1==0 && z_cifra2==z_cifra3 && z_cifra3==z_cifra4 && z_cifra4==z_cifra5 && z_cifra5==z_cifra6)
	    printf("%d",c1);
	    else
	    
	    printf("%d%d%d%d%d",c5,c4,c3,c2,c1);
	
		
	 }
	 else if(brojac==5)
	 {
	 	z_cifra1=broj%10;
		broj=broj/10;
		z_cifra2=broj%10;
		c1=fabs(z_cifra1-z_cifra2);
		
		
		broj=broj/10;
		z_cifra3=broj%10;
		c2=fabs(z_cifra2-z_cifra3);
		
		broj=broj/10;
		z_cifra4=broj%10;
		c3=fabs(z_cifra3-z_cifra4);
		
		broj=broj/10;
		z_cifra5=broj%10;
		c4=fabs(z_cifra4-z_cifra5);
		printf("%d%d%d%d",c4,c3,c2,c1);
		
	
		
	 }
	 else if(brojac==4)
	 {
	 	z_cifra1=broj%10;
		broj=broj/10;
		z_cifra2=broj%10;
		c1=fabs(z_cifra1-z_cifra2);
		
		
		broj=broj/10;
		z_cifra3=broj%10;
		c2=fabs(z_cifra2-z_cifra3);
		
		broj=broj/10;
		z_cifra4=broj%10;
		c3=fabs(z_cifra3-z_cifra4);
		
		printf("%d%d%d",c3,c2,c1);
	
		
		
		
	 }
	 	 else if(brojac==3)
	 {
	 	
	 	z_cifra1=broj%10;
		broj=broj/10;
		z_cifra2=broj%10;
		c1=fabs(z_cifra1-z_cifra2);
		
		broj=broj/10;
		z_cifra3=broj%10;
		c2=fabs(z_cifra2-z_cifra3);
		if(c1!=0 && c2!=0)
		printf("%d%d",c2,c1);
		else printf("%d",0);
		
	 }
	 else if(brojac==2)
	 {
	 	z_cifra1=broj%10;
		broj=broj/10;
		z_cifra2=broj%10;
		c1=fabs(z_cifra1-z_cifra2);
		
		printf("%d",c1);
		
	 }









	
		
	return 0;
}
